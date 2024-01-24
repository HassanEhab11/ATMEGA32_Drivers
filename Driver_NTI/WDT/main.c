/****** LIBIRARY INCLUDE SECTION *******/
#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"
#include <util/delay.h>

/***** MCAL INCLUDE SECTION ***********/
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MADC/MADC_interface.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "MCAL/MTIMER0/MTIMER0_interface.h"
#include "MCAL/MTIMER1/TIMER_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/WDT/WDT_interface.h"

/***** HAL INCLUDE SECTION **************/
#include "HAL/HPB/HPB_interface.h"
#include "HAL/HSSD/HSSD_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HCLCD/CLCD_interface.h"
#include "HAL/HKEYPAD/KEYPAD_interface.h"
#include "HAL/HDCMOTOR/HDCMOTOR_interface.h"

/******** FUNCTION PROTOTYPE ***********/

/******* GLOBAL VARIABLE *************/


void main(void)
{
	/*** Initialization Section ***/
	MGIE_VoidEnable();


	HCLCD_Init();
	HLED_voidInit(LED_BLUE);
	HLED_voidInit(LED_RED);
	HLED_voidInit(LED_YELLOW);


	HCLCD_SendString("Hello");
	HLED_voidTurnOn(LED_BLUE);
	_delay_ms(500);
	HLED_voidTurnOff(LED_BLUE);

	WDT_voidEnable();
	WDT_voidSleep(WDT_TIME_OUT_2_1_S);

	while(1)
	{
		HCLCD_SendString("Hello");
		_delay_ms(3000);
		HCLCD_Clear();
		WDT_voidRefresh();



	}
}

