/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL         *********************/
/******************    SWC(Driver): HDCMOTOR    *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef HDCMOTOR_INTERFACE_H
#define HDCMOTOR_INTERFACE_H

#define HDCMOTOR_CW			1
#define HDCMOTOR_CCW		2

error_state_t HDCMOTOR_voidInit(void);
error_state_t HDCMOTOR_voidSetDirection(u8);
error_state_t HDCMOTOR_voidSetSpeed(u8);
error_state_t HDCMOTOR_voidStart(void);
error_state_t HDCMOTOR_voidStop(void);

error_state_t HDCMOTOR_MoveCW(u8 Copy_u8DutyCycle);
error_state_t HDCMOTOR_MoveCCW(u8 Copy_u8DutyCycle);



#endif
