#ifndef		__LCD1602
#define		__LCD1602
#include "config.h"
#include <stdarg.h>
#define lcd P2
#define lcdrs   P44			
#define lcdrw   P42					
#define lcden   P41					
#define lcdbusy P27     //busy test port,same as D7
#define uchar unsigned char
/***************************************************************************/
#define			CMD_clear		0x01             // �����Ļ
#define			CMD_back		0x02             // DDRAM����λ
#define			CMD_dec1		0x04             // �����AC��ָ�룩��1������д
#define			CMD_add1		0x06             // �����AC��ָ�룩��1������д
#define			CMD_dis_gb1		0x0f             // ����ʾ_�����_�������˸
#define			CMD_dis_gb2		0x0e             // ����ʾ_�����_�ع����˸
#define			CMD_dis_gb3		0x0c             // ����ʾ_�ع��_�ع����˸
#define			CMD_OFF_dis		0x08             // ����ʾ_�ع��_�ع����˸
#define			CMD_set82		0x38             // 8λ����_2����ʾ
#define			CMD_set81		0x30             // 8λ����_1����ʾ���ϱ��У�
#define			CMD_set42		0x28             // 4λ����_2����ʾ
#define			CMD_set41		0x20             // 4λ����_1����ʾ���ϱ��У�
#define			lin_1			0x80             // 4λ����_1����ʾ���ϱ��У�
#define			lin_2			0xc0             // 4λ����_1����ʾ���ϱ��У�	
/***************************************************************************/

void LCD1602_busy_test(void);
void LCD1602_com(uchar com);
void LCD1602_data(uchar date);
void LCD1602_init(void);
void print_lcd(char* fmt ,...);
#endif