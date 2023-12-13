#include<reg51.h>
#include<math.h>
sbit switch1=P0^0;		//定义k1与P0.0连接
sbit switch2=P0^1;		//定义k1与P0.1连接
sbit switch3=P0^2;		//定义k1与P0.2连接
void main()
{
	  EA=1;			//总中断允许
	  TMOD=0x20;	//T1方式2，自动装入
	  TL1=0xfd;		//波特率9600
	  TH1=0xfd;
	  TR1=1;		//启动T1
	  ES=1;			//允许串行口中断
	  SBUF=0xff;	//串行口发送0xff
	  while(T1==0); //判断是否发送完毕
	  T1=0;			//发送完毕，T1清0
	  while(1)
	  {
	  	
	  }
}


            