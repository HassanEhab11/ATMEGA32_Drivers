/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TIMER       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/
#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

/********************* TIMER1_MAX ***********************/
#define TIMER1_MAX_TICK                       65535
/********************* TIMER1_PRESCALLER_MASK ***********************/
#define TIMER1_PRESCALLER_MASK                   0b11111000

/********************* TIMER1_PRESCALLER_VALUE ***********************/

#define NO_PRESCALER		1
#define PRESCALER_8			8
#define PRESCALER_64		64
#define PRESCALER_256		256
#define PRESCALER_1024		1024

/********************* Timer_1_Modes ***********************/
#define TIMER1_NORMAL_MODE                    1
#define TIMER1_CTC_MODE                       2
#define TIMER1_FAST_PWM_MODE                  3
#define TIMER1_PHASE_CORRECT_PWM_MODE         4

/****************************** TIMER1 Prescaler Selection Options *******************************/
#define TIMER1_NO_PRESCALER                   1
#define TIMER1_DIVIDE_BY_8                    2
#define TIMER1_DIVIDE_BY_64                   3
#define TIMER1_DIVIDE_BY_256                  4
#define TIMER1_DIVIDE_BY_1024                 5

/********************* Output Compare Pin Modes (OC1A and OC1B) ***********************/
#define OC1A_DISCONNECTED                     0
#define OC1A_TOGGLE                           1
#define OC1A_CLEAR                            2
#define OC1A_SET                              3

#define OC1B_DISCONNECTED                     0
#define OC1B_TOGGLE                           1
#define OC1B_CLEAR                            2
#define OC1B_SET                              3

/*************************** COUNTER EDGE MODE ***************************/

#define COUNTER1_RISING_EDGE_MODE    0x10  // Rising edge
#define COUNTER1_FALLING_EDGE_MODE   0x08  // Falling edge
/*************************** Timer 1 Registers ***************************/
/******************* Inout Capture Register 1 Low (TCCR1A) *******************/
#define ICR1     *((volatile u16 *) 0x46)

/******************* Timer/Counter Control Register A (TCCR1A) *******************/
#define TCCR1A                *((volatile u8*)0x4F)
#define TCCR1A_COM1A1         7
#define TCCR1A_COM1A0         6
#define TCCR1A_COM1B1         5
#define TCCR1A_COM1B0         4
#define TCCR1A_FOC1A          3
#define TCCR1A_FOC1B          2
#define TCCR1A_WGM11          1
#define TCCR1A_WGM10          0

/******************* Timer/Counter Control Register B (TCCR1B) *******************/
#define TCCR1B                *((volatile u8*)0x4E)
#define TCCR1B_ICNC1          7
#define TCCR1B_ICES1          6
#define TCCR1B_WGM13          4
#define TCCR1B_WGM12          3
#define TCCR1B_CS12           2
#define TCCR1B_CS11           1
#define TCCR1B_CS10           0

/******************* Timer/Counter Register (TCNT1) *******************/
#define TCNT1                 *((volatile u16*)0x4C)

/******************* Output Compare Register A (OCR1A) *******************/
#define OCR1A                 *((volatile u16*)0x4A)

/******************* Output Compare Register B (OCR1B) *******************/
#define OCR1B                 *((volatile u16*)0x48)

/******************* Timer/Counter Interrupt Mask Register (TIMSK) *******************/
#define TIMSK                 *((volatile u8*)0x59)
#define TIMSK_TICIE1          5
#define TIMSK_OCIE1A          4
#define TIMSK_OCIE1B          3
#define TIMSK_TOIE1           2

/******************* Timer/Counter Interrupt Flag Register (TIFR) *******************/
#define TIFR                  *((volatile u8*)0x58)
#define TIFR_ICF1             5
#define TIFR_OCF1A            4
#define TIFR_OCF1B            3
#define TIFR_TOV1             2

/************ ISR Interrupt Vectors Number ***************/
#define TIMER1_CAPT_VECTOR     __vector_6
#define TIMER1_COMPA_VECTOR    __vector_7
#define TIMER1_COMPB_VECTOR    __vector_8
#define TIMER1_OVF_VECTOR      __vector_9

/************ ISR Attribute ***************/
#define ISR_ST(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)

#endif /* TIMER1_PRIVATE_H_ */
