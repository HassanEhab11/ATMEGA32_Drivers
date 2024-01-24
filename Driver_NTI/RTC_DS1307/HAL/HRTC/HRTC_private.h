#ifndef HRTC_PRIVATE_H
#define HRTC_PRIVATE_H

u8 DEC_TO_BCD(u8 decimal);
u8 BCD_TO_DEC(u8 bcd);

#define RTC_SLA_ADDRESS_W		0b11010000
#define RTC_SLA_ADDRESS_R		0b11010001

#define RTC_TIME_ADDRESS	0x00
#define RTC_DATE_ADDRESS	0x04

#define RTC_PM_MASK		0b01100000	//bit 6: to select 12 hour format, bit 5: to select PM
#define RTC_AM_MASK		0b01000000
#define RTC_24_MASK		0b00000000

#endif /*HRTC_PRIVATE_H*/
