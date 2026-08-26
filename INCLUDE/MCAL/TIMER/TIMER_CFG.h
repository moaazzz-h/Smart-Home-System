/* TIMER_CFG.H */

#ifndef INCLUDE_MCAL_TIMER_TIMER_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER_CFG_H_

#define TIMER0_MODE    NORMAL_MODE

/*
Ob000 No clock source (Timer/Counter stopped).
Ob001 clkI/O/(No prescaling)
Ob010 clkI/O/8 (From prescaler)
Ob011 clkI/O/64 (From prescaler)
Ob100 clkI/O/256 (From prescaler)
Ob101 clkI/O/1024 (From prescaler)
Ob110 External clock source on T0 pin. Clock on falling edge.
Ob111 External clock source on T0 pin. Clock on rising edge.
*/

#define TIMER0_CLK_CFG    0b010

#define TIMER0_CTC_MODE    NORMAL_DIO_PIN

#define TIMER0_PWM_MODE    NON_INVERTING_PWM

#define NULL    0

#endif /* INCLUDE_MCAL_TIMER_TIMER_CFG_H_ */
