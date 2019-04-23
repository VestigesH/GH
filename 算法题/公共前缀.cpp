//编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
#include <stdio.h>
#include <string.h>
#define N 3
char words[N][10];
void FindPrefix()
{
	int i, j, len, count;
	for(i = 0;i < 10; i++)
	{
		count = 0;
		for(j = 1; j < N; j++)
		{
			if(words[0][i] == words[j][i] && count==1)
			{
				printf("%c",words[0][i]);
				break;
			}
			else if(words[0][i] == words[j][i])
				count++;
			else
				break;
		}
	}
}
int main()
{
	int i;
	printf("请输入所要判断的3个字符串:\n");
	for(i = 0;i < N; i++)
		scanf("%s", words[i]);
	printf("公共前缀为：");
	FindPrefix();
}
