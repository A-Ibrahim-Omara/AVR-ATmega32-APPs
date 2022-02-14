/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */
#include <stdio.h>
#include <stdlib.h>

#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"

/*---------------------------------------------------------------------------------------------------------------------*/
static u8 global_u8_program_flag =0;

static u32 global_u8_SecCounter =0;
static u32 global_u8_MinCounter =0;
static u32 global_u32_num1=0;      //Num1 represent minutes
static u32 global_u32_num2=0;	   //Num2 represent seconds

/*---------------------------------------------------------------------------------------------------------------------*/
void TOGGLE(void)
{
	static u8 static_u8_LED_Value  =0;
	static_u8_LED_Value^=1;
	MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN7,static_u8_LED_Value);
}
/*---------------------------------------------------------------------------------------------------------------------*/

u8 APPCALCULATOR_u8_CheckNum(u8 copy_u8_keypad_OutputCharacter)
{
	u8 local_u8_CheckValue='o',local_u8_CharToInt = (copy_u8_keypad_OutputCharacter-48);

	if(local_u8_CharToInt >= 0  && local_u8_CharToInt < 10)
	{
		local_u8_CheckValue='n';
	}
	return local_u8_CheckValue ;
}
/*---------------------------------------------------------------------------------------------------------------------*/
void APPCALCULATOR_u8_CreatNum(u32 *ptr,u8 digit)
{
	*ptr= (*ptr) * 10 + (u32)(digit-48);
}
/*---------------------------------------------------------------------------------------------------------------------*/
void SetGlobalSecCounterMinCounter(u32 minutes,u32 seconds)
{
	global_u8_MinCounter = minutes + (seconds/60);
	global_u8_SecCounter= (seconds%60)+1 ;
}
/*---------------------------------------------------------------------------------------------------------------------*/

