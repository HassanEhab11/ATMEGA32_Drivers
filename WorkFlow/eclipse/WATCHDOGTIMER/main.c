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
#include "TIMER_interface.h"
#include "GIE_interface.h"
/************************ HAL *********************************/
#include "CLCD_interface.h"
#include "WD_TIMER_interface.h"
/*********************Global Variables *****************************/



/************************ Main Prog *******************************/
void main(void)
{
	/****************** Local Variables **************************/



	/******************** Driver Init ***************************/
	PORT_VoidInit();

	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
	WDT_voidEnable();
	WDT_voidSleep(6);



	/********************            *****************************/

	while(1)
	{
		WDT_voidDisable();

	}

}

