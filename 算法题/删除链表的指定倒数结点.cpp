//����һ������ɾ������ĵ����� n ���ڵ㣬�������ɾ���������
#include <stdio.h>
#include <stdlib.h> 
int location;
struct Data
{
	int number;
	struct Data *next;
};
void Create(struct Data *pHead)
{
	struct Data *pNew, *pMove;
	int n;
	pHead->next = NULL;
	pNew = pHead;
	printf("����������(��0��������)��");
	scanf("%d", &n);
	while( n != 0)
	{
		pMove = (struct Data *)malloc(sizeof(struct Data));
		pMove->number = n;
		pMove->next = pNew->next;
		pNew->next  = pMove;
		pNew = pMove;
		scanf("%d", &n);
	}
}
void print(struct Data *pHead)
{
	struct Data *p = (struct Data *)malloc(sizeof (struct Data));
	p = pHead->next;
	while(p != NULL)
	{
		printf("%d",p->number);
		p = p->next;
	}
} 
struct Data *Delete(struct Data *pHead)
{
	int count = 0, count1 = 0;
	struct Data *d = (struct Data *)malloc(sizeof(struct Data));
	struct Data *d1 = (struct Data *)malloc(sizeof(struct Data));
	struct Data *d2 = (struct Data *)malloc(sizeof(struct Data));
	d = d1 = pHead->next;
	d2 = d1->next;
	printf("��������Ҫɾ�������Ľڵ�λ�ã�");
	scanf("%d", &location);
	while(d->next != NULL)
	{
		d = d->next;
		count++;
	}
	while( count1 != count - location)
	{
		d1 = d1->next;
		d2 = d2->next;
		count1++;
	}
	if(count1 == count - location)
	{
		d1->next = d2->next;
		free(d2);
	} 
	return pHead;
}
int main()
{
	struct Data *pHead = (struct Data *)malloc(sizeof(struct Data));
	Create(pHead);  
	Delete(pHead);
	printf("ɾ��������%d���ڵ�������Ϊ��",location);
	print(pHead);
}
