//题目：如何组合1、2、5这三个数使其和为100.
#include <stdio.h>
int main()
{
	int i,j,k;
	for (i=1;i<=100;i++)
	{
		for (j=1;j<=50;j++)
		{
			for (k=1;k<=20;k++)
			{
				if (i+j*2+k*5==100) printf("%d*1+%d*2+%d*5=100\n",i,j,k);
				else break;
			}
		}
	}		
}
