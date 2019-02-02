//题目：有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数 
#include <stdio.h>
f(int a[100],int n,int m)
{
	int b[100],i;
	for(i=0;i<m;i++)	//b中存放最后m个数 
	{
		b[i]=a[n-m+i];
	}
	for(i=n-1;i>=m;i--)	//前面各数后移m个位置
	{
		a[i]=a[i-m];
	}
	for(i=0;i<m;i++)	//最后m个数放回a的前m位置 
	{
		a[i]=b[i]; 
    }
}
int main()
{	
	int a[100],n,m,i;
	printf("请输入整数个数n:");
	scanf("%d",&n);
	printf("请输入这组整数:");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	printf("请输入要移动的位置数m:");
	scanf("%d",&m);
	if(n>m)
	{
		printf("改变后的整数组为:"); 
		f(a,n,m);
		for(i=0;i<n;i++) printf("%d ",a[i]);
	}
	else printf("输入错误"); 
	return 0;
}

