/*
 * main.c
 *
 *  Created on: Sep 14, 2022
 *      Author: hassa
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include <util/delay.h>


#include "GIE_interface.h"


void main(void)
{
	PORT_VoidInit();


	while(1)
	{


		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
		_delay_us(100);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		_delay_us(100);


	}
}

