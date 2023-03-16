/********************************************************************/
/********************************************************************/
 /******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): ADC         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*************************** N.O Of Bits: ************************************************
 * 1- _8_BITS
 * 2- _10_BITS
 */
#define NO_OF_BITS          _10_BITS
#define ADC_u32TIMEOUT       50000

/*****************************Voltage Reference Selection Options**************************
 *   1- AREF
 *   2- AVCC
 *   3- _2.56_Volt_
 *
 */

#define ADC_VOLT_REF_SELEC       AVCC
/***************************** ADC Select Channel *****************************************
 * 0 - ADC0
 * 1 - ADC1
 * 2 - ADC2
 * 3 - ADC3
 * 4 - ADC4
 * 5 - ADC5
 * 6 - ADC6
 * 7 - ADC7
 * 8 - ADC0_ADC0_10x
 * 9 - ADC1_ADC0_10x
 * 10- ADC0_ADC0_200x
 * 11- ADC1_ADC0_200x
 * 12- ADC2_ADC2_10x
 * 13- ADC3_ADC2_10x
 * 14- ADC2_ADC2_200x
 * 15- ADC3_ADC2_200x
 * 16- ADC0_ADC1_1x
 * 17- ADC1_ADC1_1x
 * 18- ADC2_ADC1_1x
 * 19- ADC3_ADC1_1x
 * 20- ADC4_ADC1_1x
 * 21- ADC5_ADC1_1x
 * 22- ADC6_ADC1_1x
 * 23- ADC7_ADC1_1x
 * 24- ADC0_ADC2_1x
 * 25- ADC1_ADC2_1x
 * 26- ADC2_ADC2_1x
 * 27- ADC3_ADC2_1x
 * 28- ADC4_ADC2_1x
 * 29- ADC5_ADC2_1x
 * 30- _1022_VOLT
 * 31- GND
 *
 */
#define ADC_SELEC_CHANNEL  ADC0

/***************************** ADC Prescaler Selection Options ******************************
 * 1- DIV_BY_2
 * 2- DIV_BY_4
 * 3- DIV_BY_8
 * 4- DIV_BY_16
 * 5- DIV_BY_32
 * 6- DIV_BY_64
 * 7- DIV_BY_128A
 *
 */

#define ADC_PRESC_SELEC          DIV_BY_128

/***************************** ADC Data Register Options ************************************
 * 1- ADC_Left_Adj
 * 2- ADC_Right_Adj     use it with 10 bits
 *
 */

#define ADC_Data_Register        ADC_Right_Adj

/***************************** ADC  Conversion Options **************************************
 * 1- ADC_Single_Conv_Mode
 * 2- ADC_Auto_Trigger_Mode
 *
 */

#define ADC_Conversion_Mode      ADC_Single_Conv_Mode
/***************************** ADC Auto Trigger Source Options *******************************
 * 1- Free_Running_mode
 * 2- Analog_Comparator
 * 3- EXT_INT_0
 * 4- Timer_0_Compare_Match
 * 5- Timer_0_Overflow
 * 6- Timer_Compare_Match_B
 * 7- Timer_1_Overflow
 * 8- Timer_1_Capture_Event
 *
 */

#define ADC_Auto_Trigger_Source   Free_Running_Mode


#endif
