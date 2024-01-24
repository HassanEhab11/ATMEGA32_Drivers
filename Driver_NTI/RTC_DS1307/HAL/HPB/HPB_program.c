/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL         *********************/
/******************    SWC(Driver): HPB         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include <util/delay.h>

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "HPB_private.h"
#include "HPB_config.h"
#include "HPB_interface.h"

void PB_voidInit(const PB_t* ptr_PB)
{
	MDIO_SetPinDirection(ptr_PB->PB_port, ptr_PB->PB_Pin, DIO_u8PIN_INPUT);


}
#if 0
void PB_voidReadState(const PB_t* ptr_PB, State_t* pstate)
{
	static State_t copy_u8state = NOT_PRESSED;

	u8 copy_u8PinVal;
	MDIO_GetPinValue(ptr_PB->PB_port, ptr_PB->PB_Pin, &copy_u8PinVal);

	if(copy_u8PinVal == ptr_PB->PB_mode)   // in this case the button is pressed
	{

		// check button previous state
		if(copy_u8state == NOT_PRESSED)
		{
			copy_u8state = PRESSED;
			_delay_ms(20);
			* pstate = PRESSED;

		}
		else if(copy_u8state == PRESSED)
		{
			* pstate = NOT_PRESSED;

		}
		else
		{
			//nothing
		}
	}
	else
	{
		* pstate = NOT_PRESSED;
		copy_u8state = NOT_PRESSED;
	}

}
#endif
void PB_voidReadState(const PB_t* ptr_PB, State_t* pstate)
{
	static State_t copy_u8state = NOT_PRESSED;

	u8 copy_u8PinVal;
	MDIO_GetPinValue(ptr_PB->PB_port, ptr_PB->PB_Pin, &copy_u8PinVal);

	if(copy_u8PinVal == ptr_PB->PB_mode)   // in this case the button is pressed
	{
		_delay_ms(20);
		MDIO_GetPinValue(ptr_PB->PB_port, ptr_PB->PB_Pin, &copy_u8PinVal);
		if(copy_u8PinVal == ptr_PB->PB_mode)
		{
			// check button previous state
			if(copy_u8state == NOT_PRESSED) // 1st press
			{
				copy_u8state = PRESSED;
				* pstate = PRESSED;

			}
			else if(copy_u8state == PRESSED)// trapped (long press)
			{
				* pstate = NOT_PRESSED;

			}
			else
			{
				//nothing
			}
		}// 2nd read after delay
		else {//Noise
			* pstate = NOT_PRESSED;
			copy_u8state = NOT_PRESSED;
		}

	}// 1st read befor delay
	else
	{
		* pstate = NOT_PRESSED;
		copy_u8state = NOT_PRESSED;
	}

}

