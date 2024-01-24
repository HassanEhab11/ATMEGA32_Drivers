/*
 * STD_TYPES.h
 *
 * Created: 1/25/2023 1:19:25 AM
 *  Author: hassa
 */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef	unsigned char	u8;
typedef	  signed char	s8;

typedef	unsigned short	u16;
typedef	  signed short	s16;

typedef	unsigned long	u32;
typedef	signed long		s32;

typedef	float			f32;
typedef	double			f64;
typedef	long double		f128;

typedef enum
{
	R_NOK        ,
	R_OK         ,
	TIMER0_OK    ,
	TIMER0_NOK   ,
	TIMER2_OK    ,
	TIMER2_NOK   ,
	NULL_POINTER ,
	BUSY_FUNC	 ,
	DCMOTOR_OK	,
	DCMOTOR_NOK	,
	TIMER1_OK,
	TIMER1_NOK,
	USART_OK,
	USART_NOK,
	TIME_OUT
}error_state_t;

#define NULL 0
typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteWithAckErr,


}TWI_ErrStatus;
/*typedef enum
{
	RESET_		  ,
	INT0_		  ,
	INT1_		  ,
	INT2_		  ,
	TIMER2_COMP_  ,
	TIMER2_OVF_	  ,
	TIMER1_CAPT_  ,
	TIMER1_COMPA_ ,
	TIMER1_COMPB_ ,
	TIMER1_OVF_	  ,
	TIMER0_COMP_  ,
	TIMER0_OVF_	  ,
	SPI_STC_	  ,
	USART_RXC_	  ,
	USART_UDRE_	  ,
	USART_TXC_	  ,
	ADC_		  ,
	EE_RDY_		  ,
	ANA_COMP_	  ,
	TWI_		  ,
	SPM_RDY_

	}int_sourse_t;*/
#define	RESET_VECTOR			__vector_0
//#define	INT0_VECTOR				__vector_1
//#define	INT1_VECTOR				__vector_2
//#define	INT2_VECTOR				__vector_3
//#define	TIMER2_COMP_VECTOR		__vector_4
//#define	TIMER2_OVF_VECTOR		__vector_5
//#define	TIMER1_CAPT_VECTOR		__vector_6
//#define	TIMER1_COMPA_VECTOR		__vector_7
//#define	TIMER1_COMPB_VECTOR		__vector_8
//#define	TIMER1_OVF_VECTOR		__vector_9
//#define	TIMER0_COMP_VECTOR		__vector_10
//#define	TIMER0_OVF_VECTOR		__vector_11
#define	SPI_STC_VECTOR			__vector_12
#define	USART_RXC_VECTOR		__vector_13
#define	USART_UDRE_VECTOR		__vector_14
#define	USART_TXC_VECTOR		__vector_15
//#define	ADC_VECTOR				__vector_16
#define	EE_RDY_VECTOR			__vector_17
#define	ANA_COMP_VECTOR			__vector_18
#define	TWI_VECTOR				__vector_19
#define	SPM_RDY_VECTOR			__vector_20

/*#define ISR_ST(vector_)            \
  void vector_ (void) __attribute__ ((signal)); \
  void vector_ (void)
*/

#endif /* STD_TYPES_H_ */
