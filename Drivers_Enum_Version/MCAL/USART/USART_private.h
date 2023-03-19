/*
 * USART_private.h
 *
 * Created: 2/17/2023 3:13:11 AM
 *  Author: hassa
 */ 


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_



/****************** Registers **********************/


#define  UDR               *((volatile u8*)0x2C)

#define  UCSRA             *((volatile u8*)0x2B)
#define  UCSRA_RXC         7
#define  UCSRA_TXC         6
#define  UCSRA_UDRE        5
#define  UCSRA_FE          4
#define  UCSRA_DOR         3
#define  UCSRA_PE          2
#define  UCSRA_U2X         1
#define  UCSRA_MPCM        0

#define  UCSRB             *((volatile u8*)0x2A)
#define  UCSRB_RXIC        7
#define  UCSRB_TXIC        6
#define  UCSRB_UDRIE       5
#define  UCSRB_RXEN        4
#define  UCSRB_TXEN        3
#define  UCSRB_UCSZ2       2
#define  UCSRB_RXB2        1
#define  UCSRB_TXB8        0

#define  UCSRC             *((volatile u8*)0x40)
#define  UCSRC_URSEL        7
#define  UCSRC_UMSEL        6
#define  UCSRC_UPM1         5
#define  UCSRC_UPM0         4
#define  UCSRC_USBS         3
#define  UCSRC_UCSZ1        2
#define  UCSRC_UCSZ0        1
#define  UCSRC_UCPOL        0

#define  UBRRL             *((volatile u8*)0x29)
#define  UBRRH             *((volatile u8*)0x40)

/************ USART Interrupt Vectors Number ************/
#define	USART_RXC_VECTOR		__vector_13
#define	USART_UDRE_VECTOR		__vector_14
#define	USART_TXC_VECTOR		__vector_15
/********************* ISR Attribute ****************************/
#define ISR_(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)



#endif /* USART_PRIVATE_H_ */