/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
/*************    SWC(Driver): LED (INTERFACE.h) ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H

#define LED_u8_CONNEC_SINK     0
#define LED_u8_CONNEC_SOURCE   1

typedef struct LED
{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
	u8 Copy_u8ConnecType;
}LED_t;



u8 LED_u8Init(LED_t* LED);
u8 LED_u8TurnOn(LED_t* LED);
u8 LED_u8TurnOff(LED_t* LED);
















#endif
