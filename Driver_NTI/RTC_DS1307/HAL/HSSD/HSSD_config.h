/*
 * SSD_config.h
 *
 * Created: 1/28/2023 2:20:36 AM
 *  Author: Hassan Ehab
 */ 


#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_


/*
 *	Chose CTRL & DATA Port:
 *							1) DIO_u8PORTA
 *							2) DIO_u8PORTB
 *							3) DIO_u8PORTC
 *							4) DIO_u8PORTD
 */
#define SSD_CTRL_PORT_1		DIO_u8PORTA
#define SSD_CTRL_PORT_2		DIO_u8PORTB

#define SSD_DATA_PORT		DIO_u8PORTB
/*
 *	Chose SSD_1 & SSD_2 EN Pin:
 *							1) DIO_u8PIN0
 *							2) DIO_u8PIN1
 *							3) DIO_u8PIN2
 *							4) DIO_u8PIN3
 *							5) DIO_u8PIN4
 *							6) DIO_u8PIN5
 *							7) DIO_u8PIN6
 *							7) DIO_u8PIN7
 */
#define SSD_1_EN_PIN		DIO_u8PIN3
#define SSD_2_EN_PIN		DIO_u8PIN2
#define SSD_3_EN_PIN		DIO_u8PIN5
#define SSD_4_EN_PIN		DIO_u8PIN6

#define DATA_PIN_A			DIO_u8PIN0
#define DATA_PIN_B			DIO_u8PIN1
#define DATA_PIN_C			DIO_u8PIN2
#define DATA_PIN_D			DIO_u8PIN4



#endif /* SSD_CONFIG_H_ */
