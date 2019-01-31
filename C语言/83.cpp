//题目：从键盘输入一些字符，逐个把它们写到磁盘文件上，直到输入一个 # 为止。
#include <stdio.h>
#include <ctype.h>
int main()
{
 	char ch;
 	FILE *fp;
 	printf("请输入一些字符:");
 	if (!(fp=fopen("file.txt","w"))) return 0;
 	do
	{
 		ch=getchar();
 		if(ch== '#') break;
 		fputc(ch,fp);
 	}while(1);
	fclose(fp);
} 
