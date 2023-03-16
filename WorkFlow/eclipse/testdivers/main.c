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
#include "GIE_interface.h"
#include "ADC_interface.h"
/************************ HAL *********************************/
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "SSD_interface.h"
#include "ADC_interface.h"
/*********************Local define *****************************/

#define Local_u8LedPort     DIO_u8PORTD
#define NO_OF_ID_DIGIT      4
#define NO_OF_PASS_CHECK    3


/*********************Global Variables *****************************/
u16 APP_u16ADCReading;
void ADCNotification(void);


u16 ADC_Chain1Reading[3];
u8 ADC_Chain1Channel[3]={ADC0,ADC1,ADC2};
ADC_Chain_t chain1 ={ADC_Chain1Channel,ADC_Chain1Reading,3,&ADCNotification};


/************************ Main Prog *******************************/
void main(void)
{
	/****************** Local Variables **************************/
	u8 Local_u8Counter;
	u8 Local_u8CheckCounter;
	u8 Local_u8IDArr[NO_OF_ID_DIGIT];
	u8 Local_u8PassArr[NO_OF_ID_DIGIT];
	u8 Local_u8PassOkFlag = 0;
	u8 Local_u8OutKey;



	/******************** Driver Init ***************************/

	PORT_VoidInit();
	CLCD_voidInit();
	ADC_voidInit();
	GIE_VoidEnable();

	while(1)
	{
		CLCD_voidGoToXY(0,4);
		CLCD_voidSendString("WELCOME");
		_delay_ms(2000);
		CLCD_voidClear();

		/**************************** Enter ID *********************************/
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Enter ID:");
		for(Local_u8Counter=0;Local_u8Counter<NO_OF_ID_DIGIT;Local_u8Counter++)
		{
			do
			{
				Local_u8IDArr[Local_u8Counter] = KPD_u8GetPressedKey();
			}while(Local_u8IDArr[Local_u8Counter] == KPD_NO_PRESSED_KEY);
			CLCD_VoidWriteNumber(Local_u8IDArr[Local_u8Counter]);
		}

		/******************************** Enter Pass *****************************/
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("Enter Pass:");
		for(Local_u8Counter=0;Local_u8Counter<NO_OF_ID_DIGIT;Local_u8Counter++)
		{
			SSD_u8SingleNumDisplayBlink(NO_OF_PASS_CHECK);

			do
			{
				Local_u8PassArr[Local_u8Counter] = KPD_u8GetPressedKey();
			}while(Local_u8PassArr[Local_u8Counter] == KPD_NO_PRESSED_KEY);
			CLCD_voidSendData('*');
		}
		/***************************** Pass Check *******************************/
		for(Local_u8CheckCounter=0;Local_u8CheckCounter<NO_OF_PASS_CHECK;Local_u8CheckCounter++)
		{
			for(Local_u8Counter=0;Local_u8Counter<NO_OF_ID_DIGIT;Local_u8Counter++)
			{
				if(Local_u8IDArr[Local_u8Counter] == Local_u8PassArr[NO_OF_ID_DIGIT-Local_u8Counter-1])
				{
					//SSD_u8SingleNumDisplayBlink(NO_OF_PASS_CHECK);
					if(Local_u8Counter == (NO_OF_ID_DIGIT-Local_u8Counter))
					{
						Local_u8PassOkFlag = 1;
					}

				}
				else
				{
					if(Local_u8CheckCounter == NO_OF_PASS_CHECK-1)
					{
						SSD_u8SingleNumDisplayBlink(0);
						CLCD_voidClear();
						CLCD_voidGoToXY(0,3);
						CLCD_voidSendString("BYE...BYE");
						_delay_ms(1000);
						break;
					}

					SSD_u8SingleNumDisplayBlink(NO_OF_PASS_CHECK-Local_u8CheckCounter-1);

					CLCD_voidClear();
					CLCD_voidGoToXY(0,0);
					CLCD_voidSendString("Pass Is Wrong");
					CLCD_voidGoToXY(1,0);
					CLCD_voidSendString("Enter Pass Again");
					_delay_ms(2000);
					CLCD_voidClear();
					CLCD_voidGoToXY(0,0);
					CLCD_voidSendString("ID:");
					for(Local_u8Counter=0;Local_u8Counter<NO_OF_ID_DIGIT;Local_u8Counter++)
					{
						CLCD_VoidWriteNumber(Local_u8IDArr[Local_u8Counter]);
					}
					CLCD_voidGoToXY(1,0);
					CLCD_voidSendString("Pass:");
					for(Local_u8Counter=0;Local_u8Counter<NO_OF_ID_DIGIT;Local_u8Counter++)
					{
						do
						{
							Local_u8PassArr[Local_u8Counter] = KPD_u8GetPressedKey();
						}while(Local_u8PassArr[Local_u8Counter] == KPD_NO_PRESSED_KEY);
						CLCD_voidSendData('*');
					}

				}

			}

			if (Local_u8PassOkFlag == 1)
			{
				break;
			}
		}

		if(Local_u8PassOkFlag == 1)
		{
			Local_u8PassOkFlag = 0;


			CLCD_voidClear();
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendString("Welcome Hassan");
			_delay_ms(1000);
			CLCD_voidClear();
			do
			{
				ADC_u8StartChainConversionAsynch(&chain1);

				Local_u8OutKey = KPD_u8GetPressedKey();

			}while(Local_u8OutKey == KPD_NO_PRESSED_KEY);

			// SSD off and led on
			DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
			DIO_u8SetPortValue(DIO_u8PORTB,DIO_u8PORT_LOW);
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
			DIO_u8SetPortValue(DIO_u8PORTD,DIO_u8PORT_LOW);


			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);
			CLCD_voidClear();

			do
			{
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendString("System Sleep");
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendString("Press On To Start");
				Local_u8OutKey = KPD_u8GetPressedKey();

			}while(Local_u8OutKey != 'c' );                               /* Not working good */
			CLCD_voidClear();



		}
		else {
			CLCD_voidClear();
		}







		//	ADC_u8StartChainConversionAsynch(&chain1);

	}

}

