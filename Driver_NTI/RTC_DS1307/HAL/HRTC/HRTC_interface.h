#ifndef HRTC_INTERFACE_H
#define HRTC_INTERFACE_H

// Define constants for AM and PM
#define AM 0
#define PM 1
#define _24_Hours	2

// Function prototypes for RTC operations

// Initialize the RTC
void HRTC_voidInit(void);

// Set the time on the RTC
TWI_ErrStatus HRTC_voidSetTime(u8 hours, u8 minutes, u8 seconds, u8 am_pm_24);

// Get the current time from the RTC
TWI_ErrStatus HRTC_voidGetTime(u8* hours, u8* minutes, u8* seconds, u8* am_pm);

// Set the date on the RTC
TWI_ErrStatus HRTC_voidSetDate(u16 year, u8 month, u8 day);

// Get the current date from the RTC
TWI_ErrStatus HRTC_voidGetDate(u8* year, u8* month, u8* day);


#endif /*HRTC_INTERFACE_H*/
