/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TIMER       *********************/
/******************    Version    : 1.00        *********************/
/********************************************************************/
/********************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

#include "MTIMER1_config.h"
#include "MTIMER1_interface.h"
#include "MTIMER1_private.h"

static u16 TIMER1_PRESCALLER_ARR[5] = {NO_PRESCALER, PRESCALER_8, PRESCALER_64, PRESCALER_256, PRESCALER_1024};

static void (*ICU_pvCallBackFunc)(void) = NULL;
static void (*TIMER1_pvCallBackNotificationFunc)(void) = NULL;

static u32 current_ov_count;


static u32 current_ov_count;

#if TIMER1_MODE == TIMER1_NORMAL_MODE
static u32 NORMAL_u32NoOfOverFlow = 0;
static u16 NORMAL_u16NoOfRemTicks = 0;
#elif TIMER1_MODE == TIMER1_CTC_MODE
static u32 CTC_u32NoOfCompMatch;
#endif


/**************************** Timer1 Init *****************************/
void MTIMER1_voidInit(void)
{
    #if TIMER1_MODE == TIMER1_NORMAL_MODE
    CLR_BIT(TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_WGM11);
    CLR_BIT(TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_WGM13);


    /* Enable Overflow INT */
    SET_BIT(TIMSK, TIMSK_TOIE1);

    #elif TIMER1_MODE == TIMER1_CTC_MODE
    /* Enable CTC Mode */
    CLR_BIT(TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_WGM11);
    SET_BIT(TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_WGM13);

    /* Select OC1A Pin Mode */
    switch (OC1A_MODE)
    {
        case OC1A_DISCONNECTED:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_SET:
            SET_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        default:
            break;
    }

    /* Select OC1B Pin Mode */
    switch (OC1B_MODE)
    {
        case OC1B_DISCONNECTED:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_SET:
            SET_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        default:
            break;
    }

    /* Enable CTC INT */
    SET_BIT(TIMSK, TIMSK_OCIE1A);

    #endif
}

/********************** Timer1 Set Time in ms *****************************/
error_state_t MTIMER1_enumSetTime_ms(u32 Copy_u32DesiredTime, void (*Copy_pvCallBackFunc)(void))
{
    error_state_t Local_ErrorState = TIMER1_OK;

    // Initialize callback function globally
    TIMER1_pvCallBackNotificationFunc = Copy_pvCallBackFunc;

    /* Get prescaler value */
    f32 Local_u32PrescDivFact = (f32)TIMER1_PRESCALLER_ARR[TIMER1_PRESCALLER_SELEC - 1];

    // Calculate total tick time in Microseconds
    f32 Local_u32TickTime = Local_u32PrescDivFact / CRYSTAL_FREQ;

    // Calculate total tick number
    u32 Local_u32TotalTicks = (Copy_u32DesiredTime * 1000) / Local_u32TickTime;

    #if TIMER1_MODE == TIMER1_NORMAL_MODE
    NORMAL_u32NoOfOverFlow = Local_u32TotalTicks / TIMER1_MAX_TICK;
    NORMAL_u16NoOfRemTicks = Local_u32TotalTicks % TIMER1_MAX_TICK;
    if (NORMAL_u16NoOfRemTicks != 0)
    {
        NORMAL_u16NoOfRemTicks = TIMER1_MAX_TICK - NORMAL_u16NoOfRemTicks;
        TCNT1 = NORMAL_u16NoOfRemTicks ;

        NORMAL_u32NoOfOverFlow++;
    }

    #elif TIMER1_MODE == TIMER1_CTC_MODE
    u16 Local_u16DivisionValue = TIMER1_MAX_VALUE;
    while (Local_u32TotalTicks % Local_u16DivisionValue != 0)
    {
        Local_u16DivisionValue--;
    }
    CTC_u32NoOfCompMatch = Local_u32TotalTicks / Local_u16DivisionValue;
    OCR1AH = (u8)(Local_u16DivisionValue >> 8);
    OCR1AL = (u8)(Local_u16DivisionValue & 0xFF);

    #endif

    return Local_ErrorState;
}

/********************* Timer1 Start **************************/
error_state_t MTIMER1_enumStart(void)
{
    error_state_t Local_ErrorState = TIMER1_OK;
    TCCR1B &= TIMER1_PRESCALLER_MASK;
    TCCR1B |= TIMER1_PRESCALLER_SELEC;

    return Local_ErrorState;
}

/********************* Timer1 Stop **************************/
error_state_t MTIMER1_enumStop(void)
{
    error_state_t Local_ErrorState = TIMER1_OK;
    TCCR1B &= TIMER1_PRESCALLER_MASK;
    return Local_ErrorState;
}

