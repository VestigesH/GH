//��Ŀ����һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮�͡� 
#include <stdio.h>
int main()
{
	double sum=0;
	float m=2.0,n=1.0,t;
	int i;
	for(i=1;i<=20;i++)
	{
		sum+=m/n;
		t=m;
		m=m+n;
		n=t; 
	}
	printf("������е�ǰ20��֮��Ϊ%lf",sum);	
}
