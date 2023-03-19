/*
 * CLCD_config.h
 *
 * Created: 1/26/2023 1:50:41 AM
 *  Author: hassa
 */ 


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define ATMEGA_KIT     1
#define PROTEUS        2
/* Choose Proteus Or kit:
 *                      1) ATMEGA_KIT
 *                      2) PROTEUS
 *
 */
#define DRIVER_PURPOUSE      ATMEGA_KIT
/*
 * Chose CLCD Mode : 
 *				        1)	_4_BIT_MODE
 *				        2)	_8_BIT_MODE
 */
#define CLCD_MODE			_4_BIT_MODE


/********** Select Control and Data Port **************/
/*
 * Chose CTRL & DATA Port :
 *						1)	DIO_u8PORTA
 *						2)	DIO_u8PORTB
 *						3)	DIO_u8PORTC
 *						4)	DIO_u8PORTD
 */

#if		  DRIVER_PURPOUSE   ==   PROTEUS
#define   CLCD_DATA_PORT      DIO_u8PORTA
#define   CLCD_CTRL_PORT      DIO_u8PORTC
/**************** Control Pins  *******************/
#define   CLCD_RS_PIN         DIO_u8PIN0
#define   CLCD_RW_PIN         DIO_u8PIN1                    /*for write mode */
#define   CLCD_EN_PIN         DIO_u8PIN2

#elif	  DRIVER_PURPOUSE   ==   ATMEGA_KIT
#define   CLCD_DATA_PORT      DIO_u8PORTA
#define   CLCD_CTRL_PORT      DIO_u8PORTA
/**************** Control Pins  *******************/
#define   CLCD_RS_PIN         DIO_u8PIN1
#define   CLCD_RW_PIN         DIO_u8PIN0                    /*for write mode */
#define   CLCD_EN_PIN         DIO_u8PIN2

#endif

/*
 *		_8_BIT_DATA_PIN
 */
#define CLCD_DATA_8_PIN0	DIO_u8PIN0
#define CLCD_DATA_8_PIN1	DIO_u8PIN1
#define CLCD_DATA_8_PIN2	DIO_u8PIN2
#define CLCD_DATA_8_PIN3	DIO_u8PIN3
#define CLCD_DATA_8_PIN4	DIO_u8PIN4
#define CLCD_DATA_8_PIN5	DIO_u8PIN5
#define CLCD_DATA_8_PIN6	DIO_u8PIN6
#define CLCD_DATA_8_PIN7	DIO_u8PIN7
/*
 *		_4_BIT_DATA_PIN
 */
#define CLCD_DATA_4_PIN0	DIO_u8PIN4
#define CLCD_DATA_4_PIN1	DIO_u8PIN5
#define CLCD_DATA_4_PIN2	DIO_u8PIN6
#define CLCD_DATA_4_PIN3	DIO_u8PIN7

#endif /* CLCD_CONFIG_H_ */