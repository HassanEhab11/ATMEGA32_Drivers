/*
 * ADC_prog.c
 *
 * Created: 1/29/2023 8:43:30 AM
 *  Author: Hassan Ehab
 */ 

/******************************* STD LIB DIRECTIVES ****************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
/****************************** Component DIRECTIVES ***************************/
#include "MADC_config.h"
#include "MADC_interface.h"
#include "MADC_private.h"
/************************* Global variable Deceleration ************************/
static u8 ADC_u8BusyState = IDLE;
static u8 ADC_u8ISRSourse;

/******* Global variable Deceleration (Single Conversion Asynchronous) *********/
static void(*ADC_pvCallBackNotificationFunc)(void) = NULL;
static u16* ADC_pu16Reading = NULL;
/******* Global variable Deceleration (Chain Conversion Asynchronous) *********/
static u16* ADC_pu16ChainResultArr = NULL;		    /* Global Variable to carry chain result */
static u8* ADC_pu8ChainChannelArr = NULL;		 	/* Global Variable to carry channel array*/
static u8 ADC_u8ChainSize = 0;                      /* Global Variable To Carry Number of Channel*/
static u8 ADC_u8ChainConversionIndex = 0;           /* Global variable to carry the current conversion index */
 

/*******************************************************************************/
/**************************** Function Implementation **************************/
/*******************************************************************************/

/***************************** ADC Initialization ******************************/
void MADC_voidInit(void)
{
	/* 1. Select Voltage Reference */
	ADMUX &= ADC_VOLT_REF_SELEC_MASK;
	ADMUX |= ADC_VOLT_REF_SELEC;
	/* 2. Select ADC Adjust */
	ADMUX &= ADC_Data_Register_MASK;
	ADMUX |= ADC_Data_Register;
	/* 3. Single Or Auto Trigger Conversion Mode */
	#if ADC_AUTO_TRIGGER_MODE == AUTO_TRIGGER_ENABLE
	/* Enable Auto Trigger */
	SET_BIT(ADCSRA, ADCSRA_ADATE);
	/* Select ADC Auto Trigger Source */
	SFIOR &= ADC_Auto_Trigger_Source_MASK;
	SFIOR |= ADC_Auto_Trigger_Source;
	#elif ADC_AUTO_TRIGGER_MODE == AUTO_TRIGGER_DISABLE
	CLR_BIT(ADCSRA, ADCSRA_ADATE);
	#endif
	/* 4. Prescaler Selection*/
	ADCSRA &= ADC_PRESC_MASK;
	ADCSRA |= ADC_PRESC_SELEC;
	/* 5. Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
/*************************** End ADC Initialization ****************************/

/********************* ADC Start Conversion Synch ******************************/
error_state_t MADC_StartConversionSynch(Channel_t Copy_Channel, u16 *Copy_pu16Reading)
{
	error_state_t Local_ErrorState = R_OK;
	u32 Local_u32TimeOutCounter = 0;
	
	if (ADC_u8BusyState == IDLE)
	{
		/* ADC Now Is Busy */
		ADC_u8BusyState = BUSY;
		/* Select Channel */
		ADMUX &= ADC_SELEC_CHANNEL_MASK; 	/* Clear the MUX bits in ADMUX register*/
		ADMUX |= Copy_Channel;              /*Set the required channel into the MUX bits*/
		
		#if ADC_AUTO_TRIGGER_MODE == AUTO_TRIGGER_DISABLE
		/* Start Conversion */
		SET_BIT(ADCSRA, ADCSRA_ADSC);
		#endif

		 /* Polling (Busy Wait) until the conversion complete flag is set 
		   or counter reaching TimeOut value */
		 while ((GET_BIT(ADCSRA, ADCSRA_ADIF) == 0) && ( Local_u32TimeOutCounter != ADC_u32TIMEOUT))
		 {
			 Local_u32TimeOutCounter ++;
		 } 
		 if (GET_BIT(ADCSRA, ADCSRA_ADIF) == 1)
		 {
			 /* Loop is broken because flag is raised */
			 /* Clear conversion complete Flag */
			 SET_BIT(ADCSRA, ADCSRA_ADIF);
			 
			 /* Return Value Of Conversion */
			 *Copy_pu16Reading = ADC;
			 
		 } 
		 else
		 {
			 /* Loop is broken because the time out is reached */
			 Local_ErrorState = R_NOK; 
		 }
		ADC_u8BusyState = IDLE;
	}
	else
	{
		Local_ErrorState = BUSY_FUNC;
	}
	
	return Local_ErrorState;
}
/******************** End ADC Start Conversion Synch ***************************/

/************************* ADC Start Conversion Asynch *************************/
error_state_t MADC_StartConversionAsynch(Channel_t Copy_Channel, u16 *Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void))
{
	error_state_t Local_ErrorState = R_OK;
	if(ADC_u8BusyState == IDLE)
	{
		/* make ADC BUSY in order not  work until being idle  */
		ADC_u8BusyState = BUSY;
		
		/* Make ISR source single channel Asynchronous */
		ADC_u8ISRSourse = SINGLE_CHANNEL_ASYNCH;
		
		/* Initialize the reading variable globally */
		ADC_pu16Reading = Copy_pu16Reading;
		
		/* Initialize The Callback Notification Function Globally*/
		ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;
		
		/* Select Channel */
		ADMUX &= ADC_SELEC_CHANNEL_MASK; 	/* Clear the MUX bits in ADMUX register*/
		ADMUX |= Copy_Channel;              /*Set the required channel into the MUX bits*/
	

		#if ADC_AUTO_TRIGGER_MODE == AUTO_TRIGGER_DISABLE 
		/* Start Conversion */
		SET_BIT(ADCSRA, ADCSRA_ADSC);
		#endif		
			
		SET_BIT(ADCSRA, ADCSRA_ADSC);

		/* Enable INT */
		MADC_voidInterruptEnable();

	}
	else
	{
		Local_ErrorState = BUSY_FUNC;
	}
	
	
	
	return Local_ErrorState;
}
/*********************** End ADC Start Conversion Asynch ***********************/

