//��Ŀ����дһ��������������һ���޷�������������������Ʊ��ʽ������λ��Ϊ '1' �ĸ�����Ҳ����Ϊ����������
#include <stdio.h>
int main()
{
	long unsigned int n;
	int count=0;
	printf("�������޷�������n:");
	scanf("%ld",&n);
	while (n!=0)
	{
		n&=n-1;
		count+=1;
	}
	printf("1�ĸ���Ϊ%d",count);	
} 
