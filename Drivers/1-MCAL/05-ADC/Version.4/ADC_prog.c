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

#include "DIO_interface.h"

static u16* ADC_pu16Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;
u8 ADC_u8BusyState = IDLE;
static u8 ADC_u8ISRSourse;
/****************************** Chain Conversion Global Variables and Functions ***********************/
//static void (*ADC_CallBackChainNotificationFunc)(void) = NULL;
static u8* ADC_pu8ChainChannelArr = NULL;     /* Global Variable to carry channel array*/
static u8 ADC_u8ChainSize;                    /* Global Variable To Carry Number of Channel*/
static u16* ADC_pu16ChainResultArr = NULL; /* Global Variable to carry chain result */
static u8 ADC_u8ChainConversionIndex = 0;     /* Global variable to carry the current conversion index */

/*****************************************************************************************************/

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
	/* Select ADC Auto Trigger Source */
	SFIOR &= ADC_Auto_Trigger_Source_MASK;
	SFIOR |= ADC_Auto_Trigger_Source;

#endif


}
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu16Reading)
{
	u32 Local_u32Counter = 0;
	u8 Local_u8ErrorState = OK;
	if(ADC_u8BusyState == IDLE)
	{
		/* ADC is now busy*/
		ADC_u8BusyState = BUSY;

		ADMUX &= ADC_SELEC_CHANNEL_MASK; 	/* Clear the MUX bits in ADMUX register*/
		ADMUX |= Copy_u8Channel;           /*Set the required channel into the MUX bits*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);      /* Start Conversion */


#if ADC_Conversion_Mode == ADC_Single_Conv_Mode

		/* Polling (Busy Waiting) until the conversion complete flag is set or counter reaching timeout value */
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) && (Local_u32Counter != ADC_u32TIMEOUT))
		{
			Local_u32Counter++;
		}

		if (Local_u32Counter == ADC_u32TIMEOUT)
		{
			/* Loop is broken because the time out is reached */
			Local_u8ErrorState = NOK;

		}
		else
		{
			/* Loop is broken because flag is raised */
			/* Clear the conversion complete flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);

		}


#endif
		/* Return the reading*/
#if   NO_OF_BITS == _8_BITS
		*Copy_pu16Reading = ADCH;
#elif NO_OF_BITS == _10_BITS
		*Copy_pu16Reading =  ADC;
#endif

		/* ADC is finished return it to IDLE */
		ADC_u8BusyState = IDLE;
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;


}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Reading, void (*Copy_pvNotificationFun)(void))
{
	u8 Local_u8ErrorState = OK;

	if(ADC_u8BusyState == IDLE )
	{


		if((Copy_pu16Reading == NULL) || (Copy_pvNotificationFun == NULL))
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/* make ADC BUSY in order not  work until being idle  */
			ADC_u8BusyState = BUSY;

			/* Make ISR source single channel Asynchronous */
			ADC_u8ISRSourse = SINGLE_CHANNEL_ASYNCH;

			/* Initialize the reading variable globally */
			ADC_pu16Reading = Copy_pu16Reading;

			/* Initialize the callback notification function globally */
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFun;

			/* Select Channel*/
			ADMUX &= ADC_SELEC_CHANNEL_MASK; 	/* Clear the MUX bits in ADMUX register*/
			ADMUX |= Copy_u8Channel;           /*Set the required channel into the MUX bits*/

			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/* Enable INT for ADC  */
			SET_BIT(ADCSRA,ADCSRA_ADIE);


		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}



u8 ADC_u8StartChainConversionAsynch(ADC_Chain_t* Copy_Chain)
{
	u8 Local_u8ErrorState = OK;
	/* Check Null Pointer*/
	if(Copy_Chain == NULL)
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else
	{
		if(ADC_u8BusyState == IDLE)
		{
			/* Make ADC Busy*/
			ADC_u8BusyState = BUSY;


			/* Make ISR Source*/
			ADC_u8ISRSourse = CHAIN_ASYNCH;

			/* initialize Chain Channel array globally  */
			ADC_pu8ChainChannelArr= Copy_Chain->Channel ;

			/* initialize Chain result array globally  */
			ADC_pu16ChainResultArr = Copy_Chain->Result;

			/* initialize Chain Size globally */
			ADC_u8ChainSize = Copy_Chain->Size;

			/* initialize notification function globally */
			ADC_pvCallBackNotificationFunc = Copy_Chain->NotificationFunc ;

			/* Initialize current conversion Index*/
			ADC_u8ChainConversionIndex = 0;


			/*Set required channel
			 *  Start Conversion of 1st Channel */
			ADMUX &= ADC_SELEC_CHANNEL_MASK; 	          /* Clear the MUX bits in ADMUX register*/
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex] ;           /*Set the required channel into the MUX bits
			                                                                         ADC_u8ChainConversionIndex is equal zero*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);                /* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADIE);               /* Enable Conversion Complete INT for ADC  */

		}
		else
		{
			Local_u8ErrorState = BUSY_FUNC;

		}

	}

	return Local_u8ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(ADC_u8ISRSourse == SINGLE_CHANNEL_ASYNCH)
	{
		/* Read ADC Result */
#if   NO_OF_BITS == _8_BITS
		*ADC_pu16Reading = ADCH;
#elif NO_OF_BITS == _10_BITS
		*ADC_pu16Reading =  ADC;
#endif
		/* Make ADC state be IDLE because it finished*/
		ADC_u8BusyState = IDLE;

		/* Invoke the callback notification function */
		ADC_pvCallBackNotificationFunc();

		/* Disable ADC Conversion complete interrupt */
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRSourse == CHAIN_ASYNCH)
	{
		/* Read ADC Result */
#if   NO_OF_BITS == _8_BITS
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex] = ADCH;
#elif NO_OF_BITS == _10_BITS
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex] =  ADC;
#endif
		/* Increment chain index */
		ADC_u8ChainConversionIndex ++;

		/* check chain is finished or not */
		if(ADC_u8ChainConversionIndex == ADC_u8ChainSize)
		{
			/* Chain is finished*/
			/* Make ADC state be IDLE because it finished*/
			ADC_u8BusyState = IDLE;

			/* Invoke the callback notification function */
			ADC_pvCallBackNotificationFunc();

			/* Disable ADC Conversion complete interrupt */
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			/* Chain is not finished*/
			/*Set next channel
			 *  Start Conversion of next Channel */
			ADMUX &= ADC_SELEC_CHANNEL_MASK; 	                              /* Clear the MUX bits in ADMUX register*/
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex] ;      /*Set the required channel into the MUX bits
						                                                          ADC_u8ChainConversionIndex ++ */
			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

		}




	}


}
