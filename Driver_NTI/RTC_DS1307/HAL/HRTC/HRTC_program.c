#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MTWI/MTWI_interface.h"

#include "HRTC_interface.h"
#include "HRTC_config.h"
#include "HRTC_private.h"

#include "../HCLCD/CLCD_interface.h"
#include <util/delay.h>


// Function prototypes for RTC operations

// Initialize the RTC
void HRTC_voidInit(void){
	// Initialize TWI with the required speed 100kHz:
	TWI_Init(_100KBPS);

}

// Set the time on the RTC
TWI_ErrStatus HRTC_voidSetTime(u8 hours, u8 minutes, u8 seconds, u8 am_pm_24){
	TWI_ErrStatus Local_ErrorState = NoError;
	u8 Local_u8Hour = 0;
	u8 temp;
	//step 1 : send Start
	TWI_SendStart();

	//step 2 : check status if not Start Success return false
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != START_ACK)
	{
		Local_ErrorState = StartConditionErr;
		return Local_ErrorState;
	}
	//step 3 : send address 1101000  + W
	TWI_SendByte(RTC_SLA_ADDRESS_W);

	//step 4 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
		return Local_ErrorState;
	}
	//step 5 : send Time Address
	TWI_SendByte((u8)RTC_TIME_ADDRESS);

	//step 6 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 7 : send Time -----> seconds
	TWI_SendByte(DEC_TO_BCD(seconds));

	//step 8 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 8 : send Time -----> minutes
	TWI_SendByte(DEC_TO_BCD(minutes));

	//step 9 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 10 : send Time -----> hours
	if (am_pm_24 == AM){
		Local_u8Hour = RTC_AM_MASK;
		temp = DEC_TO_BCD(hours);
		TWI_SendByte(Local_u8Hour | temp);

	} else if (am_pm_24 == PM) {
		Local_u8Hour = RTC_PM_MASK;
		temp = DEC_TO_BCD(hours);
		TWI_SendByte(Local_u8Hour | temp);

	} else if(am_pm_24 == _24_Hours){
		Local_u8Hour = RTC_24_MASK;
		temp = DEC_TO_BCD(hours);
		TWI_SendByte(DEC_TO_BCD(Local_u8Hour | temp));

	}


	//step 11 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 12 : send Stop
	TWI_SendStop();
	return Local_ErrorState;
}

// Get the current time from the RTC
TWI_ErrStatus HRTC_voidGetTime(u8* hours, u8* minutes, u8* seconds, u8* am_pm){
	TWI_ErrStatus Local_ErrorState = NoError;
	//step 1 : send Start
	TWI_SendStart();
	//step 2 : check status if not Start Success return false
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != START_ACK)
	{
		Local_ErrorState = StartConditionErr;
		return Local_ErrorState;
	}

	//step 3 : send address 1101000  + W
	TWI_SendByte(RTC_SLA_ADDRESS_W);

	//step 4 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
		return Local_ErrorState;
	}
	//step 5 : send Data Address
	TWI_SendByte((u8)RTC_TIME_ADDRESS);
	//step 6 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 7 : send Repeated Start
	TWI_SendStart();
	//step 8 : check status
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != REP_START_ACK)
	{
		Local_ErrorState = RepeatedStartErr;
		return Local_ErrorState;
	}

	//step 9 : send address 1101000  + R
	TWI_SendByte(RTC_SLA_ADDRESS_R);

	//step 10 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
		return Local_ErrorState;
	}


	//step 11 : Get Time -----> second
	TWI_ReceiveByteWithACK(seconds);
	*seconds = BCD_TO_DEC(*seconds);
	//step 11 : Get Time -----> minute
	TWI_ReceiveByteWithACK(minutes);
	*minutes = BCD_TO_DEC(*minutes);
	//step 11 : Get Time -----> hour

	TWI_ReceiveByteWithNACK(hours);
	* am_pm =*hours & 0xF0;
	if (* am_pm == RTC_AM_MASK ){
		* am_pm = AM;
		*hours &= 0x0F;
		*hours = BCD_TO_DEC(*hours);
	} else if (* am_pm == RTC_PM_MASK) {
		* am_pm = PM;
		*hours &= 0x0F;
		*hours = BCD_TO_DEC(*hours);
	} else{
		* am_pm = _24_Hours;
		*hours = BCD_TO_DEC(*hours);
	}

	//step 12 : send Stop
	TWI_SendStop();

	return Local_ErrorState;
}

