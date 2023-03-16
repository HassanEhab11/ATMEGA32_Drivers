#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCD_interface.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "FreeRTOS.h"
#include "task.h"


void LCD1(void *pv);
void LCD2(void *pv);

//void LED_1(void *pv);
//void LED_2(void *pv);
//void LED_3(void *pv);

void main(void)
{
	PORT_VoidInit();
	CLCD_voidInit();

//	xTaskCreate(&LED_1,NULL,100,NULL,0,NULL);
//	xTaskCreate(&LED_2,NULL,100,NULL,1,NULL);
//	xTaskCreate(&LED_3,NULL,100,NULL,2,NULL);

		xTaskCreate(&LCD1,NULL,250,NULL,1,NULL);
		xTaskCreate(&LCD2,NULL,250,NULL,0,NULL);

	vTaskStartScheduler();



	while(1)
	{

	}
}


void LCD1(void *pv)
{
	while(1)
	{
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("iamtask1");
		vTaskDelay(1000);
	}

}
void LCD2(void *pv)
{
	while(1)
	{
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("iamtask2");
		vTaskDelay(1000);
	}

}
//void LED_1(void *pv)
//{
//	static u8 Local_u8LedState = 0;
//
//	while(1)
//	{TOGGLE_BIT(Local_u8LedState,0);
//	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,Local_u8LedState);
//	vTaskDelay(1000 );
//
//	}
//}
//void LED_2(void *pv)
//{
//	static u8 Local_u8LedState = 0;
//
//	while(1)
//	{TOGGLE_BIT(Local_u8LedState,0);
//	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,Local_u8LedState);
//	vTaskDelay(2000 );
//
//	}}
//
//void LED_3(void *pv)
//{
//	static u8 Local_u8LedState = 0;
//
//	while(1)
//	{TOGGLE_BIT(Local_u8LedState,0);
//	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,Local_u8LedState);
//	vTaskDelay(3000 );
//
//	}
//
//}
