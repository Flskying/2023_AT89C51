#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
sbit p30=P3^0;
uchar seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay()
{
	uint i,j;
	for(i=0;i<255;i++)
		for(j=0;j<200;j++)
			;
}
void main()
{
uint i,j;
//	P1=0xc0;
//	P2=0xc0;
	while (p30==0)
	{
	for(i=0;i<6&p30==0;i++)
	{
		P1=seg[i];
		for(j=0;j<10&p30==0;j++)
		{
		 P2 = seg[j];
		 delay();
		} 
	}
	
	}
}