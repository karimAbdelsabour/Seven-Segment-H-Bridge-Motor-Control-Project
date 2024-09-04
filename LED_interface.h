/*
 * LED_interface.h
 *
 * Created: 11/7/2023 11:46:00 PM
 *  Author: Kareem
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

enum LedState_t {Led_Active_High,Led_Active_LOW};

typedef struct
{
	u8 pin;
	u8 port;
	enum LedState_t State;
}LED_t;

void HLED_voidInit(LED_t *Led);
void HLED_voidTurnOn(LED_t *Led);
void HLED_voidTurnOff(LED_t *Led);




#endif /* LED_INTERFACE_H_ */