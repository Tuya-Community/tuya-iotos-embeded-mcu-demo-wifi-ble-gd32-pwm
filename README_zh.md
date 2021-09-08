# Tuya IoTOS Embedded Mcu Demo Wifi Ble GD32_PWM

[English](./README.md) | [中文](./README_zh.md)

## 简介 

本Demo通过涂鸦智能云平台、涂鸦智能APP和IoTOS Embeded MCU SDK实现一款控制PWM占空比。

已实现功能包括：

+ 控制PWM占空比




## 快速上手 

### 编译与烧录
+ 下载Tuya IoTOS嵌入式代码

+ 执行Project.uvprojx文件

+ 点击软件中的编译，并完成下载


### 文件介绍 

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



### Demo入口

入口文件：main.c

重要函数：main()

+ 对mcu的IO,USART,PWM等进行初始化配置，所有事件在while(1)中轮询判断。




### DP点相关

+ 上报dp点处理: mcu_dp_value_update()

| 函数名 | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------ | ------------------------------------------------------------ |
| dpid   | DP的ID号                                                     |
| value  | DP数据                                                       |
| Return | SUCCESS: 成功  ERROR: 失败                                   |

+ mcu获取value型下发dp值: mcu_get_dp_download_value()

| 函数名  | unsigned long mcu_get_dp_download_value(const unsigned char value[],unsigned short len) |
| ------- | ------------------------------------------------------------ |
| value[] | DP数据缓冲区地址                                             |
| len     | DP数据长度                                                   |
| Return  | 当前DP值                                                     |

### I/O 列表 

|      key      |  UASRT0  | UASRT1  |    PWM     |
| :-----------: | :------: | :-----: | :--------: |
|      PB8      | PA9 TXD  | PA2 TXD |    PA7     |
| 控制PWM占空比 | PA10 RXD | PA3 RXD | TIEMR2_CH1 |

## 相关文档

涂鸦Demo中心：https://developer.tuya.com/demo



## 技术支持

您可以通过以下方法获得涂鸦的支持:

- 开发者中心：https://developer.tuya.com
- 帮助中心: https://support.tuya.com/help
- 技术支持工单中心: [https://service.console.tuya.com](https://service.console.tuya.com/) 