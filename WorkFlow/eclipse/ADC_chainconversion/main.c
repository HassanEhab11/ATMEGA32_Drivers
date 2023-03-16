/*
 * main.c
 *
 *  Created on: Sep 14, 2022
 *      Author: hassa
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include <util/delay.h>

#include "ADC_interface.h"
#include "CLCD_interface.h"
#include "GIE_interface.h"

u16 APP_u16ADCReading;
void ADCNotification(void);


u16 ADC_Chain1Reading[3];
u8 ADC_Chain1Channel[3]={ADC0,ADC1,ADC2};
ADC_Chain_t chain1 ={ADC_Chain1Channel,ADC_Chain1Reading,3,&ADCNotification};

void main(void)
{



	PORT_VoidInit();
	CLCD_voidInit();
	ADC_voidInit();
	GIE_VoidEnable();

	while(1)
	{
		ADC_u8StartChainConversionAsynch(&chain1);



	}

}


void ADCNotification(void)
{
	u16 Local_Adc_1_Reading;
	u16 Local_Adc_2_Reading;
	u16 Local_Adc_3_Reading;

	u16 Local_Temp;

	Local_Adc_1_Reading = ADC_Chain1Reading[0] ;
	Local_Adc_2_Reading = ADC_Chain1Reading[1] ;
	Local_Adc_3_Reading = ADC_Chain1Reading[2] ;

	//DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);




	Local_Temp = (u16)(((u32)Local_Adc_1_Reading * 500UL)/1024UL);
	CLCD_voidGoToXY(0,0);
	CLCD_VoidWriteNumber(Local_Temp);
	if(Local_Temp/10 <10)
	{
		CLCD_voidGoToXY(0,2);

		CLCD_voidSendString(" ");


	}



	if (Local_Temp>30)
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);

	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	}

	CLCD_voidGoToXY(1,0);
	CLCD_VoidWriteNumber(Local_Adc_2_Reading);

	if (Local_Adc_2_Reading<=11)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
	}
	else if (Local_Adc_2_Reading<=80)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else if (Local_Adc_2_Reading<=132)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);

	}
	else if (Local_Adc_2_Reading<=176)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
	}
	else if (Local_Adc_2_Reading<=213)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);

	}
	else if (Local_Adc_2_Reading<=274)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);

	}
	else if (Local_Adc_2_Reading<=277)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);

	}
	else if (Local_Adc_2_Reading<=304)
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);

	}
	else
	{
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);

	}

	CLCD_voidGoToXY(1,5);
	CLCD_VoidWriteNumber(Local_Adc_3_Reading);
 if(Local_Adc_3_Reading/10 <100)
	{
		CLCD_voidGoToXY(1,8);

		CLCD_voidSendString("    ");


	}
	if (Local_Adc_3_Reading<500)
	{
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);

	}
	else
	{
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_LOW);
	}




}


//Local_u8ADCReading = ADC_u8GetChannelReading(ADC0);
//		x=(Local_u8ADCReading-25.5*(u8)(Local_u8ADCReading/25));
//		CLCD_voidGoToXY(1,10);
//
//		CLCD_voidWriteFloatNumber(-25.5 );
//
//
//		if(x<0)
//		{
//			Local_u8ADCReading = Local_u8ADCReading +1;
//		}
//		CLCD_voidGoToXY(1,0);
//		if(m!=Local_u8ADCReading)   CLCD_voidSendString("    ");
//		CLCD_voidGoToXY(1,0);
//
//		CLCD_VoidWriteNumber(Local_u8ADCReading);
//		m=Local_u8ADCReading;
//		DIO_u8SetPortValue(DIO_u8PORTC,Local_u8ADCReading);
//		volt = (f32)(Local_u8ADCReading*10)/255;
//		CLCD_voidGoToXY(0,0);
//		CLCD_voidSendString("Volt = ");
//		CLCD_VoidWriteNumber(volt);
//		CLCD_voidSendString(" ");
//		CLCD_voidGoToXY(0,10);
//		CLCD_voidSendString("V");
//		_delay_ms(500);

