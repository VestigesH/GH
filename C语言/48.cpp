//��Ŀ����������ֵ������
#include <stdio.h>
int main()
{
	int x,y,t;
	printf("������x,y:");
	scanf("%d,%d",&x,&y);
	t=x;
	x=y;
	y=t;
	printf("x=%d,y=%d",x,y);
}