error_state_t MTIMER1_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
    if (Copy_pvCallBackFunc != NULL)
    {
        TIMER1_pvCallBackNotificationFunc = Copy_pvCallBackFunc;
        return TIMER1_OK;
    }
    else
    {
        return TIMER1_NOK;
    }
}

/******************************************************************************/

void MTIMER1_voidNoPrescaler(void)
{
	TCCR1B &= TIMER1_PRESCALLER_MASK;
	TCCR1B |= TIMER1_NO_PRESCALER;
}



void MTIMER1_SetChannelAComMatchValue(u16 Copy_u16CompareMatch)
{
	OCR1A = Copy_u16CompareMatch;

}


/********************* Initialization PWM1 **************************/
error_state_t MPWM1_enumInit(void)
{
    error_state_t Local_ErrorState = TIMER1_OK;
    #if TIMER1_MODE == TIMER1_FAST_PWM
    SET_BIT(TCCR1A, TCCR1A_WGM10);
    SET_BIT(TCCR1A, TCCR1A_WGM11);
    SET_BIT(TCCR1B, TCCR1B_WGM12);
    SET_BIT(TCCR1B, TCCR1B_WGM13);

    /* Select OC1A Pin Mode */
    switch (OC1A_MODE)
    {
        case OC1A_DISCONNECTED:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_SET:
            SET_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        default:
            break;
    }

    /* Select OC1B Pin Mode */
    switch (OC1B_MODE)
    {
        case OC1B_DISCONNECTED:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_SET:
            SET_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        default:
            break;
    }

    if (FAST_PWM_MODE == FAST_PWM_INVERTED_MODE)
    {
        SET_BIT(TCCR1A, TCCR1A_COM1A0);
        SET_BIT(TCCR1A, TCCR1A_COM1A1);
    }
    else if (FAST_PWM_MODE == FAST_PWM_NON_INVERTED_MODE)
    {
        CLR_BIT(TCCR1A, TCCR1A_COM1A0);
        SET_BIT(TCCR1A, TCCR1A_COM1A1);
    }

    #elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM
    SET_BIT(TCCR1A, TCCR1A_WGM10);
    SET_BIT(TCCR1B, TCCR1B_WGM13);

    /* Select OC1A Pin Mode */
    switch (OC1A_MODE)
    {
        case OC1A_DISCONNECTED:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case OC1A_SET:
            SET_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        default:
            break;
    }

    /* Select OC1B Pin Mode */
    switch (OC1B_MODE)
    {
        case OC1B_DISCONNECTED:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case OC1B_SET:
            SET_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        default:
            break;
    }

    if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_INVERTED_MODE)
    {
        SET_BIT(TCCR1A, TCCR1A_COM1A0);
        SET_BIT(TCCR1A, TCCR1A_COM1A1);
    }
    else if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED_MODE)
    {
        CLR_BIT(TCCR1A, TCCR1A_COM1A0);
        SET_BIT(TCCR1A, TCCR1A_COM1A1);
    }
    #endif

    return Local_ErrorState;
}

error_state_t MPWM1_enumSetDutyCycle(u8 Copy_u8DutyCycle)
{
    error_state_t Local_ErrorState = TIMER1_OK;
    #if TIMER1_MODE == TIMER1_FAST_PWM
    if (FAST_PWM_MODE == FAST_PWM_INVERTED_MODE)
    {
        OCR1AH = (u8)((((100 - Copy_u8DutyCycle) * TIMER1_MAX_TICK) / 100) >> 8);
        OCR1AL = (u8)((((100 - Copy_u8DutyCycle) * TIMER1_MAX_TICK) / 100) & 0xFF);
    }
    else if (FAST_PWM_MODE == FAST_PWM_NON_INVERTED_MODE)
    {
        OCR1AH = (u8)(((Copy_u8DutyCycle * TIMER1_MAX_TICK) / 100) >> 8);
        OCR1AL = (u8)(((Copy_u8DutyCycle * TIMER1_MAX_TICK) / 100) & 0xFF);
    }

    #elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM
    if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_INVERTED_MODE)
    {
        OCR1AH = (u8)((((100 - Copy_u8DutyCycle) * TIMER1_MAX_TICK) / 100) >> 8);
        OCR1AL = (u8)((((100 - Copy_u8DutyCycle) * TIMER1_MAX_TICK) / 100) & 0xFF);
    }
    else if (PHASE_CORRECT_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED_MODE)
    {
        OCR1AH = (u8)(((Copy_u8DutyCycle * TIMER1_MAX_TICK) / 100) >> 8);
        OCR1AL = (u8)(((Copy_u8DutyCycle * TIMER1_MAX_TICK) / 100) & 0xFF);
    }
    #endif

    return Local_ErrorState;
}

