#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
#include <intrins.h>
//定义P1关口的四个引脚，控制开关
sbit p10=P1^0;
sbit p11=P1^1;
sbit p12=P1^2;
sbit p13=P1^3;

//开关一数组：显示i
uchar xsl1[]={0x1e,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e,0x00};

//开关二数组：显示L O V E 和爱心
uchar xsl2_1[]={0x0f,0x06,0x06,0x06,0x46,0x66,0x7f,0x00};
uchar xsl2_2[]={0x1c,0x36,0x63,0x63,0x63,0x36,0x1c,0x00};
uchar xsl2_3[]={0x66,0x66,0x66,0x66,0x66,0x3c,0x18,0x00};
uchar xsl2_4[]={0x7f,0x46,0x16,0x1e,0x16,0x46,0x7f,0x00};
uchar xsl2_5[]={0x66,0xff,0xff,0xff,0x7e,0x3c,0x18,0x00};

//开关三数组
uchar xsl3_1[]={0x66,0x66,0x66,0x3c,0x18,0x18,0x3c,0x00};
uchar xsl3_2[]={0x1c,0x36,0x63,0x63,0x63,0x36,0x1c,0x00};
uchar xsl3_3[]={0x66,0x66,0x66,0x66,0x66,0x66,0x7e,0x00};

void delay()
{
//延时
	uint i,j=1;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++) ;
}

void main()
{
uint i;
uchar j,k=1,count;
while(1)
{
	   //开关一，控制数组显示字母I
		j=0xfe;
		for(i=0;i<8&&p10==0x00;i++)
		{
			P0=j;
			P2=xsl1[i];
			j=_crol_(j,1);
			P2=0x00;
		}
		//开关一结束

		//开关二有love和爱心共五个数组，所以设置k为1-5，循环5次，轮流显示
		for(k=1;k<6&&p11==0x00;k++)
		{
			//欲使每个数组的图案显示一段时间
			for(count=0;count<120&&p11==0x00;count++)
			{
			//行数控制
			for(i=0;i<8;i++)
			{
				P0=j;
				switch(k)
				{
					case 1:P2=xsl2_1[i];
							break;
					case 2:P2=xsl2_2[i];
						   break;
					case 3:	P2=xsl2_3[i];
						  break;
					case 4:P2=xsl2_4[i];
						  break;
					case 5:P2=xsl2_5[i];
					delay();
					delay();
					break;
				}				
				//行移位
				j=_crol_(j,1);
				delay();
				P2=0x00;
				P0=0xff;
			}
			count++;
			//清影
			P2=0x00; 
			P0=0xff;
			}
			//清影
			P2=0x00;
			P0=0xff;
			}
		 //开关二结束


		//开关三有YOU三个数组，所以设置k为1-3，循环3次，轮流显示
		for(k=1;k<4&&p12==0x00;k++)
		{
			//欲使每个数组的图案显示一段时间
			for(count=0;count<120&&p12==0x00;count++)
			{
			//行数控制
			for(i=0;i<8;i++)
			{
				P0=j;
				switch(k)
				{
					case 1:P2=xsl3_1[i];
							break;
					case 2:P2=xsl3_2[i];
						   break;
					case 3:	P2=xsl3_3[i];
						  break;
				}
				//行移位
				j=_crol_(j,1);
				delay();
				P2=0x00;
				P0=0xff;
			}
			count++;
			//清影
			P2=0x00; 
			P0=0xff;
			}
			//清影
			P2=0x00;
			P0=0xff;
			}
		 //开关三结束

		 //开关四控制显示I LOVE YOU 爱心 共九个数组，所以设置k为1-9，循环8次，轮流显示
		for(k=1;k<10&&p13==0x00;k++)
		{
			//欲使每个数组的图案显示一段时间
			for(count=0;count<120&&p13==0x00;count++)
			{
			//行数控制
			for(i=0;i<8;i++)
			{
				P0=j;
				switch(k)
				{
					case 1:P2=xsl1[i];
						delay();
						break;
					case 2:P2=xsl2_1[i];
						break;
					case 3:	P2=xsl2_2[i];
						break;
					case 4:P2=xsl2_3[i];
						break;
					case 5:P2=xsl2_4[i];
					delay();
						break;
					case 6:P2=xsl3_1[i];
					break;
					case 7:P2=xsl3_2[i];
						break;
					case 8:P2=xsl3_3[i];
					delay();
						break;
					case 9:P2=xsl2_5[i];
					   delay();
					   delay();
						break;
				}
				
				//行移位
				j=_crol_(j,1);
				delay();
				P2=0x00;
				P0=0xff;
			}
			count++;
			//清影
			P2=0x00; 
			P0=0xff;
			}
			//清影
			P2=0x00;
			P0=0xff;
			}
		 //开关四结束

}
}
