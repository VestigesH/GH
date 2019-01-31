//题目：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同
#include <stdio.h>
int main()
{
	int g,s,q,w;
	long x;
	printf("\n请输入一个五位数%d\n",x);
	scanf("%ld",&x);
	if (x>9999&&x<100000)
	{
		g=x%10;
		s=x%100/10;
		q=x%10000/1000;
		w=x/10000;	
		if(g==w&&s==q)
			printf("%ld是回文数:",x);
		else
			printf("%ld不是回文数:",x);
	}
	else
	{
		printf("输入错误");
	}
}
