// 1. Library Directives
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

// 2. MCAL Directives (مناداة درايفر الـ DIO و Timer1)
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER1/TIMER1_INTERFACE.h"

// 3. HAL Directives (ملفات السيرفو)
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_INTERFACE.h"
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_PRIVATE.h"
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_CFG.h"

void HSERVO_voidInit(void)
{
    /* أ. ضبط دبوس OC1A (وهو PD5 في ATmega32) كـ Output إجباري ليخرج إشارة الـ PWM
     * (Datasheet 15.2 / Table 22-4: DDD5 لازم تتظبط Output عشان رجل OC1A تشتغل) */
    MDIO_voidSetPinDirection(PORTD, PIN5, DIO_OUTPUT);

    /* ب. تهيئة Timer1 للعمل في وضع الـ PWM المخصص للسيرفو */
    MTIMERS_voidTimer1Init();
}

void HSERVO_voidSetAngle(u8 Copy_u8Angle)
{
    u32 Local_u32OCRValue;

    // أ. حدود الأمان للزاوية (Boundary Checking)
    if (Copy_u8Angle < SERVO_ANGLE_MIN)
    {
        Copy_u8Angle = SERVO_ANGLE_MIN;
    }
    else if (Copy_u8Angle > SERVO_ANGLE_MAX)
    {
        Copy_u8Angle = SERVO_ANGLE_MAX;
    }

    // ب. المعادلة الرياضية (Mapping) لتحويل الزاوية إلى قيمة OCR1A المناسبة (بين 1000 و 2000)
    Local_u32OCRValue = (((u32)Copy_u8Angle * (SERVO_MAX_PWM_TICKS - SERVO_MIN_PWM_TICKS))
                        / SERVO_ANGLE_MAX) + SERVO_MIN_PWM_TICKS;

    // ج. إرسال القيمة لدرايفر Timer1
    MTIMERS_voidSetCR1AValue((u16)Local_u32OCRValue);
}
