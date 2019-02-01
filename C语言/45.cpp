//题目：两个 3 行 3 列的矩阵，实现其对应位置的数据相加，并返回一个新矩阵：
#include <stdio.h>
int main()
{
	int a[3][3],b[3][3];
	int i,j;
	printf("请输入第一个3*3矩阵的元素:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) scanf("%d",&a[i][j]);
	}
	printf("\n"); 
	printf("请输入第二个3*3矩阵的元素:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) scanf("%d",&b[i][j]);
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			a[i][j]=a[i][j]+b[i][j];
	}
	printf("\n");
	printf("相加后新的矩阵为:\n"); 
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) printf("%4d",a[i][j]);
	printf("\n");
	}						
}
