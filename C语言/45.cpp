//��Ŀ������ 3 �� 3 �еľ���ʵ�����Ӧλ�õ�������ӣ�������һ���¾���
#include <stdio.h>
int main()
{
	int a[3][3],b[3][3];
	int i,j;
	printf("�������һ��3*3�����Ԫ��:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) scanf("%d",&a[i][j]);
	}
	printf("\n"); 
	printf("������ڶ���3*3�����Ԫ��:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) scanf("%d",&b[i][j]);
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			a[i][j]=a[i][j]+b[i][j];
	}
	printf("\n");
	printf("��Ӻ��µľ���Ϊ:\n"); 
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) printf("%4d",a[i][j]);
	printf("\n");
	}						
}
