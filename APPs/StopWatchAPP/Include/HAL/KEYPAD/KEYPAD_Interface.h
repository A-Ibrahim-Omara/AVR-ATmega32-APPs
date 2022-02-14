/*
 * KEYPAD_Interface.h
 *
 *  Created on: Jan 9, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_

#include "../../LIB/bit_math.h"
#include "../../LIB/std_type.h"
/*-------------------------------------------------------------*/
/*Function return the pressed key of keypad*/
u8 HKEYPAD_u8_GetPressedKey(void);
/*-------------------------------------------------------------*/

#define KEYPAD_u8_KEY_NOT_PRESSED 255

#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
