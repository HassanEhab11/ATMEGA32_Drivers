/*
 * ADC_interface.h
 *
 * Created: 1/29/2023 8:44:09 AM
 *  Author: Hassan Ehab
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



typedef struct
{
	u16 *Reading;
	u8 *ADC_Channels;
	u8 Size; 
	void (*ADC_pvNotificationFunc)(void);
	}Chain_t;


typedef enum
{
	ADC0	=0			,
	ADC1				,
	ADC2				,
	ADC3				,
	ADC4				,
	ADC5				,
	ADC6				,
	ADC7				,
	ADC0_ADC0_10x		,
	ADC1_ADC0_10x		,
	ADC0_ADC0_200x		,
	ADC1_ADC0_200x		,
	ADC2_ADC2_10x		,
	ADC3_ADC2_10x		,
	ADC2_ADC2_200x		,
	ADC3_ADC2_200x		,
	ADC0_ADC1_1x		,
	ADC1_ADC1_1x		,
	ADC2_ADC1_1x		,
	ADC3_ADC1_1x		,
	ADC4_ADC1_1x		,
	ADC5_ADC1_1x		,
	ADC6_ADC1_1x		,
	ADC7_ADC1_1x		,
	ADC0_ADC2_1x		,
	ADC1_ADC2_1x		,
	ADC2_ADC2_1x		,
	ADC3_ADC2_1x		,
	ADC4_ADC2_1x		,
	ADC5_ADC2_1x		,
	_1022_VOLT			,
	GND
	}Channel_t;

/*
 * @brief  : ADC Initialization (Voltage Ref, R/L Adjust, Auto Trigger [ENABLE Or DISABLE], Auto Trigger source,
 *					    INT[ENABLE Or DISABLE], Prescaler, ADC Enable) 
 * @param  : No Parameter
 * @retval : void
 */
void ADC_voidInit(void);

/*
 * @brief  : ADC Start Conversion Synchronous [Read Value, Pooling Function Wait Until The Reading Is Completed]
 * @param  : Copy_u8Channel [ADC0 --> ADC7]
 * @param  : Copy_pu16Reading [Pointer To Save Reading]
 * @retval : ErrorState [0 -> ADC NOK, 1 -> ADC OK]
 */
error_state_t ADC_StartConversionSynch(Channel_t Copy_Channel, u16 *Copy_pu16Reading);

/*
 * @brief  : ADC Start Conversion ASynchronous [Read Value, This Function Depend On INT]
 * @param  : Copy_u8Channel [ADC0 --> ADC7]
 * @param  : Copy_pu16Reading [Pointer To Save Reading]
 * @param  : Copy_pvNotificationFunc [Pointer To Function Needed To Executed]
 * @retval : ErrorState [0 -> ADC NOK, 1 -> ADC OK]
 */
error_state_t ADC_StartConversionAsynch(Channel_t Copy_Channel, u16 *Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void));

/*
 * @brief  : ADC Start Chain Conversion ASynchronous [Reading Values From More Than One Channel]
 * @param  : Copy_Chain [Pointer To Structure Including 
 *            [pointer to array to save result ,pointer to array to save channels, no of channel
 *			  , pointer to function]]
 * @retval : ErrorState [0 -> ADC NOK, 1 -> ADC OK]
 */
error_state_t ADC_StartChainConversionAsynch(Chain_t *Copy_Chain);

/*
 * @brief  : ADC INT Enable 
 * @param  : void
 * @retval : void
 */
void ADC_voidInterruptEnable(void);

/*
 * @brief  : ADC INT Disable 
 * @param  : void
 * @retval : void
 */
void ADC_voidInterruptDisable(void);

#endif /* ADC_INTERFACE_H_ */