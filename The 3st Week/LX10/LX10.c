#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define unit unsigned int
uchar code dis_code[]={0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0xc0};
void delay()
{
	uchar i,j;
	for(i=0;i<255;i++)
		for(j=0;j<255;j++);
}
void main()
{
	uchar i,j=0x7f;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			j=_crol_(j,1);
			P0=dis_code[i];
			P2=j;
			delay();
		}
	}
}