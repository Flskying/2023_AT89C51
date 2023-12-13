//乙机
#include<reg51.h>
unsigned char j=10;
char sign=1;
sbit P10=P1^0;
void main(){
	unsigned char increment=0;
	TR0=1;
	EA=1;
	ET0=1;
	TMOD=0x21;
	TH0=0xee;
	TL0=0x00;
	if(sign==1){
		//执行数据接收
		TR1=1;
		TL1=0xfd;
		TH1=0xfd;
		TMOD=0x20;
		SCON=0x50;
		PCON=0x00;
	}
	while(sign==1){
		//接收数据SBUF
		P2=SBUF;
	}
	if(sign==-1){
		//执行数据发送
		TR1=1;
		TL1=0xfd;
		TH1=0xfd;
		SCON=0x40;
		PCON=0x00;
	}
	while(sign==-1){
		//发送数据SBUF
		if(P10==0){
			SBUF=0xf0;
			while(TI==0);TI=0;
		}else{
			SBUF=0x0f;
			while(TI==0);TI=0;
		}
	}
}
void int0() interrupt 1 {
	j--;
	if(j==0){
		TF0=0;
		TH0=0xee;
		TL0=0x00;
		sign=sign*(-1);			
		j=10;					
	}	
}
