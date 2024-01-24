/*
 * GIE_prog.c
 *
 * Created: 1/28/2023 7:03:37 AM
 *  Author: hassa
 */ 

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"


#include "MGIE_interface.h"
#include "MGIE_private.h"

void MGIE_VoidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void MGIE_VoidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
