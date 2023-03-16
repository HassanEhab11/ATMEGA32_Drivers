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
#include "KPD_interface.h"


void main (void)
{
	u8 x;
	PORT_VoidInit();
	CLCD_voidInit();

	//	CLCD_voidSendString("Hassan Hello  ");
	//	CLCD_VoidWriteNumber(11);


	while (1)
	{
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);

		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);

		_delay_ms(1000);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);

		_delay_ms(1000);
	}

	//		do
	//		{
	//			x=KPD_u8GetPressedKey();
	//
	//		}
	//		while (x==0xff);
	//
	//		CLCD_voidSendData(x);
	//		//CLCD_VoidWriteNumber(x);
	//
	//	}




}

