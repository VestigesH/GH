//题目：写一个函数，求一个字符串的长度，在main函数中输入字符串，并输出其长度。
#include <stdio.h>
int f(char *s)
{
	int l=0;
	for(;*s!='\0';s++) l++;
	return l; 
}
int main()
{
	char s[100]={0};
	printf("please input a str:");
	gets(s);
	printf("字符串的长度为:%d",f(s));
} 

