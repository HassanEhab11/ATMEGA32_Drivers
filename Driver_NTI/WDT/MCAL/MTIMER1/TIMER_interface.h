/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TIMER       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_RISING_EDGE      1
#define ICU_FALLING_EDGE     0




void TIMER0_voidInit(void);

void TIMER1_voidInit(void);
void TIMER1_voidSTOP(void);
void TIMER1_voidSetICR(u16 Copt_u16TOP);

void TIMER1_SetChannelAComMatchValue(u16 Copy_u16CompareMatch);


u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

void TIMER0_SetComMatchValue(u8 Copy_u8Value);

void TIMER1_VoidSetTimerValue(u16 Copy_u16Value);
u16 Timer1_u16ReadTimerValue(void);

void ICU_voidInit(void);
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge);
void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
u16 ICU_u16ReadInputCapture(void);
u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

u8 ICU_u8GetInputCaptureFlag (void);
void ICU_u8ClearInputCaptureFlag (void);

void ICU_voidNoiseCanceler(void);
#endif
