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
