#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

#include "../DIO/DIO_INTERFACE.h"
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

static u32 G_u32TopValue = 20000; // Default Top Value (ICR1)

void MPWM_voidInit(void)
{
    /* Set Fast PWM Mode with ICR1 as TOP (Mode 14) */
    CLR_BIT(TCCR1A, WGM10);
    SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, WGM13);

    /* Set Non-Inverting Mode for Channel A (Clear OC1A on Compare Match, set at TOP) */
    SET_BIT(TCCR1A, COM1A1);
    CLR_BIT(TCCR1A, COM1A0);

    /* Set Non-Inverting Mode for Channel B */
    SET_BIT(TCCR1A, COM1B1);
    CLR_BIT(TCCR1A, COM1B0);

    /* Set Prescaler = 8 (F_CPU / 8) -> suitable for most PWM applications */
    CLR_BIT(TCCR1B, CS10);
    SET_BIT(TCCR1B, CS11);
    CLR_BIT(TCCR1B, CS12);
}

void MPWM_voidSetFrequency(u32 A_u32FrequencyHz)
{
    if (A_u32FrequencyHz > 0)
    {
        /* Equation: F_PWM = F_CPU / (Prescaler * (1 + TOP))
         * Assuming F_CPU = 8 MHz and Prescaler = 8
         * TOP = (8000000 / (8 * F_PWM)) - 1
         */
        G_u32TopValue = (1000000UL / A_u32FrequencyHz) - 1;
        ICR1 = (u16)G_u32TopValue;
    }
}

void MPWM_voidSetDutyCycle(PWM_CHANNEL A_Channel, f32 A_f32DutyCycle)
{
    if (A_f32DutyCycle > 100.0f) A_f32DutyCycle = 100.0f;
    if (A_f32DutyCycle < 0.0f)   A_f32DutyCycle = 0.0f;

    u16 Local_u16CompareValue = (u16)((A_f32DutyCycle / 100.0f) * (G_u32TopValue + 1));

    if (A_Channel == PWM_CHANNEL_A)
    {
        /* Set Pin PD5 (OC1A) as Output */
        MDIO_voidSetPinDirection(PORTD, PIN5, DIO_OUTPUT);
        OCR1A = Local_u16CompareValue;
    }
    else if (A_Channel == PWM_CHANNEL_B)
    {
        /* Set Pin PD4 (OC1B) as Output */
        MDIO_voidSetPinDirection(PORTD, PIN4, DIO_OUTPUT);
        OCR1B = Local_u16CompareValue;
    }
}

void MPWM_voidStop(void)
{
    /* Stop Timer Clock */
    CLR_BIT(TCCR1B, CS10);
    CLR_BIT(TCCR1B, CS11);
    CLR_BIT(TCCR1B, CS12);
}
