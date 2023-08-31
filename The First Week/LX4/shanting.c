#include <reg51.h>
#define uchar unsigned char
void delay()
{
uchar i,j;
for(i=0;i<255;i++)
for(j=0;j<255;j++);
}

void main()
{uchar m;
for(m=0;m<5;m++)
{
	P1=0;
	delay();
	P1=1;
	delay();
}
while(1){
}
}
 