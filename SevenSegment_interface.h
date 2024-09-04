/*
 * SevenSegment_interface.h
 *
 * Created: 11/8/2023 5:18:02 PM
 *  Author: Kareem
 */ 


#ifndef SEVENSEGMENT_INTERFACE_H_
#define SEVENSEGMENT_INTERFACE_H_

enum SevenSegmentType{COMMON_ANODE,COMMON_CATHODE};
enum SevenSegmentDP{DP_DESABLE,DP_ENABLE};
 typedef struct
 {
	 enum SevenSegmentType Type;
	 //a->0
	 //b->1
	 //c->2
	 //......
	 //DP->7
	 LED_t Segments[8];
	enum SevenSegmentDP DPstate;
 }SevenSegment_t;

void HSevenSegment_voidInit(SevenSegment_t* SS);

void HSevenSegment_voidDisplayDigit(SevenSegment_t* SS,u8 Digit);

void HSevenSegment_voidClear(SevenSegment_t* SS);

void HSevenSegment_voidSetDP(SevenSegment_t* SS);

void HSevenSegment_voidClearDP(SevenSegment_t* SS);

u8 HSevenSegment_u8GetDigit(SevenSegment_t* SS);


#endif /* SEVENSEGMENT_INTERFACE_H_ */