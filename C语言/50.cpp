//��Ŀ������һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ��� (�������⣩ 
#include <stdio.h>
int main()
{
	int a[100],k,n,i,t;
	printf("������Ԫ�ظ���n:");
	scanf("%d",&n);
	printf("������Ҫ�ƶ���λ����k:");
	scanf("%d",&k);
	printf("������һ������:");
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		for(k=1;k<n;k++)
		{
			t=a[i];
			a[i]=a[n-k];
			a[n-k]=t;
			printf("%d",a[i]);
		}
		if(k>n) printf("kֵ�������");
	}	
}
