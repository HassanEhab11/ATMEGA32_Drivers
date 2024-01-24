/*
 * CLCD_private.h
 *
 * Created: 1/26/2023 1:50:57 AM
 *  Author: hassa
 */ 


#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define CLCD_SELECT_4_BIT_COMMAND_1		0x33
#define CLCD_SELECT_4_BIT_COMMAND_2		0x32
#define CLCD_SELECT_4_BIT_COMMAND_3		0x28

#define CLCD_DISPLAY_ON_CURSOR_OFF		0x0C
#define CLCD_RETURN_HOME				0x02
#define CLCD_DISPLAY_LEFT_TO_RIGHT		0x06
#define CLCD_DISPLAY_CLEAR				0x01	 /* 1 or 0x01 or 0b00000001*/
#define CLCD_CURSOR_POSITION_CMD			0x80

/* Function set command : 2 lines , 5*8 font size */
#define CLCD_8_FUNC_SET		0b00111000

/*Display on off control : disable enable , disable cursor , no blink cursor*/
#define CLCD_8_DISPLAY_CTRL	0b00001111

/* Clear display */



/* Number of (col -1) *****************/
#define CLCD_COL_NUM           19
/* Number of (Row -1) *****************/
#define CLCD_ROW_NUM           3
/***********************************/
#define CLCD_ROW_0			   0
#define CLCD_ROW_1			   1
#define CLCD_ROW_2			   2
#define CLCD_ROW_3			   3
/************** ROWS ADDRESS *************/
#define CLCD_ROW_ADDRESS_0			   0
#define CLCD_ROW_ADDRESS_1			   0x40
#define CLCD_ROW_ADDRESS_2			   0x14
#define CLCD_ROW_ADDRESS_3			   0x54

#define X_INITIAL_POSITION     0
#define Y_INITIAL_POSITION     0

#define ON	1
#define OFF	0
static u8 specialCharacter  = OFF;
static void CLCD_CurrentPosition(void);
static void H_LCD_void_latchByte(u8 copy_u8Byte);


#endif /* CLCD_PRIVATE_H_ */
