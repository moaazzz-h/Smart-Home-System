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
    u8 Local_u8LightLevel;

    /* Initialize MCAL */
    MDIO_voidInit();
    MADC_voidInit();

    /* Initialize LCD */
    HLCD_voidInit();

    while(1)
    {
        /* Read LDR and convert ADC value to percentage */
        Local_u8LightLevel = HLDR_u8GetLightLevel();

        /* Display Light Level */
        HLCD_voidGoToPos(ROW1, col1);

        HLCD_voidSendString("Light = ");

        HLCD_voidDisplayNumberUNSigned(Local_u8LightLevel);

        HLCD_voidSendString("%   ");

        _delay_ms(300);
    }

    return 0;
}
