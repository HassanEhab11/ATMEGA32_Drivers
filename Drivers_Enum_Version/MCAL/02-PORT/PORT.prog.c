/*
 * PORT.c
 *
 * Created: 1/25/2023 6:31:32 AM
 *  Author: hassa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "PORT_config.h"
#include "PORT_private.h"

void PORT_VoidInit(void)
{
	DDRA  = PORTA_DIR;
	DDRB  = PORTB_DIR;
	DDRC  = PORTC_DIR;
	DDRD  = PORTD_DIR;
	
	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;
}