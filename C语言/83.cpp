//��Ŀ���Ӽ�������һЩ�ַ������������д�������ļ��ϣ�ֱ������һ�� # Ϊֹ��
#include <stdio.h>
#include <ctype.h>
int main()
{
 	char ch;
 	FILE *fp;
 	printf("������һЩ�ַ�:");
 	if (!(fp=fopen("file.txt","w"))) return 0;
 	do
	{
 		ch=getchar();
 		if(ch== '#') break;
 		fputc(ch,fp);
 	}while(1);
	fclose(fp);
} 
