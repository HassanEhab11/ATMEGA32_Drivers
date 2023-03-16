/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
/*************    SWC(Driver): SSD (INTERFACE.h) ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H


//typedef struct SSD
//{
//	u8
//
//
//
//
//
//}SSD_t;
//
//u8 SSD_u8Init(SSD_t *ssd);
u8 SSD_u8Init(void);
u8 SSD_u8DisplayBlink(u8 Copy_u8number);
u8 SSD_u8IncDec(u8 Copy_u8number);

u8 SSD_u8Displaynum(u8 Copy_u8number);
u8 SSD_u8UpDown(void);

u8 SSD_u8CountUp(u8 Copy_u8number);
u8 SSD_u8CountDown(u8 Copy_u8number);















#endif
