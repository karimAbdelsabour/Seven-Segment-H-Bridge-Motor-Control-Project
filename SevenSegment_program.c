/*
 * SevenSegment_program.c
 *
 * Created: 11/8/2023 5:19:09 PM
 *  Author: Kareem
 */ 
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "LED_interface.h"
#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
;
void HSevenSegment_voidInit(SevenSegment_t* SS)
{
	enum LedState_t state=Led_Active_High;
	  if(SS->Type==COMMON_ANODE)
	  state=Led_Active_LOW;
	  for(u8 i=0;i<7;i++)
	  {
		SS->Segments[i].State=state;
		HLED_voidInit(SS->Segments+i);
	  }
	  HSevenSegment_voidClear(SS);
	  if(SS->DPstate==DP_ENABLE)
	  {
		  SS->Segments[7].State=state;
		  HLED_voidInit(SS->Segments+7);
	  }
	  
}

void HSevenSegment_voidDisplayDigit(SevenSegment_t* SS,u8 Digit)
{
	if(Digit > 9)
	 return;
	u8 Copy_u8SSDigit=PrivateSevenSegmentDigits[Digit];
	for (u8 i =0; i < 7 ;i++)
	{
		if(GET_BIT(Copy_u8SSDigit,i)==1)
		HLED_voidTurnOn(SS->Segments+i);
		else
		HLED_voidTurnOff(SS->Segments+i);
	}
}

void HSevenSegment_voidClear(SevenSegment_t* SS)
{
	for (u8 i =0; i < 7 ;i++)
	{
		HLED_voidTurnOff(SS->Segments+i);
	}
}

void HSevenSegment_voidSetDP(SevenSegment_t* SS)
{
	for (u8 i =0; i < 7 ;i++)
	{
		HLED_voidTurnOn(SS->Segments+7);
	}
}

void HSevenSegment_voidClearDP(SevenSegment_t* SS)
{
	for (u8 i =0; i < 7 ;i++)
	{
		HLED_voidTurnOff(SS->Segments+7);
	}
}

u8 HSevenSegment_u8GetDigit(SevenSegment_t* SS);