error_state_t MPWM1_enumStart(void)
{
    error_state_t Local_ErrorState = TIMER1_OK;
    TCCR1B &= TIMER1_PRESCALLER_MASK;
    TCCR1B |= TIMER1_PRESCALLER_SELEC;
    return Local_ErrorState;
}

error_state_t MPWM1_enumStop(void)
{
    error_state_t Local_ErrorState = TIMER1_OK;
    TCCR1B &= TIMER1_PRESCALLER_MASK;
    return Local_ErrorState;
}

u32 MTIMER1_u32GetCounts(void)
{
    TCNT1 = 0;
    u32 count = TCNT1 + (current_ov_count * 65536UL);
    return count;
}

/************************ Timer 1 ************************/
void MTIMER1_voidSetTimerValue(u16 Copy_u16TimerValue)
{
    TCNT1 = Copy_u16TimerValue;
}


u16 MTIMER1__u16ReadTimerValue(void)
{
    // Read the current Timer1 value
    u16 timerValue = TCNT1;
    return timerValue;
}

/************************ Counter 1 ************************/
void MCOUNTER1_voidCounterInit(void)
{
    // Configure Timer1 for counter mode with desired edge mode (you need to define the edge mode)
    TCCR1B &= TIMER1_PRESCALLER_MASK;
    TCCR1B |= COUNTER_EDGE_MODE;
}

u8 MCOUNTER1_u8GetCounterValue(void)
{
    return TCNT1;
}
/******************************* TIMER 1 ICU ********************/

void ICU_voidInit(void)
{
    // Configure Timer1 for Input Capture Mode
    TCCR1A = 0;  // Clear TCCR1A register
    TCCR1B = 0;  // Clear TCCR1B register

    // Configure the Input Capture Edge (Rising/Falling)
	/* Set trigger source to rising edge initially */
	SET_BIT(TCCR1B,TCCR1B_ICES1);

    // Enable the Input Capture Interrupt
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

error_state_t ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	error_state_t Local_u8ErrorState = R_OK;

	if (Copy_u8Edge == ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if (Copy_u8Edge == ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		Local_u8ErrorState = R_NOK;
	}
	return Local_u8ErrorState;
}


void ICU_voidEnableInterrupt(void)
{
    SET_BIT(TIMSK, TIMSK_TICIE1); // Enable the Timer1 Input Capture interrupt
}

void ICU_voidDisableInterrupt(void)
{
    CLR_BIT(TIMSK, TIMSK_TICIE1); // Disable the Timer1 Input Capture interrupt
}

u16 ICU_u16ReadInputCapture(void)
{
    u16 capturedValue;

    // Read the Input Capture Register ICR1
    capturedValue = ICR1;

    return capturedValue;
}

u8 ICU_u8GetInputCaptureFlag (void)
{
	return 	GET_BIT(TIFR, TIFR_ICF1);

}
void ICU_u8ClearInputCaptureFlag (void)
{
	SET_BIT(TIFR, TIFR_ICF1);
}

void ICU_voidNoiseCanceler(void)
{
	SET_BIT(TCCR1B, TCCR1B_ICNC1);
}

error_state_t ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
    error_state_t Local_u8ErrorState = TIMER1_OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}



    return Local_u8ErrorState;
}


/********************************* ISR Timer/Counter1 Overflow  ***********************************/
#if TIMER1_MODE == TIMER1_NORMAL_MODE
ISR_ST(TIMER1_OVF_VECTOR)
{
	MDIO_SetPinValue(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_HIGH); // for Debugging

    static u32 Local_u32Counter = 0;
    Local_u32Counter++;
    current_ov_count = Local_u32Counter;

    if (Local_u32Counter == NORMAL_u32NoOfOverFlow)
    {

        TCNT1 = NORMAL_u16NoOfRemTicks;
        TIMER1_pvCallBackNotificationFunc();
        Local_u32Counter = 0;
    }
}
#elif TIMER1_MODE == TIMER1_CTC_MODE

ISR_ST(TIMER1_COMPA_VECTOR)
{
    static u32 Local_u32Counter = 0;
    Local_u32Counter++;
    if (Local_u32Counter == CTC_u32NoOfCompMatch)
    {
        TIMER1_pvCallBackNotificationFunc[1]();
        Local_u32Counter = 0;
    }
}
#endif
/********************************* ICU_ISR  ***********************************/
ISR_ST(TIMER1_CAPT_VECTOR)
{

	if(ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc();
	}
}













