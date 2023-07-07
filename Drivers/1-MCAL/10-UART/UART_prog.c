/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): UART        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_register.h"
#include "UART_private.h"


void USART_voidInit(void)
{
	u8 Local_u8USCRCValue = 0;     /* To write value on UCSRA*/
	SET_BIT(Local_u8USCRCValue,UCSRC_URSEL);     /* use UCSRC */
	SET_BIT(Local_u8USCRCValue,UCSRC_UCSZ0);     /* set to 8 bit */
	SET_BIT(Local_u8USCRCValue,UCSRC_UCSZ1);     /* set to 8 bit */

	/* Asynchronus UART*/
	CLR_BIT(Local_u8USCRCValue,UCSRC_UMSEL);

	UCSRC = Local_u8USCRCValue;

	/* BOUD RATE 9600 bit/sec*/
	UBRRL = 51;


	/* TX Enable Transmit and receive */
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);


}

void USART_voidSend(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);  // wait untill transmit data is empty
	UDR = Copy_u8Data;

}
u8 USART_voidReceive(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
	return UDR;

}
