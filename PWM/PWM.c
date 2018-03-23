#include "PWM.h"
#include "config.h"
/*************************************************
File name: PWM.c
Author:   ɽ����ѧ�������Э�� by lwida
Version:  V0.2
Date:     2017.10.18
Description: stc15 6ͨ��pwmģ��
������־��
*************************************************/
//========================================================================
// ����: PWM_INIT(unsigned int pwm_duty)
// ����: PWM��������ʼ��
// ����: pwm_duty: pwm���ڣ�max 32767
// ����: none.
// �汾: V0.1, 2017-10-18
//========================================================================
void PWM_INIT(unsigned int pwm_duty) {
    P_SW2 |= 0x80;     //ʹ����չSFR
    PWMCFG = 0x00;     // pwm���ó�ʼ��ƽ��������adc
    PWMFDCR &= ~0x20;  //�ر��쳣�ж�
    PWMC = pwm_duty;   //����pwm����
    PWMCKS = 0x0f;     //ѡ������ʱ��Ϊ1/16��ʱ��
    PWM2T1 = 1;
    PWM3T1 = 1;
    PWM4T1 = 1;
    PWM5T1 = 1;
    PWM6T1 = 1;
    PWM7T1 = 1;
    PWM2T2 = 0;
    PWM3T2 = 0;
    PWM4T2 = 0;
    PWM5T2 = 0;
    PWM6T2 = 0;
    PWM7T2 = 0;
    P_SW2 &= ~0x80;
}
//========================================================================
// ����: void PWM_CHN_ENABLE(unsigned char chn)
// ����: PWMͨ��ʹ��
// ����: chn:pwmͨ��  1-6
// ����: none.
// �汾: V0.1, 2017-10-18
//========================================================================
void PWM_CHN_ENABLE(unsigned char chn) {
    P_SW2 |= 0x80;            //ʹ����չSFR
    PWMCR |= 1 << (chn - 1);  //ʹ�ܵ�chnͨ��
    PWMCR |= 0x80;            //��ʹ��
    P_SW2 &= ~0x80;
    // PWMCR&=~0x80//����ʹ��
}
//========================================================================
// ����: void pwm_port_remap(unsigned char chn, bit enable)
// ����: PWMͨ����ӳ��ʹ��
// ����: enable ʹ��
//		 chn:pwmͨ��  1-6
// ����: none.
// �汾: V0.1, 2017-10-18
//========================================================================
void PWM_port_remap(unsigned char chn, bit enable) {
    switch (chn) {
        case 1:
            PWM2CR = 0x08;
            if (!enable) PWM2CR = 0;
            break;
        case 2:
            PWM3CR = 0x08;
            if (!enable) PWM3CR = 0;
            break;
        case 3:
            PWM4CR = 0x08;
            if (!enable) PWM4CR = 0;
            break;
        case 4:
            PWM5CR = 0x08;
            if (!enable) PWM5CR = 0;
            break;
        case 5:
            PWM6CR = 0x08;
            if (!enable) PWM6CR = 0;
            break;
        case 6:
            PWM7CR = 0x08;
            if (!enable) PWM7CR = 0;
            break;
        default:
            break;
    }
}

//========================================================================
// ����: set_ratio(unsigned int Duty_ration,unsigned char chn)
// ����: PWMռ�ձ�����
// ����: Duty_ration: pwmת��㣬==ռ�ձ�*pwm���� ����Ϊ 0 �� pwm����
//		 chn:pwmͨ��  1-6
// ����: none.
// �汾: V0.1, 2017-10-18
//========================================================================
void PWM_set_ratio(unsigned int Duty_ration, unsigned char chn) {
    switch (chn) {
        case 1:
            P_SW2 |= 0x80;  //ʹ����չSFR
            PWM2T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 2:
            P_SW2 |= 0x80;  //ʹ����չSFR
            PWM3T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 3:
            P_SW2 |= 0x80;  //ʹ����չSFR
            PWM4T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 4:
            P_SW2 |= 0x80;  //ʹ����չSFR
            PWM5T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 5:
            P_SW2 |= 0x80;  //ʹ����չSFR
            PWM6T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 6:
            P_SW2 |= 0x80;  //ʹ����չSFR
            PWM7T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        default:
            break;
    }
}