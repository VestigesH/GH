//��Ŀ�����ֱȽ�
#include <stdio.h>
int main()
{
	int a[10],i,j,k,t;
	printf("��������������");
	for(i=0;i<10;i++)
	scanf("%d",&a[i]); 
	for(i=0;i<10;i++)
	{
		k=i;
		for(j=0;j<i;j++)
		{
			if(a[k]<a[j]) k=j;
			if(k!=i)
			{ 
				t=a[k];  a[k]=a[i];  a[i]=t;
			} 
		}
	}
	printf("������������Ϊ: ");
    for(i=0;i<10;i++) printf("%d ",a[i]);
} 

