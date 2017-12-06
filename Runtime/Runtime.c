/*
USE AS:
	#include "Runtime.h"
	Runtime_init();
	Runtime_start();
		delay_ms(1);
	Runtime_stop();

*/

#include "Runtime.h"
void Runtime_init(){
	TIM_InitTypeDef		TIM_InitStructure;					//�ṹ����
	TIM_InitStructure.TIM_Mode      = TIM_16Bit;	//ָ������ģʽ,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//ָ���ж����ȼ�, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = DISABLE;				//�ж��Ƿ�����,   ENABLE��DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//ָ��ʱ��Դ,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = DISABLE;				//�Ƿ������������, ENABLE��DISABLE
	TIM_InitStructure.TIM_Value     = 0;					//��ֵ,
	TIM_InitStructure.TIM_Run       = DISABLE;				//�Ƿ��ʼ����������ʱ��, ENABLE��DISABLE
	Timer_Inilize(Timer1,&TIM_InitStructure);				//��ʼ��Timer0	  Timer0,Timer1,Timer2
}
//ִ��ʱ�������ʼ    ռ�ö�ʱ��1
void Runtime_start(){
	TL1=0;
	TH1=0;
	TR1=1;	
}
//ִ��ʱ���������
void Runtime_stop(){
	TR1=0;
	printf("Runtime=%fms\r\n",(unsigned int)(TL1+TH1*256)*12000.0/MAIN_Fosc);
	TL1=0;
	TH1=0;
}