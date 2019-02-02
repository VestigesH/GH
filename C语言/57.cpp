//题目：打印出杨辉三角形 
#include <stdio.h>
int main()
{
	int i,j, a[10][10]={0,0,0,0,0,0,0,0,0,0};
    for(i=0;i<=9;i++)
    {
        a[i][0]=1;
        printf(" \n");
        printf("%6d",a[i][0]);
        if(i>=1)
        {
            for(j=1;j<=i;j++)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
                printf("%6d",a[i][j]);
            }
        }
        printf("\n");
    }
}
