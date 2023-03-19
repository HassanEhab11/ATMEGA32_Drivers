/*
 * USART_prog.c
 *
 * Created: 2/17/2023 3:12:14 AM
 * Author: hassan ehab
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"


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
	UBRRL = 103;


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

void USART_voidSendString(const char *Copy_u8Data)
{
	u8 index = 0;
	while(Copy_u8Data[index]!= '\0') 
	{
		USART_voidSend(Copy_u8Data[index]);
		index++;
	}

}