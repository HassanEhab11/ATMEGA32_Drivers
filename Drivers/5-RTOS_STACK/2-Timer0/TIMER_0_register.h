/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab    ******************/
/******************    Layer      : RTOS STACK     ******************/
/******************    SWC(Driver): TIMER          ******************/
/******************    Version    : 1.00           ******************/
/******************    DATE       : 14/11/2022     ******************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER_0_REGISTER_H_
#define TIMER_0_REGISTER_H_
/*****************************  Timer/Counter Control Register ( TCCR0 )  ********************************/
#define TCCR0               *((volatile u8*)0x53)
#define TCCR0_FOC0          7
#define TCCR0_WGM00         6
#define TCCR0_COM01         5
#define TCCR0_COM00         4
#define TCCR0_WGM01         3
#define TCCR0_CS02          2
#define TCCR0_CS01          1
#define TCCR0_CS00          0

/******************************* Timer/Counter Register ( TCNT0 )    *************************************/
#define TCNT0               *((volatile u8*)0x52)

/********************************  Output Compare Register ( OCR0 ) **************************************/
#define OCR0                *((volatile u8*)0x5C)

/**************************  Timer/Counter Interrupt Mask Register ( TIMSK ) *****************************/
#define TIMSK               *((volatile u8*)0x59)
#define TIMSK_OCIE0          1
#define TIMSK_TOIE0          0

/**************************  Timer/Counter Interrupt Flag Register ( TIFR ) *****************************/
#define TIFR                 *((volatile u8*)0x58)


#endif
