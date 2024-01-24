/*
 * EXTI_interface.h
 *
 * Created: 1/28/2023 4:05:51 AM
 *  Author: hassa
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	LOW_LEVEL = 1 ,
	ON_CHANGE	  ,
	FALLING_EDGE  ,
	RISING_EDGE
	
	}exti_sense_control_t;
/*#define LOW_LEVEL        1
#define ON_CHANGE        2
#define FALLING_EDGE     3
#define RISING_EDGE      4*/

typedef enum
{
	INT0 = 1 ,
	INT1     ,
	INT2  
}exti_t;
/*#define INT0             1
#define INT1             2
#define INT2             3*/

/*
 *	@brief	:	Enable EXTI, Select Sense Control and Send Function Needed to Execute
 *	@retval	:	ErrorState [0 -> Func Is NOK, 1 -> Func Is OK ]
 *	@param	:	Copy_u8EXTIx -> INT Sourse [INT0 ,INT1 ,INT2 ]
 *	@param	:	Copy_u8EXTIxSense -> INT Sense [LOW_LEVEL ,ON_CHANGE ,FALLING_EDGE ,RISING_EDGE ]
 *	@param	:	Copy_pvEXTIxFunc -> pointer to function Needed to execute										   			   
 */												
error_state_t MEXTI_Enable(exti_t Copy_u8EXTIx, exti_sense_control_t Copy_u8EXTIxSense, void(*Copy_pvEXTIxFunc)(void));
/*
 *	@brief	:	Disable EXTI
 *	@retval	:	ErrorState [0 -> Func Is NOK, 1 -> Func Is OK ]
 *	@param	:	Copy_u8EXTIx -> INT Sourse [INT0 ,INT1 ,INT2 ]
 */
error_state_t MEXTI_Disable(exti_t Copy_u8EXTIx);

void MEXTI_FUNC( void(*Copy_pvEXTIxFunc)(void));


#endif /* EXTI_INTERFACE_H_ */