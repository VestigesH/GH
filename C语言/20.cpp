//��Ŀ��дһ����������� 1 �� n ���ֵ��ַ�����ʾ��1. ��� n ��3�ı��������"Fizz"��2. ��� n ��5�ı��������"Buzz"��
//3.��� n ͬʱ��3��5�ı�������� "FizzBuzz"��
#include <stdio.h>
int main()
{
	int n;
	printf("������n:");
	scanf("%d",&n);
	if (n%3==0&&n%5!=0)           printf("Fizz");
	else if (n%5==0&&n%3!=0)      printf("Buzz");
	else if (n%3==0&&n%5==0) 	  printf("FizzBuzz");
	else                          printf("%d",n);
}

