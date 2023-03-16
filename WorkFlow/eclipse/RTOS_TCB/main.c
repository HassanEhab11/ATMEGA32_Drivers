/*
 * main.c
 *
 *  Created on: Nov 14, 2022
 *      Author: hassa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
//#include "TIMER_0_interface.h"
//#include "GIE_interface.h"
#include "RTOS_interface.h"

void LED_1(void);
void LED_2(void);
void LED_3(void);



void main(void)
{
	PORT_VoidInit();

	RTOS_u8CreateTask(0,1000,&LED_1,1000);
	RTOS_u8CreateTask(1,2000,&LED_2,1000);
	RTOS_u8CreateTask(2,3000,&LED_3,1000);

	RTOS_voidStart(1);

//	TIMER0_u8SetCallBack(&LED_1);
//		GIE_VoidEnable();
//		TIMER0_voidInit();
//		TIMER0_voidSetTime_ms(1000);
//		TIMER0_voidStart();

	while(1)
	{

	}
}

void LED_1(void)
{
	static u8 Local_u8LedState = 0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,Local_u8LedState);

}
void LED_2(void)
{
	static u8 Local_u8LedState = 0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,Local_u8LedState);

}
void LED_3(void)
{
	static u8 Local_u8LedState = 0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,Local_u8LedState);

}
