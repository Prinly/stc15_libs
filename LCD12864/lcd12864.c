#include "LCD12864.H"
#include "delay.h"
#include "stdio.h"
#include "stdarg.h"
#include <string.h>
/*****************************************************************
          ��ʼ������ init();	  
     ��ʼ��Һ������ʾ���꣬��ʾ�α���˸
*****************************************************************/
void init_LCD12864()			    //12864��ʼ������
{					                    //���г�ʼ��
	write_com_LCD12864(0x30);   //д����ָ�
	delay_ms(50);
	write_com_LCD12864(0x0c);    //on��
	delay_ms(50);
	write_com_LCD12864(0x01);    //����
	delay_ms(50);

}

// ����Һ���Ĵ���ͨ��Э�飬��������

void sendbyte(unsigned char zdata)
{
	unsigned int i;
	for(i=0; i<8; i++)
	{
		if((zdata << i) & 0x80)
		{
			SID = 1;
		}
		else 
		{
			SID = 0;
		}
		SCLK = 0;
		SCLK = 1;//�����ط�������
	}
}

/*****************************************************************
	   д����� write_com();	д��������ʾ�αꡢ��ַ��Һ��
*****************************************************************/
void write_com_LCD12864(unsigned char cmdcode)
{
	CS = 1;
	sendbyte(0xf8);
	sendbyte(cmdcode & 0xf0);
	sendbyte((cmdcode << 4) & 0xf0);
	delay_ms(2);
}


/*****************************************************************
	   д���ݺ��� write_data();	д��ʾ���ݵ�Һ��
*****************************************************************/
void write_data_LCD12864(unsigned char Dispdata)
{	
	CS = 1;
	sendbyte(0xfa);
	sendbyte(Dispdata & 0xf0);
	sendbyte((Dispdata << 4) & 0xf0);
	delay_ms(2);
}

/*****************************************************************
	   ��ʾ����	��ʾҺ����һ������
*****************************************************************/
void disp_line_LCD12864(unsigned char x,unsigned char *dat)		 //
{
	unsigned char add,i;
	switch(x)
	{
		case 1:add=0x80;break;
		case 2:add=0x90;break;
		case 3:add=0x88;break;
		case 4:add=0x98;break;
	}
	write_com_LCD12864(add);
	for(i=0;i<strlen(dat);i++)write_data_LCD12864(dat[i]);
}

/*****************************************************************
	   ��ʾ����	��ʾһ���ַ���s��Һ��   x����x�У�y����y�У��ӵ�X�е�Y�п�ʼд
*****************************************************************/
void disp_string_LCD12864(unsigned char x,unsigned char y,unsigned char *s)		  
{
	unsigned char add;
	switch(x)
	{
		case 1:add=0x80;break;
		case 2:add=0x90;break;
		case 3:add=0x88;break;
		case 4:add=0x98;break;
	}
	write_com_LCD12864(add+y-1);
	while(*s>0) { write_data_LCD12864(*s); s++; }
}
void print_lcd12864(char* fmt ,...){
	unsigned char i,num;
	unsigned char xdata lcd_buf[64]={0};
	va_list ap;  
    va_start(ap,fmt); 
	num=vsprintf(lcd_buf,fmt,ap);
	write_com_LCD12864(0x30);//clear
	for(i=0;i<num;i++){
	switch(i)
	{
		case 16:write_com_LCD12864(0x90);break;
		case 32:write_com_LCD12864(0x88);break;
		case 48:write_com_LCD12864(0x98);break;
		default:break;
	}
		write_data_LCD12864(lcd_buf[i]);		
	}
	va_end(ap);
}