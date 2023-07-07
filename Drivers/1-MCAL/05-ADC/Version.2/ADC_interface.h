/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): ADC         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/*************************** N.O Of Bits: ******************************************************/
 #define _8_BITS                   1
 #define _10_BITS                  2
/**************************** Voltage Reference Selection Options *****************************/
#define AREF                       0
#define AVCC                       64         //0b01000000
#define _2056_Volt                 192        //0b11000000
/****************************** ADC Prescaler Selection Options *******************************/
#define DIV_BY_2                   0
#define DIV_BY_4                   2
#define DIV_BY_8                   3
#define DIV_BY_16                  4
#define DIV_BY_32                  5
#define DIV_BY_64                  6
#define DIV_BY_128                 7
/********************************* ADC Data Register Options ********************************/
#define ADC_Left_Adj               0b00100000      //32
#define ADC_Right_Adj              0              //0b00000000
/***************************** ADC Select Channel ******************************************/
#define ADC0                       0
#define ADC1                       1
#define ADC2                       2
#define ADC3                       3
#define ADC4                       4
#define ADC5                       5
#define ADC6                       6
#define ADC7                       7
#define ADC0_ADC0_10x              8
#define ADC1_ADC0_10x              9
#define ADC0_ADC0_200x             10
#define ADC1_ADC0_200x             11
#define ADC2_ADC2_10x              12
#define ADC3_ADC2_10x              13
#define ADC2_ADC2_200x             14
#define ADC3_ADC2_200x             15
#define ADC0_ADC1_1x               16
#define ADC1_ADC1_1x               17
#define ADC2_ADC1_1x               18
#define ADC3_ADC1_1x               19
#define ADC4_ADC1_1x               20
#define ADC5_ADC1_1x               21
#define ADC6_ADC1_1x               22
#define ADC7_ADC1_1x               23
#define ADC0_ADC2_1x               24
#define ADC1_ADC2_1x               25
#define ADC2_ADC2_1x               26
#define ADC3_ADC2_1x               27
#define ADC4_ADC2_1x               28
#define ADC5_ADC2_1x               29
#define _1022_VOLT                 30
#define GND                        31

/***************************** ADC  Conversion Mode Options **************************************/
#define ADC_Single_Conv_Mode       1
#define ADC_Auto_Trigger_Mode      2
/***************************** ADC Auto Trigger Source Options ***********************************/
#define Free_Running_Mode          0       //0b00000000
#define Analog_Comparator          32      //0b00100000
#define EXT_INT_0                  64      //0b01000000
#define Timer_0_Compare_Match      96      //0b01100000
#define Timer_0_Overflow           128     //0b10000000
#define Timer_Compare_Match_B      160     //0b10100000
#define Timer_1_Overflow           192     //0b11000000
#define Timer_1_Capture_Event      224     //0b11100000



void ADC_voidInit(void);
u16 ADC_u8GetChannelReading(u8 Copy_u8Channel);


#endif
