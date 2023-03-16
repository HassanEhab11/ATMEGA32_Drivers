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
	PORT_VoidInit();
	SPI_voidMasterInit();



	while(1)
	{
		SPI_u8Transceive(1);
		_delay_ms(10);

	}
}

