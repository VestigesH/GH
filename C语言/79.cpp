//��Ŀ����ȡ7������1-50��������ֵ��ÿ��ȡһ��ֵ�������ӡ����ֵ�����ģ���
#include <stdio.h>
int main()
{
	int i,j,n;
	for(i=1;i<=7;i++)
	{   
		printf("please input n:");
		scanf("%d",&n);
		if(1<=n<=50)
		{
			for(j=1;j<=n;j++) printf("*");
			printf("\n");
		}
	}
}
