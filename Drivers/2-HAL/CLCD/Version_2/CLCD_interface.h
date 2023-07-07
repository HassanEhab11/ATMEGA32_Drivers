/********************************************************************/
/********************************************************************/
/*************    Author     : Hassan Ehab       ********************/
/*************    Layer      : MCAL              ********************/
/*************    SWC(Driver): CLCD(INTERFACE.h) ********************/
/*************    Version    : 1.00              ********************/
/********************************************************************/
/********************************************************************/

/* preprocessor file guard */
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H


void C_LCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char* Copy_pcString );

void CLCD_voidGoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos);

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);

void CLCD_VoidWriteNumber(f32 Copy_u32Number);
void LCD_enuWriteFloatNum(f32 Copy_f32FloatNum);
void CLCD_voidWriteFloatNumber(f32 Copy_f32FloatNumber );

void CLCD_voidClear();



#define   _4_BIT_MODE      4
#define   _8_BIT_MODE      8







#endif
