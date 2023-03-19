/*
 * TIMER1_private.h
 *
 * Created: 2/5/2023 1:37:20 PM
 *  Author: hassa
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

/*************** TIMER1 maximum count they could reach *******************/
#define TIMER1_MAX_COUNT    65535

/************ TIMER1 Registers Addresses Definition  ********************/

#define TIMSK     *((volatile u8 *) 0x59)
#define TIFR      *((volatile u8 *) 0x58)
#define TCCR1A    *((volatile u8 *) 0x4F)
#define TCCR1B    *((volatile u8 *) 0x4E)
#define TCNT1H    *((volatile u8 *) 0x4D)
#define TCNT1L    *((volatile u8 *) 0x4C)
#define OCR1AH    *((volatile u8 *) 0x4B)
#define OCR1AL    *((volatile u8 *) 0x4A)
#define OCR1BH    *((volatile u8 *) 0x49)
#define OCR1BL    *((volatile u8 *) 0x48)
#define ICR1H     *((volatile u8 *) 0x47)
#define ICR1L     *((volatile u8 *) 0x46)

#define TCNT1     *((volatile u6 *) 0x4C)
#define OCR1A     *((volatile u6 *) 0x4A)
#define OCR1B     *((volatile u6 *) 0x48)
#define ICR1      *((volatile u6 *) 0x46)


/*************  TCCR1A Register PINS Definition *************/  			         	          

#define WGM10      0
#define WGM11      1
#define FOC1B      2
#define FOC1A      3
#define COM1B0     4
#define COM1B1     5
#define COM1A0     6
#define COM1A1     7

/************* TCCR1B Register PINS Definition ***********************/

#define CS10       0
#define CS11       1
#define CS12       2
#define WGM12      3
#define WGM13      4
#define ICES1      6
#define ICNC1      7

/*********************** TIMSK Register PINS Definition ***************************/

#define TOIE1      2
#define OCIE1B     3
#define OCIE1A     4
#define TICIE1     5

/***********************  TIFR Register PINS Definition ***********************/ 			         	          

#define TOV1       2
#define OCF1B      3
#define OCF1A      4
#define ICF1       5




/********************  TIMER1 Prescaler mask ***********************/ 			         	                
#define PRESCALER_MASK		0xF8

/****************** TIMER1 ISR __attribute__ ************************/ 			         	         

#define ISR_ST(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)


/**************************  TIMER1 Interrupt Vectors Numbers Definition  ***************/

#define TIMER1_CAPT_VECTOR		__vector_6
#define TIMER1_COMPA_VECTOR		__vector_7
#define TIMER1_COMPB_VECTOR		__vector_8
#define TIMER1_OVF_VECTOR		__vector_9



#endif /* TIMER1_PRIVATE_H_ */