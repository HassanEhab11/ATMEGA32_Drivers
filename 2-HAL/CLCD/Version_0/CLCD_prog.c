/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
/*************    SWC(Driver): CLCD (Prog.c)      ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/
#include <avr/io.h>
#include<util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"


void C_LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS Pin to low to send command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW Pin to low to write command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/* Set Command to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);



}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS Pin to low to send dta */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW Pin to low to write command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/* Set Data to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);



	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);



}

void CLCD_voidInit(void)
{
	/* wait for more than 30ms */
	_delay_ms(40);

	/* Function set command : 2 lines , 5*8 font size */
	C_LCD_voidSendCommand(0b00111000);

	/*Display on off control : disable enable , disable cursor , no blink cursor*/
	C_LCD_voidSendCommand(0b00001100);

	/* Clear display */
	C_LCD_voidSendCommand(0x01); /* 1 or 0x01 or 0b00000001*/


}

void CLCD_voidSendString(const char* Copy_pcString )
{
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] != NULL)
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{
	u8 Local_u8Adress;
	if (Copy_u8Xpos == 0)
	{
		Local_u8Adress = Copy_u8Ypos;
	}
	else if (Copy_u8Xpos == 1)
	{
		Local_u8Adress = Copy_u8Ypos+0x40;
	}

	C_LCD_voidSendCommand(Local_u8Adress+128);



}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress= 0, Local_u8Iterator;
	/* Calculate the CGRAM address whose each block is 8 bytes */
	Local_u8CGRAMAddress =Copy_u8PatternNumber*8;

	/* Send CGRAM Address command to LCD, with setting bit 6, clearing bit 7*/
	C_LCD_voidSendCommand(Local_u8CGRAMAddress+64);

	/* Write the pattern into CGRAM */

	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	/* go back to the DDRAM to display the Pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	/* Display the pattern written in the CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}






