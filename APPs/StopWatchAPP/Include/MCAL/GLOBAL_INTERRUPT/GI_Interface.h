/*
 * GI_Interface.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_GLOBAL_INTERRUPT_GI_INTERFACE_H_
#define INCLUDE_MCAL_GLOBAL_INTERRUPT_GI_INTERFACE_H_
#include "../../LIB/bit_math.h"
#include "../../LIB/std_type.h"

/*-------------------------------------------------------------*/
#define MGI_u8_INTERRUPT_ENABLE_BIT 7
/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MGI_u8_voidInit                  *******/
/*Description      -->> Global Interrupt Initialization  *******/
/*Arguments Input  -->> void                             *******/
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MGI_u8_voidInit(void);
/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MGI_voidEnable                  *******/
/*Description      -->> Global Interrupt Enable          *******/
/*Arguments Input  -->> void                             *******/
/*Arguments Output -->> void                             *******/
/***************************************************************/
void MGI_voidEnable(void);
/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MGI_voidDisable                  *******/
/*Description      -->> Global Interrupt Disable         *******/
/*Arguments Input  -->> void                             *******/
/*Arguments Output -->> void                             *******/
/***************************************************************/
void MGI_voidDisable(void);
/*-------------------------------------------------------------*/

#endif /* INCLUDE_MCAL_GLOBAL_INTERRUPT_GI_INTERFACE_H_ */
