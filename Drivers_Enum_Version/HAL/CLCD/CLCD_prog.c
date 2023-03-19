/*
 * CLCD_prog.c
 *
 * Created: 1/26/2023 1:50:20 AM
 *  Author: Hassan Ehab
 */ 
#ifndef  F_CPU
# define F_CPU 16000000UL
#endif
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

static void CLCD_CurrentPosition(void);

u8 Local_u8SetPositionX = X_INITIAL_POSITION;
u8 Local_u8SetPositionY = Y_INITIAL_POSITION;

error_state_t CLCD_SendCommand(u8 Copy_u8Command)
{
	error_state_t Local_ErrorState = R_OK;
	
	/* CLR RS Pin To Send Command */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
	/* CLR RW Pin To Select Write Mode */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	
	#if CLCD_MODE == _4_BIT_MODE
    /* Send Command To Data Pin */
	
	#if DRIVER_PURPOUSE == PROTEUS
	u8 Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_PROTEUS_MASK, &Local_u8AndResult);
	u8 LocalData = ((Copy_u8Command & CLCD_COMMAND_PROTEUS_MASK) | Local_u8AndResult);
	#elif DRIVER_PURPOUSE == ATMEGA_KIT
	u8 Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_ATMEGA_KIT_MASK, &Local_u8AndResult);
	u8 LocalData = (((Copy_u8Command>>1 ) & CLCD_COMMAND_ATMEGA_KIT_MASK) | Local_u8AndResult);
	#endif
	
	DIO_SetPortValue(CLCD_DATA_PORT, LocalData);
	/* Enable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
	_delay_ms(5);
	
	#if DRIVER_PURPOUSE == PROTEUS
	Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_PROTEUS_MASK, &Local_u8AndResult);
	LocalData = ((Copy_u8Command <<4) |Local_u8AndResult);
	#elif DRIVER_PURPOUSE == ATMEGA_KIT
	Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_ATMEGA_KIT_MASK, &Local_u8AndResult);
	LocalData = ((Copy_u8Command <<3) |Local_u8AndResult);
	#endif
	
	DIO_SetPortValue(CLCD_DATA_PORT, LocalData);
	/* Enable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
	_delay_ms(5);
	#elif CLCD_MODE == _8_BIT_MODE
	/* Send Command To Data Pin */
	DIO_SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	/* Enable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);

	#else
	#warning  Select Correct Mode !!! 
	#endif
	
	
	return Local_ErrorState;
}



error_state_t CLCD_SendData(u8 Copy_u8Data)
{
	error_state_t Local_ErrorState = R_OK;
	CLCD_CurrentPosition();
	
	/* SET RS Pin To Send Data */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);
	/* CLR RW Pin To Select Write Mode */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	
	#if CLCD_MODE == _4_BIT_MODE
	/* Send Command To Data Pin */
	#if DRIVER_PURPOUSE == PROTEUS
	u8 Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_PROTEUS_MASK, &Local_u8AndResult);
	u8 LocalData = ((Copy_u8Data & CLCD_COMMAND_PROTEUS_MASK) | Local_u8AndResult);
	#elif DRIVER_PURPOUSE == ATMEGA_KIT
	u8 Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_ATMEGA_KIT_MASK, &Local_u8AndResult);
	u8 LocalData = (((Copy_u8Data>>1 ) & CLCD_COMMAND_ATMEGA_KIT_MASK) | Local_u8AndResult);
	#endif
		
	DIO_SetPortValue(CLCD_DATA_PORT, LocalData);
	/* Enable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
	_delay_ms(5);
	
	#if DRIVER_PURPOUSE == PROTEUS
	Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_PROTEUS_MASK, &Local_u8AndResult);
	LocalData = ((Copy_u8Data <<4) |Local_u8AndResult);
	#elif DRIVER_PURPOUSE == ATMEGA_KIT
	Local_u8AndResult = 0;
	DIO_AndValueWithPort(CLCD_DATA_PORT, CLCD_DATA_PORT_ATMEGA_KIT_MASK, &Local_u8AndResult);
	LocalData = ((Copy_u8Data <<3) |Local_u8AndResult);
	#endif	
	DIO_SetPortValue(CLCD_DATA_PORT, LocalData);
	
	/* Enable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
	_delay_ms(5);
	#elif CLCD_MODE == _8_BIT_MODE
	/* Send Data To Data Pin */
	DIO_SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	/* Enable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);

	#else
	#warning  Select Correct Mode !!!
	#endif
	
	
	return Local_ErrorState;
}
error_state_t CLCD_Init(void)
{
	error_state_t Local_ErrorState = R_OK;
	/* Wait more than 30ms */
	_delay_ms(40);
	
	#if CLCD_MODE == _4_BIT_MODE
	/* Function set command : 2 lines , 5*8 font size */
	CLCD_SendCommand(0x33);
	CLCD_SendCommand(0x32);
	CLCD_SendCommand(0x28);   /* 0bNFXXXXXX  --> N: no of lines F: font size*/


	/*Display on off control : disable enable , disable cursor , no blink cursor*/
	CLCD_SendCommand(0x0C);
	CLCD_SendCommand(0x02);

	CLCD_SendCommand(0x06);

	/* Clear display */
	CLCD_SendCommand(0x01);	
	#elif CLCD_MODE == _8_BIT_MODE

	
	CLCD_SendCommand(CLCD_8_FUNC_SET);
	
	CLCD_SendCommand(CLCD_8_DISPLAY_CTRL);
	
	CLCD_SendCommand(CLCD_DISPLAY_CLEAR); 
	
	#else
	#warning  Select Correct Mode !!!
	#endif
	
	
	return Local_ErrorState;
}



