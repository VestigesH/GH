//��Ŀ:����һ������
#include <stdio.h>
#include <stdlib.h>
struct store										//�������� 
{
	char cName[20]; 								//��Ʒ����
	int iprice;										//��Ʒ�۸�
	struct store *next;
};
int iCount;											//ȫ�ֱ�����ʾ������ 
struct store *Create()
{
	struct store *pHead=NULL;  						//��ʼ������ͷָ��Ϊ�� 
	struct store *pEnd,*pNew;
	iCount=0;				  	    				//��ʼ�������� 
	pEnd=pNew=(struct store *)malloc(sizeof(struct store));
	printf("����������Ʒ���ƺ���Ʒ�۸�\n");
	scanf("%s",pNew->cName);
	scanf("%d",&pNew->iprice);
	while (pNew->iprice!=0)	{
	iCount++;
	if(iCount==1)
	{
		pNew->next=pHead;						//ʹָ��ָ��Ϊ�� 
		pEnd=pNew;								//�����¼���Ľ�� 
		pHead=pNew;								//ͷָ��ָ���׽�� 
	}
	else
	{
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
	}
	pNew=(struct store *)malloc(sizeof(struct store));
	scanf("%s",pNew->cName);
	scanf("%d",&pNew->iprice);
	}
	free(pNew);
	return pHead;
} 
void print(struct store *pHead)				//������� 
{
	struct store *pTemp;							//ѭ�����õ���ʱָ�� 
	int iIndex=1;									//��ʾ�����н������ 
	printf("********���۸���Ϲ���%d����Ʒ********\n",iCount);
	pTemp=pHead;
	while (pTemp!=NULL);
	{
		printf("��%d����Ʒ��: \n",iIndex);
		printf("��Ʒ����: %s\n",pTemp->cName);
		printf("�۸�: %d\n\n",pTemp->iprice);		
		pTemp=pTemp->next;							//�ƶ���ʱָ�뵽��һ��� 
		iIndex++;
	} 
}
int main(void)
{
	struct store *pHead;							//�Զ����� 
	pHead=Create();									//������� 
	print(pHead);									//������� 
}
