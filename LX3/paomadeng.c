#include <reg51.h>
#define uchar unsigned char
void delay()
{
uchar i,j;
for(i=0;i<255;i++)
for(j=0;j<255;j++);
}

void main()
{
int m;
P1 = 1;
while(1) {
 for(m = 0; m < 8; m++) 
 {
    P1 = ~(1 << m); 
    delay();
 }
		}			    
}
 