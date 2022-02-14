/*
 * LCD_Program.c
 *
 *  Created on: Jan 4, 2022
 *      Author: Ahmed Ibrahim
 */

/*
 * main.c
 *
 *  Created on: Jan 3, 2022
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
#include "../Include/HAL/LCD/LCD_Cfg.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/LCD/LCD_Private.h"


 u8 Char1BallArr[8]={0x00,
					  0x00,
					  0x00,
		  		      0x00,
					  0x00,
					  0x00,
					  0x03,
					  0x03};
 u8 Char3Ball2Arr[8]={0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x18,
  0x18};
 u8 Char4ChildArr[8]={0x00,
		  0x00,
		  0x0E,
		  0x0E,
		  0x04,
		  0x0E,
		  0x04,
		  0x0A};
 u8 Char7ChildrunArr[8]={0x00,
  0x00,
  0x0C,
  0x0C,
  0x05,
  0x0E,
  0x05,
  0x0A};

 u8 Char5Childrun2Arr[8]={ 0x00,
   0x00,
   0x06,
   0x06,
   0x14,
   0x0E,
   0x14,
   0x0A};
 u8 Char5ChildbigArr[8]={0x00,
   0x0E,
   0x0E,
   0x04,
   0x0E,
   0x15,
   0x0E,
   0x0A};
u8 Char5MothArr[8]={ 0x06,
   0x0E,
   0x14,
   0x0E,
   0x15,
   0x04,
   0x0A,
   0x0A};
u8 CharRun2Arr[8]={0x0C,
		  0x0C,
		  0x05,
		  0x16,
		  0x1C,
		  0x05,
		  0x0B,
		  0x10};
u8 CharRunArr[8]={0x06,
		  0x06,
		  0x14,
		  0x0D,
		  0x07,
		  0x14,
		  0x1A,
		  0x01};
u8 CharStandArr[8]={0x0E,
		  0x0E,
		  0x04,
		  0x0E,
		  0x15,
		  0x04,
		  0x0A,
		  0x11};
u8 CharGunArr[8]={0x1C,
		  0x1C,
		  0x08,
		  0x0F,
		  0x0C,
		  0x08,
		  0x0C,
		  0x0C};
u8 CharBulletArr[8]={0x00,
		  0x00,
		  0x18,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x00};
u8 CharDiedArr[8]={0x00,
		  0x00,
		  0x00,
		  0x18,
		  0x1A,
		  0x0C,
		  0x0E,
		  0x09};
u8 CharEnemyArr[8]={0x0C,
		  0x0C,
		  0x04,
		  0x1C,
		  0x0C,
		  0x04,
		  0x07,
		  0x04};
u8 Char0FCorner1Arr[8]={0x1F,
		  0x18,
		  0x14,
		  0x12,
		  0x11,
		  0x10,
		  0x10,
		  0x10};
u8 Char1FCorner2Arr[8]={0x10,
		  0x10,
		  0x10,
		  0x11,
		  0x12,
		  0x14,
		  0x18,
		  0x1F};
u8 Char2FTopArr[8]={0x1F,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x1F,
		  0x00,
		  0x00};
u8 Char3FBotArr[8]={0x00,
		  0x00,
		  0x1F,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x1F};
u8 Char4FDiagonal1Arr[8]={0x1F,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x1F,
		  0x08,
		  0x04};
u8 Char5FDiagonal2Arr[8]={0x04,
		  0x08,
		  0x1F,
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x1F};
u8 Char6Fend1Arr[8]={0x1F,
		  0x01,
		  0x01,
		  0x01,
		  0x01,
		  0x1F,
		  0x01,
		  0x01};
u8 Char7Fend2Arr[8]={0x01,
		  0x01,
		  0x1F,
		  0x01,
		  0x01,
		  0x01,
		  0x01,
		  0x1F};
void HLCD_SendCommand(u8 copy_u8_command)
{

		MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_LOW);
		MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);
		MDIO_VoidSetPortValue(LCD_DATA_PORT,copy_u8_command);
		MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);
		_delay_ms(2);
		MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_LOW);
}
void HLCD_VoidInit(void)
{
    _delay_ms(30);
    HLCD_SendCommand(LCD_U8_FUNCTION_SET);
    _delay_ms(1);
    HLCD_SendCommand(LCD_U8_DISPLAY_CONTROL);
    _delay_ms(1);
    HLCD_SendCommand(LCD_U8_CLEAR_DISPLAY);
    _delay_ms(2);
    HLCD_SendCommand(LCD_U8_ENTRY_SET);

}

void HLCD_VoidSendData(u8 copy_8uChar)
{
	        //rs=1
			MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_HIGH);
			//rw=0
			MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);

			MDIO_VoidSetPortValue(LCD_DATA_PORT,copy_8uChar);
			//1 enable
			MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);
			//delay
			_delay_ms(3);
			MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_LOW);
}
void HLCD_VoidSendString(u8 *copy_P8uString)
{
	while(*copy_P8uString>0)
	{
		HLCD_VoidSendData(*copy_P8uString++);
	}
}

void HLCD_VoidClearDisplay(void)
{
	HLCD_SendCommand(0x01);
	_delay_ms(2);
}

void HLCD_VoidDisplayNumber(s32 copy_u32Number)
{
	u8 U8data,count=0;
	u32 U32data=0,reverse_n=0,remainder_n;
	    	if (copy_u32Number == 0)
	    	{
	    		HLCD_VoidSendData('0');
	    	}
	    	if (copy_u32Number < 0)
	    	{
	    		HLCD_VoidSendData('-');
	    		copy_u32Number *= -1;
	    	}
	    	U32data = copy_u32Number;
			while(U32data!=0)
			{
				    remainder_n=(U32data % 10);
					reverse_n = remainder_n + reverse_n * 10;
					U32data = U32data/10;
                    count++;
			}
			while(count!=0)
			{
				remainder_n=(reverse_n % 10);
				reverse_n = reverse_n/10;
		     	U8data = (u8)(remainder_n+48);
			    HLCD_VoidSendData(U8data);
			    count--;
			}
}


void HLCD_VoidGoToPos(u8 copy_u8RowNum,u8 copy_u8ColumnNo)
{
   if( (copy_u8RowNum <= LCD_U8_ROW1) && (copy_u8ColumnNo <= LCD_U8_COL15) )
   {
     switch(copy_u8RowNum)
     {
     case LCD_U8_ROW0 :
    	 HLCD_SendCommand(LCD_U8_ROW0_ADDRESS+copy_u8ColumnNo);
    	 break;
     case LCD_U8_ROW1 :
         HLCD_SendCommand(LCD_U8_ROW1_ADDRESS+copy_u8ColumnNo);
         break;
     }
   }
   /* wait for more 39 usec */
   	_delay_ms(1);
}


void HLCD_VoidSendSpecialCharacter(u8 *copy_pu8CharArr,u8 copy_u8PatternNum,
								   u8 copy_u8RowNum, u8 copy_ColNum)
{
	u8 local_u8CGRAMAddress, local_u8Counter;
	/* Calculate CGRAM Address = Pattern Number * 8 */
	local_u8CGRAMAddress = copy_u8PatternNum * 8;
	SET_BIT(local_u8CGRAMAddress,6);
	/* Send Command to set CGRAM Address */
	HLCD_SendCommand(local_u8CGRAMAddress);

	for (local_u8Counter=0; local_u8Counter < 8; local_u8Counter++)
	{
		/* Send byte from character array */
		HLCD_VoidSendData(copy_pu8CharArr[local_u8Counter]);
	}
	/* Send Command to set DDRAM Address */
	HLCD_VoidGoToPos(copy_u8RowNum,copy_ColNum);
	/* Display pattern from CGRAM */
	HLCD_VoidSendData(copy_u8PatternNum);
}


