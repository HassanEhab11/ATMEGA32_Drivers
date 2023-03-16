/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): PORT         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/* Choose : 0 for  input
*           1 for  output
*/

#define PORTA_PIN0_DIR        0            /*******     >>    PA0  (ADC0)       <<    *******/
#define PORTA_PIN1_DIR        0            /*******     >>    PA1  (ADC1)       <<    *******/
#define PORTA_PIN2_DIR        0            /*******     >>    PA2  (ADC2)       <<    *******/
#define PORTA_PIN3_DIR        0            /*******     >>    PA3  (ADC3)       <<    *******/
#define PORTA_PIN4_DIR        0            /*******     >>    PA4  (ADC4)       <<    *******/
#define PORTA_PIN5_DIR        0            /*******     >>    PA5  (ADC5)       <<    *******/
#define PORTA_PIN6_DIR        0            /*******     >>    PA6  (ADC6)       <<    *******/
#define PORTA_PIN7_DIR        0            /*******     >>    PA7  (ADC7)       <<    *******/

#define PORTB_PIN0_DIR        0            /*******     >>    PB0  (XCK/T0)     <<    *******/
#define PORTB_PIN1_DIR        0            /*******     >>    PB1  (T1)         <<    *******/
#define PORTB_PIN2_DIR        0            /*******     >>    PB2  (INT2/AIN0)  <<    *******/
#define PORTB_PIN3_DIR        0            /*******     >>    PB3  (OC0/AIN1)   <<    *******/
#define PORTB_PIN4_DIR        0            /*******     >>    PB4  (SS)         <<    *******/
#define PORTB_PIN5_DIR        0            /*******     >>    PB5  (MOSI)       <<    *******/
#define PORTB_PIN6_DIR        0            /*******     >>    PB6  (MISO)       <<    *******/
#define PORTB_PIN7_DIR        0            /*******     >>    PB7  (SCK)        <<    *******/

#define PORTC_PIN0_DIR        1            /*******     >>    PC0  (SCL)        <<    *******/
#define PORTC_PIN1_DIR        1            /*******     >>    PC1  (SDA)        <<    *******/
#define PORTC_PIN2_DIR        1            /*******     >>    PC2  (TCK)        <<    *******/
#define PORTC_PIN3_DIR        0            /*******     >>    PC3  (TMS)        <<    *******/
#define PORTC_PIN4_DIR        0            /*******     >>    PC4  (TDO)        <<    *******/
#define PORTC_PIN5_DIR        0            /*******     >>    PC5  (TDI)        <<    *******/
#define PORTC_PIN6_DIR        0            /*******     >>    PC6  (TOSC1)      <<    *******/
#define PORTC_PIN7_DIR        0            /*******     >>    PC7  (TOSC2)      <<    *******/

#define PORTD_PIN0_DIR        0            /*******     >>    PD0  (RXD)        <<    *******/
#define PORTD_PIN1_DIR        0            /*******     >>    PD1  (TXD)        <<    *******/
#define PORTD_PIN2_DIR        0            /*******     >>    PD2  (INT0)       <<    *******/
#define PORTD_PIN3_DIR        0            /*******     >>    PD3  (INT1)       <<    *******/
#define PORTD_PIN4_DIR        0            /*******     >>    PD4  (OC1B)       <<    *******/
#define PORTD_PIN5_DIR        0            /*******     >>    PD5  (OC1A)       <<    *******/
#define PORTD_PIN6_DIR        0            /*******     >>    PD6  (ICP)        <<    *******/
#define PORTD_PIN7_DIR        0            /*******     >>    PD7  (OC2)        <<    *******/

/* Choose : 0 for  (output -> Low  , input ->Floating )
*           1 for  (output -> High , input ->pullup   )
*/

#define PORTA_PIN0_INITIAL_VALUE        0
#define PORTA_PIN1_INITIAL_VALUE        0
#define PORTA_PIN2_INITIAL_VALUE        0
#define PORTA_PIN3_INITIAL_VALUE        0
#define PORTA_PIN4_INITIAL_VALUE        0
#define PORTA_PIN5_INITIAL_VALUE        0
#define PORTA_PIN6_INITIAL_VALUE        0
#define PORTA_PIN7_INITIAL_VALUE        0
						 
						 
#define PORTB_PIN0_INITIAL_VALUE        0
#define PORTB_PIN1_INITIAL_VALUE        0
#define PORTB_PIN2_INITIAL_VALUE        0
#define PORTB_PIN3_INITIAL_VALUE        0
#define PORTB_PIN4_INITIAL_VALUE        0
#define PORTB_PIN5_INITIAL_VALUE        0
#define PORTB_PIN6_INITIAL_VALUE        0
#define PORTB_PIN7_INITIAL_VALUE        0
						 
						
#define PORTC_PIN0_INITIAL_VALUE        0
#define PORTC_PIN1_INITIAL_VALUE        0
#define PORTC_PIN2_INITIAL_VALUE        0
#define PORTC_PIN3_INITIAL_VALUE        0
#define PORTC_PIN4_INITIAL_VALUE        0
#define PORTC_PIN5_INITIAL_VALUE        0
#define PORTC_PIN6_INITIAL_VALUE        0
#define PORTC_PIN7_INITIAL_VALUE        0
						 
						 
#define PORTD_PIN0_INITIAL_VALUE        0
#define PORTD_PIN1_INITIAL_VALUE        0
#define PORTD_PIN2_INITIAL_VALUE        0
#define PORTD_PIN3_INITIAL_VALUE        0
#define PORTD_PIN4_INITIAL_VALUE        0
#define PORTD_PIN5_INITIAL_VALUE        0
#define PORTD_PIN6_INITIAL_VALUE        0
#define PORTD_PIN7_INITIAL_VALUE        0



#endif
