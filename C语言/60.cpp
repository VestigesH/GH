//��Ŀ������һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
#include <stdio.h>
int main()
{
	long n,i;
	printf("�������������:");
	scanf("%ld",&n);
	while(n)
	{
		i=i*10+n%10;
		n/=10;
	}
	printf("��ת����Ϊ:%ld",i);	
} 
