/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TIMER       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0          *((volatile u8*)0x53)    /* Timer0 Control Register */	
#define TCCR0_WGM00    6                        /*Wave Generation Mode bit0 */
#define TCCR0_WGM01    3                        /*Wave Generation Mode bit1 */
#define TCCR0_CS02     0                        /*Prescaler bit2 */
#define TCCR0_CS01     1                        /*Prescaler bit1 */
#define TCCR0_CS00     0                        /*Prescaler bit0 */



#define OCR0           *((volatile u8*)0x5C)    /* Output compare register 0 */

#define TIMSK          *((volatile u8*)0x59)    /*Timer mask*/
#define TIMSK_OCIE0    1                        /*Output compare 0 interrupt enable*/




#endif