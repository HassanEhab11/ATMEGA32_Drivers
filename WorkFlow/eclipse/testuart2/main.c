
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_interface.h"

void main(void)
{
uint8 Data[5]={'h','e','l','l','\n'};
USART_voidInit();

USART_voidSensStringBlocking(Data);


	while(1)
	{
		//USART_voidSensByteBlocking(uint16 Copy_u16Data);


		//uint16 USART_u16ReadByteBlocking(void);

	}
}

