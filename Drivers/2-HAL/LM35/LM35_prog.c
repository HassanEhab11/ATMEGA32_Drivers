/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
/*************    SWC(Driver): SSD (Prog.c)      ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/
#include <avr/io.h>
#include<util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

u8 seven_seg[10]={0b01111110,0b00001100,0b10110110,
		0b10011110,0b11001100,0b11011010,
		0b11111010,0b00001110,0b11111110,
		0b11011110};

u8 SSD_u8Init(void)

{
	u8 Local_u8ErrorState = 0;

	DIO_u8SetPortDirection(DIO_u8PORTA,254);   /* SSD PORT */
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_OUTPUT);    /* SSD1 EN PIN */
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_OUTPUT);   /* SSD2 EN PIN */


	return Local_u8ErrorState;

}

u8 SSD_u8DisplayBlink(u8 number)
{
	u8 Local_u8ErrorState = 0;

	u8 i;
	u8 ones = number%10;
	u8 tens = number/10;

	for(i=0;i<185;i++)
	{
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
		DIO_u8SetPortValue(DIO_u8PORTA,seven_seg[ones]);

		_delay_ms(5);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(DIO_u8PORTA,seven_seg[tens]);
		_delay_ms(5);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);

	}

	return Local_u8ErrorState;

}
//u8 SSD_u8IncDec(u8 number)
//{
//	u8 Local_u8ErrorState = 0;
//
//	u8 i,temp;
//	temp = number;
//	for(;;)
//	{
//	u8 ones = temp%10;
//	u8 tens = temp/10;
//	DIO_u8GetPinValue()
//	if (GET_BIT(PIND,PD2) == 0)
//	{
//		//while(GET_BIT(PIND,PD2) == 0);
//
//		_delay_ms(500);
//		if(temp>=99)
//			{temp=0;}
//		else
//		temp++;
//	}
//	if (GET_BIT(PIND,PD3) == 0)
//	{
//		//while(GET_BIT(PIND,PD3) == 0);
//		_delay_ms(500);
//		if(temp<=0)
//			{temp=99;}
//		else
//		temp--;
//	}
//
////	for(i=0;i<70;i++)
////	{
//		SET_BIT(PORTC,PC6);
//	    CLR_BIT(PORTC,PC7);
//		PORTA = seven_seg[ones];
//	    _delay_ms(5);
//	    SET_BIT(PORTC,PC7);
//	    CLR_BIT(PORTC,PC6);
//		PORTA = seven_seg[tens];
//		_delay_ms(5);
//		CLR_BIT(PORTC,PC6);
//		CLR_BIT(PORTC,PC7);
////}
//	}
//
//	return Local_u8ErrorState;
//}

u8 SSD_u8Displaynum(u8 number)
{
	u8 Local_u8ErrorState = 0;

	u8 ones = number%10;
	u8 tens = number/10;

	for(;;)
	{
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
		DIO_u8SetPortValue(DIO_u8PORTA,seven_seg[ones]);

		_delay_ms(5);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(DIO_u8PORTA,seven_seg[tens]);
		_delay_ms(5);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);

	}

	return Local_u8ErrorState;

}

u8 SSD_u8CountUp(u8 number)
{
	u8 Local_u8ErrorState = 0;

	u8 i;
		for(i=0;i<=number;i++)
		{
			SSD_u8DisplayBlink(i);

		}

	return Local_u8ErrorState;
}
u8 SSD_u8CountDown(u8 number)
{
	u8 Local_u8ErrorState = 0;
	s8 i;
	for(i=number;i>=0;i--)
	{
		SSD_u8DisplayBlink(i);

	}

	return Local_u8ErrorState;
}
