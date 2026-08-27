#include <util/delay.h>
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"
#include "../INCLUDE/MCAL/PWM/PWM_INTERFACE.h"
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/APP/APP_INTERFACE.h"

#define HLCD_voidSendChar    HLCD_voidSendData

static const u8 UsersPasswords[4][4] = {
    {'1', '2', '3', '4'}, // ALI
    {'1', '1', '1', '1'}, // OMAR
    {'2', '2', '2', '2'}, // SARA
    {'4', '3', '2', '1'}  // ANAS
};

static const char* UsersNames[4] = {"ALI", "OMAR", "SARA", "ANAS"};
static u8 DoorState = 0; // 0: Closed, 1: Opened

void APP_voidSystemInit(void)
{
    MDIO_voidInit();
    HLCD_voidInit();
    KPAD_voidInit();
    HBUZZER_voidInit();
    MADC_voidInit(); //  ÂÌ∆… «·‹ ADC
    MPWM_voidInit();
    MPWM_voidSetFrequency(50);
}

void APP_voidWelcomeScreen(void)
{
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col4);
    HLCD_voidSendString((u8*)"SMART HOME SYSTEM");
    HLCD_voidGoToPos(ROW2, col6);
    HLCD_voidSendString((u8*)"WELCOME!");
    HLCD_voidGoToPos(ROW3, col3);
    HLCD_voidSendString((u8*)"IEEE ZSB PROJECT");
    HLCD_voidGoToPos(ROW4, col2);
    HLCD_voidSendString((u8*)"PRESS ANY KEY...");
    _delay_ms(1500);
}

u8 APP_u8SelectUser(void)
{
    u8 Local_u8Key = KPAD_NOT_PRESSED;
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col4);
    HLCD_voidSendString((u8*)"SELECT USER:");
    HLCD_voidGoToPos(ROW2, col2);
    HLCD_voidSendString((u8*)"1: ALI     2: OMAR");
    HLCD_voidGoToPos(ROW3, col2);
    HLCD_voidSendString((u8*)"3: SARA    4: ANAS");
    HLCD_voidGoToPos(ROW4, col3);
    HLCD_voidSendString((u8*)"ENTER OPTION [1-4]");

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
    HLCD_voidGoToPos(ROW1, col3);
    HLCD_voidSendString((u8*)"USER: ");
    HLCD_voidSendString((u8*)UsersNames[Copy_u8User - 1]);

    HLCD_voidGoToPos(ROW2, col2);
    HLCD_voidSendString((u8*)"ENTER 4-DIGIT PASS:");

    HLCD_voidGoToPos(ROW3, col2);
    HLCD_voidSendString((u8*)"[*]: MASK/UNMASK");

    HLCD_voidGoToPos(ROW4, col8); // „ﬂ«‰ ≈œŒ«· «·»«”Ê—œ ›Ì „‰ ’› «·”ÿ— «·—«»⁄

    while(Local_u8Index < 4)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();
        if(Local_u8Key != KPAD_NOT_PRESSED)
        {
            HBUZZER_voidBeep();

            if(Local_u8Key == '*')
            {
                Local_u8MaskMode ^= 1;
                HLCD_voidGoToPos(ROW4, col8);
                for(u8 i = 0; i < Local_u8Index; i++)
                {
                    if(Local_u8MaskMode) HLCD_voidSendData('*');
                    else HLCD_voidSendData(Local_u8InputPass[i]);
                }
            }
            else if(Local_u8Key >= '0' && Local_u8Key <= '9')
            {
                Local_u8InputPass[Local_u8Index] = Local_u8Key;
                if(Local_u8MaskMode) HLCD_voidSendData('*');
                else HLCD_voidSendData(Local_u8Key);
                Local_u8Index++;
            }
        }
    }

    for(u8 i = 0; i < 4; i++)
    {
        if(Local_u8InputPass[i] != UsersPasswords[Copy_u8User - 1][i]) return 0;
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
    HLCD_voidGoToPos(ROW2, col3);
    HLCD_voidSendString((u8*)"WELCOME BACK!");
    HLCD_voidGoToPos(ROW3, col7);
    HLCD_voidSendString((u8*)UsersNames[Copy_u8User - 1]);
    _delay_ms(1500);
}

u8 APP_u8SelectMode(void)
{
    u8 Local_u8Key = KPAD_NOT_PRESSED;
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col5);
    HLCD_voidSendString((u8*)"MAIN MENU");
    HLCD_voidGoToPos(ROW2, col2);
    HLCD_voidSendString((u8*)"1: MANUAL MODE");
    HLCD_voidGoToPos(ROW3, col2);
    HLCD_voidSendString((u8*)"2: AUTO MODE");
    HLCD_voidGoToPos(ROW4, col2);
    HLCD_voidSendString((u8*)"3: TEST SYSTEM");

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

