/*
 * CLCD_prog.c
 *
 * Created: 1/26/2023 1:50:20 AM
 *  Author: Hassan Ehab
 */ 

#include <util/delay.h>

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

u8 Local_u8SetPositionX = X_INITIAL_POSITION;
u8 Local_u8SetPositionY = Y_INITIAL_POSITION;



error_state_t HCLCD_SendCommand(u8 Copy_u8Command)
{
	error_state_t Local_ErrorState = R_OK;

	/* CLR RS Pin To Send Command */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
	/* CLR RW Pin To Select Write Mode */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/* Send Command To Data Pin */
	H_LCD_void_latchByte(Copy_u8Command);

	return Local_ErrorState;
}



error_state_t HCLCD_SendData(u8 Copy_u8Data)
{
	error_state_t Local_ErrorState = R_OK;
	if(specialCharacter  == OFF)
	{
		CLCD_CurrentPosition();
	}

	/* SET RS Pin To Send Data */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);
	/* CLR RW Pin To Select Write Mode */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/* Send Data To Data Pin */
	H_LCD_void_latchByte(Copy_u8Data);

	return Local_ErrorState;
}
error_state_t HCLCD_Init(void)
{
	error_state_t Local_ErrorState = R_OK;

	/* Initialize Data pins as output pin */
	MDIO_SetPinDirection(CLCD_DATA_PORT, CLCD_DATA_4_PIN0, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(CLCD_DATA_PORT, CLCD_DATA_4_PIN1, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(CLCD_DATA_PORT, CLCD_DATA_4_PIN2, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(CLCD_DATA_PORT, CLCD_DATA_4_PIN3, DIO_u8PIN_OUTPUT);
	/* Initialize Control pins as output pin */
	MDIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_OUTPUT);

	/* Wait more than 30ms */
	_delay_ms(40);

#if CLCD_MODE == _4_BIT_MODE
	/* Function set command : 2 lines , 5*8 font size */
	HCLCD_SendCommand(CLCD_SELECT_4_BIT_COMMAND_1);
	HCLCD_SendCommand(CLCD_SELECT_4_BIT_COMMAND_2);
	HCLCD_SendCommand(CLCD_SELECT_4_BIT_COMMAND_3);   /* 0bNFXXXXXX  --> N: no of lines F: font size*/

	/*Display on off control : disable enable , disable cursor , no blink cursor*/
	HCLCD_SendCommand(CLCD_DISPLAY_ON_CURSOR_OFF);
	HCLCD_SendCommand(CLCD_RETURN_HOME);

	HCLCD_SendCommand(CLCD_DISPLAY_LEFT_TO_RIGHT);

	/* Clear display */
	HCLCD_SendCommand(CLCD_DISPLAY_CLEAR);
#elif CLCD_MODE == _8_BIT_MODE


	HCLCD_SendCommand(CLCD_8_FUNC_SET);

	HCLCD_SendCommand(CLCD_8_DISPLAY_CTRL);

	HCLCD_SendCommand(CLCD_DISPLAY_CLEAR);

#else
#warning  Select Correct Mode !!!
#endif

	return Local_ErrorState;
}

error_state_t HCLCD_Clear(void)
{
	error_state_t Local_ErrorState = R_OK;
	/* Clear display */
	HCLCD_SendCommand(CLCD_DISPLAY_CLEAR); /* 1 or 0x01 or 0b00000001*/
	return Local_ErrorState;
}

error_state_t HCLCD_SendString(const char *Copy_pu8String)
{
	error_state_t Local_ErrorState = R_OK;
	u8 Local_Counter = 0;
	while (Copy_pu8String[Local_Counter] != NULL )
	{
		HCLCD_SendData(Copy_pu8String[Local_Counter]);
		Local_Counter ++;
	}

	return Local_ErrorState;
}

error_state_t HCLCD_SendNumber(f32 Copy_u32Number)
{
	error_state_t Local_ErrorState = R_OK;

	s32 Local_s32Number = Copy_u32Number;

	if(Local_s32Number == 0)
	{
		HCLCD_SendData('0');
	}
	else if (Local_s32Number <0)
	{
		HCLCD_SendData('-');
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
		HCLCD_SendData(Local_u8Array[local_s8Counter]+'0');
		local_s8Counter--;
	}
	return Local_ErrorState;
}

void HCLCD_voidWriteFloatNumber(f32 Copy_f32FloatNumber )
{

	if(Copy_f32FloatNumber == 0)
	{
		HCLCD_SendNumber(0);
	}

	else
	{
		s32 Local_s32DecemalNum=Copy_f32FloatNumber;
		HCLCD_SendNumber(Local_s32DecemalNum);

		Copy_f32FloatNumber = Copy_f32FloatNumber -Local_s32DecemalNum;
		if (Copy_f32FloatNumber>0)
		{
			HCLCD_SendData('.');
			Copy_f32FloatNumber*=100000;
			Local_s32DecemalNum = Copy_f32FloatNumber;

			while (Local_s32DecemalNum%10 == 0)
			{
				Local_s32DecemalNum/=10;
			}
			HCLCD_SendNumber(Local_s32DecemalNum);

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

/****
void DisplayValueOnLCD(u8 row, u8 col, u16 value) {  // need to edit
    HCLCD_GoToXY(row, col);
    HCLCD_SendNumber(value);
}****/

error_state_t HCLCD_WriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	error_state_t Local_ErrorState = R_OK;
	specialCharacter  = ON;

	u8 Local_u8CGRAMAddress= 0;
	u8 Local_u8Iterator =0;

	/* Calculate the CGRAM address whose each block is 8 bytes */
	Local_u8CGRAMAddress =Copy_u8PatternNumber*8;

	/* Send CGRAM Address command to LCD, with setting bit 6, clearing bit 7*/
	HCLCD_SendCommand(Local_u8CGRAMAddress+64);

	/* Write the pattern into CGRAM */

	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		HCLCD_SendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	/* go back to the DDRAM to display the Pattern*/
	HCLCD_GoToXY(Copy_u8XPos,Copy_u8YPos);
	/* Display the pattern written in the CGRAM*/
	HCLCD_SendData(Copy_u8PatternNumber);
	specialCharacter  = OFF;

	return Local_ErrorState;

}
/*
error_state_t HCLCD_GoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{
	error_state_t Local_ErrorState = R_OK;
    u8 Local_u8Adress=0;
    Local_u8SetPositionY = Copy_u8Ypos;
    Local_u8SetPositionX = Copy_u8Xpos;

    if (Copy_u8Xpos == CLCD_ROW_0)                      // First Line
    {
    	Local_u8Adress = Copy_u8Ypos+CLCD_ROW_ADDRESS_0;
    }
    else if (Copy_u8Xpos == CLCD_ROW_1)                // Second Line
    {
    	Local_u8Adress = Copy_u8Ypos+CLCD_ROW_ADDRESS_1;
    }
    else if (Copy_u8Xpos == CLCD_ROW_2)                // Third Line
    {
    	Local_u8Adress = Copy_u8Ypos+CLCD_ROW_ADDRESS_2;
    }
    else if (Copy_u8Xpos == CLCD_ROW_3)                // Fourth Line
    {
    	Local_u8Adress = Copy_u8Ypos+CLCD_ROW_ADDRESS_3;
    }

    HCLCD_SendCommand(Local_u8Adress+128);
	return Local_ErrorState;

}*/

error_state_t HCLCD_GoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{
	error_state_t Local_ErrorState = R_OK;
	u8 Local_u8Address = 0;
	Local_u8SetPositionY = Copy_u8Ypos;
	Local_u8SetPositionX = Copy_u8Xpos;

	// Array to store row addresses
	u8 RowAddresses[] = {CLCD_ROW_ADDRESS_0, CLCD_ROW_ADDRESS_1, CLCD_ROW_ADDRESS_2, CLCD_ROW_ADDRESS_3};

	// Check if Copy_u8Xpos is within a valid range (0-3)
	if (Copy_u8Xpos <= CLCD_ROW_NUM)
	{
		// Calculate the LCD address based on row and column
		Local_u8Address = RowAddresses[Copy_u8Xpos] + Copy_u8Ypos;

		// Set the cursor position on the LCD
		HCLCD_SendCommand(Local_u8Address | CLCD_CURSOR_POSITION_CMD); // Add 0x80 to set the cursor position command
	}
	else
	{
		// Invalid row value, set an error state
		Local_ErrorState = R_NOK;
	}

	return Local_ErrorState;
}



/********************* Static Functions *************************/

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
		HCLCD_GoToXY(Local_u8SetPositionX,Local_u8SetPositionY);
	}
	Local_u8SetPositionY++;
}


static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
#if CLCD_MODE == _4_BIT_MODE
	/* Send Command To Data Pin */
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN0, GET_BIT(copy_u8Byte,4));
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN1, GET_BIT(copy_u8Byte,5));
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN2, GET_BIT(copy_u8Byte,6));
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN3, GET_BIT(copy_u8Byte,7));


	/* Enable CLCD */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
	_delay_ms(5);
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN0, GET_BIT(copy_u8Byte,0));
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN1, GET_BIT(copy_u8Byte,1));
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN2, GET_BIT(copy_u8Byte,2));
	MDIO_SetPinValue(CLCD_DATA_PORT, CLCD_DATA_4_PIN3, GET_BIT(copy_u8Byte,3));
	/* Enable CLCD */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
	_delay_ms(5);
#elif CLCD_MODE == _8_BIT_MODE
	/* Send Command To Data Pin */
	MDIO_SetPortValue(CLCD_DATA_PORT, copy_u8Byte);
	/* Enable CLCD */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	/* Disable CLCD */
	MDIO_SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);

#else
#warning  Select Correct Mode !!!
#endif
}
