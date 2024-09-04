/*
 * GPIO_interface.h
 *
 * Created: 11/3/2023 10:54:58 AM
 *  Author: Kareem
 */ 


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

enum GPIOPort_ID_T{GPIO_PortA,GPIO_PortB,GPIO_PortC,GPIO_PortD};
enum GPIODirection_T{GPIO_Input,GPIO_Output,GPIO_Input_PullUp};
enum GPIOValue_T{GPIO_LOW=0,GPIO_High=1};

void MGPIO_voidSetPinDirection(enum GPIOPort_ID_T PortId,u8 PinNumber,enum GPIODirection_T Direction);
void MGPIO_voidSetPinValue(enum GPIOPort_ID_T PortId,u8 PinNumber,enum GPIOValue_T Value);

void MGPIO_voidSetPortDirection(enum GPIOPort_ID_T PortId,enum GPIODirection_T Direction);
void MGPIO_voidSetPortValue(enum GPIOPort_ID_T PortId,u8 Value);


void MGPIO_voidTogglePort(enum GPIOPort_ID_T PortId);
u8 MGPIO_u8GetPinValue(enum GPIOPort_ID_T PortId,u8 PinNumber);
u8 MGPIO_u8GetPortValue(enum GPIOPort_ID_T PortId);

//Port_t* PGPIO_PORT_tPtrGetRegister(enum GPIOPort_ID_T PortId);

#endif /* GPIO_INTERFACE_H_ */