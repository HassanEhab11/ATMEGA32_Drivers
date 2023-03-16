/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
/*************    SWC(Driver): SSD (Prog.c)      ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "PB_interface.h"
#include "PB_config.h"
#include "PB_private.h"



u8 PB_u8Init(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState=0;
	if (Copy_u8Port<=DIO_u8PORTD && Copy_u8Pin <= DIO_u8PIN7)
	{
		DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin, DIO_u8PIN_INPUT);
	}
	else
	{
		Local_u8ErrorState = 1;
	}


	return Local_u8ErrorState;
}

u8 PB_u8GetState(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_Pu8Value)
{
		u8 Local_u8ErrorState=0;
		u8 Local_u8PinState=1;
		if (Copy_u8Port<=DIO_u8PORTD && Copy_u8Pin <= DIO_u8PIN7)
		{
		DIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin,&Local_u8PinState);

		if (Local_u8PinState == 0 )
		{
			_delay_ms(150);
			//while(Local_u8PinState == 0 ); /* not working */
			*Copy_Pu8Value = 1;
		}
		else if (Local_u8PinState == 1 )
		{
			*Copy_Pu8Value = 0;
		}

		else
		{
			Local_u8ErrorState = 1;
		}

		}

		else
		{
			Local_u8ErrorState = 1;
		}


		return Local_u8ErrorState;

}
