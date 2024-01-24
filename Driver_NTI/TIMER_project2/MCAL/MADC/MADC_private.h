/*
 * ADC_private.h
 *
 * Created: 1/29/2023 8:43:47 AM
 *  Author: hassa
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*************************** N.O Of Bits: ******************************************************/
#define _8_BITS                    1
#define _10_BITS                   2
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
/********************************* ADC Data Register Options *******************************/
#define ADC_Left_Adj               0b00100000      //32
#define ADC_Right_Adj              0              //0b00000000
/***************************** ADC  Conversion Mode Options ********************************/
#define AUTO_TRIGGER_ENABLE      1
#define AUTO_TRIGGER_DISABLE     2
/***************************** ADC Auto Trigger Source Options *****************************/
#define Free_Running_Mode          0       //0b00000000
#define Analog_Comparator          32      //0b00100000
#define EXT_INT_0                  64      //0b01000000
#define Timer_0_Compare_Match      96      //0b01100000
#define Timer_0_Overflow           128     //0b10000000
#define Timer_Compare_Match_B      160     //0b10100000
#define Timer_1_Overflow           192     //0b11000000
#define Timer_1_Capture_Event      224     //0b11100000
/**************** ADC MASK **********************************/
#define ADC_VOLT_REF_SELEC_MASK          0b00111111
#define ADC_Data_Register_MASK           0b11011111
#define ADC_PRESC_MASK                   0b11111000    //248 in decimal

#define ADC_SELEC_CHANNEL_MASK           0b11100000
#define ADC_Auto_Trigger_Source_MASK     0b00011111

#define IDLE                             0
#define BUSY                             1

#define  SINGLE_CHANNEL_ASYNCH           0
#define  CHAIN_ASYNCH                    1
/****************************** ADC REGISTERS ***********************************/
#define ADMUX           *((volatile u8*)0x27)     // ADC multiplexer selection register
#define ADMUX_REFS1     7                         // Reference Selection bit1
#define ADMUX_REFS0     6                         // Reference Selection bit0
#define ADMUX_ADLAR     5                         // ADc left adjust result
/**************************************************************************************/
#define ADCSRA           *((volatile u8*)0x26)     // ADC control and status register A
#define ADCSRA_ADEN      7                         // ADC enable
#define ADCSRA_ADSC      6                         // Start conversion
#define ADCSRA_ADATE     5                         // Auto trigger enable
#define ADCSRA_ADIF      4                         // Interrupt flag
#define ADCSRA_ADIE      3                         // Interrupt enable
#define ADCSRA_ADPS2     2                         // Prescaler bit2
#define ADCSRA_ADPS1     1                         // Prescaler bit1
#define ADCSRA_ADPS0     0                         // Prescaler bit0
/**************************************************************************************/
#define ADCH      *((volatile u8*)0x25)           // ADC high register
/**************************************************************************************/
#define ADCL      *((volatile u8*)0x24)           // ADC low register
/**************************************************************************************/
#define ADC       *((volatile u16*)0x24)           // ADC 16 for 10_bit
/**************************************************************************************/
#define SFIOR     *((volatile u8*)0x50)

/************ ADC Interrupt Vectors Number ************/
#define	ADC_VECTOR				__vector_16
/********************* ISR Attribute ****************************/
#define ISR_(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)


#endif /* ADC_PRIVATE_H_ */