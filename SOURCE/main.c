/*
 * main.c
 *
 *  Created on: Aug 18, 2026
 *      Author: HP
 */
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"



#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"


#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"


#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"



int main(void)
{
	while(1){
		MDIO_voidInit();
				HLCD_voidInit();
				KEPAD_voidInit();
				HLCD_voidSendString("HELLO CALCULATOR ");
				u8  Number_1;
				u8  Number_2;
				u8  Operator;
			    u8  Pressed_Button;
			    f32 ResultofInt;
			    while(1)
			    {

			    	//Number 1  +++++++++++++++++++++++++++++++++++++++++
			    	do {
			    	  Number_1 = HKEYPAD_u8GetPressedKey();
			    	   } while(Number_1 == 0xff);

			    	  if(Number_1 == 'C'){
			    	         HLCD_voidClearDisplay();
			    	         continue;
			    	        }
			    	  else if(Number_1=='+' || Number_1=='-'||Number_1=='='||Number_1=='*'||Number_1=='/' ){
			    		HLCD_voidClearDisplay();
			    		const u8 *msg = "Error";
			    	    HLCD_voidSendString(msg);

			    	    while(1) {
			    	         u8 c = HKEYPAD_u8GetPressedKey();
			    	            if(c == 'C') {
			    	              HLCD_voidClearDisplay();
			    	              break;
			    	                }
			    	            }
			    	                continue;
			    	      }
			              HLCD_voidSendData(Number_1);

			        //operator +++++++++++++++++++++++++++++++++++++++++


			         do {
			            Operator = HKEYPAD_u8GetPressedKey();
			        	} while(Operator == 0xff);
			         HLCD_voidSendData(Operator);


			     	//Number 2  +++++++++++++++++++++++++++++++++++++++++

			         do {
			        	 Number_2 = HKEYPAD_u8GetPressedKey();
			            } while(Number_2 == 0xff);


			         if(Number_2 == 'C'){
			             HLCD_voidClearDisplay();
			             continue;
			             }

			         else if(Number_2=='+' || Number_2=='-'||Number_2=='='||Number_2=='*'||Number_2=='/' ){
			             HLCD_voidClearDisplay();
			             const u8 *msg = "Error";
			             HLCD_voidSendString(msg);

			           while(1) {
			             u8 c = HKEYPAD_u8GetPressedKey();
			             	if(c == 'C') {
			             	     HLCD_voidClearDisplay();
			             	     break;
			             	  }
			               }
			             	   continue;
			          }
			             HLCD_voidSendData(Number_2);

			         while(1){

			        	 Pressed_Button=HKEYPAD_u8GetPressedKey();

			        	 if(Pressed_Button =='='){
			        		 f32 NumberofInt1=Number_1-'0';
			        		 f32 NumberofInt2=Number_2-'0';
			        		 if(Operator=='+'){
			        			 ResultofInt=NumberofInt1+NumberofInt2;
			        		 }
			        		 else if(Operator=='-'){
			        			 ResultofInt=NumberofInt1-NumberofInt2;
			        		 }
			        		 else if(Operator=='*'){
			        			 ResultofInt=NumberofInt1*NumberofInt2;

			        		 }
			        		 else if(Operator=='/'){

			        			 if(NumberofInt2!=0){
			        				 ResultofInt=NumberofInt1/NumberofInt2;
			        			 }
			        			 else
			        				 ResultofInt = 0;
			        		 }

			                 HLCD_voidSendData('=');
			                 if(ResultofInt < 0)
			                      {
			                           HLCD_voidDisplayNumberSigned((s32)ResultofInt);
			                      }

			                 else
			                      {
			                                     HLCD_voidDisplayNumber((u32)ResultofInt);
			                      }


			                 break;

			        	 }
			        	 else if(Pressed_Button == 'C')
			        	         {
			        	             HLCD_voidClearDisplay();
			        	             break;
			        	         }
			         }






			    }


	}
}
