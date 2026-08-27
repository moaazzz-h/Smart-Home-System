#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

#define USER_ALI      1
#define USER_OMAR     2
#define USER_SARA     3
#define USER_ANAS     4

#define MODE_MANUAL   1
#define MODE_AUTO     2
#define MODE_TEST     3

void APP_voidSystemInit(void);
void APP_voidWelcomeScreen(void);
u8   APP_u8SelectUser(void);
u8 APP_u8GetPasswordWithMask(u8 Copy_u8User);
void APP_voidPlayWelcomeTone(void);
void APP_voidScrollWelcomeUser(u8 Copy_u8User);
u8   APP_u8SelectMode(void);

void APP_voidHandleManualMode(void);
void APP_voidHandleAutoMode(void);
void APP_voidHandleTestMode(void);

#endif /* APP_INTERFACE_H_ */
