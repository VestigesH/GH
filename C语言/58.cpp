//��Ŀ����һ�����ַ����в��Ҷ��ַ�����λ��                                            
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[100],s2[100];
	printf("please input s1:");
	scanf("%s",&s1);
	printf("please input s2:");
	scanf("%s",&s2);
	char *p;
	p=strstr(s1,s2);
	printf("%d",p-s1+1);
	return 0;
}

