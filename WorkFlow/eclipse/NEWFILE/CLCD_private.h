/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : HAL              ********************/
/*************    SWC(Driver): CLCD (Prog.c)      ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/
#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H

#define CLCD_COMMAND_PROTEUS_MASK      0b11110000
#define CLCD_DATA_PORT_PROTEUS_MASK    0b00001111

#define CLCD_COMMAND_ATMEGA_KIT_MASK      0b01111000
#define CLCD_DATA_PORT_ATMEGA_KIT_MASK    0b10000111

/* Number of (col -1) *****************/
#define CLCD_COL_NUM           15
/* Number of (Row -1) *****************/
#define CLCD_ROW_NUM           3

#define X_INITIAL_POSITION     0
#define Y_INITIAL_POSITION     0



#endif
