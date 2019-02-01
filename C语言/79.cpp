//题目：读取7个数（1-50）的整数值，每读取一个值，程序打印出该值个数的＊。
#include <stdio.h>
int main()
{
	int i,j,n;
	for(i=1;i<=7;i++)
	{   
		printf("please input n:");
		scanf("%d",&n);
		if(1<=n<=50)
		{
			for(j=1;j<=n;j++) printf("*");
			printf("\n");
		}
	}
}
