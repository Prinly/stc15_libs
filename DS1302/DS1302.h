#ifndef __DS1302_H_
#define __DS1302_H_

//---����ͷ�ļ�---//
#include"config.h"
#include<intrins.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

//---����ds1302ʹ�õ�IO��---//
#define DSIO P23
#define RST P24
#define SCLK1302 P25

//---����ȫ�ֺ���---//
void Ds1302Write(uchar addr, uchar dat);
uchar Ds1302Read(uchar addr);
void Ds1302Init();
void Ds1302ReadTime();

//---����ȫ�ֱ���--//
extern uchar TIME[7];	//����ȫ�ֱ���

#endif