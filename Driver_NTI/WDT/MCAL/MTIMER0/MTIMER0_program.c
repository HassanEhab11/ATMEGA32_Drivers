/*
 * TIMER0_prog.c
 *
 * Created: 1/31/2023 1:44:41 AM
 *  Author: Hassan Ehab
 */ 

/******************************* STD LIB DIRECTIVES ****************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

#include "../MTIMER0/MTIMER0_config.h"
#include "../MTIMER0/MTIMER0_interface.h"
#include "../MTIMER0/MTIMER0_private.h"

static u16 TIMER0_PRESCALLER_ARR[5] = {1, 8, 64, 256, 1024};
static void(*TIMER0_pvCallBackNotificationFunc)(void) = NULL;
static u32 current_ov_count ;

#if TIMER0_MODE == TIMER0_NORMAL_MODE
static u32 NORMAL_u32NoOfOverFlow = 0;
static u8 NORMAL_u8NoOfRemTicks = 0;
#elif TIMER0_MODE == TIMER0_CTC_MODE
static u32 	CTC_u32NoOfCompMatch;
#endif
/**************************** Timer0 Init *****************************/
void MTIMER0_voidInit(void)
{
	#if TIMER0_MODE == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/* Enable Over flow INT */
	SET_BIT(TIMSK,TIMSK_TOIE0);


	#elif TIMER0_MODE == TIMER0_CTC_MODE
	/* Enable CTC Mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/* Select OC0 Pin Mode */
	switch (OC0_MODE)
	{
		case OC0_DISCONNECTED:
		CLR_BIT(TCCR0,TCCR0_COM00);
		CLR_BIT(TCCR0,TCCR0_COM01);
		break;
		case OC0_TOGGLE:
		SET_BIT(TCCR0,TCCR0_COM00);
		CLR_BIT(TCCR0,TCCR0_COM01);
		break;
		case OC0_CLEAR:
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
		case OC0_SET:
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
		default:
		break;
	}
	/* Enable CTC INT */
	SET_BIT(TIMSK,TIMSK_OCIE0);

	#endif

}

/**************************** End Timer0 Init *****************************/

/********************** Timer0 Set Time in ms *****************************/
error_state_t MTIMER0_enumSetTime_ms(u32 Copy_u32DesiredTime, void(*Copy_pvCallBackFunc)(void))
{
	error_state_t Local_ErrorState = TIMER0_OK;

	//initialize callback function globally
	TIMER0_pvCallBackNotificationFunc = Copy_pvCallBackFunc;
	/* Get prescaller value */
	f32 Local_u32PrescDivFact = (f32)TIMER0_PRESCALLER_ARR[TIMER0_PRESCALLER_SELEC - 1];
	// calculate total tick time in Micro Second
	f32 Local_u32TickTime = Local_u32PrescDivFact / CRYSTAL_FREQ;
	// Calculate total tick number
	u32 Local_u32TotalTicks = (Copy_u32DesiredTime *1000 ) / Local_u32TickTime;
	
	#if TIMER0_MODE == TIMER0_NORMAL_MODE
	NORMAL_u32NoOfOverFlow = Local_u32TotalTicks / TIMER0_MAX_TICK;
	NORMAL_u8NoOfRemTicks = Local_u32TotalTicks % TIMER0_MAX_TICK;
	if(NORMAL_u8NoOfRemTicks != 0)
	{
		NORMAL_u8NoOfRemTicks = TIMER0_MAX_TICK - NORMAL_u8NoOfRemTicks;
		TCNT0 = NORMAL_u8NoOfRemTicks;
		//TCNT0 = TIMER0_MAX_TICK - NORMAL_u8NoOfRemTicks;
		NORMAL_u32NoOfOverFlow ++;
	}


	#elif TIMER0_MODE == TIMER0_CTC_MODE
	u8 Local_u8DivisionValue = 256;
	while(Local_u32TotalTicks % Local_u8DivisionValue != 0)
	{
		Local_u8DivisionValue --;
	}
	CTC_u32NoOfCompMatch = Local_u32TotalTicks /Local_u8DivisionValue;
	OCR0 = Local_u8DivisionValue ;

	#endif
	
	return Local_ErrorState;
}

/********************* End Timer0 Set Time in ms **************************/

/*********************   Timer0 Start   **************************/
error_state_t MTIMER0_enumStart(void)
{
	error_state_t Local_ErrorState = TIMER0_OK;
	TCCR0 &= TIMER0_PRESCALLER_MASK;
	TCCR0 |= TIMER0_PRESCALLER_SELEC;
	return Local_ErrorState;
}
/********************* End Timer0 Start **************************/

/*********************   Timer0 Stop   **************************/
error_state_t MTIMER0_enumStop(void)
{
	error_state_t Local_ErrorState = TIMER0_OK;
	TCCR0 &= TIMER0_PRESCALLER_MASK;
	return Local_ErrorState;
}
/********************* End Timer0 Stop **************************/

/************************ Counter 0 ****************************/
void MCOUNTER0_voidCounterInit(void)
{
	#if   COUNTER_0_MODE == COUNTER_0_FALLING_EDGE_MODE
		TCCR0 &= TIMER0_PRESCALLER_MASK;
		TCCR0 |= COUNTER_FALLING_EDGE;						
	#elif COUNTER_0_MODE == COUNTER_0_RISING_EDGE_MODE
		TCCR0 &= TIMER0_PRESCALLER_MASK;
		TCCR0 |= COUNTER_RISING_EDGE;
	#endif
}

