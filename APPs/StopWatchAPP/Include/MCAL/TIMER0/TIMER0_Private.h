/*
 * TIMERS_Private.h
 *
 *  Created on: Jan 18, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TIMER0_u8_TCCR0      *((volatile u8 *)0x53)
#define TIMER0_u8_OCR0       *((volatile u8 *)0x5C)
#define TIMER0_u8_TIMSK      *((volatile u8 *)0x59)
#define TIMER0_u8_TIFR       *((volatile u8 *)0x58)
#define TIMER0_u8_SFIOR      *((volatile u8 *)0x50)    /*comment*/
#define TIMER0_u8_TCNT0      *((volatile u8 *)0x52)

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
