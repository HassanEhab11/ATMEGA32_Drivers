/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): TWI         *********************/
/******************    Version    : 1.00        *********************/
/******************    Date       : 27/10/2022  *********************/
/********************************************************************/
/********************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define FREQ_400KBPS	12
#define FREQ_100KBPS	36

/**************************************************************************/
/************************   TWI Bit Rate Register  ************************/
/**************************************************************************/
#define TWBR                   *((volatile u8*)0x20)
/**************************************************************************/
/************************   TWI Status Register     ***********************/
/**************************************************************************/
#define TWSR                   *((volatile u8*)0x21)
#define TWPS0             0                         /* prescaler Bit0*/
#define TWPS1             1                         /* prescaler Bit1*/
/**************************************************************************/
/************************   TWI (Slave) Address Register  *****************/
/**************************************************************************/
#define TWAR                   *((volatile u8*)0x22)
#define TWGCE             0        /* General call recognition enable*/
/**************************************************************************/
/************************** TWI Data Register    **************************/
/**************************************************************************/
#define TWDR                   *((volatile u8*)0x23)
/**************************************************************************/
/************************* TWI Control Register  **************************/
/**************************************************************************/
#define TWCR                   *((volatile u8*)0x56)
#define TWINT             7                        /* Interrupt Flag */
#define TWEA              6                     /* Enable Acknowledge*/
#define TWSTA             5                        /* Start condition*/
#define TWSTO             4                         /* Stop Condition*/
#define TWWC              3                        /* Write collision*/
#define TWEN              2                                 /* Enable*/
#define TWIE              0                       /* Interrupt Enable*/
/**************************************************************************/
/**************************************************************************/


#endif
