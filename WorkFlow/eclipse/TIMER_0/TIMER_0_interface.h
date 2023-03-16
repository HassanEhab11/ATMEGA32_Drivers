/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab    ******************/
/******************    Layer      : MCAL           ******************/
/******************    SWC(Driver): TIMER          ******************/
/******************    Version    : 1.00           ******************/
/******************    DATE       : 13/10/2022     ******************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER_0_INTERFACE_H_
#define TIMER_0_INTERFACE_H_

/********************* Timer_0_Modes ***********************/
#define TIMER0_NORMAL_MODE             1
#define TIMER0_CTC_MODE                2
#define TIMER0_FAST_PWM                3
#define TIMER0_PHASE_CORRECT_PWM       4

/****************************** TIMER0 Prescaler Selection Options *******************************/
#define DIV_BY_1                   1
#define DIV_BY_8                   2
#define DIV_BY_64                  3
#define DIV_BY_256                 4
#define DIV_BY_1024                5









void TIMER0_voidInit(void);
void TIMER0_voidSetTime_ms(u32 Copy_u32DesiredTime);
void TIMER0_voidStart(void);
void TIMER0_voidStop(void);
u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

void PWM0_voidInit(void);
void PWM0_voidSetDutyCycle(u8 Copy_u8DutyCycle);
void PWM0_voidStart(void);
void PWM0_voidStop(void);


#endif
