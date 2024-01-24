/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL         *********************/
/******************    SWC(Driver): HLED        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef _HLED_INTERFACE_H
#define _HLED_INTERFACE_H


typedef enum{
	LED_YELLOW = 0,
	LED_GREEN = 1,
	LED_RED = 2,
	LED_BLUE = 3

}Led_t;

/* To Init The Port and Pin Direction*/
void HLED_voidInit(Led_t copy_ledId);
void HLED_voidTurnOn(Led_t copy_ledId);
void HLED_voidTurnOff(Led_t copy_ledId);
void HLED_voidToggle(Led_t copy_ledId);

#endif
