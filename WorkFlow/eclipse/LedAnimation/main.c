#include <avr/io.h>
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BITMATH.h"

void SsdInit(void);
void SsdDisplay(u8 number);
void SsdCountUp(u8 number);
void SsdCountDown(u8 number);




void main(void)
{
	SsdInit();
	// set led direction output mode
	SET_BIT(DDRC,PC0);
	SET_BIT(DDRC,PC1);
	SET_BIT(DDRC,PC2);

	//CLR switch direction input mode
	DDRD = 0b00;




	while(1)
	{
		if (GET_BIT(PIND,PD2) == 0)
		{
			SET_BIT(PORTC,PC0);
			SET_BIT(PORTC,PC1);
			SET_BIT(PORTC,PC2);

			_delay_ms(500);

			CLR_BIT(PORTC,PC0);
			CLR_BIT(PORTC,PC1);
			CLR_BIT(PORTC,PC2);
			_delay_ms(500);

		}
		else if (GET_BIT(PIND,PD3) == 0)
		{
			SET_BIT(PORTC,PC0);
			CLR_BIT(PORTC,PC2);
			_delay_ms(250);
			SET_BIT(PORTC,PC1);
			CLR_BIT(PORTC,PC0);
			_delay_ms(250);
			SET_BIT(PORTC,PC2);
			CLR_BIT(PORTC,PC1);
			_delay_ms(250);
			CLR_BIT(PORTC,PC0);
			CLR_BIT(PORTC,PC1);
			CLR_BIT(PORTC,PC2);
			_delay_ms(250);



		}
		else if (GET_BIT(PIND,PD4) == 0)
		{
			SET_BIT(PORTC,PC2);
			_delay_ms(250);
			SET_BIT(PORTC,PC1);
			CLR_BIT(PORTC,PC2);
			_delay_ms(250);
			SET_BIT(PORTC,PC0);
			CLR_BIT(PORTC,PC1);
			_delay_ms(250);
			CLR_BIT(PORTC,PC0);
			_delay_ms(250);


		}
		else if (GET_BIT(PIND,PD5) == 0)
		{
			SET_BIT(PORTC,PC0);
			CLR_BIT(PORTC,PC1);
			_delay_ms(250);
			SET_BIT(PORTC,PC1);
			CLR_BIT(PORTC,PC0);
			_delay_ms(250);
			SET_BIT(PORTC,PC2);
			CLR_BIT(PORTC,PC1);
			_delay_ms(250);
			SET_BIT(PORTC,PC1);
			CLR_BIT(PORTC,PC2);
			_delay_ms(250);
			CLR_BIT(PORTC,PC1);
			_delay_ms(250);



		}

	}



}






void SsdInit(void)
{
	SET_BIT(DDRC,PC6);
	SET_BIT(DDRC,PC7);

	DDRA = 0b11111110;
}

void SsdDisplay(u8 number)
{
	u8 seven_seg[10]={0b01111110,0b00001100,0b10110110,
			          0b10011110,0b11001100,0b11011010,
			          0b11111010,0b00001110,0b11111110,
					  0b11011110};
	u8 i;
	u8 ones = number%10;
	u8 tens = number/10;

	for(i=0;i<185;i++)
	{
		SET_BIT(PORTC,PC6);
	    CLR_BIT(PORTC,PC7);
		PORTA = seven_seg[ones];
	    _delay_ms(5);
	    SET_BIT(PORTC,PC7);
	    CLR_BIT(PORTC,PC6);
		PORTA = seven_seg[tens];
		_delay_ms(5);
		CLR_BIT(PORTC,PC6);
		CLR_BIT(PORTC,PC7);
	}
}

void SsdCountUp(u8 number)
{
	u8 i;
	for(i=0;i<=number;i++)
	{
		SsdDisplay(i);

	}
}
void SsdCountDown(u8 number)
{
	s8 i;
	for(i=number;i>=0;i--)
	{
		SsdDisplay(i);

	}
}

