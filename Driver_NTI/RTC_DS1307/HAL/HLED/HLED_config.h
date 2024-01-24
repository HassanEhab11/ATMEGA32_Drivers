/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL         *********************/
/******************    SWC(Driver): HLED        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef HLED_CONFIG_H
#define HLED_CONFIG_H

/* RED LED */
#define LED_RED_DIR		LED_DIR_FORWARD
#define LED_RED_PORT	DIO_u8PORTB
#define LED_RED_PIN		DIO_u8PIN7

/* YELLOW LED */
#define LED_YELLOW_DIR 	LED_DIR_FORWARD
#define LED_YELLOW_PORT	DIO_u8PORTA
#define LED_YELLOW_PIN 	DIO_u8PIN6

/* GREEN LED */
#define LED_GREEN_DIR 	LED_DIR_FORWARD
#define LED_GREEN_PORT	DIO_u8PORTA
#define LED_GREEN_PIN 	DIO_u8PIN4

/* BLUE LED */
#define LED_BLUE_DIR 	LED_DIR_FORWARD
#define LED_BLUE_PORT	DIO_u8PORTA
#define LED_BLUE_PIN 	DIO_u8PIN5

#endif
