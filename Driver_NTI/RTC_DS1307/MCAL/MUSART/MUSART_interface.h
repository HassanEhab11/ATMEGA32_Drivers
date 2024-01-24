#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

// Data Length Macro
#define UART_WORD_LENGTH_5_BIT			0b000
#define UART_WORD_LENGTH_6_BIT			0b001
#define UART_WORD_LENGTH_7_BIT			0b010
#define UART_WORD_LENGTH_8_BIT			0b011
#define UART_WORD_LENGTH_RESERVED_1		0b100
#define UART_WORD_LENGTH_RESERVED_2		0b101
#define UART_WORD_LENGTH_RESERVED_3		0b110
#define UART_WORD_LENGTH_9_BIT			0b111
// Baud Rate Macro
#define USART_BAUD_RATE_16MHZ_2400		416
#define USART_BAUD_RATE_16MHZ_4800		207
#define USART_BAUD_RATE_16MHZ_9600		103
#define USART_BAUD_RATE_16MHZ_14400		68
#define USART_BAUD_RATE_16MHZ_19200		51
#define USART_BAUD_RATE_16MHZ_28800		34
#define USART_BAUD_RATE_16MHZ_38400		25
#define USART_BAUD_RATE_16MHZ_57600		16
#define USART_BAUD_RATE_16MHZ_76800		12
#define USART_BAUD_RATE_16MHZ_115200	8
#define USART_BAUD_RATE_16MHZ_230400	3
#define USART_BAUD_RATE_16MHZ_250000	3
#define USART_BAUD_RATE_16MHZ_500000	1
#define USART_BAUD_RATE_16MHZ_1000000	0

// Parity Bits Macros
#define USART_PARITY_NONE 0
#define USART_PARITY_ODD 1
#define USART_PARITY_EVEN 2

// Stop Bits Macros
#define USART_STOP_BITS_1 1
#define USART_STOP_BITS_2 2


// UART Configuration structure
typedef struct {
    u32 BaudRate;    // Baud rate for UART communication.
    u8 WordLength;   // Word length, typically 8 bits.
    u8 ParityBits;   // Number of parity bits (0 for no parity, 1 for odd, 2 for even).
    u8 StopBits;     // Number of stop bits (usually 1 or 2).
} MUSART_Config;

/**
 * Initialize UART (MUSART) with the provided configuration.
 *
 * @param config: Pointer to the UART configuration structure.
 */
void MUSART_Init(const MUSART_Config* config);

/**
 * Send a single byte over UART (MUSART).
 *
 * @param data: The byte to be sent.
 */
void MUSART_sendByte(u8 data);

/**
 * Send a null-terminated string over UART (MUSART).
 *
 * @param str: Pointer to the string to be sent.
 */
void MUSART_sendString(const char* str);

/**
 * Receive a byte synchronously using polling with a timeout.
 *
 * @param timeout_ms: The timeout value in milliseconds.
 *
 * @return u8: The received byte, or a special value to indicate a timeout.
 */
u8 MUSART_receiveByteSynchNonBlocking(u32 timeout_ms);

/**
 * Configure UART (MUSART) Rx for asynchronous reception with a callback function.
 *
 * @param callback: Pointer to the callback function to be executed when a byte is received.
 */
void MUSART_receiveByteAsynchCallBack(void (*callback)(u8));

#endif /* UART_INTERFACE_H_ */
