//题目：计算2的20次方。不允许用**和pow()
#include <stdio.h>
int main()
{
	int n;
	long int s=1;
	for(n=1;n<=20;n++) s=2*s;
	printf("2的20次方为:%ld",s);
}
