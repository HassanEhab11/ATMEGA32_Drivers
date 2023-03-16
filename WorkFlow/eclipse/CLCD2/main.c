///*
// * main.c
// *
// *  Created on: Aug 22, 2022
// *      Author: hassa
// */
//#include "STD_TYPES.h"
//#include "DIO_interface.h"
//
//#include "CLCD_interface.h"
//
//
//
//void main(void)
//{
////DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);
////DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);
//
//CLCD_voidInit();
//
//
//
//	CLCD_voidGoToXY(0,2);
//
//	CLCD_voidSendString("Hello Hassan");
//	CLCD_voidGoToXY(1,4);
//	CLCD_voidSendString("Welcome");
//	while(1)
//	{
//
//
//	}
//}

/*
 * CLCDtest.c
 *
 *  Created on: Aug 20, 2022
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
	CLCD_voidInit();

	CLCD_voidSendString("Hassan Hello  ");
	CLCD_VoidWriteNumber(11);


	while (1)
	{

	}




}

