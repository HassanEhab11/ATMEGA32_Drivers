#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MTWI/MTWI_interface.h"

#include "HEEPROM_private.h"
#include "HEEPROM_interface.h"
#include "HEEPROM_config.h"

/*for debug */
#include "../HCLCD/CLCD_interface.h"
#include <util/delay.h>

// Function to initialize the EEPROM
void EEPROM_Init(void){
	TWI_Init(_100KBPS);

}
TWI_ErrStatus EEPROM_WriteByte(u16 Copy_u16ByteAddress, u8 Copy_u8ByteData){
	TWI_ErrStatus Local_u8Status = 0;

	//step 1 : send Start
	TWI_SendStart();
	//step 2 : check status if not Start Success return false
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != START_ACK)
	{
		Local_u8Status = StartConditionErr;
		return Local_u8Status;
	}
	//step 3 : send address 1010 + E A9 A8 + W
	TWI_SendByte(((EEPROM_SLA_4_MSB )| (Copy_u16ByteAddress>>8)) & (EEPROM_SLA_W ));
	//step 4 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != SLAVE_ADD_AND_WR_ACK)
	{
		Local_u8Status = SlaveAddressWithWriteErr;
		return Local_u8Status;
	}
	//step 5 : send rest of Byte address as data A7 .....A0
	TWI_SendByte((u8)Copy_u16ByteAddress);
	//step 6 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != MSTR_WR_BYTE_ACK)
	{
		Local_u8Status = MasterWriteByteErr;
		return Local_u8Status;
	}
	//step 7 : send Byte to be written
	TWI_SendByte((u8)Copy_u8ByteData);

	//step 8 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != MSTR_WR_BYTE_ACK)
	{
		Local_u8Status = MasterWriteByteErr;
		return Local_u8Status;
	}
	//step 9 : send stop
	TWI_SendStop();

	return NoError;
}
TWI_ErrStatus EEPROM_ReadByte(u16 Copy_u16ByteAddress, u8 *Copy_u8ByteData){

	TWI_ErrStatus Local_u8Status = 0;

	//step 1 : send Start
	TWI_SendStart();

	//step 2 : check status if not Start Success return false
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != START_ACK)
	{
		Local_u8Status = StartConditionErr;
		return Local_u8Status;
	}

	//step 3 : send address 1010 + E A9 A8 + W
	TWI_SendByte(((EEPROM_SLA_4_MSB )| (Copy_u16ByteAddress>>8)) & (EEPROM_SLA_W ));

	//step 4 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != SLAVE_ADD_AND_WR_ACK)
	{
		Local_u8Status = SlaveAddressWithWriteErr;
		return Local_u8Status;
	}

	//step 5 : send rest of Byte address as data A7 .....A0
	TWI_SendByte((u8)Copy_u16ByteAddress);

	//step 6 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != MSTR_WR_BYTE_ACK)
	{
		Local_u8Status = MasterWriteByteErr;
		return Local_u8Status;
	}

	//step 7 : send Repeated Start
	TWI_SendStart();

	//step 8 : check status
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != REP_START_ACK)
	{
		Local_u8Status = RepeatedStartErr;
		return Local_u8Status;
	}

	//step 9 : send address 1010 + 000 + R
	TWI_SendByte(((EEPROM_SLA_4_MSB )| (Copy_u16ByteAddress>>8)) | (EEPROM_SLA_R ));

	//step 10 : check status TWI_MR_SLA_R_ACK
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != SLAVE_ADD_AND_RD_ACK)
	{
		Local_u8Status = SlaveAddressWithReadErr;
		return Local_u8Status;
	}

	//step 11 : read data
	TWI_ReceiveByteWithACK(Copy_u8ByteData);

	//step 12 : check status TWI_MR_DATA_ACK
	TWI_GetStatus(&Local_u8Status);
	if(Local_u8Status != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_u8Status = MasterReadByteWithAckErr;
		return Local_u8Status;
	}

	//step 13 : send Stop
	TWI_SendStop();

	return NoError;


}
