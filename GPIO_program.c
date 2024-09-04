/*
 * GPIO_program.c
 *
 * Created: 11/3/2023 10:42:45 AM
 *  Author: Kareem
 */ 

#include <avr/io.h>

#define SET_BIT(VAR,BIT) (VAR|=(1<<BIT))
#define CLR_BIT(VAR,BIT) (VAR&=(~(1<<BIT)))
#define TOG_BIT(VAR,BIT) (VAR^=(1<<BIT))
#define GET_BIT(VAR,BIT) (((VAR>>BIT)) & 1)

#include "STD_Types.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
 
 
 
 /*Port_t* PGPIO_PORT_tPtrGetRegister(enum GPIOPort_ID_T PortId)
 {
	 switch (PortId)
	 {
		 case GPIO_PortA:
		 return PORTA_REG;

		 case GPIO_PortB:
		 return PORTB_REG;

		 case GPIO_PortC:
		 return PORTC_REG;

		 case GPIO_PortD:
		 return PORTD_REG;

		 default:
		 return 0; 
	 }
 }*/
 
void MGPIO_voidSetPinDirection(enum GPIOPort_ID_T PortId ,  u8 PinNumber, enum GPIODirection_T Direction)
{
	//0 --> PortA
	//1 --> PortB
	//2 --> PortC
	//3 --> PortD
	
	//0 --> Input
	//1 --> Output
	//2 --> Input_PullUp
	//Port_t* p=0;
	//p=PGPIO_PORT_tPtrGetRegister(PortId);
	
	switch(PortId)
	{
		case GPIO_PortA:
		if(Direction==GPIO_Input)
		{
			CLR_BIT(DDRA,PinNumber);
			CLR_BIT(PORTA,PinNumber);
		}
		else if(Direction==GPIO_Output)
		{
			SET_BIT(DDRA,PinNumber);
			CLR_BIT(PORTA,PinNumber);
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			CLR_BIT(DDRA,PinNumber);
			SET_BIT(PORTA,PinNumber);
		}
		break;
		case GPIO_PortB:
		if(Direction==GPIO_Input)
		{
			CLR_BIT(DDRB,PinNumber);
			CLR_BIT(PORTB,PinNumber);
		}
		else if(Direction==GPIO_Output)
		{
			SET_BIT(DDRB,PinNumber);
			CLR_BIT(PORTB,PinNumber);
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			CLR_BIT(DDRB,PinNumber);
			SET_BIT(PORTB,PinNumber);
		}
		break;
		case GPIO_PortC:
		if(Direction==GPIO_Input)
		{
			CLR_BIT(DDRC,PinNumber);
			CLR_BIT(PORTC,PinNumber);
		}
		else if(Direction==GPIO_Output)
		{
			SET_BIT(DDRC,PinNumber);
			CLR_BIT(PORTC,PinNumber);
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			CLR_BIT(DDRC,PinNumber);
			SET_BIT(PORTC,PinNumber);
		}
		break;
		case GPIO_PortD:
		if(Direction==GPIO_Input)
		{
			CLR_BIT(DDRD,PinNumber);
			CLR_BIT(PORTD,PinNumber);
		}
		else if(Direction==GPIO_Output)
		{
			SET_BIT(DDRD,PinNumber);
			CLR_BIT(PORTD,PinNumber);
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			CLR_BIT(DDRD,PinNumber);
			SET_BIT(PORTD,PinNumber);
		}
		break;
	}
	
}
void MGPIO_voidSetPortDirection(enum GPIOPort_ID_T PortId , enum GPIODirection_T Direction)
{
	//0 --> PortA
	//1 --> PortB
	//2 --> PortC
	//3 --> PortD
	
	//0 --> Input
	//1 --> Output
	//2 --> Input_PullUp
	
	switch(PortId)
	{
		case GPIO_PortA:
		if(Direction==GPIO_Input)
		{
			DDRA=0;
			PORTA=0;
		}
		else if(Direction==GPIO_Output)
		{
			DDRA=255;
			PORTA=0;
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			DDRA=0;
			PORTA=255;
		}
		break;
		case GPIO_PortB:
		if(Direction==GPIO_Input)
		{
			DDRB=0;
			PORTB=0;
		}
		else if(Direction==GPIO_Output)
		{
			DDRB=0;
			PORTB=0;
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			DDRB=0;
			PORTB=0;
		}
		break;
		case GPIO_PortC:
		if(Direction==GPIO_Input)
		{
			DDRC=0;
			PORTC=0;
		}
		else if(Direction==GPIO_Output)
		{
			DDRC=0;
			PORTC=0;
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			DDRC=0;
			PORTC=0;
		}
		break;
		case GPIO_PortD:
		if(Direction==GPIO_Input)
		{
			DDRD=0;
			PORTD=0;
		}
		else if(Direction==GPIO_Output)
		{
			DDRD=0;
			PORTD=0;
		}

		else if(Direction==GPIO_Input_PullUp)
		{
			DDRD=0;
			PORTD=0;
		}
		break;
	}
	
}
void MGPIO_voidSetPinValue(enum GPIOPort_ID_T PortId,u8 PinNumber,enum GPIOValue_T Value)
{
	//0 --> PortA
	//1 --> PortB
	//2 --> PortC
	//3 --> PortD
	
	//0 --> low
	//1 --> High

	
	switch(PortId)
	{
		case GPIO_PortA:
		if(Value==GPIO_LOW)
		{
			CLR_BIT(PORTA,PinNumber);
		}
		else if(Value==GPIO_High)
		{
			SET_BIT(PORTA,PinNumber);
			
		}

		
		break;
		case GPIO_PortB:
		if(Value==GPIO_LOW)
		{
			CLR_BIT(PORTB,PinNumber);
		}
		else if(Value==GPIO_High)
		{
			SET_BIT(PORTB,PinNumber);
			
		}

		
		break;
		case GPIO_PortC:
		if(Value==GPIO_LOW)
		{
			
			CLR_BIT(PORTC,PinNumber);
		}
		else if(Value==GPIO_High)
		{
			SET_BIT(PORTC,PinNumber);
			
		}

		
		break;
		case GPIO_PortD:
		if(Value==GPIO_LOW)
		{

			CLR_BIT(PORTD,PinNumber);
		}
		else if(Value==GPIO_High)
		{
			SET_BIT(PORTD,PinNumber);
			
		}
		break;
	}
	
}
void MGPIO_voidSetPortValue(enum GPIOPort_ID_T PortId,u8 Value)
{
	//0 --> PortA
	//1 --> PortB
	//2 --> PortC
	//3 --> PortD
	
	//0 --> low
	//1 --> High

	
	switch(PortId)
	{
		case GPIO_PortA:
		
		PORTA=Value;
		
		break;
		case GPIO_PortB:
		PORTB=Value;
		
		break;
		case GPIO_PortC:
		
		PORTC=Value;
		
		break;
		case GPIO_PortD:
		PORTD=Value;
		break;
		
	}
	
}
void MGPIO_voidTogglePort(enum GPIOPort_ID_T PortId)
{
	//0 --> PortA
	//1 --> PortB
	//2 --> PortC
	//3 --> PortD
	
	switch(PortId)
	{
		case GPIO_PortA:
		
		PORTA ^=255;
	
		break;
		
		case GPIO_PortB:
		PORTB ^=255;
		
		break;
		
		case GPIO_PortC:
		
		PORTC ^=255;
		
		break;
		
		case GPIO_PortD:
		PORTD ^=255;
		
		break;
		
	}
	
}
u8 MGPIO_u8GetPinValue(enum GPIOPort_ID_T PortId,u8 PinNumber)
{
		
		
		u8 local_u8Val=0;
		switch(PortId)
		{
		case GPIO_PortA:
		
		local_u8Val=GET_BIT(PINA,PinNumber);
		
		
		break;
		
		case GPIO_PortB:
		local_u8Val=GET_BIT(PORTB,PinNumber);
		
		break;
		
		case GPIO_PortC:
		
		 local_u8Val=GET_BIT(PORTC,PinNumber);
		
		break;
		
		case GPIO_PortD:
		local_u8Val=GET_BIT(PORTD,PinNumber);
		
		break;
		}
		if(local_u8Val)
		{
			
		return GPIO_High;
		}
		else
		{
			
		return GPIO_LOW;	
		}
		

}
u8 MGPIO_u8GetPortValue(enum GPIOPort_ID_T PortId)
{
	u8 local_u8Val=0;
	switch(PortId)
	{
		case GPIO_PortA:
		
		local_u8Val=PINA;
		
		
		break;
		
		case GPIO_PortB:
		local_u8Val=PORTB;
		
		break;
		
		case GPIO_PortC:
		
		local_u8Val=PORTC;
		
		break;
		
		case GPIO_PortD:
		local_u8Val=PORTD;
		
		break;
	}
	return local_u8Val;
}

