//题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？ 
#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,x;
	for (;-100<x<1000;x++)
	{
		i=int(sqrt(double(x+100)));
		j=int(sqrt(double(x+168)));
		if (i*i==x+100 && j*j==x+168) printf("该数是%d\n",x);	
	}
}
