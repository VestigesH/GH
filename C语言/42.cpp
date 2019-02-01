//题目：求一个3*3矩阵主对角线元素之和。 
#include <stdio.h>
int main()
{
	int i,j,a[3][3];
	int sum=0;
	printf("请输入3*3的矩阵:");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==j) sum+=a[i][j]; 
		}	
	printf("主对角线之和为:%d",sum);
}
