//��Ŀ��һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ
#include <stdio.h>
int main()
{
	int g,s,q,w;
	long x;
	printf("\n������һ����λ��%d\n",x);
	scanf("%ld",&x);
	if (x>9999&&x<100000)
	{
		g=x%10;
		s=x%100/10;
		q=x%10000/1000;
		w=x/10000;	
		if(g==w&&s==q)
			printf("%ld�ǻ�����:",x);
		else
			printf("%ld���ǻ�����:",x);
	}
	else
	{
		printf("�������");
	}
}
