//题目：利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
#include <stdio.h>
int main()
{
	int score;
	char grade;
	printf("请输入学生成绩:");
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
	else	printf("输入错误"); 
}
