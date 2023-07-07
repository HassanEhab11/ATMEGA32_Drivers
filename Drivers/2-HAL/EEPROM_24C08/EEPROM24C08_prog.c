/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): EEPROM24C08 *********************/
/******************    Version    : 1.00        *********************/
/******************    Date       : 1/11/2022   *********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "EEPROM24C08_config.h"
#include "EEPROM24C08_interface.h"
#include "EEPROM24C08_private.h"

void EEPROM_SendDataByte(u8 Copy_u8DataByte,u16 Copy_u16Address)
{
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite((0b10100000)|(A2_PIN<<2)|((Copy_u16Address>>8)&3));
	TWI_MasterWriteDataByte((u8)Copy_u16Address);
	TWI_MasterWriteDataByte(Copy_u8DataByte);
	TWI_SendStopCondition();
}
void EEPROM_ReadDataByte(u16 Copy_u16Address ,u8* Copy_pu8DataByte)
{
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite((0b10100000)|(A2_PIN<<2)|((Copy_u16Address>>8)&3));
	TWI_MasterWriteDataByte((u8)Copy_u16Address);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead((0b10100000)|(A2_PIN<<2)|((Copy_u16Address>>8)&3));
	TWI_MasterReadDataByte(Copy_pu8DataByte);
	TWI_SendStopCondition();



}
