/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL         *********************/
/******************    SWC(Driver): HLED        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "HLED_private.h"
#include "HLED_config.h"
#include "HLED_interface.h"

void HLED_voidInit(Led_t copy_ledId)
{

	switch(copy_ledId){
	case LED_YELLOW:
		MDIO_SetPinDirection (LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_u8PIN_OUTPUT);
		break;
	case LED_GREEN:
		MDIO_SetPinDirection (LED_GREEN_PORT, LED_GREEN_PIN, DIO_u8PIN_OUTPUT);
		break;
	case LED_RED:
		MDIO_SetPinDirection (LED_RED_PORT, LED_RED_PIN, DIO_u8PIN_OUTPUT);

		break;
	case LED_BLUE:
		MDIO_SetPinDirection (LED_BLUE_PORT, LED_BLUE_PIN, DIO_u8PIN_OUTPUT);
		break;



	}


}
void HLED_voidTurnOn(Led_t copy_ledId)
{
	switch(copy_ledId){
		case LED_YELLOW:
#if LED_YELLOW_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_u8PIN_HIGH);

#elif  LED_YELLOW_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_u8PIN_LOW);

#endif
			break;

		case LED_GREEN:
#if LED_GREEN_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_GREEN_PORT, LED_GREEN_PIN, DIO_u8PIN_HIGH);

#elif  LED_GREEN_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_GREEN_PORT, LED_GREEN_PIN, DIO_u8PIN_LOW);

#endif
			break;

		case LED_RED:
#if LED_RED_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_RED_PORT, LED_RED_PIN, DIO_u8PIN_HIGH);

#elif  LED_RED_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_RED_PORT, LED_RED_PIN, DIO_u8PIN_LOW);

#endif
			break;
		case LED_BLUE:
#if LED_BLUE_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_BLUE_PORT, LED_BLUE_PIN, DIO_u8PIN_HIGH);

#elif  LED_BLUE_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_BLUE_PORT, LED_BLUE_PIN, DIO_u8PIN_LOW);

#endif
			break;

	}


}
void HLED_voidTurnOff(Led_t copy_ledId)
{
	switch(copy_ledId){
		case LED_YELLOW:
#if LED_YELLOW_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_u8PIN_LOW);

#elif  LED_YELLOW_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_u8PIN_HIGH);
#endif
			break;

		case LED_GREEN:
#if LED_GREEN_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_GREEN_PORT, LED_GREEN_PIN, DIO_u8PIN_LOW);

#elif  LED_GREEN_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_GREEN_PORT, LED_GREEN_PIN, DIO_u8PIN_HIGH);

#endif
			break;

		case LED_RED:
#if LED_RED_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_RED_PORT, LED_RED_PIN, DIO_u8PIN_LOW);

#elif  LED_RED_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_RED_PORT, LED_RED_PIN, DIO_u8PIN_HIGH);

#endif
			break;
		case LED_BLUE:
#if LED_BLUE_DIR == LED_DIR_FORWARD
			MDIO_SetPinValue (LED_BLUE_PORT, LED_BLUE_PIN, DIO_u8PIN_LOW);

#elif  LED_BLUE_DIR == LED_DIR_REVERSE
			MDIO_SetPinValue (LED_BLUE_PORT, LED_BLUE_PIN, DIO_u8PIN_HIGH);

#endif
			break;

	}

}
void HLED_voidToggle(Led_t copy_ledId)
{
	switch(copy_ledId){
		case LED_YELLOW:
#if LED_YELLOW_DIR == LED_DIR_FORWARD
			MDIO_TogglePinValue (LED_YELLOW_PORT, LED_YELLOW_PIN);

#elif  LED_YELLOW_DIR == LED_DIR_REVERSE
			MDIO_TogglePinValue (LED_YELLOW_PORT, LED_YELLOW_PIN);
#endif
			break;

		case LED_GREEN:
#if LED_GREEN_DIR == LED_DIR_FORWARD
			MDIO_TogglePinValue (LED_GREEN_PORT, LED_GREEN_PIN);

#elif  LED_GREEN_DIR == LED_DIR_REVERSE
			MDIO_TogglePinValue(LED_GREEN_PORT, LED_GREEN_PIN);

#endif
			break;

		case LED_RED:
#if LED_RED_DIR == LED_DIR_FORWARD
			MDIO_TogglePinValue (LED_RED_PORT, LED_RED_PIN);

#elif  LED_RED_DIR == LED_DIR_REVERSE
			MDIO_TogglePinValue (LED_RED_PORT, LED_RED_PIN);

#endif
			break;
		case LED_BLUE:
#if LED_BLUE_DIR == LED_DIR_FORWARD
			MDIO_TogglePinValue (LED_BLUE_PORT, LED_BLUE_PIN);

#elif  LED_BLUE_DIR == LED_DIR_REVERSE
			MDIO_TogglePinValue (LED_BLUE_PORT, LED_BLUE_PIN);

#endif
			break;

	}

}
