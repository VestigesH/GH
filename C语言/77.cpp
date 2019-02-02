//题目：求0-7所能组成的奇数个数。
#include <stdio.h>
int main()
{
    long sum=4,s=4;//sum初值4表示一位数的奇数个数  sum表示0-7能组成的奇数总个数 ,
    int j;
    for(j=2;j<=8;j++)//j初值为2,j-1表示组的奇数的位数 
    {    
        if(j<=2) s*=7;//s表示每种位数能组成的奇数个数 
        else  s*=8;
        sum+=s;    
    }
    printf("能组成奇数的总个数为：%ld\n", sum);
    return 0;
}
