/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): ADC         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADC_VOLT_REF_SELEC_MASK          0b00111111
#define ADC_Data_Register_MASK           0b11011111
#define ADC_PRESC_MASK                   0b11111000    //248 in decimal

#define ADC_SELEC_CHANNEL_MASK           0b11100000

#define ADC_Auto_Trigger_Source_MASK    0b00001111

#define IDLE     0
#define BUSY     1

#define  SINGLE_CHANNEL_ASYNCH       0
#define  CHAIN_ASYNCH                1

#endif
