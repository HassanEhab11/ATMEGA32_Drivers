/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): USART       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

#include "MUSART_interface.h"
#include "MUSART_config.h"
#include "MUSART_private.h"

void (*usart_rx_callback)(u8) = NULL;

char USART_MessageArr[MESSAGE_LENGTH] = {NULL};

// Function to initialize UART parameters
void MUSART_Init(const MUSART_Config* config) {

    u8 Local_u8USCRCValue = 0; // To write value on UCSRA

    // Use UCSRC, set data frame length according to the configuration
   switch (config->WordLength) {
        case UART_WORD_LENGTH_5_BIT:
            CLR_BIT(Local_u8USCRCValue, UCSRC_UCSZ0);
            CLR_BIT(Local_u8USCRCValue, UCSRC_UCSZ1);
            CLR_BIT(UCSRB, UCSRB_UCSZ2);
            break;
        case UART_WORD_LENGTH_6_BIT:
            SET_BIT(Local_u8USCRCValue, UCSRC_UCSZ0);
            CLR_BIT(Local_u8USCRCValue, UCSRC_UCSZ1);
            CLR_BIT(UCSRB, UCSRB_UCSZ2);
            break;
        case UART_WORD_LENGTH_7_BIT:
            CLR_BIT(Local_u8USCRCValue, UCSRC_UCSZ0);
            SET_BIT(Local_u8USCRCValue, UCSRC_UCSZ1);
            CLR_BIT(UCSRB, UCSRB_UCSZ2);
            break;
        case UART_WORD_LENGTH_8_BIT:
            SET_BIT(Local_u8USCRCValue, UCSRC_UCSZ0);
            SET_BIT(Local_u8USCRCValue, UCSRC_UCSZ1);
            CLR_BIT(UCSRB, UCSRB_UCSZ2);
            break;
        case UART_WORD_LENGTH_9_BIT:
            SET_BIT(Local_u8USCRCValue, UCSRC_UCSZ0);
            SET_BIT(Local_u8USCRCValue, UCSRC_UCSZ1);
            SET_BIT(UCSRB, UCSRB_UCSZ2); // For 9-bit data frame
            break;
        default:
            // Handle invalid word length configuration
            return;
    }

   switch(config->ParityBits)
   {
   case USART_PARITY_NONE:
	   CLR_BIT(Local_u8USCRCValue, UCSRC_UPM0);
	   CLR_BIT(Local_u8USCRCValue, UCSRC_UPM1);
	   break;
   case USART_PARITY_ODD :
	   SET_BIT(Local_u8USCRCValue, UCSRC_UPM0);
	   SET_BIT(Local_u8USCRCValue, UCSRC_UPM1);
	   break;
   case USART_PARITY_EVEN:
	   CLR_BIT(Local_u8USCRCValue, UCSRC_UPM0);
	   SET_BIT(Local_u8USCRCValue, UCSRC_UPM1);
	   break;
   default:
	   break;
   }

   switch(config->StopBits)
   {
   case USART_STOP_BITS_1:
	   CLR_BIT(Local_u8USCRCValue, UCSRC_USBS);
	   break;
   case USART_STOP_BITS_2:
	   SET_BIT(Local_u8USCRCValue, UCSRC_USBS);
	   break;
   default:
	   break;
   }
    // Asynchronous UART
    CLR_BIT(Local_u8USCRCValue, UCSRC_UMSEL);

    SET_BIT(Local_u8USCRCValue,UCSRC_URSEL);     /* use UCSRC */

    // Set UCSRC register
    UCSRC = Local_u8USCRCValue;

    // Set the baud rate using the provided macro
    UBRRH = (u8)(config->BaudRate >> 8);
    UBRRL = (u8)(config->BaudRate & 0xFF);

    // Enable Receiver and Transmitter
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);

#if 0
	u8 Local_u8USCRCValue = 0;     /* To write value on UCSRA*/
		SET_BIT(Local_u8USCRCValue,UCSRC_URSEL);     /* use UCSRC */
		SET_BIT(Local_u8USCRCValue,UCSRC_UCSZ0);     /* set to 8 bit */
		SET_BIT(Local_u8USCRCValue,UCSRC_UCSZ1);     /* set to 8 bit */

		/* Asynchronus UART*/
		CLR_BIT(Local_u8USCRCValue,UCSRC_UMSEL);

		UCSRC = Local_u8USCRCValue;

		/* BOUD RATE 9600 bit/sec*/
		UBRRL = 103;


		/* TX Enable Transmit and receive */
		SET_BIT(UCSRB,UCSRB_TXEN);
		SET_BIT(UCSRB,UCSRB_RXEN);
#endif
}


// Function to send a byte over UART
void MUSART_sendByte(u8 data) {
    while (GET_BIT(UCSRA, UCSRA_UDRE) == 0); // Wait until transmit data is empty
    UDR = data;
}
// Function to send a string over UART
void MUSART_sendString(const char* str) {
    u8 index = 0;
    while (str[index] != '\0') {
        MUSART_sendByte(str[index]);
        index++;
    }
}

// Function to receive a byte using polling with a timeout
u8 MUSART_receiveByteSynchNonBlocking(u32 timeout_ms) {
    u32 timeout = 0;
    while (GET_BIT(UCSRA, UCSRA_RXC) == 0) {
        if (timeout >= timeout_ms) {
            // Timeout occurred
            return 0xFF; // Or any special value to indicate a timeout
        }
        // You may need to add a delay here to control the polling rate
        // add delay
        timeout++;
    }
    return UDR;
}

// Function to configure UART Rx for asynchronous reception with a callback
void MUSART_receiveByteAsynchCallBack(void (*callback)(u8)) {
    // Enable UART Rx interrupt
    UCSRB |= (1 << UCSRB_RXCIE);

    // Set the callback function
    usart_rx_callback = callback;
}
void MUSART_recieveStringAsynchCallBack(void (*callback)(u8))
{
	MUSART_receiveByteAsynchCallBack(callback);

}

// UART Receive Complete (RX) interrupt handler
ISR_(USART_RXC_VECTOR) {
    u8 receivedByte = UDR; // Read the received byte
    if (usart_rx_callback != NULL) {
        usart_rx_callback(receivedByte); // Call the callback function
    }
}
