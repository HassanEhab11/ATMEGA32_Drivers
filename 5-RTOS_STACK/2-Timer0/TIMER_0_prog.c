/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab    ******************/
/******************    Layer      : RTOS STACK     ******************/
/******************    SWC(Driver): TIMER          ******************/
/******************    Version    : 1.00           ******************/
/******************    DATE       : 14/11/2022     ******************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "TIMER_0_interface.h"
#include "TIMER_0_config.h"
#include "TIMER_0_private.h"
#include "TIMER_0_register.h"


static void(*TIMER0_pvCallBackNotificationFunc)(void) = NULL;
#if TIMER0_MODE == TIMER0_NORMAL_MODE
static u32 NORMAL_u32NoOfOverFlow;
static u8 NORMAL_u8NoOfRemTicks;
#elif TIMER0_MODE == TIMER0_CTC_MODE
static u32 	CTC_u32NoOfCompMatch;
#endif

void TIMER0_voidInit(void)
{
#if TIMER0_MODE == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	/* Normal port operation, OC0 disconnected */
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	/* Enable Over flow INT */
	SET_BIT(TIMSK,TIMSK_TOIE0);


#elif TIMER0_MODE == TIMER0_CTC_MODE
	/* Enable CTC Mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
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
	/* Enable CTC INT */
	SET_BIT(TIMSK,TIMSK_OCIE0);


#endif


}
void TIMER0_voidSetTime_ms(u32 Copy_u32DesiredTime)
{

#if TIMER0_MODE == TIMER0_NORMAL_MODE || TIMER0_MODE == TIMER0_CTC_MODE
	u32 Local_u32PrescDivFact;
#if  TIMER0_PRESCALLER_SELEC  ==  DIV_BY_1
	Local_u32PrescDivFact  = 1;
#elif TIMER0_PRESCALLER_SELEC  == DIV_BY_8
	Local_u32PrescDivFact = 8;
#elif TIMER0_PRESCALLER_SELEC  == DIV_BY_64
	Local_u32PrescDivFact = 64;
#elif TIMER0_PRESCALLER_SELEC  == DIV_BY_256
	Local_u32PrescDivFact = 256
#elif TIMER0_PRESCALLER_SELEC  == DIV_BY_1024
			Local_u32PrescDivFact = 1024;

#endif

	u32 Local_u32TickTime = Local_u32PrescDivFact / CRYSTAL_FREQ;    // in Micro Second
	u32 Local_u32TotalTicks = (Copy_u32DesiredTimeOrDutyCycle *1000 ) / Local_u32TickTime;
#endif

#if TIMER0_MODE == TIMER0_NORMAL_MODE
	NORMAL_u32NoOfOverFlow = Local_u32TotalTicks / TIMER0_MAX;
	NORMAL_u8NoOfRemTicks = Local_u32TotalTicks % TIMER0_MAX;
	if(NORMAL_u8NoOfRemTicks != 0)
	{
		NORMAL_u8NoOfRemTicks = TIMER0_MAX - NORMAL_u8NoOfRemTicks;
		TCNT0 = NORMAL_u8NoOfRemTicks;
		//TCNT0 = TIMER0_MAX - NORMAL_u8NoOfRemTicks;
		NORMAL_u32NoOfOverFlow ++;
	}


#elif TIMER0_MODE == TIMER0_CTC_MODE
	u8 Local_u8DivisionValue = 255;
	while(Local_u32TotalTicks % Local_u8DivisionValue != 0)
	{
		Local_u8DivisionValue --;
	}
	CTC_u32NoOfCompMatch = Local_u32TotalTicks /Local_u8DivisionValue;
	OCR0 = Local_u8DivisionValue -1;


#endif


}
void TIMER0_voidStart(void)
{
	TCCR0 &= TIMER0_PRESCALLER_MASK;
	TCCR0 |= TIMER0_PRESCALLER_SELEC;

}
void TIMER0_voidStop(void)
{
	TCCR0 &= TIMER0_PRESCALLER_MASK;

}
u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if( Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackNotificationFunc = Copy_pvCallBackFunc;

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;

	}
	return Local_u8ErrorState;
}

/*************************************** PWM FUNCTION *************************************/
void PWM0_voidInit(void)
{
#if TIMER0_MODE == TIMER0_FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

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
}
void PWM0_voidSetDutyCycle(u8 Copy_u8DutyCycle)
{
#if TIMER0_MODE == TIMER0_FAST_PWM
	if (FAST_PWM_MODE == FAST_PWM_INVERTED_MODE)
	{
		OCR0 = (((100 - Copy_u8DutyCycle) * TIMER0_MAX ) / 100) -  1 ;
	}
	else if (FAST_PWM_MODE == FAST_PWM_NON_INVERTED_MODE)
	{
		OCR0 = ((Copy_u8DutyCycle * TIMER0_MAX ) / 100) -1;
	}

#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
	if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_INVERTED_MODE)
	{
		OCR0 = ((( 100 -Copy_u8DutyCycle ) * (TIMER0_MAX -1 ) ) / 100) ;
	}
	else if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED_MODE)
	{
		OCR0 = ((Copy_u8DutyCycle * (TIMER0_MAX -1 ) ) / 100) ;
	}
#endif

}
void PWM0_voidStart(void)
{
	TCCR0 &= TIMER0_PRESCALLER_MASK;
	TCCR0 |= TIMER0_PRESCALLER_SELEC;
}

void PWM0_voidStop(void)
{
	TCCR0 &= TIMER0_PRESCALLER_MASK;
}


/********************************* ISR Timer/Counter0 Overflow  ***********************************/
#if TIMER0_MODE == TIMER0_NORMAL_MODE
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{

	static u32 Local_u32Counter = 0;
	Local_u32Counter ++;
	if(Local_u32Counter == NORMAL_u32NoOfOverFlow)
	{
		//DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);

		TCNT0 = NORMAL_u8NoOfRemTicks;
		TIMER0_pvCallBackNotificationFunc();
		Local_u32Counter =0;
	}

}
#elif TIMER0_MODE == TIMER0_CTC_MODE
/********************** ISR Timer/Counter0 Overflow  *****************************************/

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter ++;
	if(Local_u32Counter == CTC_u32NoOfCompMatch)
	{
		TIMER0_pvCallBackNotificationFunc();
		Local_u32Counter = 0;
	}

}

#endif










