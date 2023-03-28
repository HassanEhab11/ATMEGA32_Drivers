/********************************************************************/
/********************************************************************/
/******************    Author     : Hassan Ehab *********************/
/******************    Layer      : MCAL        *********************/
/******************    SWC(Driver): SPI         *********************/
/******************    Version    : 1.00        *********************/
/******************    Date       : 25/10/2022  *********************/
/********************************************************************/
/********************************************************************/


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_
/****  SPI Control Register ****/
#define  SPCR     *((volatile u8*)0x2D)
#define  SPCR_SPIE    7                  /**  SPI Interrupt Enable     **/
#define  SPCR_SPE     6                  /**        SPI Enable         **/
#define  SPCR_DORD    5                  /**        Data Order         **/
#define  SPCR_MSTR    4                  /**   Master/Slave Select     **/
#define  SPCR_CPOL    3                  /**      Clock Polarity       **/
#define  SPCR_CPHA    2                  /**        Clock Phase        **/
#define  SPCR_SPR1    1                  /**  SPI Clock Rate Select  1 **/
#define  SPCR_SPR0    0                  /**  SPI Clock Rate Select  0 **/
/****  SPI Status Register  ****/
#define  SPSR   *((volatile u8*)0x2E)
#define  SPSR_SPIF    7                 /**    SPI Interrupt Flag     **/
#define  SPSR_WCOL    6                 /**    Write COLlision Flag   **/
#define  SPSR_SPI2X   0                 /**    Double SPI Speed Bit   **/
/****  SPI Data Register    ****/
#define  SPDR   *((volatile u8*)0x2F)





#endif







