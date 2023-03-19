/*
 * KEYPAD_prog.c
 *
 * Created: 1/27/2023 12:43:30 AM
 *  Author: hassa
 */ 

#ifndef F_CPU
#define F_CPU 16000000 //CPU freq. in
#endif

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"

u8 KPD_u8ArrayValue[ROW_NUM][COL_NUM] = KPD_ARR_VAL;  

u8	KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	
	u8 Local_u8ColCounter = 0;
	u8 Local_u8RowCounter = 0;
	
	u8 Local_u8PinValue = 1;
	
	do 
	{
	
		for (Local_u8RowCounter = ROW_PIN1; Local_u8RowCounter <= ROW_PIN4; Local_u8RowCounter++)
		{
			/* Activate current Row*/
			DIO_SetPinValue(ROW_PORT, Local_u8RowCounter, DIO_u8PIN_LOW);
			
			for (Local_u8ColCounter = COL_PIN1; Local_u8ColCounter <= COL_PIN4; Local_u8ColCounter++)
			{
				/* Read Current Column */
				DIO_GetPinValue(COL_PORT, Local_u8ColCounter, &Local_u8PinValue);
				if (DIO_u8PIN_LOW == Local_u8PinValue)
				{
					/* Delay To Prevent Bouncing */
					_delay_ms(25);
				    DIO_GetPinValue(COL_PORT, Local_u8ColCounter, &Local_u8PinValue);
					if (DIO_u8PIN_LOW == Local_u8PinValue )
					{
						/* Polling (busy waiting ) until the key is released */
						while(DIO_u8PIN_LOW == Local_u8PinValue )
						{
							DIO_GetPinValue(COL_PORT, Local_u8ColCounter, &Local_u8PinValue);
						}

						Local_u8PressedKey = KPD_u8ArrayValue [Local_u8RowCounter-ROW_PIN1][Local_u8ColCounter-COL_PIN1];
					}	
				}		
			}	
			/* Deactivate current Row*/
			DIO_SetPinValue(ROW_PORT, Local_u8RowCounter, DIO_u8PIN_HIGH);
		}
	
	} while (KPD_NO_PRESSED_KEY == Local_u8PressedKey);
		//	DIO_SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);

	return Local_u8PressedKey;
}