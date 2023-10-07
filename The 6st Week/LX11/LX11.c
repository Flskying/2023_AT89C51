#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
#include <intrins.h>
//����P1�ؿڵ��ĸ����ţ����ƿ���
sbit p10=P1^0;
sbit p11=P1^1;
sbit p12=P1^2;
sbit p13=P1^3;

//����һ���飺��ʾi
uchar xsl1[]={0x1e,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e,0x00};

//���ض����飺��ʾL O V E �Ͱ���
uchar xsl2_1[]={0x0f,0x06,0x06,0x06,0x46,0x66,0x7f,0x00};
uchar xsl2_2[]={0x1c,0x36,0x63,0x63,0x63,0x36,0x1c,0x00};
uchar xsl2_3[]={0x66,0x66,0x66,0x66,0x66,0x3c,0x18,0x00};
uchar xsl2_4[]={0x7f,0x46,0x16,0x1e,0x16,0x46,0x7f,0x00};
uchar xsl2_5[]={0x66,0xff,0xff,0xff,0x7e,0x3c,0x18,0x00};

//����������
uchar xsl3_1[]={0x66,0x66,0x66,0x3c,0x18,0x18,0x3c,0x00};
uchar xsl3_2[]={0x1c,0x36,0x63,0x63,0x63,0x36,0x1c,0x00};
uchar xsl3_3[]={0x66,0x66,0x66,0x66,0x66,0x66,0x7e,0x00};

void delay()
{
//��ʱ
	uint i,j=1;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++) ;
}

void main()
{
uint i;
uchar j,k=1,count;
while(1)
{
	   //����һ������������ʾ��ĸI
		j=0xfe;
		for(i=0;i<8&&p10==0x00;i++)
		{
			P0=j;
			P2=xsl1[i];
			j=_crol_(j,1);
			P2=0x00;
		}
		//����һ����

		//���ض���love�Ͱ��Ĺ�������飬��������kΪ1-5��ѭ��5�Σ�������ʾ
		for(k=1;k<6&&p11==0x00;k++)
		{
			//��ʹÿ�������ͼ����ʾһ��ʱ��
			for(count=0;count<120&&p11==0x00;count++)
			{
			//��������
			for(i=0;i<8;i++)
			{
				P0=j;
				switch(k)
				{
					case 1:P2=xsl2_1[i];
							break;
					case 2:P2=xsl2_2[i];
						   break;
					case 3:	P2=xsl2_3[i];
						  break;
					case 4:P2=xsl2_4[i];
						  break;
					case 5:P2=xsl2_5[i];
					delay();
					delay();
					break;
				}				
				//����λ
				j=_crol_(j,1);
				delay();
				P2=0x00;
				P0=0xff;
			}
			count++;
			//��Ӱ
			P2=0x00; 
			P0=0xff;
			}
			//��Ӱ
			P2=0x00;
			P0=0xff;
			}
		 //���ض�����


		//��������YOU�������飬��������kΪ1-3��ѭ��3�Σ�������ʾ
		for(k=1;k<4&&p12==0x00;k++)
		{
			//��ʹÿ�������ͼ����ʾһ��ʱ��
			for(count=0;count<120&&p12==0x00;count++)
			{
			//��������
			for(i=0;i<8;i++)
			{
				P0=j;
				switch(k)
				{
					case 1:P2=xsl3_1[i];
							break;
					case 2:P2=xsl3_2[i];
						   break;
					case 3:	P2=xsl3_3[i];
						  break;
				}
				//����λ
				j=_crol_(j,1);
				delay();
				P2=0x00;
				P0=0xff;
			}
			count++;
			//��Ӱ
			P2=0x00; 
			P0=0xff;
			}
			//��Ӱ
			P2=0x00;
			P0=0xff;
			}
		 //����������

		 //�����Ŀ�����ʾI LOVE YOU ���� ���Ÿ����飬��������kΪ1-9��ѭ��8�Σ�������ʾ
		for(k=1;k<10&&p13==0x00;k++)
		{
			//��ʹÿ�������ͼ����ʾһ��ʱ��
			for(count=0;count<120&&p13==0x00;count++)
			{
			//��������
			for(i=0;i<8;i++)
			{
				P0=j;
				switch(k)
				{
					case 1:P2=xsl1[i];
						delay();
						break;
					case 2:P2=xsl2_1[i];
						break;
					case 3:	P2=xsl2_2[i];
						break;
					case 4:P2=xsl2_3[i];
						break;
					case 5:P2=xsl2_4[i];
					delay();
						break;
					case 6:P2=xsl3_1[i];
					break;
					case 7:P2=xsl3_2[i];
						break;
					case 8:P2=xsl3_3[i];
					delay();
						break;
					case 9:P2=xsl2_5[i];
					   delay();
					   delay();
						break;
				}
				
				//����λ
				j=_crol_(j,1);
				delay();
				P2=0x00;
				P0=0xff;
			}
			count++;
			//��Ӱ
			P2=0x00; 
			P0=0xff;
			}
			//��Ӱ
			P2=0x00;
			P0=0xff;
			}
		 //�����Ľ���

}
}
