/*
 * USART_interface.h
 *
 * Created: 2/17/2023 3:12:34 AM
 *  Author: hassa
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);

void USART_voidSend(u8 Copy_u8Data);
u8 USART_voidReceive(void);
void USART_voidSendString(const char *Copy_u8Data);

/*error_state_t USART_SendCharSynch(u8 Copy_u8Data);
error_state_t USART_SendCharAsynch(u8 Copy_u8Data, void (*NotificationFunc)(void));

error_state_t USART_SendStringSynch(char *Copy_pString);
error_state_t USART_SendStringAsynch(char *Copy_pString, void (*NotificationFunc)(void));

error_state_t USART_ResieveCharSynch(u8 *Copy_pu8RecievedData);
error_state_t USART_ResieveCharAsynch(u8 *Copy_pu8RecievedData, void (*NotificationFunc)(void));

error_state_t USART_ResieveBufferSynch(u8 *Copy_pu8RecievedBuffer, u8 Copy_u8BufferSize);
error_state_t USART_ResieveBufferAsynch(u8 *Copy_pu8RecievedBuffer, u8 Copy_u8BufferSize, void (*NotificationFunc)(void));

*/

#endif /* USART_INTERFACE_H_ */