//题目：输出 9*9 乘法口诀表
#include <stdio.h>
int main()
{
	int i,j;
	for (i=1;i<=9;i++)
	{
		for (j=1;j<=i;j++)
		{
			printf("%d*%d=%d\t",i,j,i*j);
		}
		printf("\n");	
	}
}
