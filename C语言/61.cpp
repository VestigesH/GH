//题目：输入3个数a,b,c，按大小顺序输出。
#include <stdio.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
int main()
{
	int a,b,c;
	printf("请输入a,b,c:");
	scanf("%d,%d,%d",&a,&b,&c);
	printf("三个数从大到小的顺序为:%d %d %d",max(max(a,b),c),min(max(a,b),c),min(min(a,b),c));
}
