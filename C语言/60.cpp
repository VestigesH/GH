//题目：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
#include <stdio.h>
int main()
{
	long n,i;
	printf("请输入这个整数:");
	scanf("%ld",&n);
	while(n)
	{
		i=i*10+n%10;
		n/=10;
	}
	printf("反转后结果为:%ld",i);	
} 
