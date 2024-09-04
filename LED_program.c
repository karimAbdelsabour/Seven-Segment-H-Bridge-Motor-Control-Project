/*
 * GPIO_program.c
 *
 * Created: 11/3/2023 10:42:45 AM
 *  Author: Kareem
 */ 

#include <avr/io.h>
#include "STD_Types.h"
#include "GPIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "BIT_MATH.H"
 
 void HLED_voidInit(LED_t *Led)
 {
	MGPIO_voidSetPinDirection(Led->port,Led->pin,GPIO_Output);  
	 HLED_voidTurnOff(Led);
 }
 void HLED_voidTurnOn(LED_t *Led)
 {
	 if(Led->State==Led_Active_High)
	 MGPIO_voidSetPinValue(Led->port,Led->pin,GPIO_High);
	 else
	 MGPIO_voidSetPinValue(Led->port,Led->pin,GPIO_LOW); 
	 
 }
 void HLED_voidTurnOff(LED_t *Led)
 {
	  if(Led->State==Led_Active_High)
	  MGPIO_voidSetPinValue(Led->port,Led->pin,GPIO_LOW);
	  else
	  MGPIO_voidSetPinValue(Led->port,Led->pin,GPIO_High);
	 
 }


 