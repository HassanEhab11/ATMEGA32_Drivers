/*
 * TIMER0_config.h
 *
 * Created: 1/31/2023 1:44:07 AM
 *  Author: hassa
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/************** CRYSTAL_FREQ *************************/
#define CRYSTAL_FREQ         16        // in MHZ
/*********** COUNTER 0 ************/
/*COUNTER_0_MODES:
 *					1) COUNTER_0_FALLING_EDGE_MODE
 *					2) COUNTER_0_RISING_EDGE_MODE
 */
#define COUNTER_0_MODE	COUNTER_0_FALLING_EDGE_MODE

/*TIMER_0_MODES:
 * 1) TIMER0_NORMAL_MODE
 * 2) TIMER0_CTC_MODE
 * 3) TIMER0_FAST_PWM
 * 4) TIMER0_PHASE_CORRECT_PWM
 *
 * */
#define TIMER0_MODE  TIMER0_NORMAL_MODE

/*OC0_COMP_MATCH_PIN_MODES:
 * 1) OC0_DISCONNECTED
 * 2) OC0_TOGGLE
 * 3) OC0_CLEAR
 * 4) OC0_SET
 * */
#define OC0_MODE       OC0_CLEAR

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






#endif /* TIMER0_CONFIG_H_ */