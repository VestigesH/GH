//题目：打印出所有的"水仙花数"
#include <stdio.h>
#include <math.h>
int main()
{
	int x,i,j,k;
	for(x=100;x<999;x++)
	{
		i=x/100;
		j=x%100/10;
		k=x%10;
		if (pow(i,3)+pow(j,3)+pow(k,3)==x) printf("%d ",x);	
	}
}
