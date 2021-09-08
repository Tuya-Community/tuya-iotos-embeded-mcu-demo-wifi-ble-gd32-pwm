# Tuya IoTOS Embedded Mcu Demo Wifi Ble GD32_PWM

[English](./README.md) | [中文](./README_zh.md)

## Introduction  

This Demo uses the Tuya smart cloud platform, Tuya smart APP,  and IoTOS Embedded MCU SDK to realize a control PWM duty cycle.

The implemented features include:

+ control PWM duty cycle


## Quick start  

### Compile & Burn
+ Download Tuya IoTOS Embeded Code
+ Execute the Project.uvprojx file
+ Click Compile in the software and complete the download


### File introduction 

```
├── Application
│   ├── main.c
│   ├── gd32e23x_it.c
│   ├── systick.c
│   ├── gd32e23x_it.h
│   ├── systick.h
│   ├── gd32e23x_libopt.h
├── GD32E23x_Firmware_Library
│   ├── CMSIS
        ├── Include
           │   ├──gd32e23x.h
           │   ├──system_gd32e23x.h
        ├── Source
           │   ├──startup_gd32e23x.s
           │   ├──system_gd32e23x.h        
│   ├── GD32E23x_standard_peripheral
        ├── Include
        ├── Source
├──User
│   ├── delay.c
│   ├── delay.h
│   ├── led.c
│   ├── led.h
│   ├── key.c
│   ├── key.h
│   ├── pwm.c
│   ├── pwm.h
│   ├── usart.c
│   ├── usart.h
└── MCU_SDK
    ├── mcu_api.c
    ├── mcu_api.h
    ├── protocol.c
    ├── protocol.h
    ├── system.c
    ├── system.h
    └── wifi.h
```



### Demo entry

Entry file：main.c

Important functions：main()

+ Initialize and configure MCU IO,USART,PWM,etc. All events are polled and judged in while(1)。




### DataPoint related

+ DP point processing: mcu_dp_value_update()

| function name | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------------- | ------------------------------------------------------------ |
| dpid          | DP ID number                                                 |
| value         | DP data                                                      |
| Return        | SUCCESS: Success ERROR: Failure                              |

+ MCU gets the dp value of the value type: mcu_get_dp_download_value()

| function name | unsigned long mcu_get_dp_download_value(const unsigned char value[],unsigned short len) |
| ------------- | ------------------------------------------------------------ |
| value[]       | DP data buffer address                                       |
| len           | DP data length                                               |
| Return        | The current values of dp                                     |

### I/O List  

|          key           |  UASRT0  | UASRT1  |    PWM     |
| :--------------------: | :------: | :-----: | :--------: |
|          PB8           | PA9 TXD  | PA2 TXD |    PA7     |
| Control PWM duty cycle | PA10 RXD | PA3 RXD | TIEMR2_CH1 |



## Related Documents

 Tuya Demo Center: https://developer.tuya.com/demo



## Technical Support

  You can get support for Tuya by using the following methods:

- Developer Center: https://developer.tuya.com
- Help Center: https://support.tuya.com/help
- Technical Support Work Order Center: [https://service.console.tuya.com](https://service.console.tuya.com/) 

