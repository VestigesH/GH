//题目：斐波那契数列。
#include <stdio.h>
int main()
{
	long x=1,y=1;
	while (y<10000)
	{
		printf("%d ",x);
		y=x+y;
		x=y-x;
	}	
}
