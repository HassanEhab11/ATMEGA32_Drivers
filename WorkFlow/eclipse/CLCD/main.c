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



void main (void)
{
//	u8 arr1[8] ={0b00011000,0b00000000,0b00010010,0b00010010,0b00010011,0b00011110,0b00011110,0b00000000};
//	u8 arr2[8] ={0b00000000,0b00001010,0b00001010,0b00001010,0b00011111,0b00000000,0b00000000,0b00000000};
//	u8 arr3[8] ={0b00000111,0b00010001,0b00010001,0b00010001,0b00011111,0b00000000,0b00000000,0b00000000};
//	u8 arr4[8] ={0b00000100,0b00001010,0b00000100,0b00000100,0b00001110,0b00000100,0b00001010,0b00010100};
//	u8 arr5[8] ={0b00000100,0b00001010,0b00000100,0b00000100,0b00001110,0b00000100,0b00001010,0b00010100};

	u8 shape1[8] ={0b00001110,0b00010001,0b00010001,0b00010001,0b00001110,0b00000100,0b00000100,0b00000100};
	u8 shape2[8] ={0b00011111,0b00000100,0b00000100,0b00000100,0b00000100,0b00001010,0b00010001,0b00000000};
	u8 shape3[8] ={0b00000111,0b00001100,0b00010100,0b00000100,0b00000100,0b00001010,0b00010001,0b00000000};
	u8 ballup[8] ={0b00000000,0b00001110,0b00010001,0b00010001,0b00001110,0b00000000,0b00000000,0b00000000};
	u8 balldown[8] ={0b00000000,0b00000000,0b00000000,0b00001110,0b00010001,0b00010001,0b00001110,0b00000000};



	CLCD_voidInit();

	//	CLCD_voidSendData('H');
	//	CLCD_voidSendData('A');
	//	CLCD_voidSendData('S');
	//	CLCD_voidSendData('S');
	//	CLCD_voidSendData('A');
	//	CLCD_voidSendData('N');
	CLCD_voidGoToXY(1,5);
	//CLCD_voidSendString("Hassan10.5");
	//CLCD_voidWriteSpecialCharacter(arr1,0,0,0);
	//CLCD_voidWriteSpecialCharacter(arr2,1,0,1);
	//CLCD_voidWriteSpecialCharacter(arr3,2,0,2);
	//CLCD_voidWriteSpecialCharacter(arr4,3,1,2);
	CLCD_voidGoToXY(0,0);

//	CLCD_voidSendString("Hello Hassan");
//	CLCD_voidGoToXY(1,0);
//	CLCD_voidSendString("Welcome ****");

	CLCD_VoidWriteNumber(-102584);
//	LCD_enuWriteFloatNum(-20.8);
//	CLCD_voidWriteFloatNumber(-20.8 );

	while (1)
	{
//		CLCD_voidWriteSpecialCharacter(shape1,5,0,15);
//		CLCD_voidWriteSpecialCharacter(shape2,6,1,15);
//		CLCD_voidWriteSpecialCharacter(ballup,0,1,14);
//
//		_delay_ms(500);
//		CLCD_voidWriteSpecialCharacter(shape3,6,1,15);
//		CLCD_voidWriteSpecialCharacter(balldown,1,1,14);
//
//		_delay_ms(500);
//		CLCD_voidWriteSpecialCharacter(shape2,6,1,15);
//		CLCD_voidWriteSpecialCharacter(ballup,0,1,14);




	}




}

