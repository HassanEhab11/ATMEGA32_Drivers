#ifndef DS1307_DRIVER_H
#define DS1307_DRIVER_H

// Define constants for AM and PM
#define DS1307_AM 0
#define DS1307_PM 1

// Function to initialize the DS1307 RTC
void DS1307_Init();

// Function to set the time on the DS1307 RTC
void DS1307_SetTime(u8 hours, u8 minutes, u8 seconds, u8 am_pm);

// Function to get the time from the DS1307 RTC
void DS1307_GetTime(u8 *hours, u8 *minutes, u8 *seconds, u8 *am_pm);

// Function to set the date on the DS1307 RTC
void DS1307_SetDate(u8 year, u8 month, u8 day);

// Function to get the date from the DS1307 RTC
void DS1307_GetDate(u8 *year, u8 *month, u8 *day);

#endif /* DS1307_DRIVER_H */
