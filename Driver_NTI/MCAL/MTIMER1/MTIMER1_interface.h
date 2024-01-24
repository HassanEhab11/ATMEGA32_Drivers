/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TIMER       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_RISING_EDGE      1
#define ICU_FALLING_EDGE     0

/* Timer1 Initialization
 *
 * This function initializes Timer1 according to the selected mode (NORMAL or CTC).
 * It configures the timer's mode, prescaler, and enables the overflow or compare match interrupt.
 */
void MTIMER1_voidInit(void);

/* Timer1 Set Time in ms
 *
 * Sets the desired time in milliseconds for Timer1 to generate an interrupt.
 * It calculates the necessary settings based on the selected prescaler and timer mode.
 *
 * @param Copy_u32DesiredTime: Desired time in milliseconds.
 * @param Copy_pvCallBackFunc: Pointer to the callback function to be executed when the time elapses.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MTIMER1_enumSetTime_ms(u32 Copy_u32DesiredTime, void (*Copy_pvCallBackFunc)(void));

/* Timer1 Start
 *
 * Starts Timer1 by configuring the prescaler.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MTIMER1_enumStart(void);

/* Timer1 Stop
 *
 * Stops Timer1 by clearing the prescaler.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MTIMER1_enumStop(void);

/* Timer1 Set Callback Function
 *
 * Sets the callback function to be executed when Timer1 interrupts occur.
 *
 * @param Copy_pvCallBackFunc: Pointer to the callback function.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MTIMER1_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

/* Timer1 No Prescaler
 *
 * Configures Timer1 to operate with no prescaler, i.e., the timer will run at the maximum frequency.
 */
void MTIMER1_voidNoPrescaler(void);

/* Timer1 Set ICR1 Register
 *
 * Sets the Input Capture Register (ICR1) with the specified value for CTC mode.
 *
 * @param Copy_u16TOP: The value to set in ICR1.
 */
void MTIMER1_voidSetICR(u16 Copy_u16TOP);

/* Timer1 Set OCR1A Register (For CTC Mode)
 *
 * Sets the value of OCR1A register for CTC mode.
 *
 * @param Copy_u16CompareMatch: The value to set in OCR1A.
 */
void MTIMER1_SetChannelAComMatchValue(u16 Copy_u16CompareMatch);

/* PWM1 Initialization
 *
 * Initializes PWM1 according to the selected mode (FAST_PWM or PHASE_CORRECT_PWM).
 * It configures the timer mode, prescaler, and PWM output mode.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MPWM1_enumInit(void);

/* PWM1 Set Duty Cycle
 *
 * Sets the duty cycle of PWM1.
 *
 * @param Copy_u8DutyCycle: The desired duty cycle value (0-100).
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MPWM1_enumSetDutyCycle(u8 Copy_u8DutyCycle);

/* PWM1 Start
 *
 * Starts PWM1 operation by configuring the prescaler.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MPWM1_enumStart(void);

/* PWM1 Stop
 *
 * Stops PWM1 operation by clearing the prescaler.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t MPWM1_enumStop(void);

/* Get Timer1 Counts
 *
 * Returns the current count value of Timer1, considering overflow.
 *
 * @return u32: The timer count value.
 */
u32 MTIMER1_u32GetCounts(void);

/* Set Timer1 Value
 *
 * Sets the current value of Timer1.
 *
 * @param Copy_u16TimerValue: The value to set in Timer1.
 */
void MTIMER1_voidSetTimerValue(u16 Copy_u16TimerValue);

/* Read Timer1 Value
 *
 * Reads and returns the current value of Timer1.
 *
 * @return u16: The current timer value.
 */
u16 MTIMER1__u16ReadTimerValue(void);

/* Timer1 Counter Mode Initialization
 *
 * Initializes Timer1 in counter mode with the specified edge mode.
 *
 * @param Copy_u8EdgeMode: The edge mode for counting (rising or falling).
 */
void MCOUNTER1_voidCounterInit(void);

/* Get Timer1 Counter Value
 *
 * Reads and returns the current counter value of Timer1.
 *
 * @return u8: The current counter value.
 */
u8 MCOUNTER1_u8GetCounterValue(void);

/* Input Capture Unit (ICU) Initialization
 *
 * Initializes Timer1 in Input Capture Mode.
 */
void ICU_voidInit(void);

/* ICU Set Trigger Edge
 *
 * Sets the trigger edge for the Input Capture Unit (ICU).
 *
 * @param Copy_u8Edge: The desired edge mode (ICU_RISING_EDGE or ICU_FALLING_EDGE).
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t ICU_u8SetTriggerEdge(u8 Copy_u8Edge);

/* Enable ICU Interrupt
 *
 * Enables the interrupt for the Input Capture Unit (ICU).
 */
void ICU_voidEnableInterrupt(void);

/* Disable ICU Interrupt
 *
 * Disables the interrupt for the Input Capture Unit (ICU).
 */
void ICU_voidDisableInterrupt(void);

/* Read ICU Input Capture Value
 *
 * Reads and returns the captured value from the Input Capture Unit (ICU).
 *
 * @return u16: The captured value.
 */
u16 ICU_u16ReadInputCapture(void);

/* Get ICU Input Capture Flag
 *
 * Returns the status of the Input Capture Flag for ICU.
 *
 * @return u8: The flag status.
 */
u8 ICU_u8GetInputCaptureFlag(void);

/* Clear ICU Input Capture Flag
 *
 * Clears the Input Capture Flag for ICU.
 */
void ICU_u8ClearInputCaptureFlag(void);

/* Enable Noise Canceler for ICU
 *
 * Enables the Noise Canceler for the Input Capture Unit (ICU).
 */
void ICU_voidNoiseCanceler(void);

/* Set ICU Callback Function
 *
 * Sets the callback function to be executed when ICU interrupts occur.
 *
 * @param Copy_pvCallBackFunc: Pointer to the callback function.
 *
 * @return ErrorState: TIMER1_OK if the operation is successful, TIMER1_NOK if there is an error.
 */
error_state_t ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif /* MTIMER1_INTERFACE_H_ */


