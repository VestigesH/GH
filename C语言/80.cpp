//��Ŀ������һ������ nums����дһ������������ 0���������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��(�������⣩ 
#include <stdio.h>
int main()
{
	int a[100],n,i,num,t;
	printf("�����������Ԫ�ظ���:");
	scanf("%d",&n);
	printf("�������������:");
	for(i=0;i<n;i++)  scanf("%d",&a[i]);
	printf("�µ�����Ϊ��"); 
	for(i=0;i<n;i++)
	{
		if(a[i]==0) num++;
		else if(num!=0)
		{
			a[i-num]=a[i];
			a[i]=0;
		}
	printf("%d ",a[i]);	
	}	
}
