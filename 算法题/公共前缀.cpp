//��дһ�������������ַ��������е������ǰ׺����������ڹ���ǰ׺�����ؿ��ַ��� ""��
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
	printf("��������Ҫ�жϵ�3���ַ���:\n");
	for(i = 0;i < N; i++)
		scanf("%s", words[i]);
	printf("����ǰ׺Ϊ��");
	FindPrefix();
}
