//题目：从键盘输入一个字符串，将小写字母全部转换成大写字母，然后输出到一个磁盘文件"test"中保存。
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

