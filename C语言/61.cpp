//��Ŀ������3����a,b,c������С˳�������
#include <stdio.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
int main()
{
	int a,b,c;
	printf("������a,b,c:");
	scanf("%d,%d,%d",&a,&b,&c);
	printf("�������Ӵ�С��˳��Ϊ:%d %d %d",max(max(a,b),c),min(max(a,b),c),min(min(a,b),c));
}
