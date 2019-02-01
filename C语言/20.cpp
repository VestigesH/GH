//题目：写一个程序，输出从 1 到 n 数字的字符串表示。1. 如果 n 是3的倍数，输出"Fizz"；2. 如果 n 是5的倍数，输出"Buzz"；
//3.如果 n 同时是3和5的倍数，输出 "FizzBuzz"。
#include <stdio.h>
int main()
{
	int n;
	printf("请输入n:");
	scanf("%d",&n);
	if (n%3==0&&n%5!=0)           printf("Fizz");
	else if (n%5==0&&n%3!=0)      printf("Buzz");
	else if (n%3==0&&n%5==0) 	  printf("FizzBuzz");
	else                          printf("%d",n);
}

