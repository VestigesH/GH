//题目:创建一个链表
#include <stdio.h>
#include <stdlib.h>
struct store										//创建链表 
{
	char cName[20]; 								//物品名称
	int iprice;										//商品价格
	struct store *next;
};
int iCount;											//全局变量表示链表长度 
struct store *Create()
{
	struct store *pHead=NULL;  						//初始化链表，头指针为空 
	struct store *pEnd,*pNew;
	iCount=0;				  	    				//初始化链表长度 
	pEnd=pNew=(struct store *)malloc(sizeof(struct store));
	printf("请先输入商品名称和商品价格；\n");
	scanf("%s",pNew->cName);
	scanf("%d",&pNew->iprice);
	while (pNew->iprice!=0)	{
	iCount++;
	if(iCount==1)
	{
		pNew->next=pHead;						//使指针指向为空 
		pEnd=pNew;								//跟踪新加入的结点 
		pHead=pNew;								//头指针指向首结点 
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
void print(struct store *pHead)				//输出链表 
{
	struct store *pTemp;							//循环所用的临时指针 
	int iIndex=1;									//表示链表中结点的序号 
	printf("********本价格表上共有%d个商品********\n",iCount);
	pTemp=pHead;
	while (pTemp!=NULL);
	{
		printf("第%d个商品是: \n",iIndex);
		printf("商品名称: %s\n",pTemp->cName);
		printf("价格: %d\n\n",pTemp->iprice);		
		pTemp=pTemp->next;							//移动临时指针到下一结点 
		iIndex++;
	} 
}
int main(void)
{
	struct store *pHead;							//自定义结点 
	pHead=Create();									//创建结点 
	print(pHead);									//输出链表 
}
