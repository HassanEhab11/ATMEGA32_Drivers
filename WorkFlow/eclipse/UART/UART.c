
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_register.h"
void UART_Init(void)
{
	//  // Set BaudRate -> 9600/16MhZ
	//  UBRRL = 102;
	//  UBRRH = 0;
	//  // Set Frame Format -> 8 data, 1 stop, No Parity
	//  UCSRC = 0x86;
	//  // Enable RX and TX
	//  UCSRB = 0x18;
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
}

void UART_SendChar(u8 data)
{
//	// Wait until transmission Register Empty
//	while((UCSRA&0x20) == 0x00);
//	UDR = data;
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);  // wait untill transmit data is empty
	UDR = data;
}

u8 UART_GetChar(void)
{
//	u8 Result;
//	// Wait until Reception Complete
//	while((UCSRA&0x80) == 0x00);
//	Result = UDR;
//
//	/* Clear Flag */
//	SET_BIT(UCSRA,7);
//	return Result;
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
		return UDR;

}

