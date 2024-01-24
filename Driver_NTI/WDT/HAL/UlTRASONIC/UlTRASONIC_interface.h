/*
 * ULTRASONIC.h
 *
 * Created: 29/09/2023 10:21:39 م
 *  Author: hassan ehab
 */


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_


void HUltra_voidInit(void);
void HUltra_voidTrigger(void);

u32  HUltra_u32Distance(void);

void HUltra_voidUltraRissingEdge(void);
void HUltra_voidUltraFallingEdge(void);

void HUltra_voidStop(void);



#endif /* ULTRASONIC_INTERFACE_H_ */
