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

//void delay1()	  //一个机器周期的延时
//{
//	uint i=0;
//	for(i;i<1;i++)
//	;
//}
//
//void delay100()	  //一个机器周期的延时
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

void write_command(uchar com)//写命令函数
{
	check_busy();
	E=0;
	RS=0;
	RW=0;
	out=com;
	E=1;
	_nop_();
//	delay1();  //空语句,延时很短
	E=0;
	delay(1);
}

void write_data(uchar dat)	 //写显示数据函数
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

void lcd_initial(void) //初始化函数
{
	write_command(0x38);//8位两行显示，5*7点阵
	write_command(0x0c);//开显示、无光标
	write_command(0x07);//设置显示模式:指针减一 S有效
	write_command(0x01);//清屏
	delay(1);
}

void string(uchar ad,uchar *s) //输出显示字符串的函数
{
	write_command(ad);
	while(*s>0)
	{
		write_data(*s++);
		delay(100);
	}
}