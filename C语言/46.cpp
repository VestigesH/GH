//题目：统计 1 到 100 之和。
#include <stdio.h>
int main()
{
	int i=1,sum=0;
	for (;i<=100;i++) sum=sum+i;
	printf("1-100之和为%d",sum);
}
