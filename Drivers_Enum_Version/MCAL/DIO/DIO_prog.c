/*
 * DIO_prog.c
 *
 * Created: 1/24/2023 8:41:27 PM
 *  Author: Hassan Ehab
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_private.h"

error_state_t	DIO_SetPinDirection (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin, dio_direc_t Copy_Direction)
{
	error_state_t Local_ErrorState = R_OK;
	
	if (Copy_u8Pin <= DIO_u8PIN7)
	{
		if (Copy_Direction == DIO_u8PIN_INPUT)
		{
			switch (Copy_u8Port)
			{
				case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin); break;
				case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin); break;
				case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin); break;
				case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin); break;
		        default: Local_ErrorState = R_NOK; break;
			}
			
		}
		else if (Copy_Direction == DIO_u8PIN_OUTPUT)
		{
			switch (Copy_u8Port)
			{
				case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin); break;
				case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin); break;
				case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin); break;
				case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin); break;
				default: Local_ErrorState = R_NOK; break;
			}
			
		}
		else
		{
			Local_ErrorState = R_NOK;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}

error_state_t	DIO_SetPortDirection (dio_u8port_t Copy_u8Port, dio_u8portdirec_t Copy_Direction)
{
	error_state_t Local_ErrorState = R_OK;
	
	if(Copy_u8Port <= DIO_u8PORTD)
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA : DDRA = Copy_Direction; break;
			case DIO_u8PORTB : DDRB = Copy_Direction; break;
			case DIO_u8PORTC : DDRC = Copy_Direction; break;
			case DIO_u8PORTD : DDRD = Copy_Direction; break;
			default: Local_ErrorState = R_NOK; break;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}


error_state_t	DIO_SetPinValue (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin, dio_value_t Copy_Value)
{
	error_state_t Local_ErrorState = R_OK;
	
	if (Copy_u8Pin <= DIO_u8PIN7)
	{
		if (Copy_Value == DIO_u8PIN_LOW)
		{
			switch (Copy_u8Port)
			{
				case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin); break;
			}
			
		}
		else if (Copy_Value == DIO_u8PIN_HIGH)
		{
			switch (Copy_u8Port)
			{
				case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin); break;
		    	default: Local_ErrorState = R_NOK; break;
			}
			
		}
		else
		{
			Local_ErrorState = R_NOK;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}


error_state_t	DIO_SetPortValue (dio_u8port_t Copy_u8Port, dio_u8portvalue_t Copy_Value)
{
	error_state_t Local_ErrorState = R_OK;
	
	if(Copy_u8Port <= DIO_u8PORTD)
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA : PORTA = Copy_Value; break;
			case DIO_u8PORTB : PORTB = Copy_Value; break;
			case DIO_u8PORTC : PORTC = Copy_Value; break;
			case DIO_u8PORTD : PORTD = Copy_Value; break;
			default: Local_ErrorState = R_NOK; break;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}


error_state_t	DIO_GetPinValue (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin, u8* Copy_pu8Value)
{
	error_state_t Local_ErrorState = R_OK;
	
	if((Copy_pu8Value != NULL) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA : * Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin); break;
			case DIO_u8PORTB : * Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin); break;
			case DIO_u8PORTC : * Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin); break;
			case DIO_u8PORTD : * Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin); break;
			default: Local_ErrorState = R_NOK; break;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}
error_state_t	DIO_GetPortValue (dio_u8port_t Copy_u8Port, u8* Copy_pu8Value)
{
	error_state_t Local_ErrorState = R_OK;
	
	if((Copy_pu8Value != NULL) && (Copy_u8Port <= DIO_u8PORTD))
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA : * Copy_pu8Value = PINA; break;
			case DIO_u8PORTB : * Copy_pu8Value = PINB; break;
			case DIO_u8PORTC : * Copy_pu8Value = PINC; break;
			case DIO_u8PORTD : * Copy_pu8Value = PIND; break;
			default: Local_ErrorState = R_NOK; break;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}
error_state_t	DIO_AndValueWithPort (dio_u8port_t Copy_u8Port, u8 Copy_u8Value, u8 *Copy_u8Result)
{
	error_state_t Local_ErrorState = R_OK;
	
	if((Copy_u8Result != NULL) && (Copy_u8Port <= DIO_u8PORTD))
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA : * Copy_u8Result = PORTA & Copy_u8Value; break;
			case DIO_u8PORTB : * Copy_u8Result = PORTB & Copy_u8Value; break;
			case DIO_u8PORTC : * Copy_u8Result = PORTC & Copy_u8Value; break;
			case DIO_u8PORTD : * Copy_u8Result = PORTD & Copy_u8Value; break;
			default: Local_ErrorState = R_NOK; break;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}

error_state_t	DIO_TogglePinValue (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin)
{
	error_state_t Local_ErrorState = R_OK;
	
	if((Copy_u8Port <= DIO_u8PORTD) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA : TOG_BIT(PORTA, Copy_u8Pin); break;
			case DIO_u8PORTB : TOG_BIT(PORTB, Copy_u8Pin); break;
			case DIO_u8PORTC : TOG_BIT(PORTC, Copy_u8Pin); break;
			case DIO_u8PORTD : TOG_BIT(PORTD, Copy_u8Pin); break;
			default: Local_ErrorState = R_NOK; break;
		}
	}
	else
	{
		Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}