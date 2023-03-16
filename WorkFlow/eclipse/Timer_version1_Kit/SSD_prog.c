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


u8 seven_seg[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

u8 SSD_u8SingleNumDisplayBlink(u8 number)
{
	u8 Local_u8ErrorState = 0;
	u8 Local_u8Counter;
	u8 Local_u8PortMask;

	for(Local_u8Counter=0;Local_u8Counter<100;Local_u8Counter++)
	{
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_HIGH);
		Local_u8PortMask = DIO_u8AndWithPort(SSD_DATA_PORT,SSD_DATA_MASK);

		seven_seg[number]|=Local_u8PortMask;
		DIO_u8SetPortValue(SSD_DATA_PORT,seven_seg[number]);
		//		_delay_ms(5);
		//		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_LOW);
	}
	return Local_u8ErrorState;
}

u8 SSD_u8DisplayBlink(u8 number)
{
	u8 Local_u8ErrorState = 0;
	u8 Local_u8PortMask;

	u8 Local_u8Counter;
	u8 ones = number%10;
	u8 tens = number/10;

	Local_u8PortMask = DIO_u8AndWithPort(SSD_DATA_PORT,SSD_DATA_MASK);
	seven_seg[ones]|=Local_u8PortMask;

	Local_u8PortMask = DIO_u8AndWithPort(SSD_DATA_PORT,SSD_DATA_MASK);
	seven_seg[tens]|=Local_u8PortMask;

	for(Local_u8Counter=0;Local_u8Counter<100;Local_u8Counter++)
	{
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPortValue(SSD_DATA_PORT,seven_seg[ones]);

		_delay_ms(20);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(SSD_DATA_PORT,seven_seg[tens]);
		_delay_ms(20);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_LOW);


	}
	return Local_u8ErrorState;
}

u8 SSD_u8Displaynum(u8 number)
{
	u8 Local_u8ErrorState = 0;

	u8 ones = number%10;
	u8 tens = number/10;

	for(;;)
	{
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPortValue(SSD_DATA_PORT,seven_seg[ones]);

		_delay_ms(5);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_HIGH);
		DIO_u8SetPortValue(SSD_DATA_PORT,seven_seg[tens]);
		_delay_ms(5);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_LOW);

	}

	return Local_u8ErrorState;

}

u8 SSD_u8CountUp(u8 number)
{
	u8 Local_u8ErrorState = 0;
	u8 Local_u8Counter;

	for(Local_u8Counter=0;Local_u8Counter<=number;Local_u8Counter++)
	{
		SSD_u8DisplayBlink(Local_u8Counter);

	}

	return Local_u8ErrorState;
}

u8 SSD_u8CountDown(u8 number)
{
	u8 Local_u8ErrorState = 0;
	s8 Local_u8Counter;
	for(Local_u8Counter=number;Local_u8Counter>=0;Local_u8Counter--)
	{
		SSD_u8DisplayBlink(Local_u8Counter);
	}

	return Local_u8ErrorState;
}

void SSD_u8Specficfunc(void)
{
	static u8 Local_u8num1 = 9;
	static u8 Local_u8num2 = 0;
	u8 Local_u8PortMask;

	u8 Local_u8Counter;


	Local_u8PortMask = DIO_u8AndWithPort(SSD_DATA_PORT,SSD_DATA_MASK);
	seven_seg[Local_u8num1]|=Local_u8PortMask;

	Local_u8PortMask = DIO_u8AndWithPort(SSD_DATA_PORT,SSD_DATA_MASK);
	seven_seg[Local_u8num2]|=Local_u8PortMask;


	DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_LOW);
	_delay_ms(5);

	DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(SSD_DATA_PORT,seven_seg[Local_u8num1]);

	_delay_ms(5);
	DIO_u8SetPinValue(SSD_EN_PORT,SSD_1_EN_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(SSD_EN_PORT,SSD_2_EN_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPortValue(SSD_DATA_PORT,seven_seg[Local_u8num2]);



	if(Local_u8num1 - Local_u8num2 >= 0 && Local_u8num2 == Local_u8num1-1)
	{
		Local_u8num1 --;
		Local_u8num2 ++;
	}
	else
	{
		Local_u8num1 ++;
		Local_u8num2 --;
	}



}

