#include "gd32e23x.h"
#include "systick.h"
#include <stdio.h>

#include <led.h>
#include <delay.h>
#include <usart.h>
#include <wifi.h>
#include <key.h>
#include <pwm.h>

uint32_t USART0_RECEIVE_Buf[100]; 
uint32_t USART1_RECEIVE_Buf[100]; 
extern void Connect_Wifi(void);
int main(void)
{
    systick_config();   
		LED_Init();  
	  wifi_protocol_init();//wifi协议初始化
		USART0_Init();
		USART1_Init();
	  Key_Init();
    PWM_Config();
	
 while(1)
		{
	  	wifi_uart_service();//wifi串口数据处理服务
			Key_Deal();		
    }
}