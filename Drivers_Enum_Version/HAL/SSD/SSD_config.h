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
#define SSD_CTRL_PORT		DIO_u8PORTC
#define SSD_DATA_PORT		DIO_u8PORTA
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
#define SSD_1_EN_PIN		DIO_u8PIN6
#define SSD_2_EN_PIN		DIO_u8PIN7




#endif /* SSD_CONFIG_H_ */