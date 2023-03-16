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
s32 MAP_s32OutPutValue(s32 IPMin, s32 IPMax, s32 OPMIN, s32 OPMax, s32 IPValue);

void main(void)
{
	PORT_VoidInit();
	CLCD_voidInit();
	ADC_voidInit();

	u16 Local_Adc_Reading;
	MAP_s32OutPutValue()

	while(1)
	{
		Local_Adc_Reading = ADC_u8GetChannelReading(ADC0);
		CLCD_voidGoToXY(0,0);
		CLCD_VoidWriteNumber(Local_Adc_Reading);
		_delay_ms(200);
		CLCD_voidClear();
		if (Local_Adc_Reading<=2)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
		}
		else if (Local_Adc_Reading<=20)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
		else if (Local_Adc_Reading<=33)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);

		}
		else if (Local_Adc_Reading<=44)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
		}
		else if (Local_Adc_Reading<=53)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);

		}
		else if (Local_Adc_Reading<=61)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);

		}
		else if (Local_Adc_Reading<=69)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);

		}
		else if (Local_Adc_Reading<=76)
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

	}
}

s32 MAP_s32OutPutValue(s32 IPMin, s32 IPMax, s32 OPMIN, s32 OPMax, s32 IPValue)
{
	s32 Local_OPValue;
	Local_OPValue = (((OPMax-OPMIN)/(IPMax-IPMin)*(IPValue-IPMax))+OPMIN);
	return Local_OPValue;
}

