/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: hassa
 */


#include <avr/io.h>
#include<util/delay.h>
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "PORT_interface.h"



void main (void)
{
	PORT_VoidInit();



	while (1)
	{

		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
		_delay_ms(3000);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
		_delay_ms(3000);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
		_delay_ms(3000);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_LOW);
		_delay_ms(3000);









	}


}

