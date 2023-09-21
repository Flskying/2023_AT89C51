#include "reg52.h"
#define uint unsigned int
#define uchar unsigned char


//定义数码管位选信号控制脚
sbit p22=P2^2;
sbit p23=P2^3;
sbit p24=P2^4;

//共阴极数码管显示0-9的断码数据
uchar number[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f};

void delay()
{
uchar i,j;
for(i=0;i<255;i++)
	for(j=0;j<255;j++);	
}


void nixie(uint location,uint num)
{
		 switch(location)//位选
		{
			case 1: p22=1;p23=1;p24=1;break;
			case 2: p22=0;p23=1;p24=1;break;
			case 3: p22=1;p23=0;p24=1;break;
			case 4: p22=0;p23=0;p24=1;break;
			case 5: p22=1;p23=1;p24=0;break;
			case 6: p22=0;p23=1;p24=0;break;
			case 7: p22=1;p23=0;p24=0;break;
			case 8: p22=0;p23=0;p24=0;break;
		}
		P0=number[num];
//P0=0x6f;
}


void main()
{
	nixie(5,7);
	while(1)
	{
		
	}
}