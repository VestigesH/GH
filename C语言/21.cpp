//��Ŀ������һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
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
	printf("Ӣ����ĸ�ĸ���Ϊ��%d\n",a);
	printf("�ո����Ϊ��%d\n",b);
	printf("���ָ���Ϊ��%d\n",c);
	printf("�����ַ�����Ϊ��%d\n",d);	
}
