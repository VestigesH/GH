//��Ŀ�������������ļ�A��B,�����һ����ĸ,Ҫ����������ļ��е���Ϣ�ϲ�(����ĸ˳������), �����һ�����ļ�C�С�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE*fa,*fb,*fc;
	int i,j,k;
	char str1[100],str2[100],t;
	if((fa=fopen("A.txt","r"))=NULL)				// ��A�ļ� 
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fgets(str1,99,fa);
	fclose(fa);
	if((fb=fopen("B.txt","r"))=NULL)				//��B�ļ� 
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fgets(str2,99,fb);
	fclose(fb);
	strcat(str1,str2);								//�ϲ���Ϣ������ 
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
	if((fc=fopen("C.txt","w"))==NULL)				//���ļ�C 
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fputs(str1,fc);
	fclose(fc);
}

