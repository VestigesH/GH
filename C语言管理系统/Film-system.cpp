#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define Savepath "./Savedata.txt"   //���ݴ洢·��

/* 
ӰƬ��Ϣ����ϵͳ���� :
			(1).¼��ӰƬ��Ϣ 
			(2).��ѯӰƬ��Ϣ 
			(3).��ӡӰƬ��Ϣ
			(4).�޸�ӰƬ��Ϣ 
			(5).ɾ��ӰƬ��Ϣ 
			(6).ͳ��ӰƬ����
			(7).ӰƬ��Ϣ���� 
			(8).�鿴����ӰƬ��Ϣ
*/ 

//�������� 

//1.���ܺ��� 
void Add(); 				// ¼�� 
void Change();				//�޸� 
void Del();					//ɾ�� 
void Search();				//���� 
void landing();				//��½ 
void registered();			//ע�� 
void Length();				//ӰƬ����  
void printall();			//��ӡӰƬ��Ϣ 
void savedata();            //����ӰƬ��Ϣ
void Sort();                //���� 
void Usortnum();            //ӰƬ�������
void Dsortnum();            //ӰƬ��Ž���
void Usortname();           //ӰƬ��������
void Dsortname();           //ӰƬ���ƽ���
void Usortdate();           //��ӳʱ������
void Dsortdate();           //��ӳʱ�併��
void Usortscore();          //ӰƬ��������
void Dsortscore();          //ӰƬ���ֽ��� 
 
//2.���溯�� 
void menu(); 				//��½ע����� 
void Menu();				//ӰƬ��Ϣ����ϵͳ���ܽ���


struct Film 				//ӰƬ��Ϣ�ṹ�� :��Ӱ��š���Ӱ���� �����ݡ� ���� �������� ��ӳʱ�� ����Ӱ���� ����Ӱ��� ����Ӱ����
{
	int num;
	char name[20];
	char actor[30];
	char direct[10];
	char area[10];
	int date;
	char type[10];
	char norms[10];
	float score;
	struct Film *next;
};
struct Film *const film=(struct Film *)malloc(sizeof(struct Film));//ȫ��������ͷ��㣬ͷָ��film��const�޶��������޸ģ�


struct User					   //�û��ṹ��
{
    char user[20];
    char code[20];
}save; 						


/*---------------------------------------------------------------------��������-------------------------------------------------------------------------------------------*/

/*=========================================��д�ļ���Ϣ����==========================================*/

void readdata()
{
	FILE *fp;
	struct Film *p;
	if((fp = fopen(Savepath,"rab")) == NULL)
		return;
	while(!feof(fp))
	{
		p = (struct Film *)malloc(sizeof(struct Film));
		if(p == NULL)
		{
			printf("�����ڴ�ʧ��");
			exit(1);
		}
		fscanf(fp,"%d %s %s %s %s %d %s %s %f\n",&p->num,p->name,p->actor,p->direct,p->area,&p->date,p->type,p->norms,&p->score);
		if(feof(fp)) 
			break;
		p->next = film->next;//ͷ�巨
		film->next = p;
	}
	fclose(fp);
}

