#include "DHT11.h"
#include "config.h"
#include "delay.h"

// unsigned char Sensor_Data_DHT11[5]={0x00,0x00,0x00,0x00,0x00};
/*
uchar dht_t1=0,dht_t2=0; //����Ϊ�¶��������ֺ��¶�С������
uchar dht_d1=0,dht_d2=0; //����Ϊʪ���������ֺ�ʪ��С������
uchar dht_chk=0; //��У�飬��ѡ���Ƿ�ʹ�ã�������������ֲ�
*/
uchar dht_num = 0;  //����while ѭ���м�������ʱ������ѭ��

uchar dht_readat()  //����һ��8 λ���ݣ��ȸ�λ���λ
{
    uchar i = 0, dat = 0;
    for (i = 0; i < 8; i++) {
        dht_num = 2;
        while ((dht_dat == 0) && (dht_num++))
            ;
        Delay10us();
        Delay10us();
        Delay10us();
        Delay10us();
        dat = dat << 1;
        if (dht_dat == 1) {
            dht_num = 2;
            dat = dat | 0x01;
            while ((dht_dat == 1) && (dht_num++))
                ;
        }
    }
    return dat;
}
void getdat_DHT11()  //��DHT11 һ����ʼ�źţ�Ȼ���ȡһ�����ݣ������8 λ�ֽ�
{
    uchar i = 0;
    dht_dat = 0;
    delay_ms(40);
    dht_dat = 1;  //��Ƭ������ʼ�����ź�
    Delay10us();
    Delay10us();
    Delay10us();
    Delay10us();
    dht_dat = 1;  //������ʱ���ȴ�DHT11 ������Ӧ����ӦΪ�͵�ƽ��
    if (dht_dat == 0)  //����Ӧ�Ž������ݣ�����������
    {
        dht_num = 2;
        while ((dht_dat == 0) && (dht_num++))
            ;
        dht_num = 2;
        while ((dht_dat == 1) && (dht_num++))
            ;
        Sensor_Data_DHT11[0] = dht_readat();
        Sensor_Data_DHT11[1] = dht_readat();
        Sensor_Data_DHT11[2] = dht_readat();
        Sensor_Data_DHT11[3] = dht_readat();
        Sensor_Data_DHT11[4] = dht_readat();  //һ�ζ����������
    }
    dht_dat = 1;    //�ͷ�����
    delay_ms(100);  //������ʱ
}
void init_DHT11()  // DHT11 �ĳ�ʼ��������������д����ʱ�ȼ���֮
{
    delay_ms(1000);  // DHT11 �ϵ�ǰ׼��ʱ�䣬���1s
    dht_dat = 1;     //����׼��
}