//��Ŀ����s=a+aa+aaa+aaaa+aa...a��ֵ������a��һ�����֡�����2+22+222+2222+22222(��ʱ����5�������)������������ɼ��̿��ơ�
#include <stdio.h>
#include <math.h>
int main()
{
	int a,n,i;
	long int s;
	printf("please input a:");
	scanf("%ld",&a);
	printf("please input n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s+=a*pow(10,i);	
	}	
	printf("s=a+aa+aaa+...��ֵΪ%ld",s);
} 
