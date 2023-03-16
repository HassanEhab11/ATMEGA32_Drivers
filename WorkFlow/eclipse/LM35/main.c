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

	u8 Local_Adc_Reading;
	u8 Local_Temp;
	u16 Local_MilliVolt;


	while(1)
	{
		Local_Adc_Reading = ADC_u8GetChannelReading(ADC0);
		Local_MilliVolt = (u16)((u32)Local_Adc_Reading * 500UL)/256UL;
		Local_Temp = Local_MilliVolt/10;
		CLCD_voidSendString("Temp = ");
		CLCD_voidWriteFloatNumber(Local_Temp);
		CLCD_voidSendString("c");
		_delay_ms(200);
		CLCD_voidClear();




	}
}

