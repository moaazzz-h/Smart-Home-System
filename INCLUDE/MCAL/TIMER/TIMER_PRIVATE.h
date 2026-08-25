/*
 * TIMER_PRIVATE.h
 *
 *  Created on: Aug 25, 2026
 *      Author: HP
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_
#define INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_

/* Timer0 Hardware Registers */

#define TCCR0   (*(volatile u8 *) 0x53)
#define TCNT0   (*(volatile u8 *) 0x52)
#define OCR0    (*(volatile u8 *) 0x5C)
#define TIMSK   (*(volatile u8 *) 0x59)
#define TIFR    (*(volatile u8 *) 0x58)


/* Timer0 Callback Functions */

extern void (*TIMER0_OVF_CALLBACK)(void);
extern void (*TIMER0_CTC_CALLBACK)(void);

#endif /* INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_ */
