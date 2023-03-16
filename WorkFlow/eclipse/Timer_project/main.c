/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: hassa
 */


#include <avr/io.h>
#include<util/delay.h>
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "PORT_interface.h"
#include "KPD_interface.h"
#include "PB_interface.h"


void main (void)
{
	u8 arrow[8] ={0b00000100,0b00001110,0b00010101,0b00000100,0b00000100,0b00000100,0b00000100,0b00000000};
	u8 shape1[8] ={0b00001110,0b00010001,0b00010001,0b00010001,0b00001110,0b00000100,0b00000100,0b00000100};
	u8 shape2[8] ={0b00011111,0b00000100,0b00000100,0b00000100,0b00000100,0b00001010,0b00010001,0b00000000};
	u8 Local_H_1=0;
	u8 Local_H_2=0;
	u8 Local_M_1=0;
	u8 Local_M_2=0;
	u8 Local_S_1=0;
	u8 Local_S_2=0;




	PORT_VoidInit();
	CLCD_voidInit();
	CLCD_VoidWriteNumber(Local_H_1);
	CLCD_VoidWriteNumber(Local_H_1);
	CLCD_voidSendData(':');
	CLCD_VoidWriteNumber(Local_M_1);
	CLCD_VoidWriteNumber(Local_M_1);
	CLCD_voidSendData(':');
	CLCD_VoidWriteNumber(Local_S_1);
	CLCD_VoidWriteNumber(Local_S_1);
	CLCD_voidWriteSpecialCharacter(arrow,1,1,0);


	while (1)
	{

			do
			{
				if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN2)==1)
				{
					if (Local_H_1>=9)
					{
						_delay_ms(150);
						Local_H_1=0;
						CLCD_voidGoToXY(0,0);
						CLCD_VoidWriteNumber(Local_H_1);
					}
					else
					{
						_delay_ms(150);
						Local_H_1++;

						CLCD_voidGoToXY(0,0);
						CLCD_VoidWriteNumber(Local_H_1);
					}


				}
				else if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN3)==1)
				{
					if (Local_H_1<=0)
					{
						_delay_ms(150);
						Local_H_1=9;
						CLCD_voidGoToXY(0,0);
						CLCD_VoidWriteNumber(Local_H_1);

					}
					else
					{
						_delay_ms(200);

						Local_H_1--;
						CLCD_voidGoToXY(0,0);

						CLCD_VoidWriteNumber(Local_H_1);

					}

				}

			}
			while(PB_u8GetState(DIO_u8PORTD,DIO_u8PIN4)!=1);


			CLCD_voidGoToXY(1,0);
			CLCD_voidSendData(' ');
			CLCD_voidWriteSpecialCharacter(arrow,1,1,1);


			do
			{
				if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN2)==1)
				{
					if (Local_H_2>=9)
					{
						_delay_ms(150);
						Local_H_2=0;
						CLCD_voidGoToXY(0,1);
						CLCD_VoidWriteNumber(Local_H_2);
					}
					else
					{
						_delay_ms(150);
						Local_H_2++;

						CLCD_voidGoToXY(0,1);
						CLCD_VoidWriteNumber(Local_H_2);
					}


				}
				else if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN3)==1)
				{
					if (Local_H_2<=0)
					{
						_delay_ms(150);
						Local_H_2=9;
						CLCD_voidGoToXY(0,1);
						CLCD_VoidWriteNumber(Local_H_2);

					}
					else
					{
						_delay_ms(200);

						Local_H_2--;
						CLCD_voidGoToXY(0,1);

						CLCD_VoidWriteNumber(Local_H_2);

					}

				}

			}
			while(PB_u8GetState(DIO_u8PORTD,DIO_u8PIN4)!=1);

			CLCD_voidGoToXY(1,1);
			CLCD_voidSendData(' ');
			CLCD_voidWriteSpecialCharacter(arrow,1,1,3);

			/**************************** Minute ****************************/

			do
			{
				if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN2)==1)
				{
					if (Local_M_1>=9)
					{
						_delay_ms(150);
						Local_M_1=0;
						CLCD_voidGoToXY(0,3);
						CLCD_VoidWriteNumber(Local_M_1);
					}
					else
					{
						_delay_ms(150);
						Local_M_1++;

						CLCD_voidGoToXY(0,3);
						CLCD_VoidWriteNumber(Local_M_1);
					}


				}
				else if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN3)==1)
				{
					if (Local_M_1<=0)
					{
						_delay_ms(150);
						Local_M_1=9;
						CLCD_voidGoToXY(0,3);
						CLCD_VoidWriteNumber(Local_M_1);

					}
					else
					{
						_delay_ms(200);

						Local_M_1--;
						CLCD_voidGoToXY(0,3);

						CLCD_VoidWriteNumber(Local_M_1);

					}

				}

			}
			while(PB_u8GetState(DIO_u8PORTD,DIO_u8PIN4)!=1);


			CLCD_voidGoToXY(1,3);
			CLCD_voidSendData(' ');
			CLCD_voidWriteSpecialCharacter(arrow,1,1,4);

			do
			{
				if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN2)==1)
				{
					if (Local_M_2>=9)
					{
						_delay_ms(150);
						Local_M_2=0;
						CLCD_voidGoToXY(0,4);
						CLCD_VoidWriteNumber(Local_M_2);
					}
					else
					{
						_delay_ms(150);
						Local_M_2++;

						CLCD_voidGoToXY(0,4);
						CLCD_VoidWriteNumber(Local_M_2);
					}


				}
				else if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN3)==1)
				{
					if (Local_M_2<=0)
					{
						_delay_ms(150);
						Local_M_2=9;
						CLCD_voidGoToXY(0,4);
						CLCD_VoidWriteNumber(Local_M_2);

					}
					else
					{
						_delay_ms(200);

						Local_M_2--;
						CLCD_voidGoToXY(0,4);

						CLCD_VoidWriteNumber(Local_M_2);

					}

				}

			}
			while(PB_u8GetState(DIO_u8PORTD,DIO_u8PIN4)!=1);

			CLCD_voidGoToXY(1,4);
			CLCD_voidSendData(' ');
			CLCD_voidWriteSpecialCharacter(arrow,1,1,6);

			/**************************** Second ****************************/

			do
			{
				if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN2)==1)
				{
					if (Local_S_1>=9)
					{
						_delay_ms(150);
						Local_S_1=0;
						CLCD_voidGoToXY(0,6);
						CLCD_VoidWriteNumber(Local_S_1);
					}
					else
					{
						_delay_ms(150);
						Local_S_1++;

						CLCD_voidGoToXY(0,6);
						CLCD_VoidWriteNumber(Local_S_1);
					}


				}
				else if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN3)==1)
				{
					if (Local_S_1<=0)
					{
						_delay_ms(150);
						Local_S_1=9;
						CLCD_voidGoToXY(0,6);
						CLCD_VoidWriteNumber(Local_S_1);

					}
					else
					{
						_delay_ms(200);

						Local_S_1--;
						CLCD_voidGoToXY(0,6);

						CLCD_VoidWriteNumber(Local_S_1);

					}

				}

			}
			while(PB_u8GetState(DIO_u8PORTD,DIO_u8PIN4)!=1);


			CLCD_voidGoToXY(1,6);
			CLCD_voidSendData(' ');
			CLCD_voidWriteSpecialCharacter(arrow,1,1,7);

			do
			{
				if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN2)==1)
				{
					if (Local_S_2>=9)
					{
						_delay_ms(150);
						Local_S_2=0;
						CLCD_voidGoToXY(0,7);
						CLCD_VoidWriteNumber(Local_S_2);
					}
					else
					{
						_delay_ms(150);
						Local_S_2++;

						CLCD_voidGoToXY(0,7);
						CLCD_VoidWriteNumber(Local_S_2);
					}


				}
				else if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN3)==1)
				{
					if (Local_S_2<=0)
					{
						_delay_ms(150);
						Local_S_2=9;
						CLCD_voidGoToXY(0,7);
						CLCD_VoidWriteNumber(Local_S_2);

					}
					else
					{
						_delay_ms(200);

						Local_S_2--;
						CLCD_voidGoToXY(0,7);

						CLCD_VoidWriteNumber(Local_S_2);

					}

				}

			}
			while(PB_u8GetState(DIO_u8PORTD,DIO_u8PIN4)!=1);

			CLCD_voidGoToXY(1,7);
			CLCD_voidSendData(' ');
			CLCD_voidWriteSpecialCharacter(arrow,1,1,0);

			_delay_ms(1000);
		if (PB_u8GetState(DIO_u8PORTD,DIO_u8PIN5)==1)
		{

		/* second timer */

		if (Local_S_2>0)
		{
			do
			{
				_delay_ms(1000);
				Local_S_2--;
				CLCD_voidGoToXY(0,7);
				CLCD_VoidWriteNumber(Local_S_2);

			}
			while (Local_S_2!=0);
		}

		if (Local_S_1>0)
		{
			do
			{
				_delay_ms(1000);
				Local_S_1--;
				CLCD_voidGoToXY(0,6);
				CLCD_VoidWriteNumber(Local_S_1);

			}
			while (Local_S_1!=0);
		}

		/* Minute timer */

		if (Local_M_2>0)
		{
			do
			{
				_delay_ms(1000);
				Local_M_2--;
				CLCD_voidGoToXY(0,4);
				CLCD_VoidWriteNumber(Local_M_2);

			}
			while (Local_M_2!=0);
		}
		if (Local_M_1>0)
		{
			do
			{
				_delay_ms(1000);
				Local_M_1--;
				CLCD_voidGoToXY(0,3);
				CLCD_VoidWriteNumber(Local_M_1);

			}
			while (Local_M_1!=0);
		}

		/* Hour timer */

		if (Local_H_2>0)
		{
			do
			{
				_delay_ms(1000);
				Local_H_2--;
				CLCD_voidGoToXY(0,1);
				CLCD_VoidWriteNumber(Local_H_2);

			}
			while (Local_H_2!=0);
		}
		if (Local_H_1>0)
		{
			do
			{
				_delay_ms(1000);
				Local_H_1--;
				CLCD_voidGoToXY(0,0);
				CLCD_VoidWriteNumber(Local_H_1);

			}
			while (Local_H_1!=0);
		}

		CLCD_voidGoToXY(1,5);
		CLCD_voidSendString("Time OUT");
		CLCD_voidWriteSpecialCharacter(shape1,2,0,14);
		CLCD_voidWriteSpecialCharacter(shape2,3,1,14);

		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);


		}




	}


}

