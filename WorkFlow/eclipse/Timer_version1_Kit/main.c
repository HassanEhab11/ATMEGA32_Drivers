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

/*********************Global Variables *****************************/

static u16 PeriodTicks = 0;
static u16 OnTicks = 0;
void ICU_HW (void);

/************************ Main Prog *******************************/
void main(void)
{
	/****************** Local Variables **************************/



	/******************** Driver Init ***************************/
	PORT_VoidInit();

	ICU_u8SetCallBack(&ICU_HW);
	ICU_voidInit();

	TIMER1_voidInit();
	TIMER0_voidInit();

	CLCD_voidInit();

	GIE_VoidEnable();

	/********************            *****************************/

	while(1)
	{
		/* Wait until period ticks */
		while ((PeriodTicks == 0) && (OnTicks == 0));
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Period = ");
		CLCD_VoidWriteNumber(PeriodTicks);
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("ON  = ");
		CLCD_VoidWriteNumber(OnTicks);

	}

}

/******************************* ISR **********************************/
void ICU_HW (void)
{
	static u16 Reading1, Reading2, Reading3;
	static u8 Local_u8Counter = 0;
	Local_u8Counter ++;

	if(Local_u8Counter == 1 )
	{
		Reading1 = ICU_u16ReadInputCapture();

	}
	else if(Local_u8Counter == 2 )
	{
		Reading2 = ICU_u16ReadInputCapture();
		PeriodTicks = Reading2 - Reading1;
		ICU_u8SetTriggerEdge(ICU_FALLING_EDGE);

	}
	if(Local_u8Counter == 3 )
	{
		Reading3 = ICU_u16ReadInputCapture();
		OnTicks = Reading3 -Reading2;
		ICU_voidDisableInterrupt();

	}
}
