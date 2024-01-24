#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

/****************** Constants **********************/
// Define TWI Status Codes
#define START 0x08
#define MT_SLA_ACK 0x18
#define MT_DATA_ACK 0x28

// Define Slave Address
#define SLA_W 0x42  // Replace with your slave device address

#define _100KBPS    1
#define _400KBPS    2


#define START_ACK                 0x08            /* Start has been sent */
#define REP_START_ACK             0x10            /* Repeated Start */
#define SLAVE_ADD_AND_WR_ACK      0x18            /* Master Transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK      0x40            /* Master Transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK          0x28            /* Master transmit data ACK*/
#define MSTR_RD_BYTE_WITH_ACK     0x50            /* Master received data with ACK*/
#define MSTR_RD_BYTE_WITH_NACK    0x58            /* Master received data with not ACK*/
#define MSTR_WR_BYTE_WITH_NACK    0x58            /*Master transmit data NACK*/


// Function prototypes
void TWI_Init(u8 Copy_u8RequiredFreq);
void TWI_SendStart();
void TWI_SendStop();
void TWI_SendByte(u8 data);
void TWI_ReceiveByteWithACK(u8* Copy_u8RecievedData);
void TWI_ReceiveByteWithNACK(u8* Copy_u8RecievedData);
void TWI_GetStatus(u8 *Copy_u8Status);

#endif /* TWI_INTERFACE_H_ */
