//��Ŀ��һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣� 
#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,x;
	for (;-100<x<1000;x++)
	{
		i=int(sqrt(double(x+100)));
		j=int(sqrt(double(x+168)));
		if (i*i==x+100 && j*j==x+168) printf("������%d\n",x);	
	}
}
