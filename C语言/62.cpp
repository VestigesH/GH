//题目：输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组。 
#include <stdio.h>
int main()
{
	int A[10],i,max,min,t1,t2;
	printf("请输入一组数:");
	for(i=0;i<10;i++)
		scanf("%d",&A[i]);
	for(i=0;i<10;i++)
	{
		if(A[i]<A[min])
		{
			min=i;
			t1=A[min];
			A[min]=A[9];
			A[9]=t1;
		}
	}
	for(i=0;i<10;i++)
	{
		if(A[i]>A[max])
		{
			max=i;
			t2=A[max];
			A[max]=A[0];
			A[0]=t2;
		}
	}
	for(i=0;i<10;i++)
		printf("%d\t",A[i]);
	return 0; 
}
