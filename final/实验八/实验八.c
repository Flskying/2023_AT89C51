#include "reg51.h"
#include "intrins.h"
#define uchar unsigned char
#define uint unsigned int
#define out P0
sbit smgl=out^4;
sbit smg2=out^5;
sbit DQ=P3^7;
void delay5(uchar);
void init_ds18b20(void);
uchar readbyte(void);
void writebyte(uchar);
uchar retemp(void);

void main(void)
{ 
	uchar i,temp;
	delay5(1000);
	while(1)
	{
		temp=retemp();
		for(i=0;i<10;i++) //连续扫描LED 数码管10次
		{
			out=(temp/10)&0x0f;
			smgl=0;
			smg2=1;
			delay5(1000);
			out=(temp%10)&0x0f;
			smgl=1;
			smg2=0;
			delay5(1000);
		}
	}
} 

void delay5(uchar n) //延时 Sus 函数
{
	do
	{
		_nop_();
		_nop_();
		_nop_();
		n--;
	}
	while(n);
}

void init_ds18b20(void) //DS18B20 初始化函数
{
	uchar x=0;
	DQ=0;
	delay5(120);
	DQ=1;
	delay5(16);
	delay5(80);
}

uchar readbyte(void) //函数功能：读取1字节数据
{
	uchar i=0;
	uchar date=0;
	for(i=8;i>0;i--)
	{
		DQ=0;
		delay5(1);
		DQ=1; //15μs内释放总线
		date>>=1;
		if(DQ)
		date|=0x80;
		delay5(11);
	}
	return(date);
}

void writebyte(uchar dat) //写1字节函数
{
uchar i=0;
for(i=8;i>0;i--)
{
	DQ=0;
	DQ=dat&0x01;
	delay5(12);
	DQ=1;
	dat>>=1;
	delay5(5);
}
}

uchar retemp(void) //读取温度函数
{
	uchar a,b,tt;
	uint t;
	init_ds18b20();
	writebyte(0xcc);
	writebyte(0x44);
	init_ds18b20();
	writebyte(0xcc);
	writebyte(0xbe);
	a=readbyte();
	b=readbyte();
	t=b;
	t<<=8;
	t=t|a;
	tt=t*0.0625;
	return(tt);
}