void savedata(struct Film *film)
{
	FILE *fp;
	struct Film *p;
	fp=fopen("Savedata.txt","W");
	p=film->next;  
	while(p)
	{
		fprintf(fp,"%d %s %s %s %s %d %s %s %f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p=p->next;
	}
	fclose(fp);
	printf("\n\t\t\t\t\t\t\t�ɹ�д���ļ���"); 
}


/*=========================================ӰƬ��Ϣ����==========================================*/

//1.¼��ӰƬ��Ϣ
void Add()
{
	system("cls");
	int n=0;					       //¼����ӰƬ�� 
	char A[3];
	printf("\n");
	printf("\n\t\t\t\t\t\t\t**************¼����ӰƬ**************\n");
	printf("\n");
	printf("\n");
	FILE *fp = fopen(Savepath,"a+");//��׷��ģʽд���ļ�
	if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Sorry! �ļ���ʧ��!\n");
        exit(1);
    }
    do
	{
		struct Film *p = (struct Film*)malloc(sizeof(struct Film));
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ���:");
   		scanf("%d",&p->num);
   		printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ����:");
    	scanf("%s",p->name);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ����:");
    	scanf("%s",p->actor);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ����:");
    	scanf("%s",p->direct);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ����:");
    	scanf("%s",p->area);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼�����ӳʱ��:");
    	scanf("%d",&p->date);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ����:");
    	scanf("%s",p->type);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ���:");
    	scanf("%s",p->norms);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t ������Ҫ¼���ӰƬ����:");
    	scanf("%f",&p->score);
    	p->next = film->next;
    	film->next = p;
    	fprintf(fp,"%d %s %s %s %s %d %s %s %f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		printf("\n");
		n++; 
		printf("\n\t\t\t\t\t\t\t Congractulations! �ɹ�¼���%d����ӰƬ!",n);
		printf("\n");
		printf("\n\t\t\t\t\t\t\t�Ƿ����¼��ӰƬ��Ϣ��������yes or no ?\t");
		scanf("\n\t\t\t\t\t\t\t%s",&A);
		system("cls");
	}while(strcmp(A,"yes") == 0);
	
	fclose(fp);
}


// 2.��ѯӰƬ��Ϣ 
void Search()
{
	int i,k,choice;
	int film_num;
	char film_name[20];
	char film_actor[30];
	char film_direct[10];
	char film_area[10];
	int  film_date;
	char film_type[10];
	char film_norms[10];
	float film_score;
	char c[3];
	struct Film *hp = film;
	struct Film f[100];  
	do
	{
		system("cls");
		k = 0;
		printf("\n\n\n\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��             *****����ӰƬ;��****                  ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t�ĩ���������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��           ���������з�ʽǰ����Ž���ѡ��           ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   1.ӰƬ���                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   2.ӰƬ����                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   3.ӰƬ����                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   4.ӰƬ����                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   5.ӰƬ����                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   6.��ӳʱ��                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   7.ӰƬ����                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   8.ӰƬ���                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   9.ӰƬ����                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                   0.�˳���ѯ                       ��\n");
		printf("\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
		printf("\n\t\t\t\t\t\t\t����ѡ����:");
		scanf("%d",&choice);
		system("cls");
		if(choice == 0)
			break;
		switch (choice)
		{
			case 1:											//���ձ�Ų�ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ���:");  
					scanf("%d",&film_num);
                    hp = film->next;
                    while(hp != NULL)
                    {
                        if(hp->num == film_num)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 2:											//�������Ʋ�ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_name);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(strcmp(hp->name,film_name)==0)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 3:											//�������ݲ�ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_actor);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(strcmp(hp->actor,film_actor)==0)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 4:											//���յ��ݲ�ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_direct);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(strcmp(hp->direct,film_direct)==0)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 5:											//���յ�����ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_area);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(strcmp(hp->area,film_area)==0)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 6:											//����ʱ���ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ��ӳʱ��:");
					scanf("%d",&film_date);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(hp->date == film_date)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 7:											//�������Ͳ�ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_type);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(strcmp(hp->type,film_type)==0)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 8:											//���չ���ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ���:");
					scanf("%s",film_norms);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(strcmp(hp->norms,film_norms)==0)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 9:											//�������ֲ�ѯ
				{
					printf("\t\t\t\t\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%f",&film_score);
					hp = film->next;
                    while(hp != NULL)
                    {
                        if(hp->score == film_score)
                        {
                            f[k] = *hp;   
                            k++;
                        }
                        hp = hp->next;
                    }
				}
				break;
			case 0: break;
			default:
				break;
		}
		if(k==0)
		{
			printf("\t\t======================================================================================================================\n");
			printf("\t\t\t\t\t\t  	   Sorry! û������Ҫ���ҵ����ݣ�\n");
			printf("\t\t======================================================================================================================\n");
		}
		else
		{
			system("cls");
			for(i=0;i<k;i++)
			{
				printf("\n");
				printf("\t\t\t\t\t\t\t ӰƬ���:%d \n",f[i].num);
				printf("\t\t\t\t\t\t\t ӰƬ����:%s \n",f[i].name);
				printf("\t\t\t\t\t\t\t ӰƬ����:%s \n",f[i].actor);
				printf("\t\t\t\t\t\t\t ӰƬ����:%s \n",f[i].direct);
				printf("\t\t\t\t\t\t\t ӰƬ����:%s \n",f[i].area);
				printf("\t\t\t\t\t\t\t ��ӳʱ��:%d \n",f[i].date);
				printf("\t\t\t\t\t\t\t ӰƬ����:%s \n",f[i].type);
				printf("\t\t\t\t\t\t\t ӰƬ���:%s \n",f[i].norms);
				printf("\t\t\t\t\t\t\t ӰƬ����:%4.1f \n",f[i].score);
			}
			printf("\n");
			printf("\t\t\t\t\t\t\t����Ϊ������ѯ�����ݣ�\n");
		}
		printf("\n");
		printf("\t\t\t\t\t\t\t���Ƿ�Ҫ�������ң�������yes��no! \t");
		scanf("\t\t\t\t\t\t\t%s",c);
	}while(strcmp(c,"yes")==0);
}


//3.�޸�ӰƬ��Ϣ
void Change()
{
	system("cls");
	int flag=1,choice;
	char name1[20];
	char A[3];
	struct Film *pc = film->next;
	printf("\t\t\t\t\t\t\t ���������޸ĵ�ӰƬ����:");
	scanf("%s",&name1);
	printf("\t\t\t\t\t\t\t		********�޸�ӰƬ��Ϣ********		\n");
	do
	{
		if(pc == NULL)
		{
			printf("\t\t\t Sorry! δ��ѯ����ӰƬ��Ϣ!\n");
			break;
		}
		if(strcmp(name1,pc->name) != 0)
			pc = pc->next;
		else if(strcmp(name1,pc->name) == 0)
		{
			printf("\n");
			printf("\t\t\t\t\t\t\t 1.ӰƬ���\n");
			printf("\t\t\t\t\t\t\t 2.ӰƬ����\n");
			printf("\t\t\t\t\t\t\t 3.ӰƬ����\n");
			printf("\t\t\t\t\t\t\t 4.ӰƬ����\n");
			printf("\t\t\t\t\t\t\t 5.ӰƬ����\n");
			printf("\t\t\t\t\t\t\t 6.��ӳʱ��\n");
			printf("\t\t\t\t\t\t\t 7.ӰƬ����\n");
			printf("\t\t\t\t\t\t\t 8.ӰƬ���\n");
			printf("\t\t\t\t\t\t\t 9.ӰƬ����\n");
			printf("\t\t\t\t\t\t\t ����������Ҫ�޸ĵ�ѡ��:");
			scanf("%d",&choice);
			pc = pc->next;
			switch(choice)
			{
				case 1:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ���:");
					scanf("%d",&pc->num);
					break;
				case 2:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->name);
					break;
				case 3:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->actor);
					break;
				case 4:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->direct);
					break;
				case 5:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->area);
					break;
				case 6:
					printf("\t\t\t\t\t\t\t �������µ���ӳʱ��:");
					scanf("%d",&pc->date);
					break;
				case 7:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->type);
					break;
				case 8:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ���:");
					scanf("%s",pc->norms);
					break;
				case 9:
					printf("\t\t\t\t\t\t\t �������µ�ӰƬ����:");
					scanf("%f",&pc->score);
					break;
			}
		}
		printf("\n\t\t\t\t\t\t\t�Ƿ�����޸�ӰƬ��Ϣ��������yes or no ?\t");
		scanf("\n\t\t\t\t\t\t\t%s",&A);
		if(strcmp(A,"yes")==0)
		{
			flag=1;
			system("cls");
		}
		else
			flag=0;
	}while(flag);
	savedata(film);
	printf("\t\t\t\t\t\t\t  ӰƬ��Ϣ�޸ĳɹ���");
}

 
// 4.ɾ��ӰƬ��Ϣ
void Del()
{
	system("cls");
	char name1[20];
	printf("\n\n\t\t\t\t\t\t\t		********ɾ��ӰƬ��Ϣ********		\n");
	struct Film *p = film->next;
	struct Film *q = film;
	printf("\t\t\t\t\t\t\t ������Ҫɾ����ӰƬ����:");
	scanf("%s",&name1);
	while(1)
	{
		if(p == NULL)
		{
			printf("\n\n\t\t\t\t\t\t\t  û�д�ӰƬ����Ϣ��\n");
			break;
		}
		if(strcmp(name1,p->name)!=0)
		{
			q = p;
			p = p->next;
		}
		else if(strcmp(name1,p->name)==0)
		{
			q->next = p->next;
			free(p);
			printf("\n\n\t\t\t\t\t\t\t ɾ���ɹ�!\n");
			break;
		}
		savedata(film);
	}
}


