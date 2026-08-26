/*
 * BUZZER_PROGRAM.c
 */

#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_PRIVATE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_CFG.h"


void HBUZZER_voidInit(void)
{
    MDIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT);
    MDIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
}


void HBUZZER_voidOn(void)
{
    MDIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
}


void HBUZZER_voidOff(void)
{
    MDIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
}


void HBUZZER_voidBeep(void)
{
    HBUZZER_voidOn();

    _delay_ms(200);

    HBUZZER_voidOff();
}
