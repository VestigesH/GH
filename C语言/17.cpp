//��Ŀ�����������������Ƕ������ɴ��⣺ѧϰ�ɼ�>=90�ֵ�ͬѧ��A��ʾ��60-89��֮�����B��ʾ��60�����µ���C��ʾ��
#include <stdio.h>
int main()
{
	int score;
	char grade;
	printf("������ѧ���ɼ�:");
	scanf("%d",&score);
	if (score>=90&&score<=100) 
	{
		grade='A';
		printf("%c",grade);
	}
	else if (score>=60&&score<=89)
	{
		grade='B';
		printf("%c",grade);
	}
	else if(score>0&&score<60)
	{
		grade='C';
		printf("%c",grade);
	}
	else	printf("�������"); 
}
