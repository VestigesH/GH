//题目：给定一个数组 nums，编写一个函数将所有 0动到数组的末尾，同时保持非零元素的相对顺序。(存在问题） 
#include <stdio.h>
int main()
{
	int a[100],n,i,num,t;
	printf("请输入数组的元素个数:");
	scanf("%d",&n);
	printf("请输入这个数组:");
	for(i=0;i<n;i++)  scanf("%d",&a[i]);
	printf("新的数组为："); 
	for(i=0;i<n;i++)
	{
		if(a[i]==0) num++;
		else if(num!=0)
		{
			a[i-num]=a[i];
			a[i]=0;
		}
	printf("%d ",a[i]);	
	}	
}
