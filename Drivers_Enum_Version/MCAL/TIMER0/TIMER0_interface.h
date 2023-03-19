/*
 * TIMER0_interface.h
 *
 * Created: 1/31/2023 1:43:26 AM
 *  Author: Hassan Ehab
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/*
 * @brief  : Initialization Timer0
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
void TIMER0_voidInit(void);
/*
 * @brief  : Timer0 Set Time in ms
 * @param  : Copy_u32DesiredTime [Desired Time In ms]
 * @param  : Copy_pvCallBackFunc [pointer To Function Needed To Execute]
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
error_state_t TIMER0_enumSetTime_ms(u32 Copy_u32DesiredTime, void(*Copy_pvCallBackFunc)(void));
/*
 * @brief  : Timer0 Start
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
error_state_t TIMER0_enumStart(void);
/*
 * @brief  : Timer0 Stop
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
error_state_t TIMER0_enumStop(void);
error_state_t TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

/*
 * @brief  : Initialization PWM0
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
error_state_t PWM0_enumInit(void);
/*
 * @brief  : PWM0 Set Duty Cycle
 * @param  : Copy_u32DesiredTime [Desired Time In ms]
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
error_state_t PWM0_enumSetDutyCycle(u8 Copy_u8DutyCycle);
/*
 * @brief  : PWM0 Start
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
error_state_t PWM0_enumStart(void);
/*
 * @brief  : PWM0 Stop
 * @param  : void (No Parameter )
 * @retval : ErrorState [TIMER0_OK, TIMER0_NOK]
 */
error_state_t PWM0_enumStop(void);

void COUNTER0_voidCounterInit(void);
u8   COUNTER0_u8GetCounterValue(void);


u8   TIMER0_u8GetTimerValue(void);
void TIMER0_voidSetTimerValue(u8 Copy_u8TimerValue);

#endif /* TIMER0_INTERFACE_H_ */