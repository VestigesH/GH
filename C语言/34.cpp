//��Ŀ����һ��������5λ����������Ҫ��һ�������Ǽ�λ�������������ӡ����λ���֡�
#include <stdio.h>
int main()
{
	int g,s,b,q,w;
	long x;
	printf("�����벻������λ��������x:");
	scanf("%ld",&x);
	if (x<0||x>100000)
	{
		printf("�������\n");
		return 0; 
	}		
	else if (0<x<=99999)
	{
		w=x/10000;
		q=x/1000%10;
		b=x/100%10;
		s=x/10%10;
		g=x%10;
		if(w!=0)
		{
			printf("��λ��\n");
			printf("�����ӡ:%d%d%d%d%d",g,s,b,q,w);
		}
		else if(w==0&&q!=0)
		{
			printf("��λ��\n");
			printf("�����ӡ:%d%d%d%d",g,s,b,q);
		}
		else if(w==0&&q==0&&b!=0)
		{
			printf("��λ��\n");
			printf("�����ӡ:%d%d%d",g,s,b);
		}
		else if(w==0&&q==0&&b==0&&s!=0)
		{
			printf("��λ��\n");
			printf("�����ӡ:%d%d",g,s);
		}
		else if(w==0&&q==0&&b==0&&s==0&&g!=0)
		{
			printf("һλ��\n");
			printf("�����ӡ:%d",x);
		}
	}
}
