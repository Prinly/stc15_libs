#include "key.h"
#include "Exti.h"
#include "config.h"
#include "delay.h"
//������ʼ��
//��������int0��
void key_init() {
    //���濪���ⲿ�ж�
    //	EXTI_InitTypeDef	EXTI_InitStructure;
    ////�ṹ����
    //
    //	EXTI_InitStructure.EXTI_Mode      = EXT_MODE_Fall;
    ////�ж�ģʽ�½��ش��� 	EXTI_InitStructure.EXTI_Polity    = PolityHigh;
    ////�ж����ȼ��� 	EXTI_InitStructure.EXTI_Interrupt = ENABLE;
    ////�ж����� 	Ext_Inilize(EXT_INT0,&EXTI_InitStructure);
    ////��ʼ��INT0
    EXTI_config(EXT_MODE_Fall, PolityHigh, ENABLE, EXT_INT0);
}

/********************* INT0�жϺ��� *************************/
void Ext_INT0(void) interrupt INT0_VECTOR  //���ж�ʱ�Ѿ������־
{
    delay_ms(10);
    if (P32 == 0) {
        //��ʼִ���жϷ��񲿷�
        P20 = ~P20;
    }
}
#define Submit P00
#define key1 P11
#define key2 P13
#define key3 P13

unsigned char datas[3]={0};
void mutiKeyDemo(void){
	while(Submit==1){
		if(key1==0){
			delay_ms(hold_time);
			if(key1==0){
				datas[0]++;
			}
			while(key1==0);
		}
		if(key2==0){
			delay_ms(hold_time);
			if(key2==0){
				datas[1]++;
			}
			while(key2==0);
		}
		if(key3==0){
			delay_ms(hold_time);
			if(key3==0){
				datas[2]++;
			}
			while(key3==0);
		}
	}
}