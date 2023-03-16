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


/****************************************************************************************************/
/****************************************************************************************************/
/**********************  global pointer to function to hold INT ISR address  ************************/
/****************************************************************************************************/

void (*EXTI_pvInt0Func)(void)=NULL;
void (*EXTI_pvInt1Func)(void)=NULL;
void (*EXTI_pvInt2Func)(void)=NULL;


/****************************************************************************************************/
/****************************************************************************************************/
/********************************     Init Function By pre build Method    **************************/
/****************************************************************************************************/

/*****************************************     INT0Init    ******************************************/

void EXTI_VoidInt0Init(void)
{
#if INT0_SENSE == LOW_LEVEL
	{
		/* Set Sense Control for INT0 for LOW_LEVEL*/
		ClR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);


	}
#elif INT0_SENSE == ON_CHANGE
	{
		/* Set Sense Control for INT0 for ON_CHANGE*/
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);


	}
#elif INT0_SENSE == FALLING_EDGE
	{
		/* Set Sense Control for INT0 for falling edge*/
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);


	}
#elif INT0_SENSE == RISING_EDGE
	{
		/* Set Sense Control for INT0 for RISING_EDGE*/
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
	}
#else
	{
#error "Wrong INT0_SENSE Configuration option"
	}
#endif

	/*Check Peripheral interrupt enable for INT0_INTIAL_STATE */

#if  INT0_INTIAL_STATE == ENABLED
	{
		SET_BIT(GICR,GICR_INT0);
	}
#elif  INT0_INTIAL_STATE == DISABLED
	{
		CLR_BIT(GICR,GICR_INT0);
	}
#else
	{
#error "Wrong INT0_INTIAL_STATE Configuration option"
	}
#endif
}

/*****************************************     INT1Init    ******************************************/

void EXTI_VoidInt1Init(void)
{
#if INT1_SENSE == LOW_LEVEL
	{
		/* Set Sense Control for INT1 for LOW_LEVEL*/
		ClR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);


	}
#elif INT1_SENSE == ON_CHANGE
	{
		/* Set Sense Control for INT1 for ON_CHANGE*/
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);


	}
#elif INT1_SENSE == FALLING_EDGE
	{
		/* Set Sense Control for INT1 for falling edge*/
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);


	}
#elif INT1_SENSE == RISING_EDGE
	{
		/* Set Sense Control for INT1 for RISING_EDGE*/
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
	}
#else
	{
#error "Wrong INT1_SENSE Configuration option"
	}
#endif

	/*Check Peripheral interrupt enable for INT1_INTIAL_STATE */

#if  INT1_INTIAL_STATE == ENABLED
	{
		SET_BIT(GICR,GICR_INT1);
	}
#elif  INT1_INTIAL_STATE == DISABLED
	{
		CLR_BIT(GICR,GICR_INT1);
	}
#else
	{
#error "Wrong INT1_INTIAL_STATE Configuration option"
	}
#endif
}

/*****************************************     INT2Init    ******************************************/

void EXTI_VoidInt2Init(void)
{
#if INT2_SENSE == FALLING_EDGE
	{
		/* Set Sense Control for INT2 for falling edge*/
		CLR_BIT(MCUCSR,MCUCSR_ISC2);


	}
#elif INT2_SENSE == RISING_EDGE
	{
		/* Set Sense Control for INT2 for RISING_EDGE*/
		SET_BIT(MCUCSR,MCUCSR_ISC2);
	}
#else
	{
#error "Wrong INT2_SENSE Configuration option"
	}
#endif

	/*Check Peripheral interrupt enable for INT2_INTIAL_STATE */

#if  INT2_INTIAL_STATE == ENABLED
	{
		SET_BIT(GICR,GICR_INT2);
	}
#elif  INT2_INTIAL_STATE == DISABLED
	{
		CLR_BIT(GICR,GICR_INT2);
	}
#else
	{
#error "Wrong INT2_INTIAL_STATE Configuration option"
	}
#endif
}

