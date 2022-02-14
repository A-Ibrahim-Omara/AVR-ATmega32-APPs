/*
 * LCD_Private.h
 *
 *  Created on: Jan 4, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_HAL_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_PRIVATE_H_

void HLCD_SendCommand(u8 copy_u8_command);

#define LCD_U8_FUNCTION_SET       0b00111100
#define LCD_U8_DISPLAY_CONTROL    0b00001100
#define LCD_U8_CLEAR_DISPLAY      0b00000001
#define LCD_U8_ENTRY_SET          0b00000110

#define LCD_U8_ROW0_ADDRESS  0x80
#define LCD_U8_ROW1_ADDRESS  0xC0

#endif /* INCLUDE_HAL_LCD_PRIVATE_H_ */
