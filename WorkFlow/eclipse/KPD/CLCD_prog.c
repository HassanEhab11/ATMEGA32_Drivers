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
#include "CLCD_config.h"
#include "CLCD_interface.h"

#include "CLCD_private.h"


void C_LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS Pin to low to send command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

 	/*Set RW Pin to low to write command */
 	//DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

#if   MODE_SELECT ==_8_BIT_MODE

	/* Set Command to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#elif   MODE_SELECT ==_4_BIT_MODE

	u8 Local_u8Command = (((Copy_u8Command >> 1) & 0b01111000) | DIO_u8AndWithPort(CLCD_DATA_PORT, 0b10000111));
	/* Set Command to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Local_u8Command);

	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(5);

	Local_u8Command = ((Copy_u8Command <<3) |DIO_u8AndWithPort(CLCD_DATA_PORT, 0b10000111));
	DIO_u8SetPortValue(CLCD_DATA_PORT,Local_u8Command);

	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(5);


#endif



}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS Pin to low to send data */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW Pin to low to write command */
//	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
#if   MODE_SELECT ==_8_BIT_MODE

	/* Set Data to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);



	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#elif   MODE_SELECT ==_4_BIT_MODE

	u8 Local_u8Data = (((Copy_u8Data >> 1) & 0b01111000) | DIO_u8AndWithPort(CLCD_DATA_PORT, 0b10000111));
	/* Set Command to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Local_u8Data);

	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(5);

	Local_u8Data = ((Copy_u8Data <<3) |DIO_u8AndWithPort(CLCD_DATA_PORT, 0b10000111));

	DIO_u8SetPortValue(CLCD_DATA_PORT,Local_u8Data);

	/*Send Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(5);





#endif

}

void CLCD_voidInit(void)
{

	/* wait for more than 30ms */
	_delay_ms(40);

#if   MODE_SELECT ==_8_BIT_MODE


	/* Function set command : 2 lines , 5*8 font size */
	C_LCD_voidSendCommand(0b00111000);

	/*Display on off control : disable enable , disable cursor , no blink cursor*/
	C_LCD_voidSendCommand(0b00001100);

	/* Clear display */
	C_LCD_voidSendCommand(0x01); /* 1 or 0x01 or 0b00000001*/

#elif   MODE_SELECT ==_4_BIT_MODE

	/* Function set command : 2 lines , 5*8 font size */
	C_LCD_voidSendCommand(0x33);
	C_LCD_voidSendCommand(0x32);
	C_LCD_voidSendCommand(0x28);   /* 0bNFXXXXXX  --> N: no of lines F: font size*/


	/*Display on off control : disable enable , disable cursor , no blink cursor*/
	C_LCD_voidSendCommand(0x0C);
	C_LCD_voidSendCommand(0x02);

	C_LCD_voidSendCommand(0x06);

	/* Clear display */
	C_LCD_voidSendCommand(0x01);


#endif


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
	u8 Local_u8Adress=0;
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

void CLCD_VoidWriteNumber(f32 Copy_u32Number)
{
	s32 Local_s32Number = Copy_u32Number;

	if(Local_s32Number == 0)
	{
		CLCD_voidSendData('0');
	}
	else if (Local_s32Number <0)
	{
		CLCD_voidSendData('-');
		Local_s32Number = Local_s32Number *(-1);

	}
	u8 Local_u8Array[20]={0};
	s8 local_s8Counter =0;
	while (Local_s32Number != 0)
	{
		Local_u8Array[local_s8Counter]= Local_s32Number%10;
		Local_s32Number/=10;
		local_s8Counter++;
	}
	local_s8Counter--;
	while (local_s8Counter>=0)
	{
		CLCD_voidSendData(Local_u8Array[local_s8Counter]+'0');
		local_s8Counter--;
	}


}


//void LCD_enuWriteFloatNum(f32 Copy_f32FloatNum)
//{
//	//u8 Local_u8ErrorState = ES_NOK;
//	if(Copy_f32FloatNum == 0)
//	{
//		CLCD_voidSendData('0');
//		//Local_u8ErrorState = ES_OK;
//	}else
//	{
//		s32 Local_s32DecimalVal = Copy_f32FloatNum;
//		CLCD_VoidWriteNumber(Local_s32DecimalVal);
//		CLCD_voidSendData('.');
//		Copy_f32FloatNum -= Local_s32DecimalVal;
//		Copy_f32FloatNum *= 1000000;
//		Local_s32DecimalVal = Copy_f32FloatNum;
//		while((Local_s32DecimalVal%10 == 0))
//		{
//			Local_s32DecimalVal /=10;
//		}
//		CLCD_VoidWriteNumber(Local_s32DecimalVal);
//
//		//Local_u8ErrorState = ES_OK;
//	}
//	//return Local_u8ErrorState;
//}
//
//void CLCD_voidWriteFloatNumber(f32 Copy_f32FloatNumber )
//{
//
//	if(Copy_f32FloatNumber == 0)
//	{
//		CLCD_VoidWriteNumber(0);
//	}
//
//	else
//	{
//		s32 Local_s32DecemalNum=Copy_f32FloatNumber;
//		CLCD_VoidWriteNumber(Local_s32DecemalNum);
//		CLCD_voidSendData('.');
//		Copy_f32FloatNumber = Copy_f32FloatNumber -Local_s32DecemalNum;
//
//		Copy_f32FloatNumber*=100000;
//		Local_s32DecemalNum = Copy_f32FloatNumber;
//
//while (Local_s32DecemalNum%10 == 0)
//{
//	Local_s32DecemalNum/=10;
//}
//CLCD_VoidWriteNumber(Local_s32DecemalNum);
//	}
//
//
//
//
//
//
//
//}
//



























