/*
 * EXTI_prog.c
 *
 * Created: 1/28/2023 4:05:21 AM
 *  Author: hassa
 */ 

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "MEXTI_config.h"
#include "MEXTI_interface.h"
#include "MEXTI_private.h"

void (*INT0_pvFunc)(void) = NULL;
void (*INT_pvFunc)(void) = NULL;
void (*INT1_pvFunc)(void) = NULL;
void (*INT2_pvFunc)(void) = NULL;


error_state_t MEXTI_Enable(exti_t Copy_u8EXTIx, exti_sense_control_t Copy_u8EXTIxSense, void(*Copy_pvEXTIxFunc)(void))
{
	error_state_t Local_ErrorState = R_OK;
	
	switch(Copy_u8EXTIx)
	{
		/********** INT0 **********/
		case INT0 :
		/* Initialize the INT0 callback notification function globally */
		if (Copy_pvEXTIxFunc != NULL)
		{
			INT0_pvFunc = Copy_pvEXTIxFunc;
		} 
		else
		{
			Local_ErrorState = NULL_POINTER;
		}
		/* SET INT0 Sense Control */
		switch (Copy_u8EXTIxSense)
		{
			case LOW_LEVEL    : CLR_BIT(MCUCR,MCUCR_ISC00);    CLR_BIT(MCUCR,MCUCR_ISC01);    break;
			case ON_CHANGE    : SET_BIT(MCUCR,MCUCR_ISC00);    CLR_BIT(MCUCR,MCUCR_ISC01);    break;
			case FALLING_EDGE : SET_BIT(MCUCR,MCUCR_ISC01);    CLR_BIT(MCUCR,MCUCR_ISC00);    break;
			case RISING_EDGE  : SET_BIT(MCUCR,MCUCR_ISC01);    SET_BIT(MCUCR,MCUCR_ISC00);    break;
			default:           Local_ErrorState = R_NOK;                                      break;
	    }
		/* Enable INT0 */
		SET_BIT(GICR,GICR_INT0);
		break;
		/********** INT1 **********/
		case INT1 :
		/* Initialize the INT1 callback notification function globally */
        if (Copy_pvEXTIxFunc != NULL)
        {
        	INT1_pvFunc = Copy_pvEXTIxFunc;
        }
        else
        {
        	Local_ErrorState = NULL_POINTER;
        }		
		/* SET INT1 Sense Control */
		switch (Copy_u8EXTIxSense)
		{
			case LOW_LEVEL    : CLR_BIT(MCUCR,MCUCR_ISC10);    CLR_BIT(MCUCR,MCUCR_ISC11);    break;
			case ON_CHANGE    : SET_BIT(MCUCR,MCUCR_ISC10);    CLR_BIT(MCUCR,MCUCR_ISC11);    break;
			case FALLING_EDGE : SET_BIT(MCUCR,MCUCR_ISC11);    CLR_BIT(MCUCR,MCUCR_ISC10);    break;
			case RISING_EDGE  : SET_BIT(MCUCR,MCUCR_ISC11);    SET_BIT(MCUCR,MCUCR_ISC10);    break;
			default:           Local_ErrorState = R_NOK;                                      break;
		}
		/* Enable INT1 */
		SET_BIT(GICR,GICR_INT1);
		break;
		
		/********** INT2 **********/
		case INT2 :
		/* Initialize the INT2 callback notification function globally */
        if (Copy_pvEXTIxFunc != NULL)
        {
        	INT2_pvFunc = Copy_pvEXTIxFunc;
        }
        else
        {
        	Local_ErrorState = NULL_POINTER;
        }
		/* SET INT2 Sense Control */
		switch (Copy_u8EXTIxSense)
		{
			case FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2);    break;
			case RISING_EDGE : SET_BIT(MCUCSR,MCUCSR_ISC2);    break;
			default:           Local_ErrorState = R_NOK;       break;
		}
		/* Enable INT2 */
		SET_BIT(GICR,GICR_INT2);
		break;
		
		default: Local_ErrorState = R_NOK;
	}
	
	return Local_ErrorState;
}

error_state_t MEXTI_Disable(exti_t Copy_u8EXTIx)
{
	error_state_t Local_ErrorState = R_OK;
	switch(Copy_u8EXTIx)
	{
		case INT0:  CLR_BIT(GICR,GICR_INT0);  break;
		case INT1:  CLR_BIT(GICR,GICR_INT1);  break;
		case INT2:  CLR_BIT(GICR,GICR_INT2);  break;
		default:    Local_ErrorState = R_NOK; break;
	}
	
	return Local_ErrorState;
}

void MEXTI_FUNC( void(*Copy_pvEXTIxFunc)(void))
{
	INT_pvFunc = Copy_pvEXTIxFunc;
}


/*************** ISR Functions **************/
/******** INT0 ********/
ISR_ST(INT0_VECTOR)
{
	//if (INT_pvFunc != NULL)
	if (INT0_pvFunc != NULL)
	{
		INT0_pvFunc();
		//INT_pvFunc();
	} 
	else
	{
		/* Do No Thing */
	}
}
/******** INT1 ********/
ISR_ST(INT1_VECTOR)
{
	if (INT1_pvFunc != NULL)
	{
		INT1_pvFunc();
	}
	else
	{
		/* Do No Thing */
	}
}
/******** INT2 ********/
ISR_ST(INT2_VECTOR)
{
	if (INT2_pvFunc != NULL)
	{
		INT2_pvFunc();
	}
	else
	{
		/* Do No Thing */
	}
}
