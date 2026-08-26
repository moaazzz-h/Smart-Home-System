#ifndef INCLUDE_MCAL_PWM_PWM_INTERFACE_H_
#define INCLUDE_MCAL_PWM_PWM_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

typedef enum {
    PWM_CHANNEL_A = 0,
    PWM_CHANNEL_B
} PWM_CHANNEL;

/* Init PWM (Fast PWM Mode with Top = ICR1) */
void MPWM_voidInit(void);

/* Set Frequency in Hz (e.g. 50Hz for Servo, 1000Hz for DC Motor) */
void MPWM_voidSetFrequency(u32 A_u32FrequencyHz);

/* Set Duty Cycle from 0% to 100% (Supports Float like 2.5%) */
void MPWM_voidSetDutyCycle(PWM_CHANNEL A_Channel, f32 A_f32DutyCycle);

/* Stop PWM Signal */
void MPWM_voidStop(void);

#endif /* INCLUDE_MCAL_PWM_PWM_INTERFACE_H_ */
