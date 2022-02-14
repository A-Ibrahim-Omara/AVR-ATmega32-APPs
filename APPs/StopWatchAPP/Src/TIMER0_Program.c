/*
 * TIMERS_Program.c
 *
 *  Created on: Jan 18, 2022
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

#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Interface.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Private.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Cfg.h"

#include "../Include/MCAL/TIMER0/TIMER0_Private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Cfg.h"

static PF global_PF_NORMAL=NULL ;
static PF global_PF_CTC=NULL ;


void __vector_11(void)	__attribute__((signal));
void __vector_11(void)
{
	static u16 local_u8Counter =0;
		local_u8Counter++;
		if(local_u8Counter==3097)
		{
			TIMER0_u8_TCNT0=TIMERS_u8_PRELOAD_VALUE;
			local_u8Counter=0;
			if (global_PF_NORMAL!=NULL)
			{
				global_PF_NORMAL();
			}
		}
}
void __vector_10(void)	__attribute__((signal));
void __vector_10(void)
{
	static u16 local_u8Counter =0;
			local_u8Counter++;
			if(local_u8Counter==10000)
			{
				local_u8Counter=0;
				if (global_PF_CTC!=NULL)
				{
					global_PF_CTC();
				}
			}
}
void MTIMERS_voidTimer0Init(void)
{
  #if(TIMER_u8_MODE == TIMER_u8_NORMAL_MODE)
	  /*Choose Normal Mode*/
	  CLR_BIT(TIMER0_u8_TCCR0,TCCR0_u8_WGM01_PIN3);
      CLR_BIT(TIMER0_u8_TCCR0,TCCR0_u8_WGM00_PIN6);
			#if(TIMER_u8_OVF_INTERRUPT == ENABLE)
      	  	  /*Timer/Counter0 Overflow Interrupt Enable*/
      	  	  SET_BIT(TIMER0_u8_TIMSK,TIMSK_u8_TOIE0_PIN0);
    		#else
      	  	  /*Timer/Counter0 Overflow Interrupt Disable*/
      	  	  CLR_BIT(TIMER0_u8_TIMSK,TIMSK_u8_TOIE0_PIN0);
    		#endif
  TIMER0_u8_TCNT0=TIMERS_u8_PRELOAD_VALUE;

  #elif (TIMER_u8_MODE == TIMER_u8_CTC_MODE)

    	  SET_BIT(TIMER0_u8_TCCR0,TCCR0_u8_WGM01_PIN3);
    	  CLR_BIT(TIMER0_u8_TCCR0,TCCR0_u8_WGM00_PIN6);

			#if(TIMER_u8_CTC_INTERRUPT == ENABLE)
    	  	  /*Timer/Counter0 Overflow Interrupt Enable*/
    	  	  SET_BIT(TIMER0_u8_TIMSK,TIMSK_u8_OCIE0_PIN1);
    		#else
    	  	  /*Timer/Counter0 Overflow Interrupt Disable*/
    	  	  CLR_BIT(TIMER0_u8_TIMSK,TIMSK_u8_OCIE0_PIN1);
    		#endif
 TIMER0_u8_OCR0= TIMERS_u8_OCR0_VALUE;

  #endif

  TIMER0_u8_TCCR0 &=TIMERS_u8_TCCR0_PRESCALER_MASK;
  TIMER0_u8_TCCR0 |= TIMERS_u8_PRESCALER_VALUE;

     /*Compare match OUTPUT mode off*/
  /*    CLR_BIT(TIMER0_u8_TCCR0,TCCR0_u8_COM00_PIN4);
      CLR_BIT(TIMER0_u8_TCCR0,TCCR0_u8_COM01_PIN5);
*/
     /*Select 1024 Prescaler */

}

void MTIMERS_voidTimer0OVFSetCallBack(void(*copy_pf)(void))
{
	global_PF_NORMAL=copy_pf;
}
void MTIMERS_voidTimer0CTCSetCallBack(void(*copy_pf)(void))
{
	global_PF_CTC=copy_pf;
}
