#include "gd32e23x.h"
#include "pwm.h"
void PWM_Config(void)
{
        timer_oc_parameter_struct timer_ocintpara;
        timer_parameter_struct timer_initpara;
        rcu_periph_clock_enable(PWM_OUT_PORT_CLK);
        rcu_periph_clock_enable(RCU_TIMER2);
        gpio_mode_set(PWM_OUT_PORT, GPIO_MODE_AF,GPIO_PUPD_NONE ,PWM_OUT_PIN);
        gpio_output_options_set(PWM_OUT_PORT,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,PWM_OUT_PIN);//PA7(TIMER2_CH1)
        gpio_af_set(PWM_OUT_PORT,GPIO_AF_1,PWM_OUT_PIN);//配置PA7引脚复用功能为TIEMR2_CH1
        timer_deinit(TIMER2);

        /* TIMER2 configuration */
        timer_initpara.prescaler         = 719;//预分频器值72M/(719+1)=100KHz
        timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;//对齐模式
        timer_initpara.counterdirection  = TIMER_COUNTER_UP;
        timer_initpara.period            = 999;//周期值，此值确定了PWM输出的周期
        timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;//时钟分频值
        timer_initpara.repetitioncounter = 0;//计数器重复值
        timer_init(TIMER2,&timer_initpara);

         /* CH0 configuration in PWM mode */
        timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
        timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
        timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
        timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
        timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
        timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
        timer_channel_output_config(TIMER2,TIMER_CH_1,&timer_ocintpara);

        timer_channel_output_pulse_value_config(TIMER2,TIMER_CH_1,0);
        timer_channel_output_mode_config(TIMER2,TIMER_CH_1,TIMER_OC_MODE_PWM0);
        timer_channel_output_shadow_config(TIMER2,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);

        timer_primary_output_config(TIMER2,ENABLE);
        timer_auto_reload_shadow_enable(TIMER2);
        timer_enable(TIMER2);
}
