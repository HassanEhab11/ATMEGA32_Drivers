/*
 * CLCD_interface.h
 *
 * Created: 1/26/2023 1:51:27 AM
 *  Author: Hassan Ehab
 */ 


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_



#define _4_BIT_MODE     1
#define _8_BIT_MODE     2

#define ATMEGA_KIT     1
#define PROTEUS        2


/*
 *	@brief	: Initialized CLCD
 *	@retval	: Error State [0 -> CLCD_NOK ,1 -> CLCD_OK]
 *	@param	: No Parameter
 */
error_state_t HCLCD_Init(void);
/*
 *	@brief	: CLCD Send Command
 *	@retval	: Error State [0 -> CLCD_NOK ,1 -> CLCD_OK]
 *	@param	: Command Need To Send
 */
error_state_t HCLCD_SendCommand(u8 Copy_u8Command);
/*
 *	@brief	: CLCD Send Data
 *	@retval	: Error State [0 -> CLCD_NOK ,1 -> CLCD_OK]
 *	@param	: Data Need To Send
 */
error_state_t HCLCD_SendData(u8 Copy_u8Data);
/*
 *	@brief	: CLCD Clear Screen
 *	@retval	: Error State [0 -> CLCD_NOK ,1 -> CLCD_OK]
 *	@param	: No Parameter
 */
error_state_t HCLCD_Clear(void);
/*
 *	@brief	: CLCD Send String
 *	@retval	: Error State [0 -> CLCD_NOK ,1 -> CLCD_OK]
 *	@param	: String Needed To Send [Pointer to char]
 */
error_state_t HCLCD_SendString(const char *Copy_pu8String);
/*
 *	@brief	: CLCD Send Number
 *	@retval	: Error State [0 -> CLCD_NOK ,1 -> CLCD_OK]
 *	@param	: Number Needed To Send [Pointer to char]
 */
error_state_t HCLCD_SendNumber(f32 Copy_u32Number);
/*
 *	@brief	: CLCD Set Position
 *	@retval	: Error State [0 -> CLCD_NOK ,1 -> CLCD_OK]
 *	@param	: Copy_u8Xpos -> Row Position
 *	@param	: Copy_u8Ypos -> Col Position
 */
error_state_t HCLCD_GoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos);

error_state_t HCLCD_WriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);


void CLCD_voidWriteFloatNumber(f32 Copy_f32FloatNumber );


#endif /* CLCD_INTERFACE_H_ */
