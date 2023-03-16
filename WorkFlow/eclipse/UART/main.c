/*
 * main.c
 *
 *  Created on: Oct 1, 2022
 *      Author: hassa
 */
/************************ Delay ******************************/
#include <util/delay.h>
/***********************  LIB  *******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/************************ MCAL *******************************/
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "UART.h"
/************************ HAL *********************************/
#include "CLCD_interface.h"

/*********************Global Variables *****************************/



/************************ Main Prog *******************************/
void main(void)
{
	/****************** Local Variables **************************/



	/******************** Driver Init ***************************/
	PORT_VoidInit();
	CLCD_voidInit();
	UART_Init();

	GIE_VoidEnable();

	/********************            *****************************/
	char Data;
	char *data="*** hello ***";
	u8 i=0;

	do{
		UART_SendChar(data[i]);
		i++;
	}
	while(data[i]!='\0');

	while(1)
	{
		Data = UART_GetChar();
		if (Data == '1')
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			_delay_ms(500);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			_delay_ms(500);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			_delay_ms(500);
		}
		else if (Data == '2')
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
//			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
			_delay_ms(500);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			_delay_ms(500);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			_delay_ms(500);

		}
		UART_SendChar('D');

	}

}


