/*
 * KEYPAD_config.h
 *
 * Created: 1/27/2023 12:51:55 AM
 *  Author: hassa
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KPD_NO_PRESSED_KEY   0xff
#define KPD_ARR_VAL       {{'7','8','9','+'},{'4','5','6','-'},{'1','2','3','*'},{'c','0','d','/'}}
 

#define COL_PORT		DIO_u8PORTD
#define ROW_PORT		DIO_u8PORTB

#define COL_PIN1		DIO_u8PIN2
#define COL_PIN2		DIO_u8PIN3
#define COL_PIN3		DIO_u8PIN4
#define COL_PIN4		DIO_u8PIN5

#define ROW_PIN1		DIO_u8PIN4
#define ROW_PIN2		DIO_u8PIN5
#define ROW_PIN3		DIO_u8PIN6
#define ROW_PIN4		DIO_u8PIN7



#endif /* KEYPAD_CONFIG_H_ */