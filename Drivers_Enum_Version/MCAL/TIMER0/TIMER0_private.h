/*
 * TIMER0_private.h
 *
 * Created: 1/31/2023 1:44:26 AM
 *  Author: Hassan Ehab
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

/********************* TIMER0_MAX ***********************/
#define TIMER0_MAX							     255

/********************* Timer_0_Modes ***********************/
#define TIMER0_NORMAL_MODE                       1
#define TIMER0_CTC_MODE                          2
#define TIMER0_FAST_PWM                          3
#define TIMER0_PHASE_CORRECT_PWM                 4

#define  COUNTER_0_FALLING_EDGE_MODE			 1
#define  COUNTER_0_RISING_EDGE_MODE			     2

/****************************** TIMER0 Prescaler Selection Options *******************************/
#define DIV_BY_1                                 1
#define DIV_BY_8                                 2
#define DIV_BY_64                                3
#define DIV_BY_256                               4
#define DIV_BY_1024                              5
#define COUNTER_FALLING_EDGE                     6
#define COUNTER_RISING_EDGE                      7

/***************** OC0_COMP_MATCH_PIN_MODES **************************/
#define OC0_DISCONNECTED                         0
#define OC0_TOGGLE                               1
#define OC0_CLEAR                                2
#define OC0_SET                                  3

/*********************** FAST_PWM_MODE ******************************/
#define FAST_PWM_INVERTED_MODE                   0
#define FAST_PWM_NON_INVERTED_MODE               1

/********************* PHASE_CORRECT_PWM_MODE ***********************/
#define PHASE_CORRECT_PWM_INVERTED_MODE          0
#define PHASE_CORRECT_PWM_NON_INVERTED_MODE      1

/********************* TIMER0_PRESCALLER_MASK ***********************/
#define TIMER0_PRESCALLER_MASK                   0b11111000


/***********************************************************************/
/*************************** Timer 0 Registers *************************/
/***********************************************************************/

/*****************************  Timer/Counter Control Register ( TCCR0 )  ********************************/
#define TCCR0                *((volatile u8*)0x53)
#define TCCR0_FOC0           7
#define TCCR0_WGM00          6
#define TCCR0_COM01          5
#define TCCR0_COM00          4
#define TCCR0_WGM01          3
#define TCCR0_CS02           2
#define TCCR0_CS01           1
#define TCCR0_CS00           0

/******************************* Timer/Counter Register ( TCNT0 )    *************************************/
#define TCNT0                *((volatile u8*)0x52)

/********************************  Output Compare Register ( OCR0 ) **************************************/
#define OCR0                 *((volatile u8*)0x5C)

/**************************  Timer/Counter Interrupt Mask Register ( TIMSK ) *****************************/
#define TIMSK                *((volatile u8*)0x59)
#define TIMSK_OCIE0          1
#define TIMSK_TOIE0          0

/**************************  Timer/Counter Interrupt Flag Register ( TIFR ) *****************************/
#define TIFR                 *((volatile u8*)0x58)

/*************** ISR Interrupt Vectors Number ******************/
#define	TIMER0_COMP_VECTOR		__vector_10
#define	TIMER0_OVF_VECTOR		__vector_11

/************ ISR Attribute ***************/
#define ISR_ST(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)




#endif /* TIMER0_PRIVATE_H_ */