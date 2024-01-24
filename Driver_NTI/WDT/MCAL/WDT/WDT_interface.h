/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): WD_TIMER    *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef WD_TIMER_INTERFACE_H_
#define WD_TIMER_INTERFACE_H_

#define WDT_TIME_OUT_16_3_MS	0
#define WDT_TIME_OUT_32_5_MS	1
#define WDT_TIME_OUT_65_MS  	2
#define WDT_TIME_OUT_0_13_S 	3
#define WDT_TIME_OUT_0_26_S 	4
#define WDT_TIME_OUT_0_52_S 	5
#define WDT_TIME_OUT_1_S    	6
#define WDT_TIME_OUT_2_1_S  	7


void WDT_voidSleep(u8 Copy_u8SleepTime);
void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidRefresh(void);

#endif
