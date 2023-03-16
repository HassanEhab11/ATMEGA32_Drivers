///*******************************************************************/
///********************************************************************/
///******************    Author     : Hassan Ehab *********************/
///******************    Layer      : MCAL        *********************/
///******************    SWC(Driver): DIO (prog.c)*********************/
///******************    Version    : 1.00        *********************/
///********************************************************************/
///********************************************************************/
////#include <avr/io.h>
//
////#include<util/delay.h>
//#include "STD_TYPES.h"
//#include "DIO_interface.h"
//#include "LED_interface.h"
//
//
//void main(void)
//{
//	/* Define C0 As Output */
////	DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
////
////
////	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
////	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
////	/*ACTIVATE PULLUP */
////	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);
////	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
//
//
//
//	while(1)
//	{
//		LED_t led ={DI
//
////		u8 x =1,y=1;
////		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&x);
////		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,&y);
////
////		/*Define C0 As HIGH */
////		if(x == 0)
////		{
////			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
////			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
////
////
////
////		}
////		else if (y==0)
////		{
////			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
////			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
////
////
////		}
//
////		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
////		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
////
//    // _delay_ms(1000);
////
////		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
////		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
// //     _delay_ms(1000);
//
//	}
//
//}
