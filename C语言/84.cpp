//��Ŀ���Ӽ�������һ���ַ�������Сд��ĸȫ��ת���ɴ�д��ĸ��Ȼ�������һ�������ļ�"test"�б��档
#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int i,len;
	FILE *fp;
	printf("please input a str:");
	scanf("%s",&str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]>='a'&&str[i]<='z') str[i]-=32;
	}
	fp=fopen("test.txt","w");
	fputs(str,fp);
	fclose(fp);
}

