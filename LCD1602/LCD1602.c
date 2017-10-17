#include "LCD1602.h"
#include "stdio.h"

void LCD1602_busy_test()
{
   	lcd = 0xff;	    	//��æ����
   	lcdrs = 0;
   	lcdrw = 1;
   	lcden = 1;
   	while(lcdbusy);		
   	lcden = 0;			
}
void LCD1602_com(uchar com)  //д����
{ 
  	LCD1602_busy_test();
  	lcd = com;
  	lcdrs = 0;
  	lcdrw = 0;
  	lcden = 1;
  	lcden = 0;
}
void LCD1602_data(uchar date) //д����
{ 
    LCD1602_busy_test();
	lcd = date;
  	lcdrs = 1;
  	lcdrw = 0;
  	lcden = 1;
  	lcden = 0;
}
void LCD1602_init(void)
{
	P4M0=0;
	P4M1=0;
	P2M0=0;
	P2M1=0;
  	LCD1602_com(CMD_set82);	    //* ��ʾģʽ���ã���ʾ2�У�ÿ���ַ�Ϊ5*7������
  	LCD1602_com(CMD_clear);   	//  ��ʾ����
  	LCD1602_com(CMD_back);		//* ����ָ��ָ���1�е�1���ַ�λ��
  	LCD1602_com(CMD_add1);		//  ��ʾ����ƶ����ã����ֲ������������
  	LCD1602_com(CMD_dis_gb3); 	//  ��ʾ����������ã���ʾ������꿪����˸��
}
void print_lcd(char* fmt ,...){
	unsigned char i,num;
	unsigned char xdata lcd_buf[32]={0};
	va_list ap;  
    va_start(ap,fmt); 
	num=vsprintf(lcd_buf,fmt,ap);
	LCD1602_com(CMD_clear);
	LCD1602_com(CMD_back);
	for(i=0;i<num;i++){
		if(i==16)
			LCD1602_com(0x80+0x40);	//����
		if(i<32)
			LCD1602_data(lcd_buf[i]);		
	}
	va_end(ap);
}