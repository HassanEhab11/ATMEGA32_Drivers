/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): EXTI        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

void EXTI_VoidInt0Init(void)
{
	/* Set Sense Control for INT0 for falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	/*Peripheral interrupt enable for INT0*/

	SET_BIT(GICR,GICR_INT0);
}

void EXTI_VoidInt1Init(void)
{
	/* Set Sense Control for INT0 for falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

	/*Peripheral interrupt enable for INT0*/

	SET_BIT(GICR,GICR_INT1);
}
