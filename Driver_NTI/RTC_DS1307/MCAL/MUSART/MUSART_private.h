/*
 * USART_private.h
 *
 * Created: 24/09/2023 3:13:11 AM
 * Author: hassan ehab
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/****************** Registers **********************/

#define UDR               *((volatile u8*)0x2C) // USART I/O Data Register

#define UCSRA             *((volatile u8*)0x2B) // USART Control and Status Register A
#define UCSRA_RXC         7 // USART Receive Complete Flag
#define UCSRA_TXC         6 // USART Transmit Complete Flag
#define UCSRA_UDRE        5 // USART Data Register Empty Flag
#define UCSRA_FE          4 // Frame Error Flag
#define UCSRA_DOR         3 // Data OverRun Flag
#define UCSRA_PE          2 // Parity Error Flag
#define UCSRA_U2X         1 // Double Transmission Speed
#define UCSRA_MPCM        0 // Multi-processor Communication Mode

#define UCSRB             *((volatile u8*)0x2A) // USART Control and Status Register B
#define UCSRB_RXCIE       7 // USART RX Complete Interrupt Enable
#define UCSRB_TXCIE       6 // USART TX Complete Interrupt Enable
#define UCSRB_UDRIE       5 // USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN        4 // Receiver Enable
#define UCSRB_TXEN        3 // Transmitter Enable
#define UCSRB_UCSZ2       2 // Character Size (Bit 2)
#define UCSRB_RXB8        1 // Receive Data Bit 9 (used when UCSZ2 = 1)
#define UCSRB_TXB8        0 // Transmit Data Bit 8 (used when UCSZ2 = 1)

#define UCSRC             *((volatile u8*)0x40) // USART Control and Status Register C
#define UCSRC_URSEL        7 // Register Select
#define UCSRC_UMSEL        6 // USART Mode Select
#define UCSRC_UPM1         5 // Parity Mode Bit 1
#define UCSRC_UPM0         4 // Parity Mode Bit 0
#define UCSRC_USBS         3 // Stop Bit Select
#define UCSRC_UCSZ1        2 // Character Size Bit 1
#define UCSRC_UCSZ0        1 // Character Size Bit 0
#define UCSRC_UCPOL        0 // Clock Polarity


#define UBRRL             *((volatile u8*)0x29) // USART Baud Rate Register (Low Byte)
#define UBRRH             *((volatile u8*)0x40) // USART Baud Rate Register (High Byte)

/************ USART Interrupt Vectors Number ************/
#define USART_RXC_VECTOR    __vector_13
#define USART_UDRE_VECTOR   __vector_14
#define USART_TXC_VECTOR    __vector_15
/********************* ISR Attribute ****************************/
#define ISR_(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)

#endif /* USART_PRIVATE_H_ */
