/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): ADC         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_register.h"




void ADC_voidInit(void)
{
	/* AVCC as reference voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/* Activate Left Adjust result */
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/* Prescaler Selection */
	ADCSRA &= ADC_PRESC_MASK;
	ADCSRA |= ADC_PRESC_SELEC;

	/* Enable peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{

	/* Clear the MUX bits in ADMUX register*/
	ADMUX &= ADC_SELEC_CHANNEL_MASK;

	/*Set the required channel into the MUX bits*/
	ADMUX |= Copy_u8Channel;

	/* Start Conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/* Polling (Busy Waiting) until the conversion complete flag is set */
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/* Clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/* Return the reading*/
	return ADCH;

}
