//��Ŀ��������������¥�ݡ���Ҫ n ������ܵ���¥����ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
#include <stdio.h>
int getway(int n)
{
	if(n==1) return 1;
	else if(n==2)  return 2;
	else return getway(n-1)+getway(n-2);
} 
int main()
{
	int n,way;
	printf("������¥�ݽ���n:");
	scanf("%d",&n);
	way=getway(n);
	printf("��%d�ֲ�ͬ�ķ���",way);
}
