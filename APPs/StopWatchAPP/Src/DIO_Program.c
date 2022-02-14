/*
 * DIO_Program.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */
#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"

/*---------------------------------------------------------------------------------------------------------------------------*/
void MDIO_VoidInit(void)
{
	DIO_U8_DDRA_REG= CONC_BIT(DIO_U8_PA7_INITIAL_DIRECTION
						         ,DIO_U8_PA6_INITIAL_DIRECTION
						         ,DIO_U8_PA5_INITIAL_DIRECTION
						         ,DIO_U8_PA4_INITIAL_DIRECTION
						         ,DIO_U8_PA3_INITIAL_DIRECTION
						         ,DIO_U8_PA2_INITIAL_DIRECTION
						         ,DIO_U8_PA1_INITIAL_DIRECTION
						         ,DIO_U8_PA0_INITIAL_DIRECTION);

	DIO_U8_DDRB_REG= CONC_BIT(DIO_U8_PB7_INITIAL_DIRECTION
					         ,DIO_U8_PB6_INITIAL_DIRECTION
					         ,DIO_U8_PB5_INITIAL_DIRECTION
					         ,DIO_U8_PB4_INITIAL_DIRECTION
					         ,DIO_U8_PB3_INITIAL_DIRECTION
					         ,DIO_U8_PB2_INITIAL_DIRECTION
					         ,DIO_U8_PB1_INITIAL_DIRECTION
					         ,DIO_U8_PB0_INITIAL_DIRECTION);

	DIO_U8_DDRC_REG= CONC_BIT(DIO_U8_PC7_INITIAL_DIRECTION
						     ,DIO_U8_PC6_INITIAL_DIRECTION
						     ,DIO_U8_PC5_INITIAL_DIRECTION
						     ,DIO_U8_PC4_INITIAL_DIRECTION
						     ,DIO_U8_PC3_INITIAL_DIRECTION
						     ,DIO_U8_PC2_INITIAL_DIRECTION
						     ,DIO_U8_PC1_INITIAL_DIRECTION
						     ,DIO_U8_PC0_INITIAL_DIRECTION);

	DIO_U8_DDRD_REG= CONC_BIT(DIO_U8_PD7_INITIAL_DIRECTION
					         ,DIO_U8_PD6_INITIAL_DIRECTION
					         ,DIO_U8_PD5_INITIAL_DIRECTION
					         ,DIO_U8_PD4_INITIAL_DIRECTION
					         ,DIO_U8_PD3_INITIAL_DIRECTION
					         ,DIO_U8_PD2_INITIAL_DIRECTION
					         ,DIO_U8_PD1_INITIAL_DIRECTION
					         ,DIO_U8_PD0_INITIAL_DIRECTION);

	DIO_U8_PORTA_REG= CONC_BIT(DIO_U8_PA7_INITIAL_VALUE
					          ,DIO_U8_PA6_INITIAL_VALUE
					          ,DIO_U8_PA5_INITIAL_VALUE
					          ,DIO_U8_PA4_INITIAL_VALUE
					          ,DIO_U8_PA3_INITIAL_VALUE
					          ,DIO_U8_PA2_INITIAL_VALUE
					          ,DIO_U8_PA1_INITIAL_VALUE
					          ,DIO_U8_PA0_INITIAL_VALUE);

	DIO_U8_PORTB_REG= CONC_BIT(DIO_U8_PB7_INITIAL_VALUE
						      ,DIO_U8_PB6_INITIAL_VALUE
						      ,DIO_U8_PB5_INITIAL_VALUE
						      ,DIO_U8_PB4_INITIAL_VALUE
						      ,DIO_U8_PB3_INITIAL_VALUE
						      ,DIO_U8_PB2_INITIAL_VALUE
						      ,DIO_U8_PB1_INITIAL_VALUE
						      ,DIO_U8_PB0_INITIAL_VALUE);

	DIO_U8_PORTC_REG= CONC_BIT(DIO_U8_PC7_INITIAL_VALUE
							  ,DIO_U8_PC6_INITIAL_VALUE
							  ,DIO_U8_PC5_INITIAL_VALUE
							  ,DIO_U8_PC4_INITIAL_VALUE
							  ,DIO_U8_PC3_INITIAL_VALUE
							  ,DIO_U8_PC2_INITIAL_VALUE
							  ,DIO_U8_PC1_INITIAL_VALUE
							  ,DIO_U8_PC0_INITIAL_VALUE);

	DIO_U8_PORTD_REG= CONC_BIT(DIO_U8_PD7_INITIAL_VALUE
						      ,DIO_U8_PD6_INITIAL_VALUE
						      ,DIO_U8_PD5_INITIAL_VALUE
						      ,DIO_U8_PD4_INITIAL_VALUE
						      ,DIO_U8_PD3_INITIAL_VALUE
						      ,DIO_U8_PD2_INITIAL_VALUE
						      ,DIO_U8_PD1_INITIAL_VALUE
						      ,DIO_U8_PD0_INITIAL_VALUE);
}
/*---------------------------------------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPinDirection(u8 copy_u8portid,u8 copy_u8pinid,u8 copy_u8pindirection)
{
	if( (copy_u8portid > DIO_U8_PORTD) || (copy_u8portid < DIO_U8_PORTA) )
	{

	}
else
{
	switch(copy_u8portid)
	{
	case DIO_U8_PORTA:
		switch(copy_u8pindirection)
		{
		   case DIO_U8_OUTPUT: SET_BIT(DIO_U8_DDRA_REG,copy_u8pinid);
		   break;
		   case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRA_REG,copy_u8pinid);
		   break;
		}
		break;

	case DIO_U8_PORTB:
		switch(copy_u8pindirection)
		{
		   case DIO_U8_OUTPUT: SET_BIT(DIO_U8_DDRB_REG,copy_u8pinid);
		   break;
		   case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRB_REG,copy_u8pinid);
		   break;
				}
	    break;
	case DIO_U8_PORTC:
		switch(copy_u8pindirection)
		{
			 case DIO_U8_OUTPUT: SET_BIT(DIO_U8_DDRC_REG,copy_u8pinid);
			 break;
			 case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRC_REG,copy_u8pinid);
			 break;
			}
						break;
		case DIO_U8_PORTD:
				switch(copy_u8pindirection)
				{
				   case DIO_U8_OUTPUT: SET_BIT(DIO_U8_DDRD_REG,copy_u8pinid);
				   break;
				   case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRD_REG,copy_u8pinid);
				   break;
				}
				break;
	}
	}

}
/*---------------------------------------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPinValue(u8 copy_u8portid,u8 copy_u8pinid,u8 copy_u8pinValue)
{
	if( (copy_u8portid > DIO_U8_PORTD) || (copy_u8portid < DIO_U8_PORTA)||	(copy_u8pinid > DIO_U8_PIN7) || (copy_u8pinid < DIO_U8_PIN0) )
		{

		}
	else
	{
		switch(copy_u8portid)
		{
		case DIO_U8_PORTA:
			switch(copy_u8pinValue)
			{
			   case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTA_REG,copy_u8pinid);
			   break;
			   case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTA_REG,copy_u8pinid);
			   break;
			}
			break;

		case DIO_U8_PORTB:
			switch(copy_u8pinValue)
			{
			   case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTB_REG,copy_u8pinid);
			   break;
			   case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTB_REG,copy_u8pinid);
			   break;
					}
		    break;
		case DIO_U8_PORTC:
			switch(copy_u8pinValue)
			{
				 case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTC_REG,copy_u8pinid);
				 break;
				 case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTC_REG,copy_u8pinid);
				 break;
				}
							break;
			case DIO_U8_PORTD:
					switch(copy_u8pinValue)
					{
					   case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTD_REG,copy_u8pinid);
					   break;
					   case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTD_REG,copy_u8pinid);
					   break;
					}
					break;
		}
		}

	}
/*---------------------------------------------------------------------------------------------------------------------------*/
u8 MDIO_U8GetPinValue(u8 copy_u8portid,u8 copy_u8pinid)
{
	u8 result=0;
	if( (copy_u8portid > DIO_U8_PORTD) || (copy_u8portid < DIO_U8_PORTA)|| (copy_u8pinid > DIO_U8_PIN7) || (copy_u8pinid < DIO_U8_PIN0) )
			{

			}
		else
		{
			switch(copy_u8portid)
			{
			case DIO_U8_PORTA:
				   result= GET_BIT(DIO_U8_PINA_REG,copy_u8pinid);
				   break;

			case DIO_U8_PORTB:
				   result= GET_BIT(DIO_U8_PINB_REG,copy_u8pinid);
				   break;

			case DIO_U8_PORTC:
			       result= GET_BIT(DIO_U8_PINC_REG,copy_u8pinid);
				   break;
				case DIO_U8_PORTD:
				   result= GET_BIT(DIO_U8_PIND_REG,copy_u8pinid);
				   break;
			}
			}
	return result;
	}
