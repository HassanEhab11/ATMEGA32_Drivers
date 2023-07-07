/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab    ******************/
/******************    Layer      : RTOS STACK     ******************/
/******************    SWC(Driver): TIMER          ******************/
/******************    Version    : 1.00           ******************/
/******************    DATE       : 14/11/2022     ******************/
/********************************************************************/
/********************************************************************/
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_



void RTOS_voidStart(u32 Copy_u8SystemTick);

u8 RTOS_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc) (void), u16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);


#endif
