//��Ŀ��������������x,y,z���������������С���������
#include <stdio.h>
int main()
{
	int x,y,z,t;
	printf("\n��������������:");
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
	printf("��С����˳��Ϊ%d %d %d\n",x,y,z);
}