// 5.ͳ��ӰƬ����
void Length()
{
	system("cls");
	int count=0;
	struct Film *p = film->next;
	while(p)
	{
		p = p->next;
		++count;
	}
	printf("\n\n\t\t\t\t\t\t\t  ӰƬ����Ϊ��%d",count);
}


// 6.�鿴����ӰƬ��Ϣ
void  Printall()
{
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t ********�鿴����ӰƬ��Ϣ********		\n");
	struct Film *p = film->next;
	if(p)
	{
		printf("\t=================================================================================================================================================\n");
		printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");
		while(p)
		{
			printf("\n");
			printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
			p = p->next;
		}
		printf("\t=================================================================================================================================================\n");
	}
	else
		printf("\n\t\t\t\t\t\t\t  Ŀǰ����ӰƬ��Ϣ��");
}


// 7.ӰƬ��Ϣ����  
void Sort()
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1,*p2 ;
	struct Film f;
	p2 = film;
	int choice; 
		printf("\n\n\n\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");	
	printf("\t\t\t\t\t\t\t��                 *****ӰƬ�������*****             ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t�ĩ���������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��            ���������з�ʽǰ����Ž���ѡ��          ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   1.ӰƬ�������                   ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   2.ӰƬ��Ž���                   ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   3.ӰƬ��������                   ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   4.ӰƬ���ƽ���                   ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   5.��ӳʱ������                   ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   6.��ӳʱ�併��                   ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   7.ӰƬ��������                   ��\n");
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   8.ӰƬ���ֽ���                   ��\n"); 
	printf("\t\t\t\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t\t\t\t��                   0.�˳��鿴����                   ��\n");
	printf("\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
	printf("\n\t\t\t\t\t\t\t����ѡ����:");
	scanf("%d",&choice);
	if(p2 == NULL)
	{
		printf("\n\t\t\t\t\t\t\tSorry! ��ʱ��ӰƬ��Ϣ���޷�����!"); 
		return;
	}
	switch(choice)
	{
		case 1: 
			Usortnum();//ӰƬ������� 
			break;
		case 2: 
			Dsortnum();//ӰƬ��Ž���
			break;
		case 3:
			Usortname();//ӰƬ�������� 
			break;
		case 4:
			Dsortname();//ӰƬ���ƽ��� 
			break;
		case 5:
			Usortdate();//��ӳʱ������ 
			break;
		case 6:
			Dsortdate();//��ӳʱ�併�� 
			break;
		case 7: 
			Usortscore();//ӰƬ��������
			break;
		case 8:
			Dsortscore();//ӰƬ���ֽ��� 
			break;
		default:
			exit(1); 
	}														
}

