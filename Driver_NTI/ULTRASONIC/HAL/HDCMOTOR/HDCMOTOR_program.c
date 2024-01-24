/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL         *********************/
/******************    SWC(Driver): HDCMOTOR    *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MTIMER0/MTIMER0_interface.h"

#include "HDCMOTOR_private.h"
#include "HDCMOTOR_config.h"
#include "HDCMOTOR_interface.h"


error_state_t HDCMOTOR_voidInit(void)
{
	error_state_t Local_u8ErrorState = DCMOTOR_OK;
	// init PWM0
	MPWM0_enumInit();

	// set motor pin direction as output
	MDIO_SetPinDirection(DCMOTOR_PWM_PORT, DCMOTOR_PWM_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(DCMOTOR_DIR_PORT, DCMOTOR_DIR_PIN, DIO_u8PIN_OUTPUT);
	MDIO_SetPinDirection(DCMOTOR_EN_PORT, DCMOTOR_EN_PIN, DIO_u8PIN_OUTPUT);

	return Local_u8ErrorState;

}

error_state_t HDCMOTOR_voidSetDirection(u8 Copy_u8MotorDirection)
{
	error_state_t Local_u8ErrorState = DCMOTOR_OK;

	if (Copy_u8MotorDirection == HDCMOTOR_CW){
		MDIO_SetPinValue(DCMOTOR_DIR_PORT, DCMOTOR_DIR_PIN, DIO_u8PIN_HIGH);

	} else if (Copy_u8MotorDirection == HDCMOTOR_CCW) {
		MDIO_SetPinValue(DCMOTOR_DIR_PORT, DCMOTOR_DIR_PIN, DIO_u8PIN_LOW);

	} else {
		// No thing
	}

	return Local_u8ErrorState;

}
error_state_t HDCMOTOR_voidSetSpeed(u8 Copy_u8DutyCycle)
{
	error_state_t Local_u8ErrorState = DCMOTOR_OK;

	MPWM0_enumSetDutyCycle(Copy_u8DutyCycle);

	return Local_u8ErrorState;
}

error_state_t HDCMOTOR_voidStart(void)
{
	error_state_t Local_u8ErrorState = DCMOTOR_OK;

	MPWM0_enumStart();

	return Local_u8ErrorState;
}

error_state_t HDCMOTOR_voidStop(void)
{
	error_state_t Local_u8ErrorState = DCMOTOR_OK;
	MPWM0_enumSetDutyCycle(0);
	MDIO_SetPinValue(1, 3, DIO_u8PIN_LOW);

	MPWM0_enumStop();
	//MDIO_SetPinValue(DCMOTOR_EN_PORT, DCMOTOR_EN_PIN, DIO_u8PIN_HIGH);

	return Local_u8ErrorState;
}

error_state_t HDCMOTOR_MoveCW(u8 Copy_u8DutyCycle)
{
	error_state_t Local_u8ErrorState = DCMOTOR_OK;

	HDCMOTOR_voidSetDirection(HDCMOTOR_CW);
	HDCMOTOR_voidSetSpeed(Copy_u8DutyCycle);
	HDCMOTOR_voidStart();

	return Local_u8ErrorState;

}

error_state_t HDCMOTOR_MoveCCW(u8 Copy_u8DutyCycle)
{
	error_state_t Local_u8ErrorState = DCMOTOR_OK;

	HDCMOTOR_voidSetDirection(HDCMOTOR_CW);
	HDCMOTOR_voidSetSpeed(Copy_u8DutyCycle);
	HDCMOTOR_voidStart();

	return Local_u8ErrorState;

}

