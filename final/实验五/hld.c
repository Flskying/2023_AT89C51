#include<reg51.h>
#define uchar unsigned char
uchar sz[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
sbit G1=P1^0;
sbit Y1=P1^1;
sbit R1=P1^2;
sbit G2=P1^4;
sbit Y2=P1^5;
sbit R2=P1^6;
void delay(){
   uchar i,j;
   for(i=0;i<255;i++)
     for(j=0;j<255;j++)  ;
}
void zd(){			   //发出中断及中断被允许
   IT0=1;
   IT1=1;
   EA=1;
   EX0=1;
   EX1=1;
}
void LED_1(){		   //东西绿灯（蓝数码管），南北红灯{红数码管）
   uchar m,n;
   P0=0xff;
   P1=0x41;
   for(m=0;m<3;m++){
	 for(n=0;n<10;n++){	
	   P2=0x01;
	   P0=sz[m];
	   delay();
	   P2=0x02;
	   P0=sz[n];
	   delay();
	   
	   if(m==2&&n>=7){  
	     P1=0x00;
		 delay();
		 P1=0x22;
		 delay();
		 P1=0x00;
	   }   
	 }
	 delay();   
   }
  P0=0xff;  
}
void LED_2(){	   	  //东西红灯（红数码管），南北绿灯{蓝数码管）
 uchar m,n,j;
   P0=0xff;
   P1=0x14;
   for(m=0;m<3;m++){
	 for(n=0;n<10;n++){	
	   P2=0x04;
	   P0=sz[m];
	   delay();
	   P2=0x08;
	   P0=sz[n];
	   delay();
	   
	   if(m==2&&n>=7){  
	     P1=0x00;
		 delay();
		 P1=0x22;
		 delay();
		 P1=0x00;
	   } 
	 }
	 delay();   
   }
  P0=0xff; 
}
void main(){
   zd();
   while(1){
     LED_1();
     LED_2();
   }
}
void int0() interrupt 0{
   uchar i;
   P0=0xff;
   P1=0x00;
   for(i=0;i<60;i++){
     Y1=1;
	 delay();
     Y1=0;
	 delay();
	 Y1=1;
   }
}
void int1() interrupt 2{
   uchar i;
   P0=0xff;
   P1=0x00;
   for(i=0;i<60;i++){
     Y2=1;
	 delay();
     Y2=0;
	 delay();
	 Y2=1;
   }
}