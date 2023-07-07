/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
/*************    SWC(Driver): LED (PROG.c)      ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

u8 LED_u8Init(LED_t* LED)
{
	u8 Local_u8ErrorState = 0;

	if (LED->Copy_u8Port<=DIO_u8PORTD && LED ->Copy_u8Pin<=DIO_u8PIN7)
	{
		DIO_u8SetPinDirection(LED->Copy_u8Port,LED->Copy_u8Pin,DIO_u8PIN_OUTPUT);

	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}


u8 LED_u8TurnOn(LED_t* LED)
{
	u8 Local_u8ErrorState = 0;


	if(LED->Copy_u8ConnecType == LED_u8_CONNEC_SINK)
	{
		DIO_u8SetPinValue(LED->Copy_u8Port,LED->Copy_u8Pin,DIO_u8PIN_LOW);

	}
	else if(LED->Copy_u8ConnecType == LED_u8_CONNEC_SOURCE)
	{
		DIO_u8SetPinValue(LED->Copy_u8Port,LED->Copy_u8Pin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 LED_u8TurnOff(LED_t* LED)
{
	u8 Local_u8ErrorState = 0;
	if(LED->Copy_u8ConnecType == LED_u8_CONNEC_SINK)
	{
		DIO_u8SetPinValue(LED->Copy_u8Port,LED->Copy_u8Pin,DIO_u8PIN_HIGH);

	}
	else if(LED->Copy_u8ConnecType == LED_u8_CONNEC_SOURCE)
	{
		DIO_u8SetPinValue(LED->Copy_u8Port,LED->Copy_u8Pin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}



