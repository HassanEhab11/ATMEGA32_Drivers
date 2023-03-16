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
#include "TWI_interface.h"
#include "EEPROM24C08_interface.h"


void main(void)
{
	PORT_VoidInit();
	TWI_voidMasterInit(0);
	u8 var=1;


	EEPROM_SendDataByte(0x50,1);
	_delay_ms(10);

	EEPROM_ReadDataByte(1,&var);

		DIO_u8SetPortValue(DIO_u8PORTA,var);

	while(1)
	{



	}
}

