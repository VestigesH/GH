//1.	题目：有四个数字：1、2、3、4，能组成多少个互不相同且无重复数字的三位数？各是多少？ 
#include <stdio.h>
int main(void)
{
	int i,j,k;
	int counter=0;
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
		{
			for(k=1;k<5;k++)
			{
				if (i!=j && j!=k && k!=i)
				{
					counter+=1;
					printf("%d,%d,%d\n",i,j,k);
				}
				
			} 
		}
		
	}
		printf("%d个三位数",counter);
}
