/*************************************************
File name: MAIN.c
Author:   山东大学电子设计协会
Version:  V0.4
Description: 基本51模块封测
更新日志：
V0.1 2017.10.14 完成sys架构，LCD1602,adc，串口，BUG:串口波特率加倍错误
v0.2 2017.10.14 修复 BUG:串口波特率加倍错误，完善注释
v0.3 2017.10.18 add 6路PWM 控制器
v0.4 2017.10.23 add LCD12864 DHT11 DHT22
v0.5 2017.11.24 fix LCD12864
*************************************************/
#include	"config.h"
#include	"delay.h"
#include	"GPIO.h"
#include	"USART1.h"

/*************	本地常量声明	**************/


/*************	本地变量声明	**************/


/*************	本地函数声明	**************/



/*************  外部函数和变量声明 *****************/



/**********************************************/
void main(void){
	GPIO_INIT();//所有GPIO配置为准双向
	UART_config();//配置串口1,P30_P31,使用定时器2 默认波特率115200,8,1
	EA = 1;			   //开中断
	while(1);	
}



