#include <reg51.h>
#include<LCD.h>
#define uchar unsigned char
#define uint unsigned int
uchar int_time;
uchar second;
uchar minute;
uchar hour;
uchar code date[] = "      TIME      ";
uchar code time[]="  23 : 59 : 55  ";
uchar second = 55,minute = 59 , hour = 23;
void clock_init()
{
	uchar i,j;
	for(i=0;i<16;i++)
	{

		write_data(date[i]);
	}
write_command(0xc0);	  
//	write_com(0x80+0x40);
	for(j=0;j<16;j++)
	{
		write_data(time[j]);
	}
}

void clock_write(uchar s,uchar m,uchar h)
{
	stringfvcdx(0x47,h);
	string(0x4a,m);
	string(0x4d,s);
//	write_sfm(0x47,h);
//	write_sfm(0x4a,m);
//	write_sfm(0x4d,s);
}

void main()
{
	void lcd_initial(void);
	clock_init();
	TMOD=0x01;
	EA=1;
	ET0=1;
	TH0=(65536-46483)/256;
	TL0=(65536-46483)%256;
	TR0=1;
	int_time=0;
	second=55;
	minute=59;
	hour=23;
	while(1)
	{
		clock_write(second,minute,hour);
	}
}

