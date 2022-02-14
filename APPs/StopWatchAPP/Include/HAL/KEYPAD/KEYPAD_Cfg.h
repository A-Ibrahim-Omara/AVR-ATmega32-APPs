/*
 * KEYPAD_Cfg.h
 *
 *  Created on: Jan 9, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_

/*-------------------------------------------------------------*/
#define KEYPAD_u8_PORT DIO_U8_PORTB
#define KEYPAD_u8_ROW_NUM 4
#define KEYPAD_u8_COL_NUM 4
/*-------------------------------------------------------------*/
#define KEYPAD_u8_R1_PIN DIO_U8_PIN0
#define KEYPAD_u8_R2_PIN DIO_U8_PIN1
#define KEYPAD_u8_R3_PIN DIO_U8_PIN2
#define KEYPAD_u8_R4_PIN DIO_U8_PIN3
/*-------------------------------------------------------------*/
#define KEYPAD_u8_C1_PIN DIO_U8_PIN4
#define KEYPAD_u8_C2_PIN DIO_U8_PIN5
#define KEYPAD_u8_C3_PIN DIO_U8_PIN6
#define KEYPAD_u8_C4_PIN DIO_U8_PIN7
/*-------------------------------------------------------------*/


/*-------------------------------------------------------------*/
#define KEYPAD_Au8ROWS {KEYPAD_u8_R1_PIN,KEYPAD_u8_R2_PIN,KEYPAD_u8_R3_PIN,KEYPAD_u8_R4_PIN}
#define KEYPAD_Au8COLS {KEYPAD_u8_C1_PIN,KEYPAD_u8_C2_PIN,KEYPAD_u8_C3_PIN,KEYPAD_u8_C4_PIN}
/*-------------------------------------------------------------*/
#define KEYPAD_Au8_KEYS {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}}
/*-------------------------------------------------------------*/
#define KEYPAD_u8_DEBOUNCING 20
/*-------------------------------------------------------------*/
#define KEYPAD_u8_FLAG_DOWN 0
#define KEYPAD_u8_FLAG_UP   1
/*-------------------------------------------------------------*/
#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_ */