void Usortnum()            //ӰƬ�������
{ 
	system("cls");
	struct Film *p = film->next;
	struct Film *p1,*p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(p2->num > p1->num)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************ӰƬ����������**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Dsortnum()            //ӰƬ��Ž���
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1,*p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(p2->num < p1->num)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************ӰƬ��Ž������**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Usortname()           //ӰƬ��������
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1,*p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(strcmp(p2->name,p1->name)>0)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************ӰƬ�����������**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Dsortname()           //ӰƬ���ƽ���
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1, *p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(strcmp(p2->name,p1->name)<0)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************ӰƬ���ƽ������**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Usortdate()           //��ӳʱ������
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1, *p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(p2->date > p1->date)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************��ӳʱ���������**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");

}
void Dsortdate()           //��ӳʱ�併��
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1, *p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(p2->date < p1->date)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************��ӳʱ�併�����**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Usortscore()          //ӰƬ��������
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1, *p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(p2->score > p1->score)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************ӰƬ�����������**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Dsortscore()          //ӰƬ���ֽ��� 
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1, *p2 ;
	struct Film f;
	p2 = film;
	for(p2 = p2->next; p2->next != NULL; p2 = p2->next)
	{
		for(p1 = p2->next; p1 != NULL; p1 = p1->next)
		{
			if(p2->score < p1->score)
			{
				f.num = p2->num;
				strcpy(f.name,p2->name);
				strcpy(f.actor,p2->actor);
				strcpy(f.direct,p2->direct);
				strcpy(f.area,p2->area);
				f.date = p2->date;
				strcpy(f.type,p2->type);
				strcpy(f.norms,p2->norms);
				f.score = p2->score;
				
				p2->num = p1->num;
				strcpy(p2->name,p1->name);
				strcpy(p2->actor,p1->actor);
				strcpy(p2->direct,p1->direct);
				strcpy(p2->area,p1->area);
				p2->date = p1->date;
				strcpy(p2->type,p1->type);
				strcpy(p2->norms,p1->norms);
				p2->score = p1->score;
				
				p1->num = f.num;
				strcpy(p1->name,f.name);
				strcpy(p1->actor,f.actor);
				strcpy(p1->direct,f.direct);
				strcpy(p1->area,f.area);
				p1->date = f.date;
				strcpy(p1->type,f.type);
				strcpy(p1->norms,f.norms);
				p1->score = f.score;
			}	
		}
	}
	printf("\n\t\t\t\t\t\t\t �ɹ�����!");	
	printf("\n\\t\t\t\t\t\t\t**************ӰƬ���ֽ������**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ�� \tӰƬ����  \tӰƬ���  \tӰƬ���� \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}




/*===================================================�����溯��=========================================*/ 


//1.ע���½����
void menu()        
{
	system("cls");
	int choice = 0;
	while(choice != 3)
	{
		printf("\n\n\n\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��               *****    WELCOME    *****            ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t�ĩ���������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                 ��. ע�����û�                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                 ��. ��½�˻�                       ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                 ��. �˳�                           ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
		printf("\n\n\t\t\t\t\t\t\t����1-3֮�����ѡ������Ҫ�Ĺ���:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				registered();
				break;
			case 2:
				landing();
				break;
			case 3:
				break;
			default:
				{
					printf("\n\t\t\t\t\t\t\t Sorry! �������������������ȷ���!");
					menu(); 
				}
				break;
		}
	}
} 


//2.ӰԺ����ϵͳ���ܽ��� 
void Menu()     
{
	system("cls");
	int choice1;
	do
	{
		printf("\n\n\n\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��     ***** ����,��ӭʹ��ӰƬ��Ϣ����ϵͳ! *****     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t�ĩ���������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.¼��ӰƬ��Ϣ                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.����ӰƬ��Ϣ                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.�޸�ӰƬ��Ϣ                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.ɾ��ӰƬ��Ϣ                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.�鿴ӰƬ����                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.�鿴ӰƬ��Ϣ                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.ӰƬ�������                     ��\n");
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t��                ��.�˳�ϵͳ                         ��\n"); 
		printf("\t\t\t\t\t\t\t��                                                    ��\n");
		printf("\t\t\t\t\t\t\t������������������������������������������������������������������������������������������������������������\n");
		printf("\n\n\t\t\t\t\t\t\t����1-7֮�����ѡ������Ҫ�Ĺ���:");
		scanf("%d",&choice1);
		if(choice1 == 8)	exit(0);
		switch(choice1)
		{
			case 1:
				Add();
				break;
			case 2:
				Search();
				break;
			case 3:
				Change();
				break;
			case 4:
				Del();
				break;
			case 5:
				Length();
				break;
			case 6:
				Printall();
				break;	
			case 7:
				Sort();
				break;	
		}
	}while(choice1);	
}	



/*===================================================�û����ֺ���=========================================*/


//1.ע�ắ�� 
void registered()													
{
    char temp[20];
    char user[20];
    FILE *User;
    do
    {
    	system("cls");
        printf("\n\t\t\t\t\t\t\t �û�ע��\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t �����������û���:");
        scanf("%s",user);
        User=fopen("user.txt","r");
		fscanf(User,"%s %s",save.user,save.code);			       
        if(strcmp(user,save.user)==0)                       		  //�ж��û����Ƿ��ظ�
        {
        	printf("\n");
        	printf("\n\t\t\t\t\t\t\t Sorry! ���û����Ѵ���!");
        	printf("\n\t\t\t\t\t\t\t �Ƿ����ע��?(Y/N)");
        	if(getchar()=='Y')
				registered();
        	else	break;
        }
        else
        {
        	strcpy(save.user, user);
        	printf("\n\t\t\t\t\t\t\t ��������������:");				//ȷ���������������Ƿ�һ��
        	scanf("%s",save.code);
        	printf("\n\t\t\t\t\t\t\t ���ٴ�����ȷ������:"); 
        	scanf("%s",temp);
        	if(strcmp(save.code,temp)!=0)
        	printf("\n\\t\t\t\t\t\t\t Sorry! �������벻һ��,����������");
        	else
        	{
        		fprintf(User,"%s",save.code);
        		printf("\n\t\t\t\t\t\t\t ע��ɹ�!"); 
			}			
		} 
		fclose(User);
    }while(strcmp(save.code,temp)!=0);
    //�û�����������д���ĵ������û���Ϣ
    User=fopen("user.txt","a+");
    if(User==NULL)
    {
	    printf("\n\t\t\t\t\t\t\t Sorry! ע��ʧ��!\n");
	    exit(0);
    }
    else
    {
        fprintf(User,"%s %s\n",save.user,save.code); 
		fclose(User);
    }
}


//2.��½����
void landing()
{
	system("cls");
    char username[20];
	char code[20];
	char temp; 
	int flag=0;     		
    printf("\n\t\t\t\t\t\t\t �û���¼");
    printf("\n");
    printf("\n\t\t\t\t\t\t\t �������û���:");
    scanf("%s",username);
    FILE *User=fopen("user.txt","r+");
    temp='0';
    fscanf(User,"%s %s",save.user,save.code);
    if(feof(User)) 
	{
    	printf("\n\t\t\t\t\t\t\t Sorry! �����û���Ϣ!��ע��!\n");
	    return registered();
	} 
	else 
	{
		do 
		{
			fscanf(User,"%s %s",save.user,save.code);
			if (strcmp(username, save.user) == 0) 
			{
				printf("\n\t\t\t\t\t\t\t ���������룺");
				scanf("%s",&code);
				if (strcmp(code, save.code) == 0) 
				{
					Sleep(1000);
					printf("\n\t\t\t\t\t\t\t ��½�ɹ���");  
					Menu();
				} else {
					printf("\n\t\t\t\t\t\t\t Sorry!�������!�����µ�¼!");
			    	landing();
				}
			}
		}while(!feof(User));
		printf("\t\t\t�û���Ϣ�����ڣ�");
		printf("\t\t\t1.ע��  \n\t\t\t2.���µ�½  \n\t\t\t3.�˳�");
		char ch = getch();
		switch(ch)
		{
			case '1':
				registered();
				break;
			case '2':
				landing();
				break;
			case '3':
				exit(0);
		 		break;
		 	defult:
		 		printf("\t\t\t�������,����ȷѡ������Ҫ�Ĺ��ܣ�"); 
		 		break; 
			  
		}	 
	}
}


/*-------------------------------------------------------------------------------������--------------------------------------------------------------------------------------------*/ 


int main()
{
	film->next=NULL;
	film->num=0;
    readdata();
	menu();
}




