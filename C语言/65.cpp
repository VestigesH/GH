//��Ŀ��дһ����������һ���ַ����ĳ��ȣ���main�����������ַ�����������䳤�ȡ�
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
	printf("�ַ����ĳ���Ϊ:%d",f(s));
} 

