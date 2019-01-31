//题目：编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）
#include <stdio.h>
int main()
{
	long unsigned int n;
	int count=0;
	printf("请输入无符号整数n:");
	scanf("%ld",&n);
	while (n!=0)
	{
		n&=n-1;
		count+=1;
	}
	printf("1的个数为%d",count);	
} 
