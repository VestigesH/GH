//��Ŀ�����õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ������ 
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
	printf("������5���ַ�:");
	char ch;
    fac(5); 
    return 0; 
}
