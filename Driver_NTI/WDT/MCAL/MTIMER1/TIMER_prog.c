/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TIMER       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

#include "../MTIMER1/TIMER_config.h"
#include "../MTIMER1/TIMER_interface.h"
#include "../MTIMER1/TIMER_private.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;
static void (*ICU_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void)
{
	/* Choose fast pwm mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	//	/* output compare match interrupt enable */
	//	SET_BIT(TIMSK,TIMSK_OCIE0);
	//
	/*Set compare match value to 250*/
	OCR0 = 64;

	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	/*prescaller : Division by 64*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

}

void TIMER0_SetComMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus = R_OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;

	}


	return Local_u8ErrorStatus;

}
/******************************************************************************/
void TIMER1_voidInit(void)
{
	//	/* Setting Fast PWM Non-Inverting Mode*/
	//	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	//	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	//	/*Setting Fast PWM Wave form Generation Mode*/
	//	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	//	SET_BIT(TCCR1A,TCCR1A_WGM11);
	//	SET_BIT(TCCR1B,TCCR1B_WGM12);
	//	SET_BIT(TCCR1B,TCCR1B_WGM13);
	/* Setting prescaller */
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= 3;


}

void TIMER1_voidSTOP(void)
{
	TCCR1B &= PRESCALER_MASK;

}

void TIMER1_VoidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

u16 Timer1_u16ReadTimerValue(void)
{
	return TCNT1;
}
void TIMER1_voidSetICR(u16 Copt_u16TOP)
{
	ICR1 = Copt_u16TOP;

}

void TIMER1_SetChannelAComMatchValue(u16 Copy_u16CompareMatch)
{
	OCR1A = Copy_u16CompareMatch;

}


void ICU_voidInit(void)
{
	/* Set trigger source to rising edge initially */
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/* Enable Input Capture interrupt */
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorState = R_OK;

	if (Copy_u8Edge == ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if (Copy_u8Edge == ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		Local_u8ErrorState = R_NOK;
	}
	return Local_u8ErrorState;
}

void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

u16 ICU_u16ReadInputCapture(void)
{
	return ICR1;
}

u8 ICU_u8GetInputCaptureFlag (void)
{
	return 	GET_BIT(TIFR, TIFR_ICF1);

}
void ICU_u8ClearInputCaptureFlag (void)
{
	SET_BIT(TIFR, TIFR_ICF1);
}

void ICU_voidNoiseCanceler(void)
{
	SET_BIT(TCCR1B, TCCR1B_ICNC1);
}

u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = R_OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}



/********************************* ISR ***********************************/

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
/********************** ICU_ISR  *****************************************/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc();
	}
}












