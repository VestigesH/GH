//��Ŀ��һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ"����"������6=1��2��3.����ҳ�1000���ڵ���������
#include <stdio.h>
int main()
{
	int n,i,sum;
	printf("1000�ڵ�������:");
	for(n=1;n<1000;n++)
	{
		sum=0;
		for(i=1;i<n;i++)
		{
			if(n%i==0) sum+=i;
		}
		if(n==sum) printf("%d ",n);
	}	
} 
