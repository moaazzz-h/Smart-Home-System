#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/PWM/PWM_INTERFACE.h"

int main(void)
{
    // 1.  ÂÌ∆… «·‹ DIO Ê«·‹ PWM
    MDIO_voidInit();
    MPWM_voidInit();

    // 2. ÷»ÿ «· —œœ ⁄·Ï 50Hz
    MPWM_voidSetFrequency(50);

    // 3. ≈Œ—«Ã Duty Cycle »‰”»… 5.0% ( Ê«“Ì 1.0ms High Pulse = “«ÊÌ… -90 / 0 œ—Ã…)
    MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 5.0);

    while(1)
    {
        // „” „— ›Ì ≈Œ—«Ã ≈‘«—… «·“«ÊÌ… -90∞ ⁄·Ï PD5
    }

    return 0;
}
