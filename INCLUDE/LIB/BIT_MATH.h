/*
 * BIT_MATH.h
 *
 *  Created on: Aug 18, 2026
 *      Author: HP
 */

#ifndef INCLUDE_LIB_BIT_MATH_H_
#define INCLUDE_LIB_BIT_MATH_H_

#define SET_BIT(Reg,bitnum)          (Reg |= 1<<bitnum)
#define GET_BIT(Reg,bitnum)          ((Reg >> bitnum)& 0x01)
#define CLR_BIT(Reg,bitnum)          (Reg &= ~(1<<bitnum))
#define TOGGLE_BIT(Reg,bitnum)       (Reg ^= (1<<bitnum))

#define SET_BYTE(Reg,value)          ( Reg = value )

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)  Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif /* INCLUDE_LIB_BIT_MATH_H_ */
