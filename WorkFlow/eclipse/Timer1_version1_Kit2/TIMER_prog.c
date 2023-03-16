/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TIMER       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void)
{
	/* Choose fast pwm mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

//	/* output compare match interrupt enable */
//	SET_BIT(TIMSK,TIMSK_OCIE0);
//
//	/*Set compare match value to 250*/
//	OCR0 = 125;

	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	/*prescaller : Division by 64*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

}

void TIMER0_SetComMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus = OK;
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
	/* Setting Fast PWM Non-Inverting Mode*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	/*Setting Fast PWM Wave form Generation Mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	/* Setting prescaller */
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= DIVIDE_BY_8;


}
void TIMER1_voidSetICR(u16 Copt_u16TOP)
{
	ICR1 = Copt_u16TOP;

}

void TIMER1_SetChannelAComMatchValue(u16 Copy_u16CompareMatch)
{
	OCR1A = Copy_u16CompareMatch;

}


/*****************************************************************************/

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
















