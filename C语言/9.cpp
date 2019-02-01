//题目：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
#include <stdio.h>
int getway(int n)
{
	if(n==1) return 1;
	else if(n==2)  return 2;
	else return getway(n-1)+getway(n-2);
} 
int main()
{
	int n,way;
	printf("请输入楼梯阶数n:");
	scanf("%d",&n);
	way=getway(n);
	printf("有%d种不同的方法",way);
}
