//��Ŀ����һ��3*3�������Խ���Ԫ��֮�͡� 
#include <stdio.h>
int main()
{
	int i,j,a[3][3];
	int sum=0;
	printf("������3*3�ľ���:");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==j) sum+=a[i][j]; 
		}	
	printf("���Խ���֮��Ϊ:%d",sum);
}
