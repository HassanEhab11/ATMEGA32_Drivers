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
#include "EXTI_interface.h"
/************************ HAL *********************************/
#include "CLCD_interface.h"

/*********************Global Variables *****************************/

static u16 PeriodTicks = 0;
static u16 OnTicks = 0;
void ICU_SW (void);

/************************ Main Prog *******************************/
void main(void)
{
	/****************** Local Variables **************************/



	/******************** Driver Init ***************************/
	PORT_VoidInit();
	CLCD_voidInit();

	EXTI_u8Int0SetCallBack(&ICU_SW);
	EXTI_VoidInt0Init();

	TIMER1_voidInit();
	TIMER0_voidInit();

	GIE_VoidEnable();

	/********************            *****************************/

	while(1)
	{
		/* Wait until period ticks */
		while ((PeriodTicks == 0) && (OnTicks == 0));
		CLCD_voidGoToXY(0,0);

		CLCD_voidSendString("Hello Hassan");
		CLCD_voidGoToXY(2,0);
		CLCD_voidSendString("Period = ");
		CLCD_VoidWriteNumber(PeriodTicks);
		CLCD_voidGoToXY(3,0);
		CLCD_voidSendString("ON  = ");
		CLCD_VoidWriteNumber(OnTicks);

	}

}

/******************************* ISR **********************************/
void ICU_SW (void)
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;

	if(Local_u8Counter == 1)
	{
		/* First Rising Edge */
		TIMER1_VoidSetTimerValue(0);
	}
	else if (Local_u8Counter == 2)
	{
		/* Second rising edge */
		PeriodTicks = Timer1_u16ReadTimerValue();
		/* Change Trigger to failing edge */
		EXTI_u8IntSetSenseControl(INT0,FALLING_EDGE);
	}
	else if(Local_u8Counter == 3)
	{
		/* Timer reading now is period ticks + on ticks */
		OnTicks = Timer1_u16ReadTimerValue();
		OnTicks -= PeriodTicks;

		/* Disable INT0 interrupt*/
		EXTI_u8IntDisable(INT0);
	}
}
