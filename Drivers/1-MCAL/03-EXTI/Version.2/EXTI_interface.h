/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): EXTI        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL           1
#define ON_CHANGE           2
#define FALLING_EDGE        3
#define RISING_EDGE         4

#define INT0       1
#define INT1       2
#define INT2       3

/*
 *  PreBuild Configuration
 * */
void EXTI_VoidInt0Init(void);

void EXTI_VoidInt1Init(void);

void EXTI_VoidInt2Init(void);

/* Description: A function to set the required sense control of INT0 using postBuild configuration
 * Input: Copy_u8Sense ,options are:
 *                                   1- LOW_LEVEL
 *                                   2- ON_CHANGE
 *                                   3- FALLING_EDGE
 *                                   4- RISING_EDGE
 *
 *   output or return : Error Status with type u8
 * */
u8 EXTI_u8IntSetSenseControl(u8 Copy_u8Int,u8 Copy_u8Sense);


u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void));
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void));


#endif
