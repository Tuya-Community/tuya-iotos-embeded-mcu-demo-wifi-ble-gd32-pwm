#include "led.h"

void LED_Init(void)
{    
    rcu_periph_clock_enable(RCU_GPIOA);          //ʹ��GPIOAʱ��
	  rcu_periph_clock_enable(RCU_GPIOB);          //ʹ��GPIOBʱ��
    //����GPIOA_07 
    gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_7);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);
	  //����GPIOA_08 
    gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_8);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
    //����GPIOB_09 
    gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_9);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

	  //Ĭ�ϵ͵�ƽ
    gpio_bit_reset(GPIOA,GPIO_PIN_7);
    gpio_bit_reset(GPIOA,GPIO_PIN_8);
    gpio_bit_set(GPIOB,GPIO_PIN_9);
}
 