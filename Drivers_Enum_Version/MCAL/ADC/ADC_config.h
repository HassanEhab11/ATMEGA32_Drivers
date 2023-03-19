/*
 * ADC_config.h
 *
 * Created: 1/29/2023 8:44:25 AM
 *  Author: hassa
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/***************************** ADC Time Out **************************/
#define ADC_u32TIMEOUT       50000
/*************************** N.O Of Bits: ************************************************
 * 1- _8_BITS
 * 2- _10_BITS
 */
#define NO_OF_BITS          _10_BITS
/*****************************Voltage Reference Selection Options**************************
 *   1- AREF
 *   2- AVCC
 *   3- _2.56_Volt_
 */
#define ADC_VOLT_REF_SELEC       AVCC
/***************************** ADC Data Register Options ************************************
 * 1- ADC_Left_Adj
 * 2- ADC_Right_Adj
 */
#define ADC_Data_Register        ADC_Right_Adj
/***************************** ADC  Conversion Mode **************************************
 * 1- AUTO_TRIGGER_ENABLE
 * 2- AUTO_TRIGGER_DISABLE
 */
#define ADC_AUTO_TRIGGER_MODE      AUTO_TRIGGER_DISABLE
/******************* ADC Auto Trigger Source Options (In Case You Chose Auto Trigger Mode )****************
 * 1- Free_Running_Mode
 * 2- Analog_Comparator
 * 3- EXT_INT_0
 * 4- Timer_0_Compare_Match
 * 5- Timer_0_Overflow
 * 6- Timer_Compare_Match_B
 * 7- Timer_1_Overflow
 * 8- Timer_1_Capture_Event
 */
#define ADC_Auto_Trigger_Source   Free_Running_Mode
/***************************** ADC Prescaler Selection Options ******************************
 * 1- DIV_BY_2
 * 2- DIV_BY_4
 * 3- DIV_BY_8
 * 4- DIV_BY_16
 * 5- DIV_BY_32
 * 6- DIV_BY_64
 * 7- DIV_BY_128
 */
#define ADC_PRESC_SELEC          DIV_BY_128



#endif /* ADC_CONFIG_H_ */