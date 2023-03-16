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

void TIMER0_voidInit(void);

void TIMER1_voidInit(void);
void TIMER1_voidSetICR(u16 Copt_u16TOP);

void TIMER1_SetChannelAComMatchValue(u16 Copy_u16CompareMatch);


u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

void TIMER0_SetComMatchValue(u8 Copy_u8Value);



#endif
