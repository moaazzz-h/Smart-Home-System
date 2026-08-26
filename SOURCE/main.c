#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

// MCAL
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"

// HAL
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/LDR/LDR_INTERFACE.h"




int main(void)
{
	MDIO_voidInit();

    HSERVO_voidInit();

    /* اختبار 1: نقاط ثابتة للتأكد إن كل زاوية بتوصل صح */
    HSERVO_voidSetAngle(0);
    _delay_ms(1000);

    HSERVO_voidSetAngle(90);
    _delay_ms(1000);

    HSERVO_voidSetAngle(180);
    _delay_ms(1000);

    while (1)
    {
        /* اختبار 2: مسح كامل (Sweep) من 0 لـ180 بالتدريج */
        u8 Local_u8Angle;

        for (Local_u8Angle = 0; Local_u8Angle <= 180; Local_u8Angle++)
        {
            HSERVO_voidSetAngle(Local_u8Angle);
            _delay_ms(15);
        }
        _delay_ms(500);

        for (Local_u8Angle = 180; Local_u8Angle > 0; Local_u8Angle--)
        {
            HSERVO_voidSetAngle(Local_u8Angle);
            _delay_ms(15);
        }
        _delay_ms(500);
    }
}
