/*
 * TIMER2_prog.c
 *
 * Created: 2/1/2023 2:18:49 PM
 *  Author: hassa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "TIMER2_interface.h"
#include "TIMER2_config.h"
#include "TIMER2_private.h"

static void(*TIMER2_pvCallBackNotificationFunc)(void) = NULL;
#if TIMER2_MODE == TIMER2_NORMAL_MODE
static u32 NORMAL_u32NoOfOverFlow = 0;
static u8 NORMAL_u8NoOfRemTicks = 0;
#elif TIMER2_MODE == TIMER2_CTC_MODE
static u32 	CTC_u32NoOfCompMatch;
#endif
/**************************** Timer0 Init *****************************/
void TIMER2_voidInit(void)
{
	#if TIMER2_MODE == TIMER2_NORMAL_MODE
	CLR_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

	/* Enable Over flow INT */
	SET_BIT(TIMSK,TIMSK_TOIE2);


	#elif TIMER2_MODE == TIMER2_CTC_MODE
	/* Enable CTC Mode */
	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);
	/* Select OC2 Pin Mode */
	switch (OC2_MODE)
	{
		case OC2_DISCONNECTED:
		CLR_BIT(TCCR2,TCCR2_COM20);
		CLR_BIT(TCCR2,TCCR2_COM21);
		break;
		case OC2_TOGGLE:
		SET_BIT(TCCR2,TCCR2_COM20);
		CLR_BIT(TCCR2,TCCR2_COM21);
		break;
		case OC2_CLEAR:
		CLR_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		break;
		case OC2_SET:
		SET_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		break;
		default:
		break;
	}
	/* Enable CTC INT */
	SET_BIT(TIMSK,TIMSK_OCIE2);

	#endif

}

/**************************** End Timer2 Init *****************************/

/********************** Timer2 Set Time in ms *****************************/
error_state_t TIMER2_enumSetTime_ms(u32 Copy_u32DesiredTime, void(*Copy_pvCallBackFunc)(void))
{
	error_state_t Local_ErrorState = TIMER2_OK;
	TIMER2_pvCallBackNotificationFunc = Copy_pvCallBackFunc;

	#if TIMER2_MODE == TIMER2_NORMAL_MODE || TIMER2_MODE == TIMER2_CTC_MODE

	u32 Local_u32PrescDivFact;
	
	#if  TIMER2_PRESCALLER_SELEC  ==  DIV_BY_1
	Local_u32PrescDivFact  = 1;
	#elif TIMER2_PRESCALLER_SELEC  == DIV_BY_8
	Local_u32PrescDivFact = 8;
	#elif TIMER2_PRESCALLER_SELEC  == DIV_BY_64
	Local_u32PrescDivFact = 64;
	#elif TIMER2_PRESCALLER_SELEC  == DIV_BY_256
	Local_u32PrescDivFact = 256
	#elif TIMER2_PRESCALLER_SELEC  == DIV_BY_1024
	Local_u32PrescDivFact = 1024;
	#endif
	
	u32 Local_u32TickTime = Local_u32PrescDivFact / CRYSTAL_FREQ;    // in Micro Second
	u32 Local_u32TotalTicks = (Copy_u32DesiredTime *1000 ) / Local_u32TickTime;
	#endif
	
	#if TIMER2_MODE == TIMER2_NORMAL_MODE
	NORMAL_u32NoOfOverFlow = Local_u32TotalTicks / TIMER2_MAX;
	NORMAL_u8NoOfRemTicks = Local_u32TotalTicks % TIMER2_MAX;
	if(NORMAL_u8NoOfRemTicks != 0)
	{
		NORMAL_u8NoOfRemTicks = TIMER2_MAX - NORMAL_u8NoOfRemTicks;
		TCNT2 = NORMAL_u8NoOfRemTicks;
		//TCNT0 = TIMER0_MAX - NORMAL_u8NoOfRemTicks;
		NORMAL_u32NoOfOverFlow ++;
	}


	#elif TIMER2_MODE == TIMER2_CTC_MODE
	u8 Local_u8DivisionValue = 255;
	while(Local_u32TotalTicks % Local_u8DivisionValue != 0)
	{
		Local_u8DivisionValue --;
	}
	CTC_u32NoOfCompMatch = Local_u32TotalTicks /Local_u8DivisionValue;
	OCR2 = Local_u8DivisionValue -1;

	#endif
	
	return Local_ErrorState;
}

