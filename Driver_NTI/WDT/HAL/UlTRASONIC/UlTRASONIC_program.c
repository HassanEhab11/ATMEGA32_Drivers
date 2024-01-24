/*
 * ULTRASONIC_program.c
 *
 * Created: 29/09/2023 10:21:39 م
 *  Author: hassan ehab
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MTIMER1/TIMER_interface.h"

#include "ULTRASONIC_CONFIG.h"
#include "ULTRASONIC_interface.h"
#include "UlTRASONIC_private.h"


#define F_CPU 16000000UL
#include <util/delay.h>

static u16 u16_global_RissingValue = 0;
static u16 u16_global_FallingValue = 0;

void H_UltraInit(void)
{
	//TCCR1A = 0;
	MDIO_SetPinDirection(TRIGGER_PORT, TRIGGER_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(ECHO_PORT, ECHO_PIN, DIO_u8PIN_INPUT);

	/* Clear ICF flag */
	ICU_u8ClearInputCaptureFlag ();

}
void H_UltraTrigger(void)
{
	MDIO_SetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_u8PIN_HIGH);
	_delay_ms(50);
	MDIO_SetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_u8PIN_LOW);

}

void H_UltraUltraRissingEdge(void)
{
	// Rising edge, no prescaler , noise canceler
	ICU_u8SetTriggerEdge(ICU_RISING_EDGE);
	ICU_voidNoiseCanceler();
	TIMER1_voidSTOP();

	while (ICU_u8GetInputCaptureFlag() == 0);
	u16_global_RissingValue = ICU_u16ReadInputCapture();  		/* Take value of capture register */
	ICU_u8ClearInputCaptureFlag ();			/* Clear ICF flag */


}
void H_UltraUltraFallingEdge(void)
{
	// Rising edge, no prescaler , noise canceler
	ICU_u8SetTriggerEdge(ICU_RISING_EDGE);
	ICU_voidNoiseCanceler();
	TIMER1_voidSTOP();

	while (ICU_u8GetInputCaptureFlag() == 0);
	u16_global_RissingValue = ICU_u16ReadInputCapture();  		/* Take value of capture register */
	ICU_u8ClearInputCaptureFlag ();			/* Clear ICF flag */



	TIMER1_VoidSetTimerValue(0);        // try to remove ****************
	TIMER1_voidSTOP();  				/* Stop the timer */

}

u32  H_UltraDistance(void)
{
	u32 u32_local_TimeOn = u16_global_FallingValue - u16_global_RissingValue;
	u32 u32_local_Distance = 0;
	u32_local_Distance = ((u32_local_TimeOn * 34600) / (F_CPU*2)); //cpu*2


	return u32_local_Distance;
}

	/*if (u32_local_Distance>=80)
	{

		H_LcdClear();
		H_LcdWriteString("no object");
		_delay_ms(500);
	}
	else
	{
		H_LcdClear();
		H_LcdWriteString("distance=");
		H_LcdWriteNumber(u32_local_Distance);
		//H_LcdWriteNumber(u32_local_Distance);
		H_LcdWriteString("cm");
		_delay_ms(500);
	}*/

/*
void H_UltraStop(void)
{

}*/
