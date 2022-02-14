/*
 * LCD_Interface.h
 *
 *  Created on: Jan 4, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_HAL_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_INTERFACE_H_

#include "../../LIB/bit_math.h"
#include "../../LIB/std_type.h"


void HLCD_SendCommand(u8 copy_u8_command);

void HLCD_VoidInit(void);

void HLCD_VoidSendData(u8 copy_8uChar);

void HLCD_VoidSendString(u8 *copy_P8uString);


void HLCD_VoidClearDisplay(void);


void HLCD_VoidDisplayNumber(s32 copy_u32Number);


void HLCD_VoidGoToPos(u8 copy_u8RowNum,u8 copy_u8ColumnNo);

void HLCD_VoidSendSpecialCharacter(u8 *copy_pu8CharArr,u8 copy_u8PatternNum,
								   u8 copy_u8LineNum, u8 copy_ColNum);



#define LCD_U8_LINE0  0
#define LCD_U8_LINE1  1

#define LCD_U8_ROW0     0
#define LCD_U8_ROW1     1

#define LCD_U8_COL0     0
#define LCD_U8_COL1     1
#define LCD_U8_COL2     2
#define LCD_U8_COL3     3
#define LCD_U8_COL4     4
#define LCD_U8_COL5     5
#define LCD_U8_COL6     6
#define LCD_U8_COL7     7
#define LCD_U8_COL8     8
#define LCD_U8_COL9     9
#define LCD_U8_COL10    10
#define LCD_U8_COL11    11
#define LCD_U8_COL12    12
#define LCD_U8_COL13    13
#define LCD_U8_COL14    14
#define LCD_U8_COL15    15
#endif /* INCLUDE_HAL_LCD_INTERFACE_H_ */
