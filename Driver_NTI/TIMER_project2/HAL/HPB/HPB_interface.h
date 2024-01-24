/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : HAL         *********************/
/******************    SWC(Driver): HPB         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef HPB_INTERFACE_H
#define HPB_INTERFACE_H

#define HIGH	1
#define LOW		0

typedef enum{
	ACTIVE_LOW =0,
	ACTIVE_HIGH =1
}PB_Active_t;

typedef enum{
	NOT_PRESSED = 0,
	PRESSED = 1
}State_t;

typedef struct{

	u8 PB_port;
	u8 PB_Pin;
	PB_Active_t PB_mode;
}PB_t;


void PB_voidInit(const PB_t* ptr_PB);
void PB_voidReadState(const PB_t* ptr_PB, State_t* pstate);

#endif
