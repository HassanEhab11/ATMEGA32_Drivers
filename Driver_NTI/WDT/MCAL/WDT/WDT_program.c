/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): WD_TIMER    *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "WDT_config.h"
#include "WDT_interface.h"
#include "WDT_private.h"





void WDT_voidSleep(u8 Copy_u8SleepTime)
{
	/* Clear the prescaler bits*/
	WDTCR &= WDT_MUSK;
	/* Set the required prescaler*/
	WDTCR |= Copy_u8SleepTime;

}
void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);

}
void WDT_voidDisable(void)
{
	/* Disable sequence */
	WDTCR |= 0b00011000;
	WDTCR = 0;

}

void WDT_voidRefresh(void)
{
	asm("WDR");
}
