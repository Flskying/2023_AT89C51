#include <reg51.h>
#include <stdlib.h>
#define uchar unsigned char
sbit P20 = P2^0	;
sbit P21 = P2^1	;
sbit P22 = P2^2	;
sbit P23 = P2^3	;
void delay()
{
uchar i,j;
for(i=0;i<100;i++)
	for(j=0;j<150;j++);
	}

void main ()
{	
	if (P20==0)
	{
		int m,i=1;
		P1 = 0xff;
		while(i) 
		{
 			for(m = 0; m < 8; m++) 
 			{
    			P1 = ~(1 << m); 
    			delay();
				if(P20==1)
					{
						P1=0xff;
						i=0;
						break;
					}
 			}
		}
	}

	if (P21==0)
	{
		int m,i=1;
		P1 = 0xff;
		while(i) 
		{
 			for(m = 7; m >=0; m--) 
 			{
    			P1 = ~(1 << m); 
    			delay();
				if(P21==1)
					{
						P1=0xff;
						i=0;
						break;
					}
 			}
		}
	}

	if (P22==0)
	 {
	  if (P22 == 0) { // 如果P2.2为低电平
            int i = 1;
            while (i) {
               uchar pattern = rand() % 256; // 生成一个随机数
                P1 = pattern; // 设置P1端口的LED灯状态
                delay();
                if (P22 == 1) { // 如果P2.3变成高电平
                    P1 = 0xFF; // 关闭所有LED
                    i = 0;
                }
            }
        } else {
            P1 = 0xFF; // 如果P2.3为高电平，关闭所有LED
        }
	  }



	 //全闪
	
//	if (P22==0)
//	{	int i=1;
//		while(i)
//		{
//			P1=0x00;
//			delay();
//			P1=0xff;
//			delay();
//			if(P22==1)
//			{
//				P1=0xff;
//				i=0;
//				
//			}
//		}
//	}

	if (P23==0)
	{	int i=1;
		while(i)
		{
			P1=0xf0;
			delay();
			P1=0x0f;
			delay();
			if(P23==1)
			{
				P1=0xff;
				i=0;
				
			}
		}
	}
}