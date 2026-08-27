/*
 * SERVO_PROGRAM.c
 *
 *  Created on: Aug 27, 2026
 *      Author: HP
 */

// 1. Library Directives
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"


#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER1/TIMER1_INTERFACE.h"


#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_INTERFACE.h"
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_PRIVATE.h"
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_CFG.h"

void HSERVO_voidInit(void)
{

    MDIO_voidSetPinDirection(PORTD, PIN5, DIO_OUTPUT);

    MTIMERS_voidTimer1Init();
}

void HSERVO_voidSetAngle(u8 Copy_u8Angle)
{
    u32 Local_u32OCRValue;

    if (Copy_u8Angle < SERVO_ANGLE_MIN)
    {
        Copy_u8Angle = SERVO_ANGLE_MIN;
    }
    else if (Copy_u8Angle > SERVO_ANGLE_MAX)
    {
        Copy_u8Angle = SERVO_ANGLE_MAX;
    }


    Local_u32OCRValue = (((u32)Copy_u8Angle * (SERVO_MAX_PWM_TICKS - SERVO_MIN_PWM_TICKS))
                        / SERVO_ANGLE_MAX) + SERVO_MIN_PWM_TICKS;


    MTIMERS_voidSetCR1AValue((u16)Local_u32OCRValue);
}