// ---- 1. «·Ê÷⁄ «·ÌœÊÌ (MANUAL MODE) ----
void APP_voidHandleManualMode(void)
{
    u8 Local_u8Key = KPAD_NOT_PRESSED;
    u16 Local_u16ADCVal = 0;
    u16 Local_u16Temp = 0;
    u16 Local_u16LDR = 0;

    HLCD_voidClearDisplay();

    while(1)
    {
    	// ﬁ—«¡… „” ‘⁄— «·Õ—«—… LM35 ⁄·Ï PA0 (Channel 0)
    	Local_u16ADCVal = MADC_u16ReadSync(ADC_Channel_0);
    	Local_u16Temp = (u16)(((u32)Local_u16ADCVal * 500) / 1024);

    	// ﬁ—«¡… „” ‘⁄— «·÷Ê¡ LDR ⁄·Ï PA1 (Channel 1)
    	Local_u16LDR = MADC_u16ReadSync(ADC_Channel_1);

        HLCD_voidGoToPos(ROW1, col4);
        HLCD_voidSendString((u8*)"-- MANUAL MODE --");

        HLCD_voidGoToPos(ROW2, col1);
        HLCD_voidSendString((u8*)"TEMP: ");
        HLCD_voidDisplayNumberUNSigned(Local_u16Temp);
        HLCD_voidSendString((u8*)"C  LDR: ");
        HLCD_voidDisplayNumberUNSigned(Local_u16LDR);
        HLCD_voidSendString((u8*)"  ");

        HLCD_voidGoToPos(ROW3, col1);
        HLCD_voidSendString((u8*)"DOOR: ");
        if(DoorState == 1) HLCD_voidSendString((u8*)"OPEN   [1:TOGGLE]");
        else               HLCD_voidSendString((u8*)"CLOSED [1:TOGGLE]");

        HLCD_voidGoToPos(ROW4, col1);
        HLCD_voidSendString((u8*)"[0]: BACK TO MENU");

        Local_u8Key = HKEYPAD_u8GetPressedKey();
        if(Local_u8Key == '1')
        {
            HBUZZER_voidBeep();
            DoorState ^= 1; // ⁄ﬂ” Õ«·… «·»«»
            if(DoorState == 1) MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 7.5); // › Õ «·»«» (90 œ—Ã…)
            else               MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 5.0); // €·ﬁ «·»«» (0 œ—Ã…)
        }
        else if(Local_u8Key == '0')
        {
            HBUZZER_voidBeep();
            break; // «·Œ—ÊÃ ··„‰ÌÊ «·—∆Ì”Ì…
        }
        _delay_ms(150);
    }
}

// ---- 2. «·Ê÷⁄ «·√Ê Ê„« ÌﬂÌ (AUTO MODE) ----
void APP_voidHandleAutoMode(void)
{
    u8 Local_u8Key = KPAD_NOT_PRESSED;
    u16 Local_u16ADCVal = 0;
    u16 Local_u16Temp = 0;
    u16 Local_u16LDR = 0;

    HLCD_voidClearDisplay();

    while(1)
    {
        // 1. ﬁ—«¡… «·”‰”Ê—« 
    	// ﬁ—«¡… „” ‘⁄— «·Õ—«—… LM35 ⁄·Ï PA0 (Channel 0)
    	Local_u16ADCVal = MADC_u16ReadSync(ADC_Channel_0);
    	Local_u16Temp = (u16)(((u32)Local_u16ADCVal * 500) / 1024);

    	// ﬁ—«¡… „” ‘⁄— «·÷Ê¡ LDR ⁄·Ï PA1 (Channel 1)
    	Local_u16LDR = MADC_u16ReadSync(ADC_Channel_1);

        // 2. «· Õﬂ„ «· ·ﬁ«∆Ì ›Ì «·”Ì—›Ê »‰«¡ ⁄·Ï «·Õ—«—… ﬂ„À«· √Ê Ê„« Ìﬂ
        if(Local_u16Temp > 35)
        {
            DoorState = 1;
            MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 7.5); // › Õ «· ÂÊÌ…/«·»«»
        }
        else
        {
            DoorState = 0;
            MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 5.0); // €·ﬁ
        }

        // 3. «·⁄—÷ «·„‰”ﬁ ⁄·Ï √—»⁄… √”ÿ—
        HLCD_voidGoToPos(ROW1, col3);
        HLCD_voidSendString((u8*)"AUTO CONTROL MODE");

        HLCD_voidGoToPos(ROW2, col1);
        HLCD_voidSendString((u8*)"ROOM TEMP : ");
        HLCD_voidDisplayNumberUNSigned(Local_u16Temp);
        HLCD_voidSendString((u8*)" C  ");

        HLCD_voidGoToPos(ROW3, col1);
        HLCD_voidSendString((u8*)"LIGHT LDR : ");
        HLCD_voidDisplayNumberUNSigned(Local_u16LDR);
        HLCD_voidSendString((u8*)"    ");

        HLCD_voidGoToPos(ROW4, col1);
        HLCD_voidSendString((u8*)"SERVO: ");
        if(DoorState == 1) HLCD_voidSendString((u8*)"ON  [0:EXIT]");
        else               HLCD_voidSendString((u8*)"OFF [0:EXIT]");

        Local_u8Key = HKEYPAD_u8GetPressedKey();
        if(Local_u8Key == '0')
        {
            HBUZZER_voidBeep();
            break; // «·⁄Êœ… ··„‰ÌÊ
        }
        _delay_ms(200);
    }
}

// ---- 3. Ê÷⁄ «·«Œ Ì«—«  Ê«· ”  (TEST MODE) ----
void APP_voidHandleTestMode(void)
{
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col4);
    HLCD_voidSendString((u8*)"RUNNING TEST...");

    HLCD_voidGoToPos(ROW2, col2);
    HLCD_voidSendString((u8*)"TESTING SERVO MOTOR");
    MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 7.5);
    _delay_ms(1000);
    MPWM_voidSetDutyCycle(PWM_CHANNEL_A, 5.0);

    HLCD_voidGoToPos(ROW3, col2);
    HLCD_voidSendString((u8*)"TESTING BUZZER SOUND");
    HBUZZER_voidBeep();
    _delay_ms(500);

    HLCD_voidGoToPos(ROW4, col4);
    HLCD_voidSendString((u8*)"TEST PASSED!");
    _delay_ms(1500);
}
