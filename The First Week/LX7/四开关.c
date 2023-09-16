#include <reg51.h>
#define uchar unsigned char
sbit P20 = P2^0	;
sbit P21 = P2^1	;
sbit P22 = P2^2	;
sbit P23 = P2^3	;
uchar seg[]={0xa4,0xc0,0xc0,0xa4,0xf9,0xc0,0xa4,0xa4};

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
		
		 //正向	
		if(P21==0) 
		{
		for(n = 7; n >= 0 && P21 == 0; n--) 
 			{
    			P1 = ~(1 << n); 
    			delay();
			}
		}

		//反向

if (P21==0)
	{
		int m,i=1;
		P1 = 0xff;
		while(i) 
		{
 			for(m = 7; m >=0&&P21==0; m--) 
 			{
    			P1 = ~(1 << m); 
    			delay();
				if(P21==1)
					{
						P1=0xff;
						i=0;
						break;
					}
 			}
		}
	}
	   //
	   
		    if (P22 == 0) 
			{
			  	for(n = 7; n >= 0 && P22 == 0; n--) 
 			{
    			P1 =seg[n]; 
    			delay();
			}
        }



	 }
}

