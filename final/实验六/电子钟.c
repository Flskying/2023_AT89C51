#include<reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define out P0
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;
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
   }
   while(dt&0x80);
   E=0;
}
void write_command(uchar com)
{
   check_busy();
   E=0;
   RS=0;
   RW=0;
   out=com;
   E=1;
   _nop_();
   E=0;
   delay(1);
}
void write_data(uchar dat)
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
void lcd_initial(void)
{
   write_command(0x38);
   _nop_();
   write_command(0x0c);
	 _nop_();
   write_command(0x04);
	 _nop_();
   write_command(0x01);
   delay(1);
}
void string(uchar ad,uchar *s)
{
   
   while(*s!='\0')
   {   
		 write_command(ad);
     write_data(*s++);
	   ad++;
   }
}
uint cishu;
uchar miao;
uchar fen;
uchar shi;
sbit K1=P3^2;
sbit K2=P1^0;
sbit K3=P1^1;
sbit K4=P1^2;
uchar miao=0,fen=0,shi=0;
uchar code tab[]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
void delay10ms()   //软件消抖延时
{
   uchar i,j;
   for(i=0;i<200;i++)
   for(j=0;j<200;j++);
}
void clock_init()//时钟初始化
{
  string(0x81,"BeiJing shijian");  
  string(0xC4,"00:00:00");       
}
void write_sfm(uchar add,uchar date)
{
  uchar ge,shi;
	shi=tab[date/10];
	ge=tab[date%10];
  write_command(add);
	write_data(shi);
  write_command(add+0x01);
	write_data(ge);
}
void clock_write(uint s,uint m,uint h)//设置时、分、秒
{
  write_sfm(0xc4,h);
  write_sfm(0xc7,m);
  write_sfm(0xca,s);	
}
void main()
{
  lcd_initial(); 
	clock_init();
	TMOD=0X01;
	EA=1;
	PX0=1;
	PT0=0;
	ET0=1;
	EX0=1;
	IT0=1;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TR0=1;
	cishu=0;
	miao=0;
	fen=0;
	shi=0;
  while(1)
	{
	clock_write(miao,fen,shi);
	}
}
void T0_int(void) interrupt 1
{
  cishu++;
	if(cishu==20)
	{
	  cishu=0;
		miao++;
	}
	if(miao==60)
	{
		miao=0;
	  fen++;
	}
	if(fen==60)
	{
	  fen=0;
		shi++;
	}
	if(shi==24)
	{
	  shi=0;
	}
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;	
}
void xuishi(void) interrupt 0
{
  do
	{
		EA=0;
	  if(K2==0)
		{
		  delay10ms();
			if(K2==0)
			{
			  shi++;
        clock_write(miao,fen,shi);
			}
		}
		if(K3==0)
		{
		  delay10ms();
			if(K3==0)
			{
			  fen++;
        clock_write(miao,fen,shi);
			}
		}
	}
	while(K4!=0);
	EA=1;
}