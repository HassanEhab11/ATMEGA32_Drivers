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
#include "ADC_interface.h"
/************************ HAL *********************************/
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "SSD_interface.h"
/*********************Global Variables *****************************/
//void PWM(void);
s32 Map(s32 Copy_s32InputMin, s32 Copy_s32InputMax, s32 Copy_s32OutputMin, s32 Copy_s32OutputMax, s32 Copy_s32InputVal)
{
	s32 Local_s32OutputVal;
	Local_s32OutputVal = Copy_s32InputVal - Copy_s32InputMin;
	Local_s32OutputVal *= Copy_s32OutputMax- Copy_s32OutputMin;
	Local_s32OutputVal /= Copy_s32InputMax -Copy_s32InputMin;
	Local_s32OutputVal += Copy_s32OutputMin;
	return Local_s32OutputVal;
}
/************************ Main Prog *******************************/
void main(void)
{
	/****************** Local Variables **************************/



	/******************** Driver Init ***************************/
	PORT_VoidInit();
	CLCD_voidInit();
	ADC_voidInit();
	GIE_VoidEnable();
	TIMER0_voidInit();
	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);
	//	TIMER0_u8SetCallBack(&PWM);
	//	GIE_VoidEnable();


	u16 Local_u8Counter;
	u16 Local_u8Reading;
	u16 Local_u8ReadingMap;


	while(1)
	{
		Local_u8ReadingMap = Map(0,180,750,2500,30);
		CLCD_voidGoToXY(0,0);
		CLCD_VoidWriteNumber(Local_u8ReadingMap);


//				ADC_u8StartConversionSynch(ADC0,&Local_u8Reading);
//		//		u16 x = (((f32)(1000UL/1024UL)*Local_u8Reading ));
//		//		Local_u8ReadingMap = x+ 1000;
//		//
//		//
//		//
//				Local_u8ReadingMap = Map(0,1024,1000,2000,Local_u8Reading);
//				if(Local_u8Reading >100)
//				{
//					DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
//				}
//				TIMER1_SetChannelAComMatchValue(Local_u8ReadingMap);


//
//		for(Local_u8Counter=1000;Local_u8Counter<2000;Local_u8Counter++)
//		{
//			TIMER1_SetChannelAComMatchValue(Local_u8Counter);
//			_delay_ms(20);
//		}
//		for(Local_u8Counter=2000;Local_u8Counter>1000;Local_u8Counter--)
//		{
//			TIMER1_SetChannelAComMatchValue(Local_u8Counter);
//			_delay_ms(20);
//		}
		//		for(Local_u8Counter=255;Local_u8Counter>0;Local_u8Counter--)
		//		{
		//			TIMER0_SetComMatchValue(Local_u8Counter);
		//			_delay_ms(10);
		//		}


	}

}


/******************************** ISR *******************************/
//void PWM(void)
//{
//	static u8 Local_u8Counter = 0;
//	//static u8 Local_u8LedState=0;
//	Local_u8Counter++;
//	if(Local_u8Counter == 1)
//	{
//		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
//
//	}
//	else if(Local_u8Counter == 3)
//	{
//		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
//
//	}
//	else if(Local_u8Counter == 2)
//	{
//		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
//
//	}
//	else if(Local_u8Counter == 20)
//	{
//		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
//		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
//		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
//
//		Local_u8Counter = 0;
//
//	}
//
//}
