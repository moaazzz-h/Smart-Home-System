/*
 * TIMER0_CFG.h
 *
 *  Created on: Aug 26, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER0_TIMER0_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER0_TIMER0_CFG_H_

//NORMAL_MODE
//PHASE_CORRECT_MODE
//CTC_MODE
//FAST_PWM_MODE
#define TIMER0_MODE FAST_PWM_MODE

/*
0b000 No clock source (Timer/Counter stopped).
0b001 clkI/O/(No prescaling)
0b010 clkI/O/8 (From prescaler)
0b011 clkI/O/64 (From prescaler)
0b100 clkI/O/256 (From prescaler)
0b101 clkI/O/1024 (From prescaler)
0b110 External clock source on T0 pin. Clock on falling edge.
0b111 External clock source on T0 pin. Clock on rising edge.
*/
#define TIMER0_CLK_CFG 0b010

//NORMAL_DIO_PIN   0
//TOGGLE_CTC       1
//CLR_CTC          2
//SET_CTC          3
#define TIMER0_CTC_OC0_PIN_MODE NORMAL_DIO_PIN

// PWM_DISCONNECTED    0
// PWM_NON_INVERTING   2
// PWM_INVERTING       3
#define TIMER0_PWM_MODE PWM_NON_INVERTING

// PHASE_CORRECT_PWM_DISCONNECTED     0
// PHASE_CORRECT_PWM_DOWNCOUNTING     2
// PHASE_CORRECT_PWM_UPCOUNTING       3
#define TIMER0_PHASE_CORRECT_MODE  PHASE_CORRECT_PWM_DOWNCOUNTING

#endif /* INCLUDE_MCAL_TIMER_TIMER0_TIMER0_CFG_H_ */
