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


void main(void)
{
	//	u8 volt,m;
	//	f32 Local_u8ADCReading,x;
	//	PORT_VoidInit();
	//	ADC_voidInit();
	//	CLCD_voidInit();
	//
	//	while(1)
	//	{
	//		Local_u8ADCReading = ADC_u8GetChannelReading(ADC0);
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


	PORT_VoidInit();
	CLCD_voidInit();
	ADC_voidInit();
	GIE_VoidEnable();




	while(1)
	{
		ADC_u8StartConversionAsynch(ADC0,&APP_u16ADCReading,&ADCNotification);




	}
}

void ADCNotification(void)
{
	DIO_u8SetPortValue(DIO_u8PORTC,APP_u16ADCReading);
}
