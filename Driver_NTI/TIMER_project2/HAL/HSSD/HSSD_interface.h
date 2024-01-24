/*
 * SSD_interface.h
 *
 * Created: 1/28/2023 2:20:16 AM
 *  Author: hassa
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

error_state_t HSSD_Init(void);
/*
 *	@brief	: SSD Display Number With Blinking
 *	@retval	: Error State [0 -> SSD Is Not OK, 1 -> SSD Is OK]  
 *	@param	: Copy_u8Num -> Number Needed To Display In SSD
 */

error_state_t HSSD_DisplayBlink(u32 Copy_u8Num);
/*
 *	@brief	: SSD Display Number !! This Function Use While(1) Loop
 *	@retval	: Error State [0 -> SSD Is Not OK, 1 -> SSD Is OK]  
 *	@param	: Copy_u8Num -> Number Needed To Display In SSD
 */

error_state_t HSSD_DisplayNum(u8 Copy_u8Num);



#endif /* SSD_INTERFACE_H_ */
