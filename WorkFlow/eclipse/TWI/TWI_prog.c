/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TWI         *********************/
/******************    Version    : 1.00        *********************/
/******************    Date       : 27/10/2022  *********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_register.h"
#include  "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"

#include "DIO_interface.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/* Set clock frequency to 400kbps*/
	/* Set TWBR to 12 */
	TWBR = 12;

	/* Clear the 2 Bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/* Initialize the node address */
	if (Copy_u8SlaveAddress != 0)
	{
		TWAR = Copy_u8SlaveAddress<<1;
	}
	/* Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/* Initialize the node address */
	TWAR=Copy_u8SlaveAddress<<1;

	/* Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);


}

TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;
	/* Send Start Condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/* Clear the Interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the Interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);
	/* Check the  operation status register*/
	if((TWSR & 0xF8 ) != START_ACK)                              /* 0xF8 == 0b11111000 */
	{
		Local_ErrStatus = StartConditionErr;
	}
	else
	{
		/* Do No Thing*/
	}

	return Local_ErrStatus;

}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;
	/* Send Start Condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/* Clear the Interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the Interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);
	/* Check the  operation status register*/
	if((TWSR & 0xF8 ) != REP_START_ACK )                              /* 0xF8 == 0b11111000 */
	{
		Local_ErrStatus = RepeatedStartErr;
	}
	else
	{
		/* Do No Thing*/
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAdress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/* Clear the Start Condition bit */
	CLR_BIT(TWCR,TWCR_TWSTA);/*******************????????????*******************************/

	/* Set the slave address in the 7 MSB in the data register */
	TWDR = Copy_u8SlaveAdress<<1;
	/*For write request */
	CLR_BIT(TWDR,0);

	/* Clear the Interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the Interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);
	/* Check the  operation status register*/
	if((TWSR & 0xF8 ) != SLAVE_ADD_AND_WR_ACK )                              /* 0xF8 == 0b11111000 */
	{
		Local_ErrStatus = SlaveAddressWithWriteErr;
	}
	else
	{
		/* Do No Thing*/
	}

	return Local_ErrStatus;

}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAdress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/* Clear the Start Condition bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Set the slave address in the 7 MSB in the data register */
	TWDR = Copy_u8SlaveAdress<<1;
	/*For Read request */
	SET_BIT(TWDR,0);

	/* Clear the Interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the Interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);
	/* Check the  operation status register*/
	if((TWSR & 0xF8 ) != SLAVE_ADD_AND_RD_ACK )                              /* 0xF8 == 0b11111000 */
	{
		Local_ErrStatus = SlaveAddressWithReadErr;
	}
	else
	{
		/* Do No Thing*/
	}

	return Local_ErrStatus;

}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;
	/* Write the Data Byte */
	TWDR = Copy_u8DataByte;

	/* Clear the Interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the Interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);
	/* Check the  operation status register*/
	if((TWSR & 0xF8 ) != MSTR_WR_BYTE_ACK )                              /* 0xF8 == 0b11111000 */
	{
		Local_ErrStatus = MasterWriteByteErr;
	}
	else
	{
		/* Do No Thing*/
	}

	return Local_ErrStatus;

}

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;
	/* Enable master generating Acknowledge bit after receiving the data */

	SET_BIT(TWCR,TWCR_TWEA);

	/* Clear the Interrupt flag to start the slave sending data */
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the Interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);
	/* Check the  operation status register*/
	if((TWSR & 0xF8 ) != MSTR_RD_BYTE_WITH_ACK )                              /* 0xF8 == 0b11111000 */
	{
		Local_ErrStatus = MasterReadByteWithAckErr;
	}
	else
	{
		/* Read the received data*/
		*Copy_pu8DataByte =TWDR;
	}

	return Local_ErrStatus;

}

void TWI_SendStopCondition(void)
{
	/* Generate stop condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);
	/* Clear the Interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

}
