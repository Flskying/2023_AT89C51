#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar keyval=0;		 //定义一个键值 判断按钮
uchar a[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	   //0-9十个共阳数组
uint k;	  //定义k用于动态刷新两个数码管
void delay10()	  //十毫秒延时
{
	uchar i,j;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
		;
}

void down()	   //判断按下按键的键值
{
	P1=0x0f;
	if(P1!=0x0f)
		{
			delay10();
			switch(P1)	   //判断列
			{
			   case (0x0e) : keyval=0; break;
			   case (0x0d) : keyval=1; break;
			   case (0x0b) : keyval=2; break;
			   case (0x07) : keyval=3; break;
			}
			P1=0xf0;		//根据行判断按键
			switch(P1)
			{
			   case (0xe0) : keyval=keyval;break;
			   case (0xd0) : keyval=keyval+4;break;
			   case (0xb0) : keyval=keyval+8;break;
			   case (0x70) : keyval=keyval+12;break;
			}		
		}
}
void main()
{
	while(1)
	{	
		down();	 //获取按键键值
		if(keyval<10&&keyval>=0)	 //一位数字 只运行一个数码管
		{
			P2=0xfe;
			P0=a[keyval] ;	  
		}
		else 						//两位数字
		{
			for(k=0;k<2;k++)	  //动态刷新两个数码管
			{
				if(k==0)
				{
				P2=0xfd;
				P0=a[keyval/10];
				P0=0xff;
				}
				else 
				{
				P2=0xfe;
				P0=a[keyval%10];
				P0=0xff;
				}
			}
		}
	}
}