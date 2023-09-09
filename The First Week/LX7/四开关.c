#include <reg51.h>
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
	uchar  m,n   ;
	while (1)
	{
		

		P1=0xff;
	
		if(P21==0) 
		{
		for(n = 7; n >= 0 && P21 == 0; n--) 
 			{
    			P1 = ~(1 << n); 
    			delay();
			}
		}

		

	   	if(P20==0) 
		{
			for(m=0;m<8&&P20==0;m++)
			{
				P1= ~ ( 1 << m );
				delay();
			}
		}


	 }
}

