#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
//#include "CLCD_interface.h"

#include "FreeRTOS.h"
#include "task.h"


//void LCD_1(void *pv);
//void LCD_2(void *pv);
void LED_3(void *pv);



void main(void)
{

	PORT_VoidInit();
	//CLCD_voidInit();

//	xTaskCreate(&LCD_1,NULL,250,NULL,0,NULL);
//	xTaskCreate(&LCD_2,NULL,250,NULL,0,NULL);
	xTaskCreate(&LED_3,NULL,100,NULL,3,NULL);
	vTaskStartScheduler();

	while(1)
	{

	}
}

//void LCD_1(void *pv)
//{
//
//	while(1)
//	{
//		CLCD_voidSendString("IAMTASk1");
//		vTaskDelay(1000);
//	}
//
//}
//
//void LCD_2(void *pv)
//{
//
//	while(1)
//	{
//		CLCD_voidSendString("IAMTASk2");
//		vTaskDelay(1000);
//	}
//
//}
void LED_3(void *pv)
{
	static u8 Local_u8LedState = 0;

	while(1)
	{TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,Local_u8LedState);
	vTaskDelay(3000 );

	}

}
