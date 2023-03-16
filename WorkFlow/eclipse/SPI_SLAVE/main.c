/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: hassa
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
#include "DIO_interface.h"

#include "PORT_interface.h"
#include "SPI_interface.h"


void main(void)
{
	u8 Local_u8ReceivedData;
	PORT_VoidInit();
	SPI_voidSlaveInit();



	while(1)
	{
		Local_u8ReceivedData = SPI_u8Transceive(10);
		_delay_ms(10);
		if (Local_u8ReceivedData == 1)
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}

	}
}

