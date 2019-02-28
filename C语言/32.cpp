//题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。 
#include <stdio.h> 
void fac(int n)
{ 
    char ch; 
    if(n>0)
	{
        ch=getchar(); 
        fac(n-1); 
    } 
    else 
        return; 
    printf("%c",ch); 
} 

int main(void)
{ 
	printf("请输入5个字符:");
	char ch;
    fac(5); 
    return 0; 
}
