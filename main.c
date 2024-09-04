/*
 * Task 3 motor driver.c
 *
 * Created: 11/13/2023 7:59:33 PM
 * Author : Kareem
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "GPIO_interface.h"
#include "LED_interface.h"
#include "SevenSegment_interface.h"

volatile unsigned char reset_requested = 0;
volatile unsigned char button_state = 0;

ISR(INT0_vect)
{
	reset_requested = 1;
}

int main(void)
{
	
	DDRC = 0b11111100;
	PORTC = 0;
	
	
	DDRB = 0b11111111; 
	PORTB = 0b00000000;

	
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);
	MCUCR |= (1 << ISC01);
	GICR |= (1 << INT0);
	sei();
	
	SevenSegment_t S1;
	S1.Type = COMMON_ANODE;
	
	for (int i = 0; i < 8; i++)
	{
		S1.Segments[i].port = GPIO_PortC;
		S1.Segments[i].pin = i;
	}
	
	HSevenSegment_voidInit(&S1);
	
	u8 count = 0;
	
	while (1)
	{
		
		if (reset_requested) //if interrupt requested counter will reset
		{
			reset_requested = 0;
			count = 0;
			HSevenSegment_voidDisplayDigit(&S1, count);
		}
		else if (GET_BIT(PIND, 1) == 0)   //if switch opened and this is the default case seven segment will increments 
		{
				count++;
				count %= 10;
				HSevenSegment_voidDisplayDigit(&S1, count);
				_delay_ms(1000);	
		}
		else if (GET_BIT(PIND,1) == 1) //if switch closed  seven segment will decrements 
		{
			
				if (count == 0)
				count = 9;
				else
				count--;
				HSevenSegment_voidDisplayDigit(&S1, count);
				_delay_ms(500);
		
		}
		if (GET_BIT(PIND, 3) == 1)    //if switch closed motor will start rotating
		{
		if (GET_BIT(PIND, 0) == 0)    //if switch open and this is the default case motor will rotate in clockwise
		{
			PORTB = 0x05;
			
		}
		else if (GET_BIT(PIND, 0) == 1) //if switch closed  motor will rotate in counterclockwise
		{
			PORTB = 0x0A ;
		}
		else 
		{
		PORTB = 0x00;	//if switch opened motor will stop rotating
		}	
		}
		

	}
	
	
	return 0;
}






	
	