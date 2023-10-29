#include "LCD.h"

void delay(uint j)
{
	uchar i=250;
	for(;j>0;j--)
	{
		while(--i);
		i=249;
		while(--i);
		i=250;
	}
}

//void delay1()	  //һ���������ڵ���ʱ
//{
//	uint i=0;
//	for(i;i<1;i++)
//	;
//}
//
//void delay100()	  //һ���������ڵ���ʱ
//{
//	uint i=0;
//	for(i;i<100;i++)
//	   for(i;i<100;i++)
//	;
//}

void check_busy(void)
{
	uchar dt;
	do
	{
		dt=0xff;
		E=0;
		RS=0;
		RW=1;
		E=1;
		dt=out;
	}while(dt&0x80);
	E=0;
}

void write_command(uchar com)//д�����
{
	check_busy();
	E=0;
	RS=0;
	RW=0;
	out=com;
	E=1;
	_nop_();
//	delay1();  //�����,��ʱ�ܶ�
	E=0;
	delay(1);
}

void write_data(uchar dat)	 //д��ʾ���ݺ���
{
	check_busy();
	E=0;
	RS=1;
	RW=0;
	out=dat;
	E=1;
	_nop_();
	E=0;
	delay(1);
}

void lcd_initial(void) //��ʼ������
{
	write_command(0x38);//8λ������ʾ��5*7����
	write_command(0x0c);//����ʾ���޹��
	write_command(0x07);//������ʾģʽ:ָ���һ S��Ч
	write_command(0x01);//����
	delay(1);
}

void string(uchar ad,uchar *s) //�����ʾ�ַ����ĺ���
{
	write_command(ad);
	while(*s>0)
	{
		write_data(*s++);
		delay(100);
	}
}