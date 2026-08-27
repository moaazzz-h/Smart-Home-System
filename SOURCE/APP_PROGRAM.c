#include <util/delay.h>
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/PWM/PWM_INTERFACE.h"
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/APP/APP_INTERFACE.h"

// ÇáÈÇÓæÑÏÇÊ ÇáÇÝÊÑÇÖíÉ ááÜ 4 ãÓÊÎÏãíä
static const u8 UsersPasswords[4][4] = {
    {'1', '2', '3', '4'}, // ALI
    {'1', '1', '1', '1'}, // OMAR
    {'2', '2', '2', '2'}, // SARA
    {'4', '3', '2', '1'}  // ANAS
};

static const char* UsersNames[4] = {"ALI", "OMAR", "SARA", "ANAS"};

void APP_voidSystemInit(void)
{
    MDIO_voidInit();
    HLCD_voidInit();
    KPAD_voidInit();
    HBUZZER_voidInit();
    MPWM_voidInit();
    MPWM_voidSetFrequency(50);
}

void APP_voidWelcomeScreen(void)
{
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)" Welcome To ");
    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)" Users System ");
    _delay_ms(1500);
}

u8 APP_u8SelectUser(void)
{
    u8 Local_u8Key = KPAD_NOT_PRESSED;
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"1:ALI   2:OMAR");
    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"3:SARA  4:ANAS");

    while(1)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();
        if(Local_u8Key >= '1' && Local_u8Key <= '4')
        {
            HBUZZER_voidBeep();
            return (Local_u8Key - '0');
        }
    }
}

u8 APP_u8GetPasswordWithMask(u8 Copy_u8User)
{
    u8 Local_u8InputPass[4];
    u8 Local_u8Index = 0;
    u8 Local_u8Key = KPAD_NOT_PRESSED;
    u8 Local_u8MaskMode = 1;

    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"Enter Pass (*:Toggle)");
    HLCD_voidGoToPos(ROW2, col1);

    while(Local_u8Index < 4)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();
        if(Local_u8Key != KPAD_NOT_PRESSED)
        {
            HBUZZER_voidBeep();

            if(Local_u8Key == '*')
            {
                Local_u8MaskMode ^= 1;
                HLCD_voidGoToPos(ROW2, col1);
                for(u8 i = 0; i < Local_u8Index; i++)
                {
                    if(Local_u8MaskMode) HLCD_voidSendData('*');
                    else HLCD_voidSendData(Local_u8InputPass[i]);
                }
            }
            else if(Local_u8Key >= '0' && Local_u8Key <= '9')
            {
                Local_u8InputPass[Local_u8Index] = Local_u8Key;
                if(Local_u8MaskMode)
                {
                    HLCD_voidSendData('*');
                }
                else
                {
                    HLCD_voidSendData(Local_u8Key);
                }
                Local_u8Index++;
            }
        }
    }

    for(u8 i = 0; i < 4; i++)
    {
        if(Local_u8InputPass[i] != UsersPasswords[Copy_u8User - 1][i])
        {
            return 0;
        }
    }
    return 1;
}

void APP_voidPlayWelcomeTone(void)
{
    for(u8 i = 0; i < 3; i++)
    {
        HBUZZER_voidOn();
        _delay_ms(80);
        HBUZZER_voidOff();
        _delay_ms(50);
    }
}

void APP_voidScrollWelcomeUser(u8 Copy_u8User)
{
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)" Welcome ");
    HLCD_voidSendString((u8*)UsersNames[Copy_u8User - 1]);
    HLCD_voidSendString((u8*)" ");

    for(u8 i = 0; i < 6; i++)
    {
        _delay_ms(200);
    }
}

u8 APP_u8SelectMode(void)
{
    u8 Local_u8Key = KPAD_NOT_PRESSED;
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"1:Manual 2:Auto");
    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"3:Test Mode");

    while(1)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();
        if(Local_u8Key >= '1' && Local_u8Key <= '3')
        {
            HBUZZER_voidBeep();
            return (Local_u8Key - '0');
        }
    }
}

void APP_voidHandleManualMode(void)
{
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"1:Light 2:Temp");
    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"3:Servo Motor");
    _delay_ms(2000);
}

void APP_voidHandleAutoMode(void)
{
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"Auto Mode Active");
    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"Waiting Sensors");
    _delay_ms(2000);
}

void APP_voidHandleTestMode(void)
{
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"Testing System..");

    MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 7.5);
    _delay_ms(1000);
    MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 5.0);

    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"Test Complete!");
    _delay_ms(1500);
}
