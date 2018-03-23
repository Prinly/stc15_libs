#include "DHT22.h"
#include "config.h"
#include "delay.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
//************dht22
unsigned char Sensor_Dat_DHT22[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char Sensor_Check;       //У���
unsigned char Sensor_AnswerFlag;  //�յ���ʼ��־λ
unsigned char Sensor_ErrorFlag;   //��ȡ�����������־
unsigned int Sys_CNT;
unsigned int Tmp;
unsigned char Read_SensorData(void)  //��һλ����
{
    unsigned char i, cnt;
    unsigned char buffer, tmp;
    buffer = 0;
    for (i = 0; i < 8; i++) {
        cnt = 0;
        while (!Sensor_SDA)  //����ϴε͵�ƽ�Ƿ����
        {
            if (++cnt >= 300) {
                break;
            }
        }
        //��ʱMin=26us Max50us ��������"0" �ĸߵ�ƽ
        Delay10us();  //��ʱ30us
        Delay10us();
        Delay10us();
        //�жϴ�������������λ
        tmp = 0;
        if (Sensor_SDA) {
            tmp = 1;
        }
        cnt = 0;
        while (Sensor_SDA)  //�ȴ��ߵ�ƽ ����
        {
            if (++cnt >= 200) {
                break;
            }
        }
        buffer <<= 1;
        buffer |= tmp;
    }
    return buffer;
}

unsigned char Read_Sensor_DHT22(void)  //��ȫ������
{
    unsigned char i;
    //��������(Min=800US Max=20Ms)
    Sensor_SDA = 0;
    Delay_N1ms(2);  //��ʱ2Ms

    //�ͷ����� ��ʱ(Min=30us Max=50us)
    Sensor_SDA = 1;
    Delay10us();  //��ʱ30us
    Delay10us();
    Delay10us();
    //������Ϊ���� �жϴ�������Ӧ�ź�
    Sensor_SDA = 1;

    Sensor_AnswerFlag = 0;  // ��������Ӧ��־

    //�жϴӻ��Ƿ��е͵�ƽ��Ӧ�ź� �粻��Ӧ����������Ӧ����������
    if (Sensor_SDA == 0) {
        Sensor_AnswerFlag = 1;  //�յ���ʼ�ź�
        Sys_CNT = 0;
        //�жϴӻ��Ƿ񷢳� 80us �ĵ͵�ƽ��Ӧ�ź��Ƿ����
        while ((!Sensor_SDA)) {
            if (++Sys_CNT > 300)  //��ֹ������ѭ��
            {
                Sensor_ErrorFlag = 1;
                return 0;
            }
        }
        Sys_CNT = 0;
        //�жϴӻ��Ƿ񷢳� 80us �ĸߵ�ƽ���緢����������ݽ���״̬
        while ((Sensor_SDA)) {
            if (++Sys_CNT > 300)  //��ֹ������ѭ��
            {
                Sensor_ErrorFlag = 1;
                return 0;
            }
        }
        // ���ݽ���	������������40λ����
        // ��5���ֽ� ��λ����  5���ֽڷֱ�Ϊʪ�ȸ�λ ʪ�ȵ�λ �¶ȸ�λ �¶ȵ�λ
        // У��� У���Ϊ��ʪ�ȸ�λ+ʪ�ȵ�λ+�¶ȸ�λ+�¶ȵ�λ
        for (i = 0; i < 5; i++) {
            Sensor_Dat_DHT22[i] = Read_SensorData();
        }
    } else {
        Sensor_AnswerFlag = 0;  // δ�յ���������Ӧ
    }
    return 1;
}