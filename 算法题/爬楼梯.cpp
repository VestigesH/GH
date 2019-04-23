//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1或 2个台阶.你有多少种不同的方法可以爬到楼顶呢？
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
