#include <stdio.h>
int getWay(int n)
{
	int way = 0;
	return ((n == 1 || n == 2) ? n : getWay(n - 1) + getWay( n - 2));
}
int main()
{
	int n;
	printf("������̨����n��");
	scanf("%d", &n);
	printf("����%d�ַ�����¥�ݣ�" ,getWay(n));
}
