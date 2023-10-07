#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define unit unsigned int
uchar code dis_code[]={0xa4,0xc0,0xc0,0xa4,0xf9,0xc0,0xa4,0xa4};
void delay()
{
	uchar i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++);
}
void main()
{
	uchar i,j=0x80;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			j=_crol_(j,1);
			P0=dis_code[i];
			P2=j;
			delay();
			P0=0XFF;
		}
	}
}