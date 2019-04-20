#include <stdio.h>
int getWay(int n)
{
	int way = 0;
	return ((n == 1 || n == 2) ? n : getWay(n - 1) + getWay( n - 2));
}
int main()
{
	int n;
	printf("请输入台阶数n：");
	scanf("%d", &n);
	printf("共有%d种方法爬楼梯！" ,getWay(n));
}
