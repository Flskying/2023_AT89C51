#ifndef LCD_H
#define LCD_H


#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define out P0
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;

void lcd_initial(void);//��ʼ��
void check_busy(void);//���æ��־λ����
void write_command(uchar com);//д�����
void write_data(uchar dat);//д���ݺ���
void string(uchar ad,uchar *s);//��ʾ�ַ�������
void delay(unit);//��ʱ����


#endif