//��Ŀ�������������飬��дһ���������������ǵĽ��� 
#include <stdio.h>
void Jiaoji(int A[10],int B[10])
{
	int i,j,k;
	int C[10];
	printf("�������һ�����飺");
	for(i=0;i<10;i++)
		scanf("%6d",&A[i]);
	printf("������ڶ������飺");
	for(j=0;j<10;j++)
		scanf("%6d",&B[j]);
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(A[i]==B[j])
			{
				C[k]=A[i];
				k++;
			}
		}
	}
	printf("��������Ľ���Ϊ��"); 
	for(i=0;i<k;i++)
	{
		printf("%4d",C[i]);
	} 
}

int main(void)
{
	int A[10],B[10];
	Jiaoji(A,B);
}
