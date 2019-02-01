//题目：给定一个整数，写一个函数来判断它是否是 3 的幂次方。
#include <stdio.h>
#include <math.h>
int f(int x)
{
	if(x==1) return 1;
	if(x%3==0) f(x/3);
	else return 0;	
}
int main()
{
	int x;
	printf("请输入要判断的整数：");
	scanf("%d",&x);
	if (f(x)==1) printf("%d是3的幂次方",x);
	else printf("%d不是3的幂次方",x); 
}


