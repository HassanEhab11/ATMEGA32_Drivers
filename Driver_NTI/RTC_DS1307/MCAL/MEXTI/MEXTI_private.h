/*
 * EXTI_private.h
 *
 * Created: 1/28/2023 4:05:35 AM
 *  Author: hassa
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/******** EXTI Registers ***********/
#define  GICR         *((volatile u8*)0x5B)
#define  GICR_INT1    7
#define  GICR_INT0    6
#define  GICR_INT2    5

#define  GIFR         *((volatile u8*)0x5A)
#define  GIFR_INTF1   7
#define  GIFR_INTF0   6
#define  GIFR_INTF2   5


#define  MCUCR        *((volatile u8*)0x55)
#define  MCUCR_ISC11  3
#define  MCUCR_ISC10  2
#define  MCUCR_ISC01  1
#define  MCUCR_ISC00  0

#define  MCUCSR       *((volatile u8*)0x54)
#define  MCUCSR_ISC2  6

/*************** ISR Interrupt Vectors Number ******************/
#define	INT0_VECTOR				__vector_1
#define	INT1_VECTOR				__vector_2
#define	INT2_VECTOR				__vector_3


/************ ISR Attribute ***************/
#define ISR_ST(vector_)            \
void vector_ (void) __attribute__ ((signal)); \
void vector_ (void)


#endif /* EXTI_PRIVATE_H_ */