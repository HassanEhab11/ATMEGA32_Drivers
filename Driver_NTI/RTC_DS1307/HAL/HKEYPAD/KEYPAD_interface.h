/*
 * KEYPAD_interface.h
 *
 * Created: 1/27/2023 12:51:22 AM
 *  Author: hassa
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/*
 *	@brief	: KeyPad Get Pressed Key
 *	@retval	: Pressed Key  
 *	@param	: Void No Parameter Needed
 */

void HKPD_u8GetPressedKey(u8 * pPressedKey);
/**/


void HKPD_voidInit(void);

//void H_KEYPAD_u8_getPressedKey(u8 * pPressedKey);



#endif /* KEYPAD_INTERFACE_H_ */
