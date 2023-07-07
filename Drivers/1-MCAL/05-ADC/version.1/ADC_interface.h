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

#define ADC_PRESC_SELEC     DIV_BY_128

#define DIV_BY_2            0
#define DIV_BY_4            2
#define DIV_BY_8            3
#define DIV_BY_16           4
#define DIV_BY_32           5
#define DIV_BY_64           6
#define DIV_BY_128          7





void ADC_voidInit(void);
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);


#endif
