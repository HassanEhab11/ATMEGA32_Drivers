/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): EXTI (Config)*********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_INTERFACE_H_


/* OPTIONS :
 * For INT0 and INT1:
 * 1- LOW_LEVEL
 * 2- ON_CHANGE
 * 3- FALLING_EDGE
 * 4- RISING_EDGE
 *
 * For INT2:
 * 1- FALLING_EDGE
 * 2- RISING_EDGE
 * */
#define INT0_SENSE   FALLING_EDGE
#define INT1_SENSE   FALLING_EDGE
#define INT2_SENSE   RISING_EDGE

/* OPTIONS :
 * 1- ENABLED
 * 2- DISABLED
 * */
#define INT0_INTIAL_STATE    ENABLED
#define INT1_INTIAL_STATE    ENABLED
#define INT2_INTIAL_STATE    ENABLED


#endif
