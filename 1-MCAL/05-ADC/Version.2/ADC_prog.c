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
	/* reference voltage */
	ADMUX &= ADC_VOLT_REF_SELEC_MASK;
	ADMUX |= ADC_VOLT_REF_SELEC;

	/* Activate Data Register */
	ADMUX &= ADC_Data_Register_MASK;
	ADMUX |= ADC_Data_Register;
	//SET_BIT(ADMUX,ADMUX_ADLAR);

	/* Prescaler Selection */
	ADCSRA &= ADC_PRESC_MASK;
	ADCSRA |= ADC_PRESC_SELEC;

	/* Enable peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

#if ADC_Conversion_Mode == ADC_Auto_Trigger_Mode
	/* Enable Auto Trigger */
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	/* SELECT CHANNEL*/
	//ADMUX &= ADC_SELEC_CHANNEL_MASK; //i need to check if it is important or not
	//ADMUX |= ADC_SELEC_CHANNEL;
	/* Enable INT for ADC  */
	SET_BIT(ADCSRA,ADCSRA_ADIE);
	/* Select ADC Auto Trigger Source */
	SFIOR &= ADC_Auto_Trigger_Source_MASK;
	SFIOR |= ADC_Auto_Trigger_Source;
	/* Start First Conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#endif


}
u16 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{

	/* Clear the MUX bits in ADMUX register*/
	ADMUX &= ADC_SELEC_CHANNEL_MASK;

	/*Set the required channel into the MUX bits*/
	ADMUX |= Copy_u8Channel;

#if ADC_Conversion_Mode == ADC_Single_Conv_Mode
	SET_BIT(ADCSRA,ADCSRA_ADSC);  /* Start Conversion */

	/* Polling (Busy Waiting) until the conversion complete flag is set */
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/* Clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

#endif

	/* Return the reading*/
#if   NO_OF_BITS == _8_BITS
	return ADCH;
#elif NO_OF_BITS == _10_BITS
	return ADC;
#endif


}
