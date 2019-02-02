//题目：有两个磁盘文件A和B,各存放一行字母,要求把这两个文件中的信息合并(按字母顺序排列), 输出到一个新文件C中。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE*fa,*fb,*fc;
	int i,j,k;
	char str1[100],str2[100],t;
	if((fa=fopen("A.txt","r"))=NULL)				// 读A文件 
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fgets(str1,99,fa);
	fclose(fa);
	if((fb=fopen("B.txt","r"))=NULL)				//读B文件 
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fgets(str2,99,fb);
	fclose(fb);
	strcat(str1,str2);								//合并信息且排序 
	for(i=strlen(str1)-1;i>1;i--)
	{
		for(j=0;j<i;j++)
		{
			if(str1[j]>str1[j+1])
			{
				t=str1[j];
				str1[j]=str1[j+1];
				str1[j+1]=t;
			}
		}
	}
	if((fc=fopen("C.txt","w"))==NULL)				//新文件C 
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fputs(str1,fc);
	fclose(fc);
}

