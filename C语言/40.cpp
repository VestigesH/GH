//��Ŀ��ͳ������С�ڷǸ����� n ��������������
#include <stdio.h>
int main()
{
	int n,i,j,counter=0;
	printf("������n:");
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0) break;		
		}	
		if(i==j) counter++;
	}
	printf("С��%d����������Ϊ:%d",n,counter);
} 
