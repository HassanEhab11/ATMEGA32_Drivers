#include <avr/io.h>
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BITMATH.h"

void SsdInit(void);
void SsdDisplay(u8 number);
void SsdIncDec(u8 number);

void SsdDisplaynum(u8 number);
void SsdUpDown(void);

void SsdCountUp(u8 number);
void SsdCountDown(u8 number);




void main(void)
{
	SsdInit();
//	SET_BIT(DDRC,PC0);
//	SET_BIT(DDRC,PC1);
//	SET_BIT(DDRC,PC2);
	DDRD = 0b00;
	PORTD =255;




	while(1)
	{
//		SET_BIT(PORTC,PC0);
//		CLR_BIT(PORTC,PC1);
//
//		SsdCountDown(15);
//		CLR_BIT(PORTC,PC0);
//		SET_BIT(PORTC,PC2);
//		SsdCountDown(3);
//		CLR_BIT(PORTC,PC2);
//		SET_BIT(PORTC,PC1);
//		SsdCountDown(15);
		//SsdDisplaynum(99);
		//SsdUpDown();
		//SsdDisplay(10);
		SsdIncDec(97);


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

void SsdIncDec(u8 number)
{
	u8 seven_seg[10]={0b01111110,0b00001100,0b10110110,
			          0b10011110,0b11001100,0b11011010,
			          0b11111010,0b00001110,0b11111110,
					  0b11011110};

	u8 i,temp;
	temp = number;
	for(;;)
	{
	u8 ones = temp%10;
	u8 tens = temp/10;
	if (GET_BIT(PIND,PD2) == 0)
	{
		//while(GET_BIT(PIND,PD2) == 0);

		_delay_ms(500);
		if(temp>=99)
			{temp=0;}
		else
		temp++;
	}
	if (GET_BIT(PIND,PD3) == 0)
	{
		//while(GET_BIT(PIND,PD3) == 0);
		_delay_ms(500);
		if(temp<=0)
			{temp=99;}
		else
		temp--;
	}

//	for(i=0;i<70;i++)
//	{
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
//}
	}
}

void SsdUpDown(void)
{
	u8 seven_seg[10]={0b01111110,0b00001100,0b10110110,
			          0b10011110,0b11001100,0b11011010,
			          0b11111010,0b00001110,0b11111110,
					  0b11011110};
	u8 i,j=9,x=0;

for(;;){
	for(i=0;i<200;i++)
	{

		SET_BIT(PORTC,PC6);
	    CLR_BIT(PORTC,PC7);
		PORTA = seven_seg[x];
	    _delay_ms(5);
	    SET_BIT(PORTC,PC7);
	    CLR_BIT(PORTC,PC6);
		PORTA = seven_seg[j];
		_delay_ms(5);
		CLR_BIT(PORTC,PC6);
		CLR_BIT(PORTC,PC7);

	}
	if(j==0)
		{
				j=10;
				x=-1;
		}
		j--;
		x++;
}
}

void SsdDisplaynum(u8 number)
{
	u8 seven_seg[10]={0b01111110,0b00001100,0b10110110,
			          0b10011110,0b11001100,0b11011010,
			          0b11111010,0b00001110,0b11111110,
					  0b11011110};

	u8 ones = number%10;
	u8 tens = number/10;

	for(;;)
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

