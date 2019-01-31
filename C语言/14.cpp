//题目：判断101-200之间有多少个素数，并输出所有素数。
#include <stdio.h>
int main()
{
	int counter=0;
	int n,i;
	for (n=101;n<200;n++)
	{
		for(i=2;i<n;i++)
		{
			if (n%i==0)
			break;
		}
		if (i>=n)
		{
			counter=counter+1;
			printf("%d ",n);
		}	
	}
		printf("\n共有%d个素数",counter);
}
