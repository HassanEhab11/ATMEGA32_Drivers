/*
 * SSD_prog.c
 *
 * Created: 1/28/2023 2:19:47 AM
 *  Author: Hassan Ehab
 */ 

#ifndef F_CPU
#define F_CPU 16000000 //CPU freq. in
#endif

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"


error_state_t HSSD_DisplayBlink(u8 Copy_u8Num)
{
	error_state_t Local_ErrorState = R_OK;
	
	u8 Local_u8Ones = Copy_u8Num%10;
	u8 Local_u8Tens = Copy_u8Num/10;
	u8 Local_u8BlinkCounter = 0;
	
	for (Local_u8BlinkCounter = 0; Local_u8BlinkCounter<185; Local_u8BlinkCounter++)
	{
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_HIGH);
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_LOW);
		DIO_SetPortValue(SSD_DATA_PORT,SSD_Numbers[Local_u8Ones]);
		
		_delay_ms(5);
		
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_LOW);
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_HIGH);
		DIO_SetPortValue(SSD_DATA_PORT,SSD_Numbers[Local_u8Tens]);
		
		_delay_ms(5);
		
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_LOW);
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_LOW);	
	}
	
	return Local_ErrorState;
}

error_state_t HSSD_DisplayNum(u8 Copy_u8Num)
{
	error_state_t Local_ErrorState = R_OK;
	
	u8 Local_u8Ones = Copy_u8Num%10;
	u8 Local_u8Tens = Copy_u8Num/10;
	
	for (; ;)
	{
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_HIGH);
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_LOW);
		DIO_SetPortValue(SSD_DATA_PORT,SSD_Numbers[Local_u8Ones]);
		
		_delay_ms(5);
		
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_LOW);
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_HIGH);
		DIO_SetPortValue(SSD_DATA_PORT,SSD_Numbers[Local_u8Tens]);
		
		_delay_ms(5);
		
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_LOW);
		DIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_LOW);
	}
	
	return Local_ErrorState;
	
}