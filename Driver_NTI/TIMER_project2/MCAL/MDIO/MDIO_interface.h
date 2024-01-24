/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): DIO         *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_



typedef enum
{
	DIO_u8PORT_INPUT ,
	DIO_u8PORT_OUTPUT = 0xFF
	}dio_u8portdirec_t;

typedef enum
{
	DIO_u8PORT_LOW ,
	DIO_u8PORT_HIGH = 0xFF
}dio_u8portvalue_t;

typedef enum
{
	DIO_u8PIN0 ,
	DIO_u8PIN1 ,
	DIO_u8PIN2 ,
	DIO_u8PIN3 ,
	DIO_u8PIN4 ,
	DIO_u8PIN5 ,
	DIO_u8PIN6 ,
	DIO_u8PIN7
	}dio_u8pin_t;

typedef enum
{
	DIO_u8PORTA ,
	DIO_u8PORTB ,
	DIO_u8PORTC ,
	DIO_u8PORTD
	}dio_u8port_t;
typedef enum
{
	DIO_u8PIN_INPUT ,
	DIO_u8PIN_OUTPUT
	}dio_direc_t;

typedef enum
{
	DIO_u8PIN_LOW ,
	DIO_u8PIN_HIGH
}dio_value_t;



/*
 *	@brief  :	Set Pin Direction
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_u8Pin  Pin Needed To Set Direction [DIO_u8PIN0 to DIO_u8PIN7]
 *	@param  :	Copy_Direction Direction [DIO_u8PIN_INPUT, DIO_u8PIN_OUTPUT]
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_SetPinDirection (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin, dio_direc_t Copy_Direction);
/*
 *	@brief  :	Set Port Direction
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_Direction Direction [DIO_u8PORT_INPUT, DIO_u8PORT_OUTPUT]
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_SetPortDirection (dio_u8port_t Copy_u8Port, dio_u8portdirec_t Copy_Direction);

/*
 *	@brief  :	Set Pin Value
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_u8Pin  Pin Needed To Set Direction [DIO_u8PIN0 to DIO_u8PIN7]
 *	@param  :	Copy_Direction Direction [DIO_u8PIN_LOW, DIO_u8PIN_HIGH]
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_SetPinValue (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin, dio_value_t Copy_Value);
/*
 *	@brief  :	Set Pin Value
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_Direction Direction [DIO_u8PORT_LOW, DIO_u8PORT_HIGH]
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_SetPortValue (dio_u8port_t Copy_u8Port, dio_u8portvalue_t Copy_Value);

/*
 *	@brief  :	Get Pin Value
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_u8Pin  Pin Needed To Get its Value [DIO_u8PIN0 to DIO_u8PIN7]
 *	@param  :	Copy_pu8Value Pointer TO The Value In This Pin
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_GetPinValue (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin, u8* Copy_pu8Value);
/*
 *	@brief  :	Get Pin Value
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_pu8Value Pointer TO The Value In This Port
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_GetPortValue (dio_u8port_t Copy_u8Port, u8* Copy_pu8Value);
/*
 *	@brief  :	Toggle Pin Value
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_u8Pin  Pin Needed To Toggle [DIO_u8PIN0 to DIO_u8PIN7]
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_TogglePinValue (dio_u8port_t Copy_u8Port, dio_u8pin_t Copy_u8Pin);
/*
 *	@brief  :	And Value With Port
 *	@param  :	Copy_u8Port Port Which Included Pin	[DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD]
 *	@param  :	Copy_u8Value Value We Needed to And It With Port
  *	@param  :	Copy_u8Result Pointer To Store Anding Result
 *	@retval :	error_state_t [0 -> DIO_NOK, 1 -> DIO_OK]
 *
 **/
error_state_t	MDIO_AndValueWithPort (dio_u8port_t Copy_u8Port, u8 Copy_u8Value, u8 *Copy_u8Result);

#endif /* DIO_INTERFACE_H_ */
