/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TWI         *********************/
/******************    Version    : 1.00        *********************/
/******************    Date       : 27/10/2022  *********************/
/********************************************************************/
/********************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteWithAckErr,


}TWI_ErrStatus;

/* Pass 0 in the slave address argument if master will not be addressed*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAdress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAdress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

void TWI_SendStopCondition(void);







#endif