// Set the date on the RTC
TWI_ErrStatus HRTC_voidSetDate(u16 year, u8 month, u8 day){
	TWI_ErrStatus Local_ErrorState = NoError;
	//step 1 : send Start
	TWI_SendStart();

	//step 2 : check status if not Start Success return false
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != START_ACK)
	{
		Local_ErrorState = StartConditionErr;
		return Local_ErrorState;
	}
	//step 3 : send address 1101000  + W
	TWI_SendByte(RTC_SLA_ADDRESS_W);

	//step 4 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
		return Local_ErrorState;
	}
	//step 5 : send Data Address
	TWI_SendByte((u8)RTC_DATE_ADDRESS);
	//step 6 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 7 : send Date -----> Day
	TWI_SendByte(DEC_TO_BCD(day));

	//step 8 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 8 : send Time -----> month
	TWI_SendByte(DEC_TO_BCD(month));

	//step 9 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 10 : send Time -----> year

	TWI_SendByte(DEC_TO_BCD(year));

	//step 11 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 12 : send Stop
	TWI_SendStop();
	return Local_ErrorState;


}

// Get the current date from the RTC
TWI_ErrStatus HRTC_voidGetDate(u8* year, u8* month, u8* day){
	TWI_ErrStatus Local_ErrorState = NoError;

	//step 1 : send Start
	TWI_SendStart();

	//step 2 : check status if not Start Success return false
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != START_ACK)
	{
		Local_ErrorState = StartConditionErr;
		return Local_ErrorState;
	}

	//step 3 : send address 1101000  + W
	TWI_SendByte(RTC_SLA_ADDRESS_W);

	//step 4 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
		return Local_ErrorState;
	}

	//step 5 : send Data Address
	TWI_SendByte((u8)RTC_DATE_ADDRESS);
	//step 6 : check status TWI_MT_DATA_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
		return Local_ErrorState;
	}

	//step 7 : send Repeated Start
	TWI_SendStart();
	//step 8 : check status
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != REP_START_ACK)
	{
		Local_ErrorState = RepeatedStartErr;
		return Local_ErrorState;
	}


	//step 9 : send address 1101000  + R
	TWI_SendByte(RTC_SLA_ADDRESS_R);

	//step 10 : check status TWI_MT_SLA_W_ACK
	TWI_GetStatus(&Local_ErrorState);
	if(Local_ErrorState != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
		return Local_ErrorState;
	}

	//step 11 : Get Date -----> day
	TWI_ReceiveByteWithACK(day);
	*day = BCD_TO_DEC(*day);
	//step 11 : Get Date -----> month
	TWI_ReceiveByteWithACK(month);
	*month = BCD_TO_DEC(*month);
	//step 11 : Get Date -----> year
	TWI_ReceiveByteWithNACK(year);
	*year = BCD_TO_DEC(*year);

	//step 12 : send Stop
	TWI_SendStop();
	return Local_ErrorState;

}


// Convert a decimal number to BCD format
u8 DEC_TO_BCD(u8 decimal) {
	u8 tens = decimal / 10;
	u8 ones = decimal % 10;

	// Combine the tens and ones digits into a BCD byte
	u8 bcd = (tens << 4) | ones;

	return bcd;
}


// Convert a BCD value to decimal
u8 BCD_TO_DEC(u8 bcd) {
	u8 tens = (bcd >> 4) & 0x0F; // Extract the tens digit
	u8 ones = bcd & 0x0F;        // Extract the ones digit

	return (tens * 10) + ones;        // Convert and return the decimal value
}
