/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
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
#define   MODE_SELECT        _8_BIT_MODE
#define   CLCD_DATA_PORT       DIO_u8PORTA

#define   CLCD_CTRL_PORT     DIO_u8PORTA
#define   CLCD_RS_PIN        DIO_u8PIN1
#define   CLCD_RW_PIN        0                    /*for write mode */
#define   CLCD_E_PIN         DIO_u8PIN2














#endif
