/*
 * KEYPAD_prog.c
 *
 * Created: 1/27/2023 12:43:30 AM
 *  Author: hassa
 */ 

#include <util/delay.h>

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"

u8 KPD_u8ArrayValue[ROW_NUM][COL_NUM] = KP_MODE;

void HKPD_voidInit(void)
{
	//column input
	MDIO_SetPinDirection(KEYPAD_C0_PORT, KEYPAD_C0_PIN, DIO_u8PIN_INPUT);
	MDIO_SetPinDirection(KEYPAD_C1_PORT, KEYPAD_C0_PIN, DIO_u8PIN_INPUT);
	MDIO_SetPinDirection(KEYPAD_C2_PORT, KEYPAD_C0_PIN, DIO_u8PIN_INPUT);
	MDIO_SetPinDirection(KEYPAD_C3_PORT, KEYPAD_C0_PIN, DIO_u8PIN_INPUT);

	MDIO_SetPinValue(KEYPAD_C0_PORT, KEYPAD_C0_PIN, DIO_u8PIN_HIGH);
	MDIO_SetPinValue(KEYPAD_C1_PORT, KEYPAD_C0_PIN, DIO_u8PIN_HIGH);
	MDIO_SetPinValue(KEYPAD_C2_PORT, KEYPAD_C0_PIN, DIO_u8PIN_HIGH);
	MDIO_SetPinValue(KEYPAD_C3_PORT, KEYPAD_C0_PIN, DIO_u8PIN_HIGH);

	//row output
	MDIO_SetPinDirection(KEYPAD_R0_PORT, KEYPAD_R0_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(KEYPAD_R1_PORT, KEYPAD_R1_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(KEYPAD_R2_PORT, KEYPAD_R2_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(KEYPAD_R3_PORT, KEYPAD_R3_PIN, DIO_u8PIN_OUTPUT);


}

void HKPD_u8GetPressedKey(u8 * pPressedKey)
{
	* pPressedKey = KPD_NO_PRESSED_KEY;
	//u8 copy_u8stateflag =
	u8 Local_u8ColCounter = COL_INIT;
	u8 Local_u8RowCounter = ROW_INIT;

	u8 Local_u8PinValue = 1;

	do
	{

		for (Local_u8RowCounter = ROW_INIT; Local_u8RowCounter <= ROW_NUM; Local_u8RowCounter++)
		{
			/* Activate current Row*/
			MDIO_SetPinValue(Row_Port_Arr[Local_u8RowCounter], Row_Pin_Arr[Local_u8RowCounter], DIO_u8PIN_LOW);

			for (Local_u8ColCounter = COL_INIT; Local_u8ColCounter <= COL_NUM; Local_u8ColCounter++)
			{
				/* Read Current Column */
				MDIO_GetPinValue(Col_Port_Arr[Local_u8ColCounter], Col_Pin_Arr[Local_u8ColCounter],&Local_u8PinValue);
				if (DIO_u8PIN_LOW == Local_u8PinValue)
				{
					/* Delay To Prevent Bouncing */
					_delay_ms(25);
					MDIO_GetPinValue(Col_Port_Arr[Local_u8ColCounter], Col_Pin_Arr[Local_u8ColCounter],&Local_u8PinValue);
					if (DIO_u8PIN_LOW == Local_u8PinValue )
					{
						/* Polling (busy waiting ) until the key is released */
						while(DIO_u8PIN_LOW == Local_u8PinValue )
						{
							MDIO_GetPinValue(Col_Port_Arr[Local_u8ColCounter], Col_Pin_Arr[Local_u8ColCounter],&Local_u8PinValue);
						}

						* pPressedKey = KPD_u8ArrayValue [Local_u8RowCounter][Local_u8ColCounter];
					}
				}
			}
			/* Deactivate current Row*/
			MDIO_SetPinValue(Row_Port_Arr[Local_u8RowCounter], Row_Pin_Arr[Local_u8RowCounter], DIO_u8PIN_HIGH);
		}

	} while (KPD_NO_PRESSED_KEY == * pPressedKey);
}
