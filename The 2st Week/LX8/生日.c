#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
uchar seg[]={0xa4,0xc0,0xc0,0xa4,0xf9,0xc0,0xa4,0xa4};
void delay()
{
	uint i,j;
	for(i=0;i<255;i++)
	for(j=0;j<255;j++);
	}
void main ()
{
	uchar n;
	while (1)
	{
		for(n=0;n<8;n++)
		{
			P1=seg[n];
			delay();
			P1=0xff;
			delay();
			if (n==10)
			n=0;
		}
	}
}