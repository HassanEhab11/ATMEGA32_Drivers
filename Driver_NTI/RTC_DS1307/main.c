/****** LIBIRARY INCLUDE SECTION *******/
#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"
#include <util/delay.h>

/***** MCAL INCLUDE SECTION ***********/
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MADC/MADC_interface.h"
#include "MCAL/MGIE/MGIE_interface.h"

#include "MCAL/MTIMER0/MTIMER0_interface.h"
#include "MCAL/MTIMER1/MTIMER1_interface.h"

#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MUSART/MUSART_interface.h"
/***** HAL INCLUDE SECTION **************/
#include "HAL/HPB/HPB_interface.h"
#include "HAL/HSSD/HSSD_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HCLCD/CLCD_interface.h"
#include "HAL/HKEYPAD/KEYPAD_interface.h"
#include "HAL/HDCMOTOR/HDCMOTOR_interface.h"
#include "HAL/HEEPROM/HEEPROM_interface.h"
#include "HAL/HUlTRASONIC/UlTRASONIC_interface.h"
#include "HAL/HRTC/HRTC_interface.h"
/******** FUNCTION PROTOTYPE ***********/
/******* GLOBAL VARIABLE *************/

#include "HAL/DS1307/DS1307_interface.h"



u32 u32_local_Distance =0;
u8 counter =  0;

void main(void)
{
	HCLCD_Init();


	/* RTC TEST */
#if 1
	u8 hours, minutes, seconds, am_pm;
	u8 year, month, day;

	HRTC_voidInit();

	// Set the initial time (e.g., 12:34:56 PM)
	HRTC_voidSetTime(9, 58, 56, AM);

	// Set the initial date (e.g., 2023-09-25)
	HRTC_voidSetDate(23, 9, 25);

	while(1)
	{
		/* Get and Display Time */

		HRTC_voidGetTime(&hours, &minutes, &seconds, &am_pm);
		HCLCD_GoToXY(0,0);
		HCLCD_SendString("Time: ");
		HCLCD_SendNumber(hours);
		HCLCD_SendData(':');
		HCLCD_SendNumber(minutes);
		HCLCD_SendData(':');
		HCLCD_SendNumber(seconds);

		HCLCD_GoToXY(0,16);
		if(am_pm == AM)
		{
			HCLCD_SendString(" AM");
		} else if(am_pm == PM){
			HCLCD_SendString(" PM");
		}
		else {
			HCLCD_SendString("   ");

		}

		/* Get and Display Date */
		HRTC_voidGetDate(&year, &month, &day);
		//_delay_ms(1000);

		HCLCD_GoToXY(1,0);
		HCLCD_SendString("Date: ");
		HCLCD_SendNumber(day);
		HCLCD_SendData('/');
		HCLCD_SendNumber(month);
		HCLCD_SendData('/');
		HCLCD_SendNumber(year);

		_delay_ms(1000);
	}
#endif

	/* EEPROM TEST */
#if 0
	EEPROM_Init();
	EEPROM_ReadByte(100, &counter);

	while(1)
	{
		EEPROM_WriteByte(100, counter++);


		HCLCD_GoToXY(1,0);
		HCLCD_SendNumber(counter);
		_delay_ms(1000);
	}
#endif

}

