
#include "reg51.h"
#include <intrins.h>

typedef unsigned int uint;	//��ϵͳĬ���������ͽ����ض���
typedef unsigned char uchar;

//����74HC595���ƹܽ�
sbit SRCLK=P3^6;	//��λ�Ĵ���ʱ������
sbit RCLK=P3^5;		//�洢�Ĵ���ʱ������
sbit SER=P3^4; 		//������������

//����P3�ؿڵ��ĸ����ţ����ƿ���
sbit p30=P3^1;
sbit p31=P3^0;
sbit p32=P3^2;
sbit p33=P3^3;

//������
uchar row[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

//����һ���飺��ʾi
uchar xsl1[]={0x87,0xcf,0xcf,0xcf,0xcf,0xcf,0x87,0xff};

//���ض����飺��ʾL O V E �Ͱ���
uchar xsl2_1[]={0x0f,0x9f,0x9f,0x9f,0x9d,0x99,0x01,0xff};
uchar xsl2_2[]={0xc7,0x93,0x39,0x39,0x39,0x93,0xc7,0xff};
uchar xsl2_3[]={0x99,0x99,0x99,0x99,0x99,0xc3,0xe7,0xff};
uchar xsl2_4[]={0x01,0x9d,0x97,0x87,0x97,0x9d,0x01,0xff};
uchar xsl2_5[]={0x99,0x00,0x00,0x00,0x81,0xc3,0xe7,0xff};

//����������
uchar xsl3_1[]={0x99,0x99,0x99,0xc3,0xe7,0xe7,0xc3,0xff};
uchar xsl3_2[]={0xc7,0x93,0x39,0x39,0x39,0x93,0xc7,0xff};
uchar xsl3_3[]={0x99,0x99,0x99,0x99,0x99,0x99,0x81,0xff};


//#define LEDDZ_COL_PORT	P0	//�����п��ƶ˿�


/*******************************************************************************
* �� �� ��       : delay_10us
* ��������		 : ��ʱ������ten_us=1ʱ����Լ��ʱ10us
* ��    ��       : ten_us
* ��    ��    	 : ��
*******************************************************************************/
void delay_10us(uint ten_us)
{
	while(ten_us--);	
}

/*******************************************************************************
* �� �� ��         : hc595_write_data(u8 dat)
* ��������		   : ��74HC595д��һ���ֽڵ�����
* ��    ��         : dat������
* ��    ��         : ��
*******************************************************************************/
void hc595_write_data(uchar dat)
{
	uchar i=0;
	
	for(i=0;i<8;i++)//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		SER=dat>>7;//���ȴ���һ���ֽ��еĸ�λ
		dat<<=1;//����λ�ƶ�����λ
		SRCLK=0;
		delay_10us(1);
		SRCLK=1;
		delay_10us(1);//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����	
	}
	RCLK=1;
	delay_10us(1);
	RCLK=0;//�洢�Ĵ���ʱ�������ؽ�ǰ��д�뵽�Ĵ������������	
}


/*******************************************************************************
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void main()
{	
uint i;
uchar j,k=1,count;
while(1)
{	   P0=0xff;
	   //����һ������������ʾ��ĸI
		j=0x80;
		for(i=0;i<8&&p30==0x00;i++)
		{  			
			hc595_write_data(row[i]);
			P0=xsl1[i];
			delay_10us(100);
			P0=0xff;
		}
		//����һ����

		//���ض���love�Ͱ��Ĺ�������飬��������kΪ1-5��ѭ��5�Σ�������ʾ
		for(k=1;k<6&&p31==0x00;k++)
		{
			//��ʹÿ�������ͼ����ʾһ��ʱ��
			for(count=0;count<120&&p31==0x00;count++)
			{
		//��������
			for(i=0;i<8;i++)
			{
				hc595_write_data(row[i]);
				switch(k)
				{
					case 1:P0=xsl2_1[i];
							break;
					case 2:P0=xsl2_2[i];
						   break;
					case 3:	P0=xsl2_3[i];
						  break;
					case 4:P0=xsl2_4[i];
						  break;
					case 5:P0=xsl2_5[i];
						break;
				}
			delay_10us(100);
			P0=0xff;
			}
			count++;
			}
			}
		 //���ض�����


		//��������YOU�������飬��������kΪ1-3��ѭ��3�Σ�������ʾ
		for(k=1;k<4&&p32==0x00;k++)
		{
			//��ʹÿ�������ͼ����ʾһ��ʱ��
			for(count=0;count<120&&p32==0x00;count++)
			{
			//��������
			for(i=0;i<8;i++)
			{
				hc595_write_data(row[i]);
				switch(k)
				{
					case 1:P0=xsl3_1[i];
							break;
					case 2:P0=xsl3_2[i];
						   break;
					case 3:P0=xsl3_3[i];
						  break;
				}
			delay_10us(100);
			P0=0xff;
			}
			count++;
			}
			}
		 //����������

		 //�����Ŀ�����ʾI LOVE YOU ���� ���Ÿ����飬��������kΪ1-9��ѭ��8�Σ�������ʾ
		for(k=1;k<10&&p33==0x00;k++)
		{
			//��ʹÿ�������ͼ����ʾһ��ʱ��
			for(count=0;count<120&&p33==0x00;count++)
			{
			//��������
			for(i=0;i<8;i++)
			{
				hc595_write_data(row[i]);
				switch(k)
				{
					case 1:P0=xsl1[i];
						break;
					case 2:P0=xsl2_1[i];
						break;
					case 3:	P0=xsl2_2[i];
						break;
					case 4:P0=xsl2_3[i];
						break;
					case 5:P0=xsl2_4[i];
					break;
					case 6:P0=xsl3_1[i];
					break;
					case 7:P0=xsl3_2[i];
						break;
					case 8:P0=xsl3_3[i];
						break;
					case 9:P0=xsl2_5[i];
						break;
				}
				delay_10us(100);
			
			}
			count++;
			}
			}
		 //�����Ľ���
 P0=0xff;
}
	
	
	
	
			
}