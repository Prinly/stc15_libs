/*************************************************
File name: MAIN.c
Author:   ɽ����ѧ�������Э��
Description: ����51ģ����

*************************************************/
#include	"config.h"
#include	"delay.h"
#include	"GPIO.h"
#include	"USART1.h"
#include 	"LCD12864.h"
#include 	"DHT11.h"
#include 	"key.h"
#include	"global.h"
void main(void){
	GPIO_INIT();//����GPIO����Ϊ׼˫��
	UART_config();//���ô���1,P30_P31,ʹ�ö�ʱ��2 Ĭ�ϲ�����115200,8,1
	EA = 1;			   //���ж�
	init_LCD12864();
	init_DHT11();
	mutiKeyDemo();
	while(1){
		delay_ms(1000);
		getdat_DHT11();
		print_lcd12864("hum:\n%d\n",(int)Sensor_Data_DHT11[2]);
	}	
}



