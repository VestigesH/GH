//��Ŀ�����������ڼ��ĵ�һ����ĸ���ж�һ�������ڼ��������һ����ĸһ����������жϵڶ�����ĸ��
#include <stdio.h>
#include <ctype.h>
int main()
{
	char letter;
	printf("�������һ����ĸ:");
	scanf("%c",&letter);
	letter=toupper(letter);
	switch(letter)
	{
		case 'M':printf("����һ\n");break;
		case 'W':printf("������\n");break;
		case 'F':printf("������\n");break;
		case 'S':printf("������ڶ�����ĸ:");
				if ((letter=getchar())=='u') printf("������\n");
				else if ((letter=getchar())=='a') printf("������\n");
				else printf("�������");break;
		case 'T':printf("������ڶ�����ĸ:");
				if ((letter=getchar())=='u') printf("���ڶ�\n");
				else if ((letter=getchar())=='h') printf("������\n");
				else printf("�������");break;
		default:printf("�������\n"); 
	}
}
