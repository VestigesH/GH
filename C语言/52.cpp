//��Ŀ��ȡһ������a���Ҷ˿�ʼ��4-7λ�� 
#include <stdio.h>
int main()
{
	long int a;
	int X[10],Y[4],i,j;
	printf("����������a:");
	scanf("%d",&a);
	for(i=0;a>0;i++)
	{
		X[i]=a%10;
		a/=10;
	}
	for(j=1;j<=4;j++)
	{
		printf("%d",X[i-j-1]);
	}	
}
