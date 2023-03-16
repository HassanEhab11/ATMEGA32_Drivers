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


/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************>>>>>>>>>>>>>>>>> Stepper motor func need to edit <<<<<<<<<<<<<<<*******************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/


#include <avr/io.h>
#include<util/delay.h>
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "PORT_interface.h"
#include "KPD_interface.h"

void MainMenu(void);
void DcMotor(void);
void StepperMotor(void);


u8 shapeuprun[8] ={0b00001110,0b00010001,0b00010001,0b00010001,0b00001110,0b00000100,0b00000101,0b00000110};
u8 shapedownrun[8] ={0b00000100,0b00001100,0b00010100,0b00001100,0b00000100,0b00000100,0b00000110,0b00000101};
u8 shapeuprun2[8] ={0b00001110,0b00010001,0b00010001,0b00010001,0b00001110,0b00000100,0b00000100,0b00000100};
u8 shapedownrun2[8] ={0b00000110,0b00001101,0b00010100,0b00000100,0b00000100,0b00000100,0b00000110,0b00010001};



void main (void)
{
	PORT_VoidInit();
	CLCD_voidInit();







	while (1)
	{
		u8 i;
		for(i=0;i<15;i++)
		{
			CLCD_voidClear();
			CLCD_voidWriteSpecialCharacter(shapeuprun,0,0,i);
			CLCD_voidWriteSpecialCharacter(shapedownrun,1,1,i);

			_delay_ms(200);
			CLCD_voidClear();
			CLCD_voidWriteSpecialCharacter(shapeuprun2,2,0,i+1);
			CLCD_voidWriteSpecialCharacter(shapedownrun2,3,1,i+1);
			_delay_ms(200);

			i++;

		}
		MainMenu();

	}




}

void MainMenu(void)
{

	u8 LocalPressedKey;

	CLCD_voidClear();
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("Welcome to Motor");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString(" DashBoard App");
	_delay_ms(2000);
	CLCD_voidClear();
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("For DC Motor-->1");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("Stepper->2|Ex->3");
	do
	{
		LocalPressedKey = KPD_u8GetPressedKey();
	}while(LocalPressedKey == 0xff);

	if (LocalPressedKey == '1')
	{
		DcMotor();

	}

	else if (LocalPressedKey == '2')
	{
		StepperMotor();

	}

}

void DcMotor(void)
{
	u8 LocalPressedKey;

	CLCD_voidClear();
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("CW -->1 |CCW -->2");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("EX , MainMenu->3");
	do
	{
		LocalPressedKey = KPD_u8GetPressedKey();
	}while(LocalPressedKey == 0xff);

	if (LocalPressedKey == '1')
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
		CLCD_voidClear();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("CW Direction");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("DC Motor Menu->0");
		do
		{
			LocalPressedKey = KPD_u8GetPressedKey();
		}while(LocalPressedKey == 0xff);
		if (LocalPressedKey == '0')
		{
			DcMotor();

		}


	}
	else if (LocalPressedKey == '2')
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
		CLCD_voidClear();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("CCW Direction");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("DC Motor Menu->0");
		do
		{
			LocalPressedKey = KPD_u8GetPressedKey();
		}while(LocalPressedKey == 0xff);
		if (LocalPressedKey == '0')
		{
			DcMotor();

		}


	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
		MainMenu();
	}

}




void StepperMotor(void)
{
	u8 LocalPressedKey;

	CLCD_voidClear();
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("CW -->1 |CCW -->2");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("EX , MainMenu->3");
	do
	{
		LocalPressedKey = KPD_u8GetPressedKey();
	}while(LocalPressedKey == 0xff);

	if (LocalPressedKey == '1')
	{
		u8 i=0;
		for (i=0;i<36;i++)
		{

			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
			_delay_ms(100);

		}

		CLCD_voidClear();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("CW Direction");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("DC Motor Menu->0");
		do
		{
			LocalPressedKey = KPD_u8GetPressedKey();
		}while(LocalPressedKey == 0xff);
		if (LocalPressedKey == '0')
		{
			StepperMotor();

		}


	}
	else if (LocalPressedKey == '2')
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
		CLCD_voidClear();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("CCW Direction");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("DC Motor Menu->0");
		do
		{
			LocalPressedKey = KPD_u8GetPressedKey();
		}while(LocalPressedKey == 0xff);
		if (LocalPressedKey == '0')
		{
			DcMotor();

		}


	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
		MainMenu();
	}
}
