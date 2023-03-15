/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab    ******************/
/******************    Layer      : MCAL           ******************/
/******************    SWC(Driver): TIMER          ******************/
/******************    Version    : 1.00           ******************/
/******************    DATE       : 13/10/2022     ******************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H


#define OC0_DISCONNECTED                         0
#define OC0_TOGGLE                               1
#define OC0_CLEAR                                2
#define OC0_SET                                  3

#define FAST_PWM_INVERTED_MODE                   0
#define FAST_PWM_NON_INVERTED_MODE               1

#define PHASE_CORRECT_PWM_INVERTED_MODE          0
#define PHASE_CORRECT_PWM_NON_INVERTED_MODE      1


#define TIMER0_PRESCALLER_MASK                   0b11111000

#define TIMER0_MAX               256



#endif
