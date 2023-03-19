/*
 * GIE_prog.c
 *
 * Created: 1/28/2023 7:03:37 AM
 *  Author: hassa
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_VoidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_VoidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}