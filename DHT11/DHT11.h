#ifndef __DHT11_H
#define __DHT11_H

#define dht_dat P07  //���ĸ�I/O ��

extern unsigned char Sensor_Data_DHT11[5];
void getdat_DHT11();
void init_DHT11();

#endif
