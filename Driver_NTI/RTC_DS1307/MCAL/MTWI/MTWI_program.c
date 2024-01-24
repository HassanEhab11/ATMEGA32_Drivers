#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "MTWI_private.h"
#include "MTWI_interface.h"
#include "MTWI_config.h"



// Function to initialize the TWI
void TWI_Init(u8 Copy_u8RequiredFreq) {

	/* Set clock frequency to 400kbps or 100kbps  */
	if(	Copy_u8RequiredFreq	== _400KBPS){
		TWBR = FREQ_400KBPS;

	}
	else if	(Copy_u8RequiredFreq	== _100KBPS){
		TWBR = FREQ_100KBPS;

	}
	else{
		// nothing
	}
	// Set prescaler and enable TWI
	TWSR = 0;
	// TWI EN
	TWCR = (1 << TWEN);
}

// Function to send a start condition
void TWI_SendStart() {
	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
}

// Function to send a stop condition
void TWI_SendStop() {
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
	while (TWCR & (1 << TWSTO));
}

// Function to send a byte
void TWI_SendByte(u8 data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

// Function to receive a byte with ACK
void TWI_ReceiveByteWithACK(u8* Copy_u8RecievedData) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA); //Bit 6 – TWEA: TWI Enable Acknowledge Bit
	while (!(TWCR & (1 << TWINT)));
	*Copy_u8RecievedData = TWDR;
}

// Function to receive a byte with NACK
void TWI_ReceiveByteWithNACK(u8* Copy_u8RecievedData) {
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	*Copy_u8RecievedData = TWDR;
}

// Function to get the status of the TWI
void TWI_GetStatus(u8 *Copy_u8Status) {
	*Copy_u8Status = TWSR & 0xF8;		//	0b1111 1000
}