u8 MCOUNTER0_u8GetCounterValue(void){

	return TCNT0;
}


u8   MTIMER0_u8GetTimerValue(void)
{
	return TCNT0;
}
void MTIMER0_voidSetTimerValue(u8 Copy_u8TimerValue)
{
	TCNT0 = Copy_u8TimerValue;
}

u32 MTIMER0_u32GetCounts(void)
{
	TCNT0 =0;
	u32 count = TCNT0 + current_ov_count*256;
	return count;

}

void MTimer0_voidEnableInt(u8 INT_ID)
{
	switch(INT_ID)
	{
	case INT_OV_MODE:
		SET_BIT(TIMSK, TIMSK_TOIE0);

		break;
	case INT_COMP_MODE:
		SET_BIT(TIMSK, TIMSK_OCIE0);
		break;

	}
}


void MTimer0_voidDisableInt(u8 INT_ID)
{
	switch(INT_ID)
	{
	case INT_OV_MODE:
		CLR_BIT(TIMSK, TIMSK_TOIE0);

		break;
	case INT_COMP_MODE:
		CLR_BIT(TIMSK, TIMSK_OCIE0);
		break;

	}
}

/******************************************************************************************/
/*************************************** PWM FUNCTION *************************************/
/******************************************************************************************/

error_state_t MPWM0_enumInit(void)
{
	error_state_t Local_ErrorState = TIMER0_OK;
	#if TIMER0_MODE == TIMER0_FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	switch (OC0_MODE)
		{
			case OC0_DISCONNECTED:
			CLR_BIT(TCCR0,TCCR0_COM00);
			CLR_BIT(TCCR0,TCCR0_COM01);
			break;
			case OC0_TOGGLE:
			SET_BIT(TCCR0,TCCR0_COM00);
			CLR_BIT(TCCR0,TCCR0_COM01);
			break;
			case OC0_CLEAR:
			CLR_BIT(TCCR0,TCCR0_COM00);
			SET_BIT(TCCR0,TCCR0_COM01);
			break;
			case OC0_SET:
			SET_BIT(TCCR0,TCCR0_COM00);
			SET_BIT(TCCR0,TCCR0_COM01);
			break;
			default:
			break;
		}

	if (FAST_PWM_MODE == FAST_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
	}
	else if (FAST_PWM_MODE == FAST_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
	}

	#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
	}
	else if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
	}

	#endif

	return Local_ErrorState;
}
error_state_t MPWM0_enumSetDutyCycle(u8 Copy_u8DutyCycle)
{
	error_state_t Local_ErrorState = TIMER0_OK;
	#if TIMER0_MODE == TIMER0_FAST_PWM
	if (FAST_PWM_MODE == FAST_PWM_INVERTED_MODE)
	{
		OCR0 = (((100 - Copy_u8DutyCycle) * TIMER0_MAX_TICK ) / 100) -  1 ;
	}
	else if (FAST_PWM_MODE == FAST_PWM_NON_INVERTED_MODE)
	{
		OCR0 = (u8)(((Copy_u8DutyCycle * TIMER0_MAX_TICK ) / 100) -1);
	}

	#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
	if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_INVERTED_MODE)
	{
		OCR0 = ((( 100 -Copy_u8DutyCycle ) * (TIMER0_MAX_TICK -1 ) ) / 100) ;
	}
	else if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED_MODE)
	{
		OCR0 = ((Copy_u8DutyCycle * (TIMER0_MAX_TICK -1 ) ) / 100) ;
	}
	#endif

	return Local_ErrorState;
}
error_state_t MPWM0_enumStart(void)
{
	error_state_t Local_ErrorState = TIMER0_OK;
	TCCR0 &= TIMER0_PRESCALLER_MASK;
	TCCR0 |= TIMER0_PRESCALLER_SELEC;

	return Local_ErrorState;
}
error_state_t MPWM0_enumStop(void)
{
	error_state_t Local_ErrorState = TIMER0_OK;
	TCCR0 &= TIMER0_PRESCALLER_MASK;
	return Local_ErrorState;
}
/********************************* ISR Timer/Counter0 Overflow  ***********************************/
#if TIMER0_MODE == TIMER0_NORMAL_MODE
ISR_ST(TIMER0_OVF_VECTOR)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter ++;
	current_ov_count = Local_u32Counter;
	if(Local_u32Counter == NORMAL_u32NoOfOverFlow)
	{
					//			DIO_SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);  //for Debugging

		TCNT0 = NORMAL_u8NoOfRemTicks;
		TIMER0_pvCallBackNotificationFunc();
		Local_u32Counter = 0;

	}

}
#elif TIMER0_MODE == TIMER0_CTC_MODE
ISR_ST(TIMER0_COMP_VECTOR)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter ++;
	if(Local_u32Counter == CTC_u32NoOfCompMatch)
	{
		TIMER0_pvCallBackNotificationFunc[1]();
		Local_u32Counter = 0;
	}
	
}
#endif
