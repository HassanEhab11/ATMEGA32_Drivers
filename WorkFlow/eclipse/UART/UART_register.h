/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): UART        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

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




#endif
/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): UART        *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

//#ifndef UART_REGISTER_H_
//#define UART_REGISTER_H_
//
//#define  UDR               *((volatile u8*)0x2C)
//
//#define  UCSRA             *((volatile u8*)0x2B)
//#define  RXC         7
//#define  TXC         6
//#define  UDRE        5
//#define  FE          4
//#define  DOR         3
//#define  PE          2
//#define  U2X         1
//#define  MPCM        0
//
//#define  UCSRB             *((volatile u8*)0x2A)
//#define  RXIC        7
//#define  TXIC        6
//#define  UDRIE       5
//#define  RXEN        4
//#define  TXEN        3
//#define  UCSZ2       2
//#define  RXB2        1
//#define  TXB8        0
//
//#define  UCSRC             *((volatile u8*)0x40)
//#define  URSEL        7
//#define  UMSEL        6
//#define  UPM1         5
//#define  UPM0         4
//#define  USBS         3
//#define  UCSZ1        2
//#define  UCSZ0        1
//#define  UCPOL        0
//
//#define  UBRRL             *((volatile u8*)0x29)
//#define  UBRRH             *((volatile u8*)0x40)
//
//
//
//
//#endif
