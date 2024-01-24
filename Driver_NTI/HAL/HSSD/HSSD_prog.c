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

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "../HSSD/HSSD_interface.h"
#include "../HSSD/HSSD_config.h"
#include "../HSSD/HSSD_private.h"

error_state_t HSSD_Init(void)
{
	error_state_t Local_ErrorState = R_OK;

	MDIO_SetPinDirection(SSD_DATA_PORT,DATA_PIN_A, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(SSD_DATA_PORT,DATA_PIN_B, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(SSD_DATA_PORT,DATA_PIN_C, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(SSD_DATA_PORT,DATA_PIN_D, DIO_u8PIN_OUTPUT);

	MDIO_SetPinDirection(SSD_CTRL_PORT_1, SSD_1_EN_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(SSD_CTRL_PORT_1, SSD_2_EN_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(SSD_CTRL_PORT_2, SSD_3_EN_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(SSD_CTRL_PORT_2, SSD_4_EN_PIN, DIO_u8PIN_OUTPUT);


	return Local_ErrorState;
}
error_state_t HSSD_WriteData(u8 Copy_u8Num)
{
	error_state_t Local_ErrorState = R_OK;

	MDIO_SetPinValue(SSD_DATA_PORT,DATA_PIN_A,GET_BIT(Copy_u8Num,PIN_0));
	MDIO_SetPinValue(SSD_DATA_PORT,DATA_PIN_B,GET_BIT(Copy_u8Num,PIN_1));
	MDIO_SetPinValue(SSD_DATA_PORT,DATA_PIN_C,GET_BIT(Copy_u8Num,PIN_2));
	MDIO_SetPinValue(SSD_DATA_PORT,DATA_PIN_D,GET_BIT(Copy_u8Num,PIN_3));

	return Local_ErrorState;

}

error_state_t HSSD_DisplayBlink(u32 Copy_u8Num)
{
	error_state_t Local_ErrorState = R_OK;
	// there other way to use array instead
	//u8 copy_u8Digit [4];

	u8 Local_u8Ones = Copy_u8Num%10;
	Copy_u8Num/=10;
	u8 Local_u8Tens = Copy_u8Num%10;
	Copy_u8Num/=10;
	u8 Local_u8Hundred = Copy_u8Num%10;
	Copy_u8Num/=10;
	u8 Local_u8Thousand = Copy_u8Num;

	u8 Local_u8BlinkCounter = 0;
	for (Local_u8BlinkCounter = 0; Local_u8BlinkCounter<60; Local_u8BlinkCounter++)
	{
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_1_EN_PIN, DIO_u8PIN_LOW);
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_2_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_3_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_4_EN_PIN, DIO_u8PIN_HIGH);
		HSSD_WriteData(Local_u8Ones);

		_delay_ms(5);

		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_1_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_2_EN_PIN, DIO_u8PIN_LOW);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_3_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_4_EN_PIN, DIO_u8PIN_HIGH);
		HSSD_WriteData(Local_u8Tens);

		_delay_ms(5);

		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_1_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_2_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_3_EN_PIN, DIO_u8PIN_LOW);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_4_EN_PIN, DIO_u8PIN_HIGH);
		HSSD_WriteData(Local_u8Hundred);
		
		_delay_ms(5);
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_1_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_2_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_3_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_4_EN_PIN, DIO_u8PIN_LOW);
		HSSD_WriteData(Local_u8Thousand);
		
		_delay_ms(5);
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_1_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_1, SSD_2_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_3_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT_2, SSD_4_EN_PIN, DIO_u8PIN_HIGH);
		
	}
	
	return Local_ErrorState;
}
/*
error_state_t HSSD_DisplayNum(u8 Copy_u8Num)
{
	error_state_t Local_ErrorState = R_OK;
	
	u8 Local_u8Ones = Copy_u8Num%10;
	u8 Local_u8Tens = Copy_u8Num/10;
	
	for (; ;)
	{
		MDIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_LOW);
		MDIO_SetPortValue(SSD_DATA_PORT,SSD_Numbers[Local_u8Ones]);
		
		_delay_ms(5);
		
		MDIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_LOW);
		MDIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_HIGH);
		MDIO_SetPortValue(SSD_DATA_PORT,SSD_Numbers[Local_u8Tens]);
		
		_delay_ms(5);
		
		MDIO_SetPinValue(SSD_CTRL_PORT, SSD_1_EN_PIN, DIO_u8PIN_LOW);
		MDIO_SetPinValue(SSD_CTRL_PORT, SSD_2_EN_PIN, DIO_u8PIN_LOW);
	}
	
	return Local_ErrorState;
	
}*/