/********************* End Timer2 Set Time in ms **************************/

/*********************   Timer2 Start   **************************/
error_state_t TIMER2_enumStart(void)
{
	error_state_t Local_ErrorState = TIMER2_OK;
	TCCR2 &= TIMER2_PRESCALLER_MASK;
	TCCR2 |= TIMER2_PRESCALLER_SELEC;
	return Local_ErrorState;
}
/********************* End Timer2 Start **************************/

/*********************   Timer2 Stop   **************************/
error_state_t TIMER2_enumStop(void)
{
	error_state_t Local_ErrorState = TIMER2_OK;
	TCCR2 &= TIMER2_PRESCALLER_MASK;
	return Local_ErrorState;
}
/********************* End Timer0 Stop **************************/

/************************ Counter 0 ****************************/



u8   TIMER2_u8GetTimerValue(void)
{
	return TCNT2;
}
void TIMER2_voidSetTimerValue(u8 Copy_u8TimerValue)
{
	TCNT2 = Copy_u8TimerValue;
}
/******************************************************************************************/
/*************************************** PWM FUNCTION *************************************/
/******************************************************************************************/

error_state_t PWM2_enumInit(void)
{
	error_state_t Local_ErrorState = TIMER2_OK;
	#if TIMER2_MODE == TIMER2_FAST_PWM
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

	if (FAST_PWM_MODE == FAST_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
	}
	else if (FAST_PWM_MODE == FAST_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
	}

	#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM
	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

	if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
	}
	else if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
	}

	#endif

	return Local_ErrorState;
}
error_state_t PWM2_enumSetDutyCycle(u8 Copy_u8DutyCycle)
{
	error_state_t Local_ErrorState = TIMER2_OK;
	#if TIMER2_MODE == TIMER2_FAST_PWM
	if (FAST_PWM_MODE == FAST_PWM_INVERTED_MODE)
	{
		OCR2 = (((100 - Copy_u8DutyCycle) * TIMER2_MAX ) / 100) -  1 ;
	}
	else if (FAST_PWM_MODE == FAST_PWM_NON_INVERTED_MODE)
	{
		OCR2 = ((Copy_u8DutyCycle * TIMER2_MAX ) / 100) -1;
	}

	#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM
	if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_INVERTED_MODE)
	{
		OCR2 = ((( 100 - Copy_u8DutyCycle ) * (TIMER2_MAX - 1 ) ) / 100) ;
	}
	else if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED_MODE)
	{
		OCR2 = ((Copy_u8DutyCycle * (TIMER2_MAX -1 ) ) / 100) ;
	}
	#endif

	return Local_ErrorState;
}
error_state_t PWM2_enumStart(void)
{
	error_state_t Local_ErrorState = TIMER2_OK;
	TCCR2 &= TIMER2_PRESCALLER_MASK;
	TCCR2 |= TIMER2_PRESCALLER_SELEC;

	return Local_ErrorState;
}
error_state_t PWM2_enumStop(void)
{
	error_state_t Local_ErrorState = TIMER2_OK;
	TCCR2 &= TIMER2_PRESCALLER_MASK;
	return Local_ErrorState;
}
/********************************* ISR Timer/Counter0 Overflow  ***********************************/
#if TIMER2_MODE == TIMER2_NORMAL_MODE
ISR_ST(TIMER2_OVF_VECTOR)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter ++;
	if(Local_u32Counter == NORMAL_u32NoOfOverFlow)
	{
		//			DIO_SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);

		TCNT2 = NORMAL_u8NoOfRemTicks;
		TIMER2_pvCallBackNotificationFunc();
		Local_u32Counter = 0;

	}

}
#elif TIMER2_MODE == TIMER2_CTC_MODE
ISR_ST(TIMER2_COMP_VECTOR)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter ++;
	if(Local_u32Counter == CTC_u32NoOfCompMatch)
	{
		TIMER2_pvCallBackNotificationFunc();
		Local_u32Counter = 0;
	}
	
}
#endif
