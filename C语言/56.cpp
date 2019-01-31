//题目：计算字符串长度。
#include <stdio.h>
#include <string.h>
int main()
{
	char a[201];
	int n;
	printf("please input a str: ");
	scanf("%s",&a);
	n=strlen(a);
	printf("字符串的长度为%d",n);
}
