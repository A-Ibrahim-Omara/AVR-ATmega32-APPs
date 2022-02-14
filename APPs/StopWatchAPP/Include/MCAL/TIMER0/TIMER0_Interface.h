/*
 * TIMERS_Interface.h
 *
 *  Created on: Jan 18, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_

/***************************************************************************************/
/***************************************************************************************/

#define TIMER0_u8_TCNT0      *((volatile u8 *)0x52)

/***************************************************************************************/
/***************************************************************************************/

/***************************************************************************************/
/* Timer/Counter Control Register – TCCR0 */


#define TCCR0_u8_COM00_PIN4      4
#define TCCR0_u8_COM01_PIN5      5


/*       Mode  WGM01   WGM00   Timer/Counter          TOP    Update of(OCR0)  OV0 Flag  *
*              (CTC0)   (PWM0)   Mode of Operation                              Set-on  *
*          0 	0        0       Normal               0xFF 	  Immediate 		MAX     *
*		  1 	0        1       PWM, Phase Correct   0xFF 	  TOP 				BOTTOM  *
*		  2 	1        0       CTC                  OCR0 	  Immediate			MAX     *
*		  3 	1        1       Fast PWM             0xFF 	  BOTTOM 			MAX     *
*/
#define TCCR0_u8_WGM01_PIN3      3
#define TCCR0_u8_WGM00_PIN6      6


/*value	CS02 CS01 CS00  Description												    *
*	0	 0    0    0      No clock source (Timer/Counter stopped).                  *
*	1	 0    0    1      clkI/O/     (No prescaling)                               *
*	2	 0    1    0      clkI/O/8    (From prescaler)                              *
*	3	 0    1    1      clkI/O/64   (From prescaler)                              *
*	4	 1    0    0      clkI/O/256  (From prescaler)                              *
*	5	 1    0    1      clkI/O/1024 (From prescaler)                              *
*	6	 1    1    0      External clock source on T0 pin. Clock on falling edge.   *
*	7	 1    1    1      External clock source on T0 pin. Clock on rising edge.    *
*/
#define TCCR0_u8_CS00_PIN0        0
#define TCCR0_u8_CS01_PIN1        1
#define TCCR0_u8_CS02_PIN2        2
/***************************************************************************************/


/***************************************************************************************/
/* Timer/Counter Interrupt MaskRegister–TIMSK */

#define TIMSK_u8_TOIE0_PIN0       0             /*Timer/Counter0 Overflow Interrupt Enable*/
#define TIMSK_u8_OCIE0_PIN1       1             /* Timer/Counter0 Output Compare Match Interrupt Enable  */

/***************************************************************************************/

/***************************************************************************************/
/*Timer/Counter Interrupt Flag Register– TIFR*/

#define TIFR_u8_OCF0_PIN0         0               /*Output Compare Flag 0*/
#define TIFR_u8_TOV0_PIN1         1               /* Timer/Counter0 Overflow Flag  */

/***************************************************************************************/
#define ENABLE                    1
#define DISABLE                   0

#define TIMER_u8_NORMAL_MODE      1
#define TIMER_u8_CTC_MODE         2

#define TIMERS_u8_PRELOAD_VALUE      192

#define TIMERS_u8_TCCR0_PRESCALER_MASK  0b11111000

/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MTIMERS_voidTimer0Init           *******/
/*Description      -->> To initiate Timer0               *******/
/*Arguments Input  -->> void                             *******/
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MTIMERS_voidTimer0Init(void);
/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MTIMERS_voidTimer0OVFSetCallBack *******/
/*Description      -->> callback function timer overflow *******/
/*Arguments Input  -->> pointer to func                  *******/
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MTIMERS_voidTimer0OVFSetCallBack(void(*copy_pf)(void));
/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MTIMERS_voidTimer0CTCSetCallBack *******/
/*Description      -->> callback function CTC mode       *******/
/*Arguments Input  -->> poiner to func                   *******/
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MTIMERS_voidTimer0CTCSetCallBack(void(*copy_pf)(void));
/*-------------------------------------------------------------*/

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
