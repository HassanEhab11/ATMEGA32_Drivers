/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab    ******************/
/******************    Layer      : RTOS STACK     ******************/
/******************    SWC(Driver): TIMER          ******************/
/******************    Version    : 1.00           ******************/
/******************    DATE       : 14/11/2022     ******************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER_0_CONFIG_H
#define TIMER_0_CONFIG_H


/*TIMER_0_MODES:
 * 1) TIMER0_NORMAL_MODE
 * 2) TIMER0_CTC_MODE
 * 3) TIMER0_FAST_PWM
 * 4) TIMER0_PHASE_CORRECT_PWM
 *
 * */
#define TIMER0_MODE  TIMER0_CTC_MODE

/*OC0_COMP_MATCH_PIN_MODES:
 * 1) OC0_DISCONNECTED
 * 2) OC0_TOGGLE
 * 3) OC0_CLEAR
 * 4) OC0_SET
 * */
#define OC0_MODE       OC0_DISCONNECTED

/*FAST_PWM_MODE:
 * 1) FAST_PWM_INVERTED_MODE
 * 2) FAST_PWM_NON_INVERTED_MODE
 *
 * */
#define FAST_PWM_MODE    FAST_PWM_NON_INVERTED_MODE

/*PHASE_CORRECT_PWM_MODE:
 * 1) PHASE_CORRECT_PWM_INVERTED_MODE
 * 2) PHASE_CORRECT_PWM_NON_INVERTED_MODE
 *
 * */
#define PHASE_CORRECT_PWM_MODE    PHASE_CORRECT_PWM_NON_INVERTED_MODE

/*
 * 1) DIV_BY_1
 * 2) DIV_BY_8
 * 3) DIV_BY_64
 * 4) DIV_BY_256
 * 5) DIV_BY_1024
 *
 * */
#define TIMER0_PRESCALLER_SELEC        DIV_BY_64

/************** CRYSTAL_FREQ *************************/
#define CRYSTAL_FREQ         8        // in MHZ

#endif
