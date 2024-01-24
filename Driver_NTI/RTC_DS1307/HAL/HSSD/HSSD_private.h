/*
 * SSD_private.h
 *
 * Created: 1/28/2023 2:20:02 AM
 *  Author: Hassan Ehab
 */ 


#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_

#define ZERO	0b01111110
#define ONE		0b00001100
#define TWO		0b10110110
#define THREE	0b10011110
#define FOUR	0b11001100
#define FIVE	0b11011010
#define SIX		0b11111010
#define SEVEN	0b00001110
#define EIGHT	0b11111110
#define NINE	0b11011110

u8 SSD_Numbers[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
typedef enum{

	PIN_0 = 0,
	PIN_1 = 1,
	PIN_2 = 2,
	PIN_3 = 3
}pins_e;

#endif /* SSD_PRIVATE_H_ */
