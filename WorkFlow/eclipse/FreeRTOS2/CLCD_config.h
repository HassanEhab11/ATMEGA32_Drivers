/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : HAL              ********************/
/*************    SWC(Driver): CLCD(CONFIG.h) ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

/*
 * IN THIS VERSION I ADDED
 */

/* preprocessor file guard */
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H


#define ATMEGA_KIT     0
#define PROTEUS        1

/* Choose Proteus Or kit:
 * 1) ATMEGA_KIT
 * 2) PROTEUS
 *
 */
#define DRIVER_PURPOUSE      ATMEGA_KIT
/* Select Between Two Mode :
 * 1)   _8_BIT_MODE
 * 2)   _4_BIT_MODE
 */
#define   MODE_SELECT        _4_BIT_MODE
/********** Select Control and Data Port **************/
#if DRIVER_PURPOUSE   ==   PROTEUS
#define   CLCD_DATA_PORT     DIO_u8PORTC
#define   CLCD_CTRL_PORT     DIO_u8PORTC
/**************** Control Pins  *******************/
#define   CLCD_RS_PIN        DIO_u8PIN2
#define   CLCD_RW_PIN        DIO_u8PIN0                    /*for write mode */
#define   CLCD_E_PIN         DIO_u8PIN3

#elif DRIVER_PURPOUSE   ==   ATMEGA_KIT
#define   CLCD_DATA_PORT     DIO_u8PORTA
#define   CLCD_CTRL_PORT     DIO_u8PORTA
/**************** Control Pins  *******************/
#define   CLCD_RS_PIN        DIO_u8PIN1
#define   CLCD_RW_PIN        DIO_u8PIN0                    /*for write mode */
#define   CLCD_E_PIN         DIO_u8PIN2

#endif
/**************** 8_BITS_Data Pins *******************/
#define   CLCD_DATA_8Bit_PIN_0    DIO_u8PIN0
#define   CLCD_DATA_8Bit_PIN_1    DIO_u8PIN1
#define   CLCD_DATA_8Bit_PIN_2    DIO_u8PIN2
#define   CLCD_DATA_8Bit_PIN_3    DIO_u8PIN3
#define   CLCD_DATA_8Bit_PIN_4    DIO_u8PIN4
#define   CLCD_DATA_8Bit_PIN_5    DIO_u8PIN5
#define   CLCD_DATA_8Bit_PIN_6    DIO_u8PIN6
#define   CLCD_DATA_8Bit_PIN_7    DIO_u8PIN7

/**************** 4_BITS_Data Pins *******************/
#define   CLCD_DATA_4Bit_PIN_0    DIO_u8PIN4
#define   CLCD_DATA_4Bit_PIN_1    DIO_u8PIN5
#define   CLCD_DATA_4Bit_PIN_2    DIO_u8PIN6
#define   CLCD_DATA_4Bit_PIN_3    DIO_u8PIN7




#endif
