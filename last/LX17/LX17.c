#include<reg51.h>
#include<math.h>
sbit switch1=P0^0;		//����k1��P0.0����
sbit switch2=P0^1;		//����k1��P0.1����
sbit switch3=P0^2;		//����k1��P0.2����
void main()
{
	  EA=1;			//���ж�����
	  TMOD=0x20;	//T1��ʽ2���Զ�װ��
	  TL1=0xfd;		//������9600
	  TH1=0xfd;
	  TR1=1;		//����T1
	  ES=1;			//�����п��ж�
	  SBUF=0xff;	//���пڷ���0xff
	  while(T1==0); //�ж��Ƿ������
	  T1=0;			//������ϣ�T1��0
	  while(1)
	  {
	  	
	  }
}


            