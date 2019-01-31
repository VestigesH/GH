//题目：求输入数字的平方，如果平方运算后小于 50 则退出。
#include <stdio.h>
int main()
{
	int x,y;
	printf("请输入x:");
	scanf("%d",&x);
	y=x*x;
	if (y>=50)   printf("%d的平方为%d",x,y);
	else         return 0;
}
