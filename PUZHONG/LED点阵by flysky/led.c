
#include "reg51.h"
#include <intrins.h>

typedef unsigned int uint;	//对系统默认数据类型进行重定义
typedef unsigned char uchar;

//定义74HC595控制管脚
sbit SRCLK=P3^6;	//移位寄存器时钟输入
sbit RCLK=P3^5;		//存储寄存器时钟输入
sbit SER=P3^4; 		//串行数据输入

//定义P3关口的四个引脚，控制开关
sbit p30=P3^1;
sbit p31=P3^0;
sbit p32=P3^2;
sbit p33=P3^3;

//行数组
uchar row[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

//开关一数组：显示i
uchar xsl1[]={0x87,0xcf,0xcf,0xcf,0xcf,0xcf,0x87,0xff};

//开关二数组：显示L O V E 和爱心
uchar xsl2_1[]={0x0f,0x9f,0x9f,0x9f,0x9d,0x99,0x01,0xff};
uchar xsl2_2[]={0xc7,0x93,0x39,0x39,0x39,0x93,0xc7,0xff};
uchar xsl2_3[]={0x99,0x99,0x99,0x99,0x99,0xc3,0xe7,0xff};
uchar xsl2_4[]={0x01,0x9d,0x97,0x87,0x97,0x9d,0x01,0xff};
uchar xsl2_5[]={0x99,0x00,0x00,0x00,0x81,0xc3,0xe7,0xff};

//开关三数组
uchar xsl3_1[]={0x99,0x99,0x99,0xc3,0xe7,0xe7,0xc3,0xff};
uchar xsl3_2[]={0xc7,0x93,0x39,0x39,0x39,0x93,0xc7,0xff};
uchar xsl3_3[]={0x99,0x99,0x99,0x99,0x99,0x99,0x81,0xff};


//#define LEDDZ_COL_PORT	P0	//点阵列控制端口


/*******************************************************************************
* 函 数 名       : delay_10us
* 函数功能		 : 延时函数，ten_us=1时，大约延时10us
* 输    入       : ten_us
* 输    出    	 : 无
*******************************************************************************/
void delay_10us(uint ten_us)
{
	while(ten_us--);	
}

/*******************************************************************************
* 函 数 名         : hc595_write_data(u8 dat)
* 函数功能		   : 向74HC595写入一个字节的数据
* 输    入         : dat：数据
* 输    出         : 无
*******************************************************************************/
void hc595_write_data(uchar dat)
{
	uchar i=0;
	
	for(i=0;i<8;i++)//循环8次即可将一个字节写入寄存器中
	{
		SER=dat>>7;//优先传输一个字节中的高位
		dat<<=1;//将低位移动到高位
		SRCLK=0;
		delay_10us(1);
		SRCLK=1;
		delay_10us(1);//移位寄存器时钟上升沿将端口数据送入寄存器中	
	}
	RCLK=1;
	delay_10us(1);
	RCLK=0;//存储寄存器时钟上升沿将前面写入到寄存器的数据输出	
}


/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
uint i;
uchar j,k=1,count;
while(1)
{	   P0=0xff;
	   //开关一，控制数组显示字母I
		j=0x80;
		for(i=0;i<8&&p30==0x00;i++)
		{  			
			hc595_write_data(row[i]);
			P0=xsl1[i];
			delay_10us(100);
			P0=0xff;
		}
		//开关一结束

		//开关二有love和爱心共五个数组，所以设置k为1-5，循环5次，轮流显示
		for(k=1;k<6&&p31==0x00;k++)
		{
			//欲使每个数组的图案显示一段时间
			for(count=0;count<120&&p31==0x00;count++)
			{
		//行数控制
			for(i=0;i<8;i++)
			{
				hc595_write_data(row[i]);
				switch(k)
				{
					case 1:P0=xsl2_1[i];
							break;
					case 2:P0=xsl2_2[i];
						   break;
					case 3:	P0=xsl2_3[i];
						  break;
					case 4:P0=xsl2_4[i];
						  break;
					case 5:P0=xsl2_5[i];
						break;
				}
			delay_10us(100);
			P0=0xff;
			}
			count++;
			}
			}
		 //开关二结束


		//开关三有YOU三个数组，所以设置k为1-3，循环3次，轮流显示
		for(k=1;k<4&&p32==0x00;k++)
		{
			//欲使每个数组的图案显示一段时间
			for(count=0;count<120&&p32==0x00;count++)
			{
			//行数控制
			for(i=0;i<8;i++)
			{
				hc595_write_data(row[i]);
				switch(k)
				{
					case 1:P0=xsl3_1[i];
							break;
					case 2:P0=xsl3_2[i];
						   break;
					case 3:P0=xsl3_3[i];
						  break;
				}
			delay_10us(100);
			P0=0xff;
			}
			count++;
			}
			}
		 //开关三结束

		 //开关四控制显示I LOVE YOU 爱心 共九个数组，所以设置k为1-9，循环8次，轮流显示
		for(k=1;k<10&&p33==0x00;k++)
		{
			//欲使每个数组的图案显示一段时间
			for(count=0;count<120&&p33==0x00;count++)
			{
			//行数控制
			for(i=0;i<8;i++)
			{
				hc595_write_data(row[i]);
				switch(k)
				{
					case 1:P0=xsl1[i];
						break;
					case 2:P0=xsl2_1[i];
						break;
					case 3:	P0=xsl2_2[i];
						break;
					case 4:P0=xsl2_3[i];
						break;
					case 5:P0=xsl2_4[i];
					break;
					case 6:P0=xsl3_1[i];
					break;
					case 7:P0=xsl3_2[i];
						break;
					case 8:P0=xsl3_3[i];
						break;
					case 9:P0=xsl2_5[i];
						break;
				}
				delay_10us(100);
			
			}
			count++;
			}
			}
		 //开关四结束
 P0=0xff;
}
	
	
	
	
			
}