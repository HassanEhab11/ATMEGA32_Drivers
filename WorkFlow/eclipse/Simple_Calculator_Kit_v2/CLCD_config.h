/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : HAL              ********************/
/*************    SWC(Driver): CLCD(CONFIG.h) ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

/* preprocessor file guard */
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H

/* Select Between Two Mode :
 * 1)   _8_BIT_MODE
 * 2)   _4_BIT_MODE
 */
#define   MODE_SELECT        _4_BIT_MODE
#define   CLCD_DATA_PORT     DIO_u8PORTA

#define   CLCD_DATA_8Bit_PIN_0    DIO_u8PIN0
#define   CLCD_DATA_8Bit_PIN_1    DIO_u8PIN1
#define   CLCD_DATA_8Bit_PIN_2    DIO_u8PIN2
#define   CLCD_DATA_8Bit_PIN_3    DIO_u8PIN3
#define   CLCD_DATA_8Bit_PIN_4    DIO_u8PIN4
#define   CLCD_DATA_8Bit_PIN_5    DIO_u8PIN5
#define   CLCD_DATA_8Bit_PIN_6    DIO_u8PIN6
#define   CLCD_DATA_8Bit_PIN_7    DIO_u8PIN7

#define   CLCD_DATA_4Bit_PIN_0    DIO_u8PIN4
#define   CLCD_DATA_4Bit_PIN_1    DIO_u8PIN5
#define   CLCD_DATA_4Bit_PIN_2    DIO_u8PIN6
#define   CLCD_DATA_4Bit_PIN_3    DIO_u8PIN7


#define   CLCD_CTRL_PORT     DIO_u8PORTA

#define   CLCD_RS_PIN        DIO_u8PIN1
#define   CLCD_RW_PIN        DIO_u8PIN0                    /*for write mode */
#define   CLCD_E_PIN         DIO_u8PIN2














#endif