void ADCNotification(void)
{
	/******************** Local Variable ************************/
	u16 Local_Adc_1_Reading;
	u16 Local_Adc_2_Reading;
	u16 Local_Adc_3_Reading;

	u16 Local_Temp;

	Local_Adc_1_Reading = ADC_Chain1Reading[0] ;
	Local_Adc_2_Reading = ADC_Chain1Reading[1] ;
	Local_Adc_3_Reading = ADC_Chain1Reading[2] ;

	/*************************** ADC0 *************************************/
	Local_Temp = (u16)(((u32)Local_Adc_1_Reading * 500UL)/1024UL);
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("Temp = ");
	CLCD_VoidWriteNumber(Local_Temp);
	if(Local_Temp/10 <10)
	{
		CLCD_voidGoToXY(0,10);
		CLCD_voidSendString(" ");
	}

	if (Local_Temp>30)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
		CLCD_voidGoToXY(0,14);
		CLCD_voidSendData('M');
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);
		CLCD_voidGoToXY(0,14);
		CLCD_voidSendData(' ');
	}
	/********************************* ADC1 *****************************/
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("LEDS:");

	if (Local_Adc_2_Reading>0)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);

	}

	if (Local_Adc_2_Reading<=11)
	{
		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_HIGH);
		CLCD_VoidWriteNumber(8);

	}
	else if (Local_Adc_2_Reading<=80)
	{
		CLCD_VoidWriteNumber(7);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else if (Local_Adc_2_Reading<=132)
	{
		CLCD_VoidWriteNumber(6);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN1,DIO_u8PIN_LOW);

	}
	else if (Local_Adc_2_Reading<=176)
	{
		CLCD_VoidWriteNumber(5);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN2,DIO_u8PIN_LOW);
	}
	else if (Local_Adc_2_Reading<=213)
	{
		CLCD_VoidWriteNumber(4);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN3,DIO_u8PIN_LOW);

	}
	else if (Local_Adc_2_Reading<=274)
	{
		CLCD_VoidWriteNumber(3);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN5,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN6,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN7,DIO_u8PIN_HIGH);

	}
	else if (Local_Adc_2_Reading<=277)
	{
		CLCD_VoidWriteNumber(2);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN6,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN7,DIO_u8PIN_HIGH);

	}
	else if (Local_Adc_2_Reading<=304)
	{
		CLCD_VoidWriteNumber(1);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(Local_u8LedPort,DIO_u8PIN7,DIO_u8PIN_HIGH);

	}
	else
	{
		CLCD_VoidWriteNumber(0);

		DIO_u8SetPortValue(Local_u8LedPort,DIO_u8PORT_LOW);

	}
	/*************************** ADC2 *****************************/
	//	CLCD_voidGoToXY(1,8);
	//	CLCD_VoidWriteNumber(Local_Adc_3_Reading);
	//	if(Local_Adc_3_Reading/10 <100)
	//	{
	//		CLCD_voidGoToXY(1,11);
	//		CLCD_voidSendString("    ");
	//
	//	}
	CLCD_voidGoToXY(1,9);

	if (Local_Adc_3_Reading>500)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);

		CLCD_voidSendString("GasON ");
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_LOW);
		CLCD_voidGoToXY(1,9);
		CLCD_voidSendString("GasOFF");


	}
	/******************************************************************/

}
