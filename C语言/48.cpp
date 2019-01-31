//题目：两个变量值互换。
#include <stdio.h>
int main()
{
	int x,y,t;
	printf("请输入x,y:");
	scanf("%d,%d",&x,&y);
	t=x;
	x=y;
	y=t;
	printf("x=%d,y=%d",x,y);
}