void StopWatch(void)
{
	if(global_u8_program_flag==1)
	{
	global_u8_SecCounter--;

	u8 local_u8_loop_counter=4;
	/*-------------------------------------------------------------*/
    /*-------WHILE LOOP TO CLEAR LINE 2 on LCD---------*/
	HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL4);
	while(local_u8_loop_counter<16)
	{
		HLCD_SendCommand(0x02);
		local_u8_loop_counter++;
	}
	local_u8_loop_counter=4;
	/*-------------------------------------------------------------*/
	/*--------LCD Display----------*/
	HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL4);
	HLCD_VoidDisplayNumber(global_u8_MinCounter);
	HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL10);
	HLCD_VoidDisplayNumber(global_u8_SecCounter);
	if(global_u8_SecCounter!= 0 && global_u8_MinCounter!= 0)
	{
	}
	else if(global_u8_SecCounter== 0 && global_u8_MinCounter!= 0)
	{
		global_u8_MinCounter--;
		global_u8_SecCounter=60;
	}
	else if(global_u8_SecCounter== 0 && global_u8_MinCounter== 0)
	{
		/*-------------------------------------------------------------*/
	    /*-------WHILE LOOP TO CLEAR LINE 2 on LCD---------*/
		HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL4);
		while(local_u8_loop_counter<16)
		{
			HLCD_SendCommand(0x02);
			local_u8_loop_counter++;
		}
		local_u8_loop_counter=4;
		/*-------------------------------------------------------------*/
		/*--------LCD Display----------*/
		HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL4);
		HLCD_VoidDisplayNumber(global_u8_MinCounter);
		HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL10);
		HLCD_VoidDisplayNumber(global_u8_SecCounter);
		/*-------------------------------------------------------------*/
		/*-----Function to toggle LED -----*/
		TOGGLE();
		/*-------------------------------------------------------------*/
		/*-----Clear this flag to start a new process -----*/
		global_u8_program_flag=0;
	}
	}
}
/*---------------------------------------------------------------------------------------------------------------------*/
void APP_u8_GetNumber(void)
{
	static u8 static_local_u8_flag=0;
	u8 local_u8_key1,local_u8_loop_flag=1;
	u32 *local_u32_pointer =NULL;

	/* get the pressed button from keypad */
	local_u8_key1 = HKEYPAD_u8_GetPressedKey();

	/*make sure that the entered key = a number */
    while(  local_u8_key1==KEYPAD_u8_KEY_NOT_PRESSED  || APPCALCULATOR_u8_CheckNum(local_u8_key1)!='n')
    {
    	 /*get the pressed button from keypad */
    	local_u8_key1 = HKEYPAD_u8_GetPressedKey();
    }
    HLCD_VoidClearDisplay();
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0);
    if(static_local_u8_flag==0)
    {
    HLCD_VoidSendString("MINUTES = ");
    local_u32_pointer=&global_u32_num1;
    static_local_u8_flag=1;
    }
    else if(static_local_u8_flag==1)
    {
    HLCD_VoidSendString("SECONDS = ");
    local_u32_pointer=&global_u32_num2;
    static_local_u8_flag=0;
    }
	HLCD_VoidSendData(local_u8_key1);
	/*FUNCTION TO ADD A NEW DIGIT TO THE NUMBER*/
	APPCALCULATOR_u8_CreatNum(local_u32_pointer,local_u8_key1);
	/* get the pressed button from keypad */
	local_u8_key1 = HKEYPAD_u8_GetPressedKey();

	/*GO OUT WHILE WHEN INPUT == '='*/
	while( local_u8_loop_flag==1 )
	{
		/*make sure that the entered key = number or '=' character*/
		 if(local_u8_key1!=KEYPAD_u8_KEY_NOT_PRESSED && (local_u8_key1>='0' &&  local_u8_key1<='9'))
		 {
			 HLCD_VoidSendData(local_u8_key1);
			 /*FUNCTION TO ADD A NEW DIGIT TO THE NUMBER*/
			 APPCALCULATOR_u8_CreatNum(local_u32_pointer,local_u8_key1);
			 /* get the pressed button from keypad */
			 local_u8_key1 = HKEYPAD_u8_GetPressedKey();
		 }
		 else if( local_u8_key1!=KEYPAD_u8_KEY_NOT_PRESSED &&   local_u8_key1=='=' )
		 {
			 /*The user entered '=' so go out the while loop */
			 local_u8_loop_flag=0;
		 }
		 else
		 {   /*IF THE INPUT CHARACTER NOT '=' NOR A NUMBER*/
			 /* get the pressed button from keypad again */
			 local_u8_key1 = HKEYPAD_u8_GetPressedKey();
		 }
	}
}
int main(void)
{
	MDIO_VoidInit();
    MDIO_VoidSetPortDirection(DIO_U8_PORTA,DIO_U8_PORT_OUTPUT);
	MDIO_VoidSetPortDirection(DIO_U8_PORTC,DIO_U8_PORT_OUTPUT);
	MDIO_VoidSetPortDirection(DIO_U8_PORTB,0x0f);
	MTIMERS_voidTimer0Init();
	HLCD_VoidInit();

	while(1)
	{
       if(global_u8_program_flag==0)
       {
    	 global_u32_num1=0;
    	 global_u32_num2=0;

    	 /*-------------------------------------------------------------*/
    	 /*--------LCD Display----------*/
		HLCD_VoidClearDisplay();
		HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL2);
		HLCD_VoidSendString("ENTER MINUTES");
		HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL2);
		HLCD_VoidSendString("THEN ENTER =");
		/* ASK USER TO INPUT THE NUMBER OF MINUTES*/
		APP_u8_GetNumber();

		/*-------------------------------------------------------------*/
		/*--------LCD Display----------*/
		HLCD_VoidClearDisplay();
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL2);
		HLCD_VoidSendString("ENTER SECONDS");
		HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL2);
		HLCD_VoidSendString("THEN ENTER =");
		/* ASK USER TO INPUT THE NUMBER OF SECONDS*/
		APP_u8_GetNumber();

		/*-------------------------------------------------------------*/
		/*--------LCD Display----------*/
	    HLCD_VoidClearDisplay();
		HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0);
		HLCD_VoidSendString("MINUTES :");
		HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL9);
		HLCD_VoidSendString("SECONDS");

		/*-------------------------------------------------------------*/
		/*-----Set SecCounter & MinCounter Values----------*/
		SetGlobalSecCounterMinCounter(global_u32_num1,global_u32_num2);

		/*-------------------------------------------------------------*/
		/*-----Start StopWatch----------*/
		MTIMERS_voidTimer0CTCSetCallBack(StopWatch);
	    MGI_voidEnable();

	    /* Set global_u8_program_flag to 1         -------
 	 	   wait function StopWatch to clear it =0  -------
 	 	   then start a new process                -------
 	 	*/
	    global_u8_program_flag=1;

        }
	} /***********_WHILE(1)_CURLE_***************/
	return 1;
}  /***********_MAIN_CURLE_***************/


