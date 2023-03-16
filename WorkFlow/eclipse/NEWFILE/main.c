#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"

#include "FreeRTOS.h"
#include "task.h"


void LCD1(void *pv);
void LCD2(void *pv);

void main(void)
{
	PORT_VoidInit();
	CLCD_voidInit();

	xTaskCreate(&LCD1,NULL,250,NULL,0,NULL);
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
		CLCD_voidSendString("IAMTASK1");
		vTaskDelay(1000);
	}

}
void LCD2(void *pv)
{
	while(1)
	{
		CLCD_voidSendString("IAMTASK2");
		vTaskDelay(1000);
	}


}
