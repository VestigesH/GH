//��Ŀ����һ���������ֽ������������磺����90,��ӡ��90=2*3*3*5
#include <stdio.h>
int main()
{
    int i,n;
    printf("Please input n:");
    scanf("%d",&n);
    printf("%d=",n);
    for(i=2;i<=n;i++)
    {
        while(n!=i)     
        {
            if(n%i==0)  
            {
                printf("%d*",i);
                n=n/i;
            }
            else break;
        }
    }
    printf("%d\n",n); 
}