error_state_t CLCD_Clear(void)
{
	error_state_t Local_ErrorState = R_OK;
		
	/* Clear display */
	CLCD_SendCommand(CLCD_DISPLAY_CLEAR); /* 1 or 0x01 or 0b00000001*/
	
	return Local_ErrorState;
}

error_state_t CLCD_SendString(const char *Copy_pu8String)
{
	error_state_t Local_ErrorState = R_OK;
	u8 Local_Counter = 0;
	while (Copy_pu8String[Local_Counter] != NULL )
	{
		CLCD_SendData(Copy_pu8String[Local_Counter]);
		Local_Counter ++;
	}
	
	return Local_ErrorState;
}

error_state_t CLCD_SendNumber(f32 Copy_u32Number)
{
	error_state_t Local_ErrorState = R_OK;

	s32 Local_s32Number = Copy_u32Number;

	if(Local_s32Number == 0)
	{
		CLCD_SendData('0');
	}
	else if (Local_s32Number <0)
	{
		CLCD_SendData('-');
		Local_s32Number = Local_s32Number *(-1);

	}
	u8 Local_u8Array[20]={0};
	s8 local_s8Counter =0;
	while (Local_s32Number != 0)
	{
		Local_u8Array[local_s8Counter]= Local_s32Number%10;
		Local_s32Number/=10;
		local_s8Counter++;
	}
	local_s8Counter--;
	while (local_s8Counter>=0)
	{
		CLCD_SendData(Local_u8Array[local_s8Counter]+'0');
		local_s8Counter--;
	}
	return Local_ErrorState;
}

void CLCD_voidWriteFloatNumber(f32 Copy_f32FloatNumber )
{

	if(Copy_f32FloatNumber == 0)
	{
		CLCD_SendNumber(0);
	}

	else
	{
		s32 Local_s32DecemalNum=Copy_f32FloatNumber;
		CLCD_SendNumber(Local_s32DecemalNum);
		
		Copy_f32FloatNumber = Copy_f32FloatNumber -Local_s32DecemalNum;
		if (Copy_f32FloatNumber>0)
		{
			CLCD_SendData('.');
			Copy_f32FloatNumber*=100000;
			Local_s32DecemalNum = Copy_f32FloatNumber;

			while (Local_s32DecemalNum%10 == 0)
			{
				Local_s32DecemalNum/=10;
			}
			CLCD_SendNumber(Local_s32DecemalNum);

		}

		
		/* Rounding to the nearest decimal number after the sign */
		//if((Local_s32DecemalNum%100 )>500 )
		//{
		//	Local_s32DecemalNum = 5;
		//}
		//else
		//{
		//	Local_s32DecemalNum /=100;
		//}
	}
}

error_state_t CLCD_GoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{
	error_state_t Local_ErrorState = R_OK;
    u8 Local_u8Adress=0;
    Local_u8SetPositionY = Copy_u8Ypos;
    Local_u8SetPositionX = Copy_u8Xpos;
	
    if (Copy_u8Xpos == 0)                      // First Line
    {
    	Local_u8Adress = Copy_u8Ypos;
    }
    else if (Copy_u8Xpos == 1)                // Second Line
    {
    	Local_u8Adress = Copy_u8Ypos+0x40;
    }
    else if (Copy_u8Xpos == 2)                // Third Line
    {
    	Local_u8Adress = Copy_u8Ypos+0x10;
    }
    else if (Copy_u8Xpos == 3)                // Fourth Line
    {
    	Local_u8Adress = Copy_u8Ypos+0x50;
    }
    
    CLCD_SendCommand(Local_u8Adress+128);
	return Local_ErrorState;
	
}




static void CLCD_CurrentPosition(void)
{
	if(Local_u8SetPositionY>CLCD_COL_NUM)
	{
		Local_u8SetPositionX++;
		if(Local_u8SetPositionX>CLCD_ROW_NUM)
		{
			Local_u8SetPositionX = X_INITIAL_POSITION;
		}
		Local_u8SetPositionY = Y_INITIAL_POSITION;
		CLCD_GoToXY(Local_u8SetPositionX,Local_u8SetPositionY);
	}
	Local_u8SetPositionY++;

}