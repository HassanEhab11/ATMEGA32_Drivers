/*
 * KEYPAD_config.h
 *
 * Created: 1/27/2023 12:51:55 AM
 *  Author: hassa
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define ROW_NUM	4
#define COL_NUM	4


#define	KPD_NO_PRESSED_KEY	0xff

#define	KP_NUMBER_MODE		{{1,2,3,4},{5,6,7,8},{9,10,0,12},{13,14,15,16}}
#define	KP_CALCULATOR_MODE	{{'7', '8', '9', '/'},{'4', '5', '6', '*'},{'1', '2', '3', '+'},{'0', '0', '=', '-'}}
#define	KP_PROTEUS_MODE	{{7,8,9,0xff},{4,5,6,0xff},{1,2,3,0xff},{10,0,11,0xff}}
// choose Keypad Mode
#define KP_MODE	KP_PROTEUS_MODE

/* configure push button mode */
#define ACTIVE_LOW		0
#define ACTIVE_HIGH		1
#define PB_MODE			ACTIVE_LOW

/** configure KeyPad ROWS port and pin **/
#define KEYPAD_R0_PORT	DIO_u8PORTC
#define KEYPAD_R0_PIN	DIO_u8PIN5

#define KEYPAD_R1_PORT	DIO_u8PORTC
#define KEYPAD_R1_PIN	DIO_u8PIN4

#define KEYPAD_R2_PORT	DIO_u8PORTC
#define KEYPAD_R2_PIN	DIO_u8PIN3

#define KEYPAD_R3_PORT	DIO_u8PORTC
#define KEYPAD_R3_PIN	DIO_u8PIN2

/** configure KeyPad COLUMS port and pin **/
#define KEYPAD_C0_PORT	DIO_u8PORTD
#define KEYPAD_C0_PIN	DIO_u8PIN7

#define KEYPAD_C1_PORT	DIO_u8PORTD
#define KEYPAD_C1_PIN	DIO_u8PIN6

#define KEYPAD_C2_PORT	DIO_u8PORTD
#define KEYPAD_C2_PIN	DIO_u8PIN5

#define KEYPAD_C3_PORT	DIO_u8PORTD
#define KEYPAD_C3_PIN	DIO_u8PIN3



#endif /* KEYPAD_CONFIG_H_ */
