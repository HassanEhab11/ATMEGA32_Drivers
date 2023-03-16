/**************************************** LIB  ****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
/**************************************** MCAL ****************************************/
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "TIMER_0_interface.h"
#include "GIE_interface.h"

/**************************************** HAL  ****************************************/
#include "CLCD_interface.h"


/*********************** FUNC PROTOTYPES AND GLOBAL VARIABLES  ************************/

void TIMER0_ISR_FUNC(void);


/**************************************** MAIN FUNC ***********************************/
void main(void)
{
	/******************  DRIVERS INIT ******************************/
	PORT_VoidInit();
	TIMER0_voidInit();
	//TIMER0_u8SetCallBack(&TIMER0_ISR_FUNC);
	TIMER0_voidStart();
	GIE_VoidEnable();
	PWM0_voidInit();
	//CLCD_voidInit();

	/***************** LOCAL VARIABLES ****************************/
u8 duty;
	while(1)
	{
		for(duty=50; duty>1; duty--)
		{
			PWM0_voidSetDutyCycle(duty);
			_delay_ms(100);
		}

		for(duty=1; duty<50; duty++)
		{
			PWM0_voidSetDutyCycle(duty);

			_delay_ms(100);
		}

	}
}

void TIMER0_ISR_FUNC(void)
{

	static u8 Local_u8Counter = 0;
	Local_u8Counter ++;
	if(Local_u8Counter == 1)
	{
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);

	}
	else if(Local_u8Counter == 2)
	{
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
		Local_u8Counter = 0;

	}
}