/********************** ADC Start Chain Conversion Asynch***********************/
error_state_t MADC_StartChainConversionAsynch(Chain_t *Copy_Chain)
{
	error_state_t Local_ErrorState = R_OK;
	if (Copy_Chain == NULL)
	{
		Local_ErrorState = NULL_POINTER;
	} 
	else
	{
		if(ADC_u8BusyState == IDLE)
		{
			/* make ADC BUSY in order not  work until being idle  */
			ADC_u8BusyState = BUSY;
			
			/* Make ISR source Chain channel Asynchronous */
			ADC_u8ISRSourse = CHAIN_ASYNCH;
			
			/* initialize Chain Channel array globally  */
			ADC_pu8ChainChannelArr = Copy_Chain->ADC_Channels;
			
			/* Initialize the reading variable globally */
			ADC_pu16ChainResultArr = Copy_Chain->Reading;
			
			/* initialize Chain Size globally */
			ADC_u8ChainSize = Copy_Chain->Size;

			/* Initialize The Callback Notification Function Globally*/
			ADC_pvCallBackNotificationFunc = Copy_Chain->ADC_pvNotificationFunc;
			
			/* Initialize current conversion Index*/
			ADC_u8ChainConversionIndex = 0;
			
			/* Select Channel */
			ADMUX &= ADC_SELEC_CHANNEL_MASK; 	   /* Clear the MUX bits in ADMUX register*/
			ADMUX |= Copy_Chain->ADC_Channels[ADC_u8ChainConversionIndex];  /*Set the required channel into the MUX bits*/
			
			/* Start Conversion In Case Auto Trigger Off */
			#if ADC_AUTO_TRIGGER_MODE == AUTO_TRIGGER_DISABLE
			/* Start Conversion */
			SET_BIT(ADCSRA, ADCSRA_ADSC);
			#endif

			/* Enable INT */
			MADC_voidInterruptEnable();
		}
		else
		{
			Local_ErrorState = BUSY_FUNC;
		}
	}

	return Local_ErrorState;
}
/******************* End ADC Start Chain Conversion Asynch *********************/

/***************************** ADC Interrupt Enable ****************************/
void MADC_voidInterruptEnable(void)
{
	/* Enable INT for ADC  */
	SET_BIT(ADCSRA,ADCSRA_ADIE);
}
/************************* End ADC Interrupt Enable ****************************/

/***************************** ADC Interrupt Disable ***************************/
void MADC_voidInterruptDisable(void)
{
	/* Disable INT for ADC  */
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
/*************************** End ADC Interrupt Disable *************************/



/************** ISR ***************/
ISR_(ADC_VECTOR)
{
	if (ADC_u8ISRSourse == SINGLE_CHANNEL_ASYNCH)
	{		
		/* Read ADC Result */
		*ADC_pu16Reading = ADC;
		/* Make ADC state be IDLE because it finished*/
		ADC_u8BusyState = IDLE;
		/* Invoke the callback notification function */
		ADC_pvCallBackNotificationFunc();
		/* Disable ADC Conversion complete interrupt */
		//MADC_voidInterruptDisable();
		
	} 
	else if (ADC_u8ISRSourse == CHAIN_ASYNCH)
	{
		/* Read ADC Result */
		 ADC_pu16Reading[ADC_u8ChainConversionIndex] = ADC;
		 /* Increment ADC Chain Conversion Index */
		 ADC_u8ChainConversionIndex ++;
		
		/* check chain is finished or not */
		if (ADC_u8ChainConversionIndex == ADC_u8ChainSize)
		{
			/* Make ADC state be IDLE because it finished*/
			ADC_u8BusyState = IDLE;
			
			/* Invoke the callback notification function */
			ADC_pvCallBackNotificationFunc();
			
			/* Disable ADC Conversion complete interrupt */
			MADC_voidInterruptDisable();
		} 
		else
		{
			/* Select Channel*/
			ADMUX &= ADC_SELEC_CHANNEL_MASK; 	                          /* Clear the MUX bits in ADMUX register*/
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];  /*Set the required channel into the MUX bits*/
			
			/* Start Conversion */
			SET_BIT(ADCSRA, ADCSRA_ADSC);
	
		}
		
		
	}
	
}
