//题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char s[100];
	int i,n,a=0,b=0,c=0,d=0;
	printf("please input a str:");
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(isalpha(s[i])) a+=1;
		else if(isspace(s[i])) b+=1;
		else if(isdigit(s[i])) c+=1;
		else d+=1;		
		
	}
	printf("英文字母的个数为：%d\n",a);
	printf("空格个数为：%d\n",b);
	printf("数字个数为：%d\n",c);
	printf("其他字符个数为：%d\n",d);	
}
