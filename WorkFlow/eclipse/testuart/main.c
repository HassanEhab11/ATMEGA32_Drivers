#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#define F_CPU 8000000UL			/* Define frequency here its 8MHz */

//#include "UART_register.h"
//#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


#define LED PORTC		/* connected LED on PORT pin */
void UART_init(long USART_BAUDRATE);
unsigned char UART_RxChar();
void UART_TxChar(char ch);
void UART_SendString(char *str);
void main(void)
{
	char Data_in;
	DDRB = 0xff;		/* make PORT as output port */
	UART_init(9600);	/* initialize USART with 9600 baud rate */
	LED = 0;

	while(1)
	{
		Data_in = UART_RxChar();	/* receive data from Bluetooth device*/
		if(Data_in =='1')
		{
			LED |= (1<<PC0);	/* Turn ON LED */
			UART_SendString("LED_ON");/* send status of LED i.e. LED ON */

		}
		else if(Data_in =='2')
		{
			LED &= ~(1<<PC0);	/* Turn OFF LED */
			UART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
		}
		else
			UART_SendString("Select proper option"); /* send message for selecting proper option */
	}
}
void UART_init(long USART_BAUDRATE)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
	UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}

unsigned char UART_RxChar()
{
	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	return(UDR);			/* Return the byte*/
}

void UART_TxChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
	UDR = ch ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}
