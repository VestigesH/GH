//题目：将一个数组逆序输出 
#include <stdio.h>
int main()
{
	int a[100],n,i,t;
	printf("请输入该数组元素个数:");
	scanf("%d",&n);
	printf("请输入这个数组:");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n/2;i++)
	{
		t=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=t;
	}
	printf("逆序的数组为：");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0; 
}
