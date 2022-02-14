/*
 * KEYPAD_Program.c
 *
 *  Created on: Jan 9, 2022
 *      Author: Ahmed Ibrahim
 */

#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"

#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"

#include "../Include/HAL/KEYPAD/KEYPAD_Cfg.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Private.h"

u8 KEYPAD_Au8Keys [KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM]= KEYPAD_Au8_KEYS;
u8 KEYPAD_Au8RowsPins [KEYPAD_u8_ROW_NUM] = KEYPAD_Au8ROWS;
u8 KEYPAD_Au8ColsPins [KEYPAD_u8_COL_NUM] = KEYPAD_Au8COLS;


u8 HKEYPAD_u8_GetPressedKey (void)
{

	u8 local_u8RowCounter,local_u8ColCounter,local_u8PinValue,local_u8KeyValue= KEYPAD_u8_KEY_NOT_PRESSED;
    u8 local_u8Flag = KEYPAD_u8_FLAG_DOWN;

	for(local_u8RowCounter=0;local_u8RowCounter<KEYPAD_u8_ROW_NUM;local_u8RowCounter++)
		{
			MDIO_VoidSetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],DIO_U8_LOW);

			for(local_u8ColCounter=0;local_u8ColCounter<KEYPAD_u8_COL_NUM;local_u8ColCounter++)
			{
				local_u8PinValue =MDIO_U8GetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]);
				if(local_u8PinValue==DIO_U8_LOW)
				{
					_delay_ms(KEYPAD_u8_DEBOUNCING);
					local_u8PinValue= MDIO_U8GetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]);
					if(local_u8PinValue==DIO_U8_LOW)
					{
					while(local_u8PinValue==DIO_U8_LOW)
					{
						local_u8PinValue=MDIO_U8GetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]);
					}
					local_u8KeyValue=KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter];
					local_u8Flag=KEYPAD_u8_FLAG_UP;
					break;
					}
				}
			}

			    MDIO_VoidSetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter], DIO_U8_HIGH);
			    if(local_u8Flag==KEYPAD_u8_FLAG_UP)
			    {
			    	break;
			    }
		}

	return local_u8KeyValue;
}
