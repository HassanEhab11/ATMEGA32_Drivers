#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
void INT0_ISR(void);
void INT1_ISR(void);


void main(void)
{
	PORT_VoidInit();
	EXTI_VoidInt0Init();
	EXTI_u8Int0SetCallBack(&INT0_ISR);

	EXTI_VoidInt1Init();
	EXTI_u8Int1SetCallBack(&INT1_ISR);

	GIE_VoidEnable();
	while(1)
	{

	}
}
void INT0_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
}
void INT1_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);

}
