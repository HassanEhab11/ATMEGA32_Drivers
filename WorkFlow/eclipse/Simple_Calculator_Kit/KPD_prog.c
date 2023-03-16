/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : HAL              ********************/
/*************    SWC(Driver): KPD (Prog.c)      ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"



u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	u8 Local_u8RowCounter;
	u8 Local_u8ColCounter;
	u8 Local_u8PinState;
	static u8 Local_u8KPDColArr[COLUMN_NUM]= {KPD_COL_0_PIN,KPD_COL_1_PIN,KPD_COL_2_PIN,KPD_COL_3_PIN };
	static u8 Local_u8KPDRowArr[ROW_NUM]= {KPD_ROW_0_PIN,KPD_ROW_1_PIN,KPD_ROW_2_PIN,KPD_ROW_3_PIN };
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;

	for (Local_u8ColCounter=0;Local_u8ColCounter<COLUMN_NUM;Local_u8ColCounter++)
	{
		/* Activate current Cloumn*/
		DIO_u8SetPinValue(KPD_COL_PORT,Local_u8KPDColArr[Local_u8ColCounter],DIO_u8PIN_LOW);

		for(Local_u8RowCounter=0;Local_u8RowCounter<ROW_NUM;Local_u8RowCounter++)
		{
			/* Read the current row */
			DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8KPDRowArr[Local_u8RowCounter],&Local_u8PinState);
			/* Check if switch is pressed */

			if(DIO_u8PIN_LOW == Local_u8PinState )
			{

				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];
				/* Polling (busy waiting ) until the key is released */
				while (DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8KPDRowArr[Local_u8RowCounter],&Local_u8PinState);

				}
				return Local_u8PressedKey;
			}

		}

		/* Deactivate the current column */

		DIO_u8SetPinValue(KPD_COL_PORT,Local_u8KPDColArr[Local_u8ColCounter],DIO_u8PIN_HIGH);

	}

	return Local_u8PressedKey;





}
