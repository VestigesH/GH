//��Ŀ����10������������
#include <stdio.h>
sort (int a[10],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i;j++)
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;	
			}
}
int main()
{
	int b[10],i;
	printf("������ʮ������:");
	for(i=0;i<10;i++) scanf("%d",&b[i]);
	sort(b,10);
	printf("������Ϊ:");
	for(i=0;i<10;i++) 
		printf("%d ",b[i]);
}
