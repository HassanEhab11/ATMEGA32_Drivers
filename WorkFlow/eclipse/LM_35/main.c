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

void main(void)
{
	PORT_VoidInit();
	CLCD_voidInit();
	ADC_voidInit();

	u16 Local_Adc_Reading;
	u16 Local_Temp,x;

	while(1)
	{
		Local_Adc_Reading = ADC_u8GetChannelReading(ADC0);

		Local_Temp = (u16)(((u32)Local_Adc_Reading * 500UL)/1024UL);

		if(x!=Local_Temp)
		CLCD_voidClear();

		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Temp = ");
		CLCD_VoidWriteNumber(Local_Temp);
		CLCD_voidSendString(" c");
		x= Local_Temp;

		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("Temp = ");
		CLCD_VoidWriteNumber(Local_Adc_Reading);
		_delay_ms(200);
		/*
		 * check first four number in lm35
		 *
		 *
		 * */




	}
}

