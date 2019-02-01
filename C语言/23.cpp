//题目：一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程找出1000以内的所有完数
#include <stdio.h>
int main()
{
	int n,i,sum;
	printf("1000内的完数有:");
	for(n=1;n<1000;n++)
	{
		sum=0;
		for(i=1;i<n;i++)
		{
			if(n%i==0) sum+=i;
		}
		if(n==sum) printf("%d ",n);
	}	
} 
