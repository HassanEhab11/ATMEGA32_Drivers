#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MTWI/MTWI_interface.h"
#include "DS1307_interface.h"

// DS1307 I2C address
#define DS1307_ADDR 0b1101000

void DS1307_Init() {
    // Initialize TWI with the desired speed (400 kHz)
    TWI_Init(_100KBPS);
}

void DS1307_SetTime(u8 hours, u8 minutes, u8 seconds, u8 am_pm) {
    // Start communication
    TWI_SendStart();

    // Select DS1307 and write mode (DS1307 address + Write bit)
    TWI_SendByte(DS1307_ADDR << 1);

    // Set the starting register address to 0x00 (seconds register)
    TWI_SendByte(0x00);

    // Write seconds, minutes, hours, and am/pm to DS1307
    TWI_SendByte(seconds);
    TWI_SendByte(minutes);
    TWI_SendByte(hours);
    TWI_SendByte(am_pm);

    // Send stop condition to end communication
    TWI_SendStop();
}

#if 0
void DS1307_GetTime(u8 *hours, u8 *minutes, u8 *seconds, u8 *am_pm) {
    // Start communication
    TWI_SendStart();

    // Select DS1307 and write mode (DS1307 address + Write bit)
    TWI_SendByte(DS1307_ADDR << 1);

    // Set the starting register address to 0x00 (seconds register)
    TWI_SendByte(0x00);

    // Restart communication
    TWI_SendStart();

    // Select DS1307 and read mode (DS1307 address + Read bit)
    TWI_SendByte((DS1307_ADDR << 1) | 1);

    // Read seconds, minutes, hours, and am/pm from DS1307
    TWI_ReceiveByteWithACK(seconds);
    TWI_ReceiveByteWithACK(minutes);
    TWI_ReceiveByteWithACK(hours);
    TWI_ReceiveByteWithNACK(am_pm);

    // Send stop condition to end communication
    TWI_SendStop();
}
#endif
void DS1307_SetDate(u8 year, u8 month, u8 day) {
    // Start communication
    TWI_SendStart();

    // Select DS1307 and write mode (DS1307 address + Write bit)
    TWI_SendByte(DS1307_ADDR << 1);

    // Set the starting register address to 0x03 (year register)
    TWI_SendByte(0x03);

    // Write year, month, and day to DS1307
    TWI_SendByte(year);
    TWI_SendByte(month);
    TWI_SendByte(day);

    // Send stop condition to end communication
    TWI_SendStop();
}
#if 0
void DS1307_GetDate(u8 *year, u8 *month, u8 *day) {
	u8 Local_u8RecievedByte = 0;
    // Start communication
    TWI_SendStart();

    // Select DS1307 and write mode (DS1307 address + Write bit)
    TWI_SendByte(DS1307_ADDR << 1);

    // Set the starting register address to 0x03 (year register)
    TWI_SendByte(0x03);

    // Restart communication
    TWI_SendStart();

    // Select DS1307 and read mode (DS1307 address + Read bit)
    TWI_SendByte((DS1307_ADDR << 1) | 1);

    // Read year, month, and day from DS1307
    TWI_ReceiveByteWithACK(year);
    TWI_ReceiveByteWithACK(month);
    TWI_ReceiveByteWithNACK(day);

    // Send stop condition to end communication
    TWI_SendStop();
}
#endif



void DS1307_GetTime(u8 *hours, u8 *minutes, u8 *seconds, u8 *am_pm) {
    // Start communication
    TWI_SendStart();

    // Select DS1307 and write mode (DS1307 address + Write bit)
    TWI_SendByte(DS1307_ADDR << 1);

    // Set the starting register address to 0x00 (seconds register)
    TWI_SendByte(0x00);

    // Restart communication
    TWI_SendStart();

    // Select DS1307 and read mode (DS1307 address + Read bit)
    TWI_SendByte((DS1307_ADDR << 1) | 1);

    // Read seconds, minutes, hours, and am/pm from DS1307 in BCD format
    u8 bcd_seconds;
    u8 bcd_minutes;
    u8 bcd_hours;
    u8 am_pm_bit;

    TWI_ReceiveByteWithACK(&bcd_seconds);
    TWI_ReceiveByteWithACK(&bcd_minutes);
    TWI_ReceiveByteWithACK(&bcd_hours);
    TWI_ReceiveByteWithNACK(&am_pm_bit);

    // Convert BCD values to decimal
    *seconds = ((bcd_seconds >> 4) * 10) + (bcd_seconds & 0x0F);
    *minutes = ((bcd_minutes >> 4) * 10) + (bcd_minutes & 0x0F);
    *hours = ((bcd_hours >> 4) * 10) + (bcd_hours & 0x0F);

    // Set the am_pm flag based on the am_pm_bit
    *am_pm = (am_pm_bit & (1 << 5)) ? DS1307_PM : DS1307_AM;

    // Send stop condition to end communication
    TWI_SendStop();
}


void DS1307_GetDate(u8 *year, u8 *month, u8 *day) {
    // Start communication
    TWI_SendStart();

    // Select DS1307 and write mode (DS1307 address + Write bit)
    TWI_SendByte(DS1307_ADDR << 1);

    // Set the starting register address to 0x03 (year register)
    TWI_SendByte(0x03);

    // Restart communication
    TWI_SendStart();

    // Select DS1307 and read mode (DS1307 address + Read bit)
    TWI_SendByte((DS1307_ADDR << 1) | 1);

    // Read year, month, and day from DS1307 in BCD format
    u8 bcd_year;
    u8 bcd_month;
    u8 bcd_day;

    TWI_ReceiveByteWithACK(&bcd_year);
    TWI_ReceiveByteWithACK(&bcd_month);
    TWI_ReceiveByteWithNACK(&bcd_day);

    // Convert BCD values to decimal
    *year = ((bcd_year >> 4) * 10) + (bcd_year & 0x0F);
    *month = ((bcd_month >> 4) * 10) + (bcd_month & 0x0F);
    *day = ((bcd_day >> 4) * 10) + (bcd_day & 0x0F);

    // Send stop condition to end communication
    TWI_SendStop();
}
