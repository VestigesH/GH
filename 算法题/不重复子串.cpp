//.给定一个字符串，请你找出其中不含有重复字符的 最长子串的长度
#include <stdio.h>
#include <stdlib.h> 
char Num[10];
void GetCount()
{
	int i, start, end = 0, count1 = 1, count2 = 0, flag;
	start = end;
	for(i = 0; i < 5; i++)
	{
		if(Num[end] != Num[end + 1])
		{	
			flag = 0;
			if(end > 1)
			{
				for(i = start; i < count1; i++)
				{
					if(Num[i] == Num[end + 1])
					{
						flag = 1;
						break;
					}
				}
			}
			end++;
			if(flag == 0)
				count1++;
			else
			{
				count2 = count1;
				count1 = 0;
				count1++;
			}
		}
		else
		{
			start++;
			end++;
		}
	}
	(count1 < count2) ? printf("%d", count2) : printf("%d", count1);
}
int main()
{
	printf("请输入字符串：");
	for(int i = 0;i < 6; i++)
		scanf("%c",&Num[i]);
	printf("最长不重复子串的长度为：");
	GetCount();
	system("pause");
	return 0;
}
