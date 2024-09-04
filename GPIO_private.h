/*
 * GPIO_private.h
 *
 * Created: 11/7/2023 9:00:56 PM
 *  Author: Kareem
 */ 


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct {
	u8 PIN;
	u8 DDR;
	u8 PORT;
	
	}Port_t;
	
#define PORTA_REG        ((volatile  Port_t*)(0x39) //volatile to force compiler to set this in memory not in CPU
#define PORTB_REG        ((volatile  Port_t*)(0x36)
#define PORTC_REG        ((volatile  Port_t*)(0x33)
#define PORTD_REG        ((volatile  Port_t*)(0x30)
//we used casting in this line so that we make 0x39 to be a pointer points to struct of Port_t


#endif /* GPIO_PRIVATE_H_ */