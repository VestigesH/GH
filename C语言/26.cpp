//��Ŀ����ӡ������ͼ�������Σ�
#include <stdio.h>
int main()
{
	int i,j;
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4-i;j++)  printf(" ");
		for (j=1;j<=2*i-1;j++) printf("*");
		printf("\n");
	}
	for (i=5;i<=8;i++)
	{
		for (j=5;j<=i;j++) 	printf(" ");
		for (j=1;j<=2*(8-i)-1;j++) printf("*");
		printf("\n");
	}
} 
