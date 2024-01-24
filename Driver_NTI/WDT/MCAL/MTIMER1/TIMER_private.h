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


#define TIFR          *((volatile u8*)0x58)    /* Timer/Counter Interrupt Flag Register */
#define TIFR_TOV0     0                             /* Timer/Counter0 Overflow Flag */
#define TIFR_OCF0     1                             /* Output Compare Flag 0 */
#define TIFR_TOV1     2                             /* Timer/Counter1 Overflow Flag */
#define TIFR_OCF1A    3                             /* Output Compare Flag 1A */
#define TIFR_OCF1B    4                             /* Output Compare Flag 1B */
#define TIFR_ICF1     5                             /* Input Capture Flag 1 */
#define TIFR_TOV2     6                             /* Timer/Counter2 Overflow Flag */
#define TIFR_OCF2     7                             /* Output Compare Flag 2 */



#define OCR0           *((volatile u8*)0x5C)    /* Output compare register 0 */

#define TIMSK          *((volatile u8*)0x59)    /*Timer mask*/
#define TIMSK_OCIE0    1                        /*Output compare 0 interrupt enable*/
#define TIMSK_TICIE1   5
/*******************************************************************************************/
#define TCCR1A          *((volatile u8*)0x4f)
#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1
#define TCCR1A_COM1A1   7
#define TCCR1A_COM1A0   6
#define PRESCALER_MASK  0b11111000
#define DIVIDE_BY_8     2



#define TCCR1B          *((volatile u8*)0x4E)
#define TCCR1B_ICNC1     7                             /* Input Capture Noise Canceler 1 */
#define TCCR1B_ICES1     6                              /* Input Capture Edge Select 1 */
#define TCCR1B_WGM13     4                              /* Waveform Generation Mode bit 3 */
#define TCCR1B_WGM12     3                              /* Waveform Generation Mode bit 2 */
#define TCCR1B_CS12      2                              /* Clock Select bit 2 */
#define TCCR1B_CS11      1                              /* Clock Select bit 1 */
#define TCCR1B_CS10      0                              /* Clock Select bit 0 */

#define TCNT1           *((volatile u16*)0x4C)                      /* Timer/counter1 Register */

#define ICR1          *((volatile u16*)0x46)

#define OCR1A          *((volatile u16*)0x4a)

#endif
