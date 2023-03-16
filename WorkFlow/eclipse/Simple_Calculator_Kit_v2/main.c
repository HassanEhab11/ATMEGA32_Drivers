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

/************************ HAL *********************************/
#include "CLCD_interface.h"
#include "KPD_interface.h"
/*********************Global Variables *****************************/
void GetNumber_1(u8* Num1);


/************************ Main Prog *******************************/
void main(void)
{
	/****************** Local Variables **************************/
	u8 Local_u8Counter;
	u8 Local_u8Num1;
	u8 Local_u8Num2;
	u8 Local_u8Operator;


	/******************** Driver Init ***************************/
	PORT_VoidInit();
	CLCD_voidInit();

	while(1)
	{
		GetNumber_1(&Local_u8Num1);

	}

}

/**************************** Function ***********************************/
void GetNumber_1(u8* Num1)
{
	do
	{
		Local_u8Num1 = KPD_u8GetPressedKey();
	}while(Local_u8CalcArr[Local_u8Counter] != '/'||Local_u8CalcArr[Local_u8Counter] !='*'||Local_u8CalcArr[Local_u8Counter] !='-'||Local_u8CalcArr[Local_u8Counter] !='+'||Local_u8CalcArr[Local_u8Counter] !='=');


}








