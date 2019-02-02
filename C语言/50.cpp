//题目：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数 (存在问题） 
#include <stdio.h>
int main()
{
	int a[100],k,n,i,t;
	printf("请输入元素个数n:");
	scanf("%d",&n);
	printf("请输入要移动的位置数k:");
	scanf("%d",&k);
	printf("请输入一个数组:");
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		for(k=1;k<n;k++)
		{
			t=a[i];
			a[i]=a[n-k];
			a[n-k]=t;
			printf("%d",a[i]);
		}
		if(k>n) printf("k值输入错误");
	}	
}
