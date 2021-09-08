#ifndef __KEY_H
#define __KEY_H

#define KEY		GPIO_PIN_8
#define GET_KEY()	gpio_input_bit_get(GPIOB, KEY)

#define KEY_PRESS			  	0U		//key pressed
#define KEY_RELEASE				1U		//key released

void Key_Init(void);
unsigned char Get_Key_State(void);
void Key_Deal(void);

#endif
