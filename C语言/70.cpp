//��Ŀ����дһ������������nΪż��ʱ�����ú�����1/2+1/4+...+1/n,������nΪ����ʱ�����ú���1/1+1/3+...+1/n
#include <stdio.h>
double Sum(int n)
{
	int i;
	double s=0;
	if(n%2==0)
	{
		for(i=0;i<=n;i=i+2) s+=1.0/i;
	}
	if(n%2==1)
	{
		for(i=1;i<=n;i=i+2) s+=1.0/i;	
	}
	return s; 
}
int main()
{
	int n;
	printf("please input n:");
	scanf("%d",n);
	printf("sum=%f",Sum(n));
}
