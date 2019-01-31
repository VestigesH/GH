//题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。
#include <stdio.h>
#include <ctype.h>
int main()
{
	char letter;
	printf("请输入第一个字母:");
	scanf("%c",&letter);
	letter=toupper(letter);
	switch(letter)
	{
		case 'M':printf("星期一\n");break;
		case 'W':printf("星期三\n");break;
		case 'F':printf("星期五\n");break;
		case 'S':printf("请输入第二个字母:");
				if ((letter=getchar())=='u') printf("星期日\n");
				else if ((letter=getchar())=='a') printf("星期六\n");
				else printf("输入错误");break;
		case 'T':printf("请输入第二个字母:");
				if ((letter=getchar())=='u') printf("星期二\n");
				else if ((letter=getchar())=='h') printf("星期四\n");
				else printf("输入错误");break;
		default:printf("输入错误\n"); 
	}
}
