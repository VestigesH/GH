//题目：求1+2!+3!+...+20!的和。
#include <stdio.h>
int main()
{
	int i,j,a;
	long int s;
	for(i=1;i<=20;i++)
	{
		a=1;
		for(j=1;j<=20;j++)
		a*=j;
		s+=a;
	}
	printf("1+2!+3!+...+20!=%ld",s);		
}
