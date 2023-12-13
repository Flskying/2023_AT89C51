//甲机
#include<reg51.h>
unsigned char j=10;
char sign=1;
sbit P10=P1^0;
sbit P11=P1^1;
sbit P12=P1^2;
void delay(unsigned char k){
	unsigned char i,j,h;
	for(h=0;h<k;h++){
		for(i=0;i<25;i++){
			for(j=0;j<20;j++);
		}
	}
}
void twoDigitDisplay(unsigned char num,unsigned char time,unsigned char portNumber){
	unsigned char box[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0xf82,0xf8,0x80,0x90};
	unsigned char k;
	if(portNumber==0){
		if(num<0||num>99||time<0){
			for(k=0;k<40;k++){
				P2=0x00;
			}	
		}else{		
			for(k=0;k<time;k++){
				unsigned char numR = num%10;
				unsigned char numL = num/10;
				P2=0x11;
				P0=box[numL];
				delay(12);
				P2=0x22;
				P0=box[numR];
				delay(12);
			}
		}
	}	
}
void main(){
	unsigned char sum=0;
	TR0=1;
	EA=1;
	ET0=1;
	TMOD=0x21;
	TH0=0xee;
	TL0=0x00;
	
	while(1){
		if(sign==1){
			//执行数据发送
			TR1=1;
			TMOD=0x20;
			TL1=0xfd;
			TH1=0xfd;
			SCON=0x40;
			PCON=0x00;
		}
		while(sign==1){
			//发送数据SBUF
			if(P10==0){SBUF=0xfe;while(TI==0);TI=0;continue;}				
			if(P11==0){SBUF=0xfd;while(TI==0);TI=0;continue;}				
			if(P12==0){SBUF=0xfc;while(TI==0);TI=0;continue;}				
			SBUF=0xff;
		}
		if(sign==-1){
			//执行数据接收
			TR1=1;
			TL1=0xfd;
			TH1=0xfd;
			SCON=0x50;
			PCON=0x00;
		}
		while(sign==-1){
			//接收数据SBUF
			if(SBUF==0xf0){
				sum++;
				twoDigitDisplay(sum,5,0);
			}
			if(SBUF==0x0f){
				twoDigitDisplay(sum,5,0);
			}
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
