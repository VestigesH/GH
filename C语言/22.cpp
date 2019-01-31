//题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加由键盘控制。
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
	printf("s=a+aa+aaa+...的值为%ld",s);
} 
