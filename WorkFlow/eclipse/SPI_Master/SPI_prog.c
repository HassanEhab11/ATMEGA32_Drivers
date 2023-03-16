/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): SPI         *********************/
/******************    Version    : 1.00        *********************/
/******************    Date       : 25/10/2022  *********************/
/********************************************************************/
/********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"



void SPI_voidMasterInit(void)
{
	/*  LSB of the data word is transmitted first */
	SET_BIT(SPCR,SPCR_DORD);

	/* Master SPI mode */
	SET_BIT(SPCR,SPCR_MSTR);

	/* Leading Edge On Rising -- Trailing Edge On Falling */
	CLR_BIT(SPCR,SPCR_CPOL);

	/*  Sample On Leading Edge -- Setup On Trailing Edge */
	CLR_BIT(SPCR,SPCR_CPHA);

	/* Clock Rate Select : Divided by 16 */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	/* SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}
void SPI_voidSlaveInit(void)
{
	/*  LSB of the data word is transmitted first */
	SET_BIT(SPCR,SPCR_DORD);

	/* Slave SPI mode */
	CLR_BIT(SPCR,SPCR_MSTR);

	/* Leading Edge On Rising -- Trailing Edge On Falling */
	CLR_BIT(SPCR,SPCR_CPOL);

	/*  Sample On Leading Edge -- Setup On Trailing Edge */
	CLR_BIT(SPCR,SPCR_CPHA);


	/* SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}
u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	/* Send the data*/
	SPDR = Copy_u8Data;
	/* Wait (busy waiting) until transfer complete */
	while (GET_BIT(SPSR,SPSR_SPIF) == 1);
	/* Get the exchanged data*/
	return SPDR;

}
