//��Ŀ�����������ֵ�ƽ�������ƽ�������С�� 50 ���˳���
#include <stdio.h>
int main()
{
	int x,y;
	printf("������x:");
	scanf("%d",&x);
	y=x*x;
	if (y>=50)   printf("%d��ƽ��Ϊ%d",x,y);
	else         return 0;
}
