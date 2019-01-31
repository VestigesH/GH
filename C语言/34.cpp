//题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
#include <stdio.h>
int main()
{
	int g,s,b,q,w;
	long x;
	printf("请输入不多于五位的正整数x:");
	scanf("%ld",&x);
	if (x<0||x>100000)
	{
		printf("输入错误\n");
		return 0; 
	}		
	else if (0<x<=99999)
	{
		w=x/10000;
		q=x/1000%10;
		b=x/100%10;
		s=x/10%10;
		g=x%10;
		if(w!=0)
		{
			printf("五位数\n");
			printf("逆序打印:%d%d%d%d%d",g,s,b,q,w);
		}
		else if(w==0&&q!=0)
		{
			printf("四位数\n");
			printf("逆序打印:%d%d%d%d",g,s,b,q);
		}
		else if(w==0&&q==0&&b!=0)
		{
			printf("三位数\n");
			printf("逆序打印:%d%d%d",g,s,b);
		}
		else if(w==0&&q==0&&b==0&&s!=0)
		{
			printf("两位数\n");
			printf("逆序打印:%d%d",g,s);
		}
		else if(w==0&&q==0&&b==0&&s==0&&g!=0)
		{
			printf("一位数\n");
			printf("逆序打印:%d",x);
		}
	}
}
