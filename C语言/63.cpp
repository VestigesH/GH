//��Ŀ����n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m���� 
#include <stdio.h>
f(int a[100],int n,int m)
{
	int b[100],i;
	for(i=0;i<m;i++)	//b�д�����m���� 
	{
		b[i]=a[n-m+i];
	}
	for(i=n-1;i>=m;i--)	//ǰ���������m��λ��
	{
		a[i]=a[i-m];
	}
	for(i=0;i<m;i++)	//���m�����Ż�a��ǰmλ�� 
	{
		a[i]=b[i]; 
    }
}
int main()
{	
	int a[100],n,m,i;
	printf("��������������n:");
	scanf("%d",&n);
	printf("��������������:");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	printf("������Ҫ�ƶ���λ����m:");
	scanf("%d",&m);
	if(n>m)
	{
		printf("�ı���������Ϊ:"); 
		f(a,n,m);
		for(i=0;i<n;i++) printf("%d ",a[i]);
	}
	else printf("�������"); 
	return 0;
}

