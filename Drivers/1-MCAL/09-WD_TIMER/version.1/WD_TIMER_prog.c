/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): WD_TIMER    *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WD_TIMER_config.h"
#include "WD_TIMER_interface.h"
#include "WD_TIMER_private.h"
#include "WD_TIMER_register.h"





void WDT_voidSleep(u8 Copy_u8SleepTime)
{
	/* Clear the prescaler bits*/
	WDTCR &= 0b11111000;
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
