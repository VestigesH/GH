//题目：利用递归方法求5! 
#include <stdio.h>
long int f(int n)
{
	if(n==1) return 1;
	else return (n*f(n-1));
}
int main()
{
	int n;
	long int s;
	printf("please input n:");
	scanf("%d",&n);
	s=f(n);
	printf("%d!=%ld",n,s);
}
