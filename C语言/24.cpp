//题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include <stdio.h>
int main()
{
	int n;
	float s=100,h=100;
	for (n=0;n<10;n++)
	{
		s=s+h;
		h=h*0.5;	
	}
		printf("第十次落地时共经过%f米\n",s);
		printf("第十次反弹高度为%f米",h);
}
