/*
 * GI_Program.c
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Ibrahim
 */
#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Interface.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Private.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Cfg.h"

void MGI_u8_voidInit(void)
{
#if MGI_u8_INITIAL_ENABLE == MGI_u8_ENABLE
	SET_BIT(GI,MGI_u8_INTERRUPT_ENABLE_BIT);
#else
	CLR_BIT(GI,MGI_u8_INTERRUPT_ENABLE_BIT);
#endif
}

void MGI_voidEnable(void)
{
	SET_BIT(GI,MGI_u8_INTERRUPT_ENABLE_BIT);
}

void MGI_voidDisable(void)
{
	CLR_BIT(GI,MGI_u8_INTERRUPT_ENABLE_BIT);
}
