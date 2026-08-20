/*
 * LCD_CFG.h
 *
 *  Created on: Aug 19, 2026
 *      Author: HP
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

#define LCD_DATA_PORT 			PORTD
#define LCD_CONTROL_PORT    	PORTC

#define LCD_RS_PIN 	        	PIN0
#define LCD_RW_PIN 				PIN1
#define LCD_E_PIN  				PIN2

// 0 --> 1 Line
// 1 --> 2 Line
#define LCD_NO_OF_LINES 		1
// 0 --> 8 BIT MODE
// 1 --> 4 BIT MODE
#define LCD_DL 1
// 0 --> 5*7
// 1 --> 5*10
#define LCD_CHAR_FONT		 	0
// 0 --> off
// 1 --> on
#define DISPLAY_ON 				1
// 0 --> off
// 1 --> on
#define CURSOR_DISPLAY 			1
// 0 --> off
// 1 --> on
#define CURSOR_BLINK 			1
//left to Right --> 1
//Right to Left --> 0
#define LCD_DATA_DIRECTION 		1
// 0 --> SHIFT ON
// 1 --> SHIFT OFF
#define LCD_SHIFT 				0

#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
