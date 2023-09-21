/**************************************************************************************
深圳市普中科技有限公司（PRECHIN 普中）
技术支持：www.prechin.net
PRECHIN
 普中

实验名称：蜂鸣器实验
接线说明：	
实验现象：下载程序后蜂鸣器发出声音，一段时间后关闭
注意事项：																				  
***************************************************************************************/
#include "reg52.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;

sbit BEEP=P2^5;	//将P2.5管脚定义为BEEP

/*******************************************************************************
* 函 数 名       : delay_10us
* 函数功能		 : 延时函数，ten_us=1时，大约延时10us
* 输    入       : ten_us
* 输    出    	 : 无
*******************************************************************************/
void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	u16 i=2000;

	while(1)
	{
	   	while(i--)//循环2000次
		{
			BEEP=!BEEP;//产生一定频率的脉冲信号
			delay_10us(100);
		}
		i=0;//清零
		BEEP=0;//关闭蜂鸣器
	}		
}