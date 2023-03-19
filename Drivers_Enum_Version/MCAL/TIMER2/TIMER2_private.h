/*
 * TIMER2_private.h
 *
 * Created: 2/1/2023 2:19:18 PM
 *  Author: hassa
 */ 


#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

/********************* TIMER2_MAX ***********************/
#define TIMER2_MAX							     256

/********************* Timer_2_Modes ***********************/
#define TIMER2_NORMAL_MODE                       1
#define TIMER2_CTC_MODE                          2
#define TIMER2_FAST_PWM                          3
#define TIMER2_PHASE_CORRECT_PWM                 4

#define  COUNTER_2_FALLING_EDGE_MODE			 1
#define  COUNTER_2_RISING_EDGE_MODE			     2

/****************************** TIMER0 Prescaler Selection Options *******************************/
#define DIV_BY_1                                 1
#define DIV_BY_8                                 2
#define DIV_BY_32                                3
#define DIV_BY_64                                4
#define DIV_BY_128                               5
#define DIV_BY_256                               6
#define DIV_BY_1024                              7


/***************** OC0_COMP_MATCH_PIN_MODES **************************/
#define OC2_DISCONNECTED                         0
#define OC2_TOGGLE                               1
#define OC2_CLEAR                                2
#define OC2_SET                                  3

/*********************** FAST_PWM_MODE ******************************/
#define FAST_PWM_INVERTED_MODE                   0
#define FAST_PWM_NON_INVERTED_MODE               1

/********************* PHASE_CORRECT_PWM_MODE ***********************/
#define PHASE_CORRECT_PWM_INVERTED_MODE          0
#define PHASE_CORRECT_PWM_NON_INVERTED_MODE      1

/********************* TIMER0_PRESCALLER_MASK ***********************/
#define TIMER2_PRESCALLER_MASK                   0b11111000


/***********************************************************************/
/*************************** Timer 2 Registers *************************/
/***********************************************************************/

/*****************************  Timer/Counter Control Register ( TCCR2 )  ********************************/
#define TCCR2                *((volatile u8*)0x45)
#define TCCR2_FOC2           7
#define TCCR2_WGM20          6
#define TCCR2_COM21          5
#define TCCR2_COM20          4
#define TCCR2_WGM21          3
#define TCCR2_CS22           2
#define TCCR2_CS21           1
#define TCCR2_CS20           0

/******************************* Timer/Counter Register ( TCNT2 )    *************************************/
#define TCNT2                *((volatile u8*)0x44)

/********************************  Output Compare Register ( OCR0 ) **************************************/
#define OCR2                 *((volatile u8*)0x43)

/**************************  Timer/Counter Interrupt Mask Register ( TIMSK ) *****************************/
#define TIMSK                *((volatile u8*)0x59)
#define TIMSK_OCIE2          7
#define TIMSK_TOIE2          6

/**************************  Timer/Counter Interrupt Flag Register ( TIFR ) *****************************/
#define TIFR                 *((volatile u8*)0x58)

/*************** ISR Interrupt Vectors Number ******************/
#define	TIMER2_COMP_VECTOR		__vector_4
#define	TIMER2_OVF_VECTOR		__vector_5
/************ ISR Attribute ***************/
#define ISR_ST(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)



#endif /* TIMER2_PRIVATE_H_ */