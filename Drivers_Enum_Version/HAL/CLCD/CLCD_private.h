/*
 * CLCD_private.h
 *
 * Created: 1/26/2023 1:50:57 AM
 *  Author: hassa
 */ 


#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

/* Function set command : 2 lines , 5*8 font size */
#define CLCD_8_FUNC_SET		0b00111000

/*Display on off control : disable enable , disable cursor , no blink cursor*/
#define CLCD_8_DISPLAY_CTRL	0b00001111

/* Clear display */
#define CLCD_DISPLAY_CLEAR	0x01	 /* 1 or 0x01 or 0b00000001*/

#define CLCD_COMMAND_PROTEUS_MASK      	  0b11110000
#define CLCD_DATA_PORT_PROTEUS_MASK    	  0b00001111

#define CLCD_COMMAND_ATMEGA_KIT_MASK      0b01111000
#define CLCD_DATA_PORT_ATMEGA_KIT_MASK    0b10000111

/* Number of (col -1) *****************/
#define CLCD_COL_NUM           15
/* Number of (Row -1) *****************/
#define CLCD_ROW_NUM           1

#define X_INITIAL_POSITION     0
#define Y_INITIAL_POSITION     0

#endif /* CLCD_PRIVATE_H_ */