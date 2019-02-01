//题目：输入三个整数x,y,z，请把这三个数由小到大输出。
#include <stdio.h>
int main()
{
	int x,y,z,t;
	printf("\n请输入三个整数:");
	scanf("%d,%d,%d",&x,&y,&z);
	if (x>y)
	{
		t=x;
		x=y;
		y=t;	
	} 
	else if (x>z)
	{
		t=z;
		z=x;
		x=t;
	}
	else if (y>z)
	{
		t=y;
		y=z;
		z=t;
		
	}
	printf("从小到大顺序为%d %d %d\n",x,y,z);
}