/****************************************************************************************************/
/****************************************************************************************************/
/********************************     Init Function By Post Build Method   **************************/
/****************************************************************************************************/

u8 EXTI_u8IntSetSenseControl(u8 Copy_u8Int,u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8Int == INT0)
	{
		switch(Copy_u8Sense)
		{
		case LOW_LEVEL:    CLR_BIT(MCUCR,MCUCR_ISC00);    CLR_BIT(MCUCR,MCUCR_ISC01);    break;
		case ON_CHANGE:    SET_BIT(MCUCR,MCUCR_ISC00);    CLR_BIT(MCUCR,MCUCR_ISC01);    break;
		case FALLING_EDGE: SET_BIT(MCUCR,MCUCR_ISC01);    CLR_BIT(MCUCR,MCUCR_ISC00);    break;
		case RISING_EDGE:  SET_BIT(MCUCR,MCUCR_ISC01);    SET_BIT(MCUCR,MCUCR_ISC00);    break;
		default:           Local_u8ErrorState = NOK;                                     break;
		}
	}
	else if(Copy_u8Int == INT1)
	{
		switch(Copy_u8Sense)
		{
		case LOW_LEVEL:    CLR_BIT(MCUCR,MCUCR_ISC10);    CLR_BIT(MCUCR,MCUCR_ISC11);    break;
		case ON_CHANGE:    SET_BIT(MCUCR,MCUCR_ISC10);    CLR_BIT(MCUCR,MCUCR_ISC11);    break;
		case FALLING_EDGE: SET_BIT(MCUCR,MCUCR_ISC11);    CLR_BIT(MCUCR,MCUCR_ISC10);    break;
		case RISING_EDGE:  SET_BIT(MCUCR,MCUCR_ISC11);    SET_BIT(MCUCR,MCUCR_ISC10);    break;
		default:           Local_u8ErrorState = NOK;                                     break;
		}
	}
	else if(Copy_u8Int == INT2)
	{
		switch(Copy_u8Sense)
		{
		case FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2);    break;
		case RISING_EDGE:  SET_BIT(MCUCSR,MCUCSR_ISC2);    break;
		default:           Local_u8ErrorState = NOK;                                     break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
/*******************************************  IntEnable   ******************************************/
u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int)
	{
	case INT0:  SET_BIT(GICR,GICR_INT0);  break;
	case INT1:  SET_BIT(GICR,GICR_INT1);  break;
	case INT2:  SET_BIT(GICR,GICR_INT2);  break;
	default:    Local_u8ErrorState = NOK; break;
	}
	return Local_u8ErrorState;
}

/*******************************************  IntDisable   ******************************************/
u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int)
	{
	case INT0:  CLR_BIT(GICR,GICR_INT0);  break;
	case INT1:  CLR_BIT(GICR,GICR_INT1);  break;
	case INT2:  CLR_BIT(GICR,GICR_INT2);  break;
	default:    Local_u8ErrorState = NOK; break;
	}
	return Local_u8ErrorState;
}

/****************************************************************************************************/
/****************************************************************************************************/
/*******************************************Call Back Function **************************************/
/****************************************************************************************************/

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;

	}
	else {

		Local_u8ErrorState = NULL_POINTER;
	}


	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;

	}
	else {

		Local_u8ErrorState = NULL_POINTER;
	}


	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState =OK;
	if(Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else {

		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/****************************************************************************************************/
/****************************************************************************************************/
/*******************************************       ISR         **************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/* ISR of INT0*/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
	if (EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else {
		/* Do nothing*/
	}


}

/* ISR of INT1*/
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
	if (EXTI_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func();
	}
	else {
		/* Do nothing*/
	}


}

/* ISR of INT2*/
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)
{
	if (EXTI_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func();
	}
	else {
		/* Do nothing*/
	}


}