/*---------------------------------------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPortDirection(u8 copy_u8portid,u8 copy_u8portdirection)
{
	if( (copy_u8portid > DIO_U8_PORTD) || (copy_u8portid < DIO_U8_PORTA))
			{

			}
		else
		{
			switch(copy_u8portid)
			{
			case DIO_U8_PORTA:
				SET_BYTE(DIO_U8_DDRA_REG,copy_u8portdirection);
				break;
			case DIO_U8_PORTB:
				SET_BYTE(DIO_U8_DDRB_REG,copy_u8portdirection);
				break;
			case DIO_U8_PORTC:
				SET_BYTE(DIO_U8_DDRC_REG,copy_u8portdirection);
				break;
			case DIO_U8_PORTD:
				SET_BYTE(DIO_U8_DDRD_REG,copy_u8portdirection);
				break;
			}
			}
	}
/*---------------------------------------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPortValue(u8 copy_u8portid,u8 copy_u8portValue)
{

		if( (copy_u8portid > DIO_U8_PORTD) || (copy_u8portid < DIO_U8_PORTA) )
				{

				}
			else
			{
				switch(copy_u8portid)
				{
				case DIO_U8_PORTA:
					    SET_BYTE(DIO_U8_PORTA_REG,copy_u8portValue);
					   break;

				case DIO_U8_PORTB:
					    SET_BYTE(DIO_U8_PORTB_REG,copy_u8portValue);
					   break;

				case DIO_U8_PORTC:
				        SET_BYTE(DIO_U8_PORTC_REG,copy_u8portValue);
					   break;
					case DIO_U8_PORTD:
					   SET_BYTE(DIO_U8_PORTD_REG,copy_u8portValue);
					   break;
				}
				}

	}
/*---------------------------------------------------------------------------------------------------------------------------*/







