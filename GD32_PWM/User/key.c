#include "gd32e23x.h"
#include "gd32e23x_timer.h"
#include "key.h"
#include "delay.h"
#include "protocol.h"
#include "mcu_api.h"
uint32_t pulse=0;
static uint8_t num=0;

void Key_Init(void)
{
    //配置GPIOB_08
	  /* configure button pin as input */
    gpio_mode_set(GPIOB, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_8);
}

//Get the state of key
unsigned char Get_Key_State(void)
{
	/*按键消抖*/
	if(KEY_PRESS == GET_KEY())
	{
			Delay_ms(10);
		if(KEY_PRESS == GET_KEY())
		{
			return KEY_PRESS;
		}
		else
		{
			return KEY_RELEASE;  
		}
	}
	else
	{
	  return KEY_RELEASE;  	
	}	
}
void Key_Deal(void)
{
	static uint8_t last_key_state = KEY_RELEASE;
	uint8_t current_key_state = KEY_RELEASE;
	
	current_key_state = Get_Key_State();
	/*last key was not pressed and now is pressed*/
	if((KEY_RELEASE == last_key_state)&&(KEY_PRESS == current_key_state))
   {
		   num++;
		  if(num==12)
				num=1;
	  switch (num)
	         {
						 case 1:
									pulse=0;   
						  break;        //占空比100%	
			       case 2:
									pulse=100;    
						  break;        //占空比10%
							case 3:
									pulse=200;   
						  break;        //占空比20%
							case 4:
						  		 pulse=300;   
							break;        //占空比30%
						  case 5:
									pulse=400;   
						  break;        //占空比40%	
							case 6:
									pulse=500;    
						  break;        //占空比50%
							case 7:
									pulse=600;   
						  break;        //占空比60%
							case 8:
						  		 pulse=700;   
							break;        //占空比70%
						  case 9:
									pulse=800;   
						  break;        //占空比80%
							case 10:
									pulse=900;   
						  break;        //占空比90%
							case 11:
									pulse=1000;   
						  break;        //占空比100%
							default:break;
					 }	
    }	
  while(KEY_PRESS == GET_KEY());	 		
	last_key_state = current_key_state;
	timer_channel_output_pulse_value_config(TIMER2,TIMER_CH_1,pulse);
	printf("X:%d \r\n",pulse);
	mcu_dp_value_update(DPID_PWM_VALUE,pulse/10); //调整PWM输出占空比，然后上传到平台
}