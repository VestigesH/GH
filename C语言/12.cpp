//��Ŀ������һ��������дһ���������ж����Ƿ��� 3 ���ݴη���
#include <stdio.h>
#include <math.h>
int f(int x)
{
	if(x==1) return 1;
	if(x%3==0) f(x/3);
	else return 0;	
}
int main()
{
	int x;
	printf("������Ҫ�жϵ�������");
	scanf("%d",&x);
	if (f(x)==1) printf("%d��3���ݴη�",x);
	else printf("%d����3���ݴη�",x); 
}


