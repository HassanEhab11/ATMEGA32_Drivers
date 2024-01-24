/****** LIBIRARY INCLUDE SECTION *******/
#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"
#include <util/delay.h>
/***** MCAL INCLUDE SECTION ***********/
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MADC/MADC_interface.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "MCAL/MTIMER0/MTIMER0_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"

/***** HAL INCLUDE SECTION **************/
#include "HAL/HPB/HPB_interface.h"
#include "HAL/HSSD/HSSD_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HCLCD/CLCD_interface.h"
#include "HAL/HKEYPAD/KEYPAD_interface.h"
#include "HAL/HDCMOTOR/HDCMOTOR_interface.h"

/******** FUNCTION PROTOTYPE ***********/

error_state_t GetDutyCycleAndDirection1(u8* Copy_u8duty, u8* Copy_u8direction );
/******* GLOBAL VARIABLE *************/


void main(void)
{
	/*** Initialization Section ***/
	MGIE_VoidEnable();


	HCLCD_Init();
	HKPD_voidInit();
	HLED_voidInit(LED_BLUE);
	HLED_voidInit(LED_RED);
	HLED_voidInit(LED_YELLOW);
	HDCMOTOR_voidInit();

	u8 Local_u8Dutycycle;
	u8 Local_u8Direction;



	u8 Local_u8state;



	while(1)
	{
		GetDutyCycleAndDirection1(&Local_u8Dutycycle, &Local_u8Direction);
		HCLCD_Clear();
		if (Local_u8Direction == HDCMOTOR_CW) {
			HCLCD_GoToXY(0,0);
			HCLCD_SendString("Motor Rotate in");
			HCLCD_GoToXY(1,0);
			HCLCD_SendString("CW Direction");
			HCLCD_GoToXY(2,0);
			HCLCD_SendString("Duty Cycle = ");
			HCLCD_SendNumber(Local_u8Dutycycle);
			HDCMOTOR_MoveCW(Local_u8Dutycycle);
		} else if (Local_u8Direction == HDCMOTOR_CCW) {
			HCLCD_GoToXY(0,0);
			HCLCD_SendString("Motor Rotate in");
			HCLCD_GoToXY(1,0);
			HCLCD_SendString("CW Direction");
			HCLCD_GoToXY(2,0);
			HCLCD_SendString("Duty Cycle = ");
			HCLCD_SendNumber(Local_u8Dutycycle);
			HDCMOTOR_MoveCCW(Local_u8Dutycycle);
		} else {
			//
		}
		HCLCD_GoToXY(3,0);
		HCLCD_SendString("1)NewDuty 2)StopMotor");
		HKPD_u8GetPressedKey(&Local_u8state);
		HDCMOTOR_voidStop();

		HCLCD_Clear();
		HCLCD_SendNumber(Local_u8state);
		_delay_ms(1000);
		if (Local_u8state == 2 ){
			HCLCD_Clear();
			HCLCD_GoToXY(0,0);
			HCLCD_SendString("Motor Stopped");
			_delay_ms(1000);
		}

	}

}


error_state_t GetDutyCycleAndDirection1(u8* Copy_u8duty, u8* Copy_u8direction )
{
	error_state_t Local_errorstate = R_OK;
	u8 digit;
	u8 isFirstDigit = 1;

	HLED_voidToggle(LED_BLUE);
	HCLCD_Clear();
	HCLCD_GoToXY(0, 0);
	HCLCD_SendString("Enter Duty Cycle (0 - 100) :");

	// Get duty cycle input
	do {

		HKPD_u8GetPressedKey(&digit); // Assuming it returns 0-9 for digits and 10 for Enter
		if (digit >= 0 && digit <= 9) {

			if (isFirstDigit) {
				*Copy_u8duty = digit;
				isFirstDigit = 0;
			} else {
				*Copy_u8duty = *Copy_u8duty * 10 + digit; // Build the duty cycle value
			}
		} else if (digit == 10) {
			Local_errorstate = R_OK;
			break; // Get Duty cycle Value
		} else {
			Local_errorstate = R_NOK; // Return an error value or handle as needed
			// Display an error message on the LCD to inform the user
			HCLCD_Clear();
			HCLCD_GoToXY(2, 0);
			HCLCD_SendString("  Invalid Input");
			_delay_ms(1000);
			HCLCD_Clear();
			HCLCD_GoToXY(0, 0);
			HCLCD_SendString("Enter Duty Cycle (0 - 100) :");
		}
	} while (1);

	// Validate and limit duty cycle to the 0-100 range
	if (*Copy_u8duty > 100) {
		*Copy_u8duty = 100;
	}

	// Print duty cycle value in LCD
	HCLCD_GoToXY(1, 11);
	HCLCD_SendNumber(*Copy_u8duty);

	// Ask the user to enter the direction of the motor (1->CW and 2->CCW)
	HCLCD_GoToXY(2, 0);
	HCLCD_SendString("Enter Motor Dir (1>CW, 2>CCW) :");
	do{
		HKPD_u8GetPressedKey(Copy_u8direction);
		if(*Copy_u8direction == 1 || *Copy_u8direction == 2 )
		{
			HCLCD_GoToXY(3, 12);
			HCLCD_SendNumber(*Copy_u8direction);
			_delay_ms(1000);
			Local_errorstate = R_OK;
			break;
		}
		else
		{
			Local_errorstate = R_NOK;
			HCLCD_Clear();
			HCLCD_GoToXY(2, 0);
			HCLCD_SendString("  Invalid Input");
			_delay_ms(1000);
			HCLCD_Clear();
			HCLCD_GoToXY(0, 0);
			HCLCD_SendString("Enter Duty Cycle (0 - 100) :");
			HCLCD_GoToXY(1, 11);
			HCLCD_SendNumber(*Copy_u8duty);
			HCLCD_GoToXY(2, 0);
			HCLCD_SendString("Enter Motor Dir (1>CW, 2>CCW) :");
		}

	}while(1);


	return Local_errorstate;
}


