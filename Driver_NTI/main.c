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

/***** HAL INCLUDE SECTION **************/
#include "HAL/HPB/HPB_interface.h"
#include "HAL/HSSD/HSSD_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HCLCD/CLCD_interface.h"
#include "HAL/HKEYPAD/KEYPAD_interface.h"
#include "HAL/HDCMOTOR/HDCMOTOR_interface.h"

#include "HAL/HUlTRASONIC/UlTRASONIC_interface.h"
/******** FUNCTION PROTOTYPE ***********/

/******* GLOBAL VARIABLE *************/


u32 u32_local_Distance =0;
void main(void)
{
	/*** Initialization Section ***/
	MGIE_VoidEnable();

	MTIMER1_voidInit();
	MTIMER1_enumStart();

	HCLCD_Init();
	HLED_voidInit(LED_BLUE);
	HLED_voidInit(LED_RED);
	HLED_voidInit(LED_YELLOW);
	HULTRASONIC_voidInit();

	HCLCD_SendString("HI");
	while(1)
	{
		HULTRASONIC_voidTrigger();

		u32_local_Distance = HULTRASONIC_u32Distance();
		if (u32_local_Distance>=68)
		{

			HCLCD_Clear();
			HCLCD_GoToXY(0,0);

			HCLCD_SendString("no object");
			_delay_ms(500);
		}
		else
		{
			HCLCD_Clear();
			HCLCD_GoToXY(1,0);

			HCLCD_SendString("distance=");
			HCLCD_SendNumber(u32_local_Distance);
			HCLCD_SendString("cm");
			_delay_ms(500);
		}


		_delay_ms(1000);


	}
}

