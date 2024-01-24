#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H


// Function to initialize the EEPROM
void EEPROM_Init(void);
/*
 * Function to write a byte to the EEPROM
 * Parameters:
 * - address: The EEPROM address where the data should be written.
 * - data: The data byte to be written.
 * Returns:
 * - u8: An error code indicating the result of the write operation.
 * */
TWI_ErrStatus EEPROM_WriteByte(u16 Copy_u16ByteAddress, u8 Copy_u8ByteData);
/*
 * Function to read a byte from the EEPROM
 * Parameters:
 * - address: The EEPROM address from which the data should be read.
 * - data: A pointer to a variable where the read data will be stored.
 * Returns:
 * - u8: An error code indicating the result of the read operation.
 * */
TWI_ErrStatus EEPROM_ReadByte(u16 Copy_u16ByteAddress, u8 *Copy_u8ByteData);

#endif
