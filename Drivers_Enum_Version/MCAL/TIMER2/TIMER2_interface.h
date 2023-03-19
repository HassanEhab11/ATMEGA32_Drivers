/*
 * TIMER2_interface.h
 *
 * Created: 2/1/2023 2:19:06 PM
 *  Author: hassa
 */ 


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

/*
 * @brief  : Initialization Timer2
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
void TIMER2_voidInit(void);
/*
 * @brief  : Timer2 Set Time in ms
 * @param  : Copy_u32DesiredTime [Desired Time In ms]
 * @param  : Copy_pvCallBackFunc [pointer To Function Needed To Execute]
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
error_state_t TIMER2_enumSetTime_ms(u32 Copy_u32DesiredTime, void(*Copy_pvCallBackFunc)(void));
/*
 * @brief  : Timer2 Start
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
error_state_t TIMER2_enumStart(void);
/*
 * @brief  : Timer2 Stop
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
error_state_t TIMER2_enumStop(void);
error_state_t TIMER2_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

/*
 * @brief  : Initialization PWM2
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
error_state_t PWM2_enumInit(void);
/*
 * @brief  : PWM2 Set Duty Cycle
 * @param  : Copy_u32DesiredTime [Desired Time In ms]
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
error_state_t PWM2_enumSetDutyCycle(u8 Copy_u8DutyCycle);
/*
 * @brief  : PWM2 Start
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
error_state_t PWM2_enumStart(void);
/*
 * @brief  : PWM2 Stop
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER2_OK, TIMER2_NOK]
 */
error_state_t PWM2_enumStop(void);


u8   TIMER2_u8GetTimerValue(void);
void TIMER2_voidSetTimerValue(u8 Copy_u8TimerValue);





#endif /* TIMER2_INTERFACE_H_ */