#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Film 					//ӰƬ�ṹ�� 
{
	int num;					//��Ӱ��� 
	char name[20];				//��Ӱ���� 
	char actor[30]; 			//���� 
	char direct[10];			//���� 
	char area[10];				//���� 
	char date[10];				//��ӳʱ�� 
	char type[10];				//��Ӱ���� 
	char norms[10];				//��Ӱ��� 
	float score;				//��Ӱ���� 	
	struct Film *next;
}film[1000],f[1000];

	int m=0;					//ȫ�ֱ�������¼ӰƬ��Ŀ 

/*---------------------------------------------------------------------��������-------------------------------------------------------------------------------------------*/

//¼��ӰƬ��Ϣ

void Add(struct Film *film)
{
	int num;
	struct Film *p,*q;
	struct Film *head=NULL;
	q=head;
	p=(struct Film *)malloc(sizeof(struct Film));
	p->num=num;
	printf("\t%d","������ӰƬ���:\t");
	scanf("%d",&p->num);
	printf("\t%s","������ӰƬ����:\t");
	scanf("%s",&p->name);
	printf("\t%s","������ӰƬ����:\t");
	scanf("%s",&p->actor);
	printf("\t%s","������ӰƬ����:\t");
	scanf("%s",&p->direct);
	printf("\t%s","������ӰƬ����:\t");
	scanf("%s",&p->area);
	printf("\t%s","��������ӳʱ��:\t");
	scanf("%s",&p->date);
	printf("\t%s","������ӰƬ����:\t");
	scanf("%s",&p->type);
	printf("\t%s","������ӰƬ���:\t");
	scanf("%s",&p->norms);
	printf("\t%f","������ӰƬ����:\t");
	scanf("%f",&p->score); 
	p->next=NULL;
	if(!p)
	{
		head=p;
	}
	else
	{
		while(q->next)
		{
			q=q->next;
		}
		q->next=p;
	}
}

//��ȡӰƬ��Ϣ

int read(struct Film *p)
{
	FILE *fa,*fb;
	int i;
	if((fa=fopen("Film.dat","rb"))==NULL);			//���ļ����ж��Ƿ����
	{
		printf("û��ӰƬ��Ϣ������¼��ӰƬ��Ϣ");	//�������� 
		getchar();
		return -1;	
	}
	if((fb=fopen("film.dat","rb"))==NULL);			//���ļ����ж��Ƿ����
	{
		printf("�����ļ�ʧ�ܣ�\n\n");				//�������� 
		getchar();
		return -1;	
	} 
	fscanf(fb,"%d",&m);								//��ȡ�ļ���ӰƬ��Ϣ�ļ�¼�� 
	fclose(fb);
		if(m==0)
		{
			printf("û��ӰƬ��Ϣ����������ӰƬ��Ϣ\n");
			//menu();
		}
		else
		{
			for(i=0;i<m;p++)
			{
				fread(p,sizeof(struct Film),1,fa);
			}
		}
	fclose(fa);
		return i;
} 

// ��ѯӰƬ��Ϣ

void Search(struct Film *p)
{
	int i,k,choice;
	int film_num;
	char *film_name;
	char *film_actor;
	char *film_direct;
	int film_area;
	char area[1000];
	char *film_date;
	int film_type;
	char type[1000];
	int film_norms;
	char norms[1000];
	float film_score;
	char c[3];
	do
	{
		k=0;
		printf("\t**************����ӰƬ;��**************\n");
		printf("\t|  ���������з�ʽǰ����Ž���ѡ��      |\n");
		printf("\t|      1.ӰƬ���                      |\n");
		printf("\t|      2.ӰƬ����                      |\n");
		printf("\t|      3.ӰƬ����                      |\n");
		printf("\t|      4.ӰƬ����                      |\n");
		printf("\t|      5.ӰƬ����                      |\n");
		printf("\t|      6.��ӳʱ��                      |\n");
		printf("\t|      7.ӰƬ����                      |\n");
		printf("\t|      8.ӰƬ���                      |\n");
		printf("\t|      9.ӰƬ����		       |\n");
		printf("\t|      0.�˳���ѯ		       |\n");
		printf("\t---------------------------------------\n");
		printf("����ѡ����:");
		scanf("%d",&choice);
		if(choice==0)
			break;
		switch (choice)
		{
			case 1:											//���ձ�Ų�ѯ 
				{
					printf("������ӰƬ���:\n");
					scanf("%d",&film_num);
					for(i=0;i<m;i++)
					{
						if(film[i] .num==film_num)
						{
							f[i]=film[i];
							k++;
						}
					}
				}
				break;
			case 2:											//�������Ʋ�ѯ 
				{
					printf("������ӰƬ����:\n");
					scanf("%s",&film_name);
					for(i=0;i<m;i++)
					{
						if(strcmp(film[i].name,film_name)==0)
						{
							f[i]=film[i];
							k++;
						}
					}
				} 
				break;
			case 3:											//�������ݲ�ѯ 
				{
					printf("������ӰƬ����:\n");
					scanf("%s",&film_actor);
					for(i=0;i<m;i++)
					{
						if(strcmp(film[i].actor,film_actor)==0)
						{
							f[i]=film[i];
							k++;
						}
					}
				}
				break;
			case 4:											//���յ��ݲ�ѯ 
				{
					printf("������ӰƬ����:\n");
					scanf("%s",&film_direct);
					for(i=0;i<m;i++)
					{
						if(strcmp(film[i].direct,film_direct)==0)
						{
							f[i]=film[i];
							k++;
						}
					}
				}
				break; 
			case 5:											//���յ�����ѯ 
				{
					printf("������ӰƬ����(1.���� 2.��� 3.���� 4.ŷ�� 5.���� 6.�ձ� 7.ӡ�� 8.����):\n");
					scanf("%d",&film_area);
					switch(film_area)
					{
						case 1:
							{
								strcpy(area,"����"); 
							}
							break;
						case 2:
							{
								strcpy(area,"���"); 
							}
							break;
						case 3:
							{
								strcpy(area,"����"); 
							}
							break;
						case 4:
							{
								strcpy(area,"ŷ��"); 
							}
							break;
						case 5:
							{
								strcpy(area,"����"); 
							}
							break;
						case 6:
							{
								strcpy(area,"�ձ�"); 
							}
							break;
						case 7:
							{
								strcpy(area,"ӡ��"); 
							}
							break;
						case 8:
							{
								strcpy(area,"����"); 
							}
							break; 
						default:
							{
								printf("��ѯʧ�ܣ���������ȷ��Ž��в�ѯ��");
							}
					}
					for(i=0;i<m;i++)
					{
						if(strcmp(film[i].area,area)==0)
						{
							f[i]=film[i];
							k++;
						}
					}
				} 
				break;
			case 6:											//����ʱ���ѯ 
				{
					printf("��������ӳʱ��:\n");
					scanf("%s",&film_date);
					for(i=0;i<m;i++)
					{
						if(strcmp(film[i].date,film_date)==0)
						{
							f[i]=film[i];
							k++;
						}
					}
				}
				break;
			case 7:											//�������Ͳ�ѯ 
				{
					printf("������ӰƬ����(1.ϲ�� 2.���� 3.���� 4.ǹս 5.���� 6. ��� 7.���� 8.��ͥ 9.�ഺ 10.����):\n");
					scanf("%d",&film_type);
					switch(film_type)
					{
						case 1:
							{
								strcpy(type,"ϲ��");
							}
							break;
						case 2:
							{
								strcpy(type,"����");
							}
							break;
						case 3:
							{
								strcpy(type,"����");
							}
							break;
						case 4:
							{
								strcpy(type,"ǹս");
							}
							break;
						case 5:
							{
								strcpy(type,"����");
							}
							break;
						case 6:
							{
								strcpy(type,"���");
							}
						case 7:
							{
								strcpy(type,"����");
							}
							break;
						case 8:
							{
								strcpy(type,"��ͥ");
							}
							break;
						case 9:
							{
								strcpy(type,"�ഺ");
							}
							break;
						case 10:
							{
								strcpy(type,"����");
							}
							break;
						default:
							{
								printf("��ѯʧ�ܣ���������ȷ��Ž��в�ѯ��");
							}
					}
					for(i=0;i<m;i++)
					{
						if(strcmp(film[i].type,type)==0)
						{
							f[i]=film[i];
							k++;
						}
					}
				}
				break;
			case 8:											//���չ���ѯ  
				{
					printf("������ӰƬ���(1.���� 2.Ժ�� 3.�ű���Ч 4.���� 5.���� ):\n");
					scanf("%d",&film_norms);
					switch(film_norms)
					{
						case 1:
							{
								strcpy(norms,"����");
							}
							break;
						case 2:
							{
								strcpy(norms,"Ժ��");
							}
							break;
						case 3:
							{
								strcpy(norms,"�ű���Ч");
							}
							break;
						case 4:
							{
								strcpy(norms,"����");
							}
							break;
						case 5:
							{
								strcpy(norms,"����");
							}
							break;
						default:
							{
								printf("��ѯʧ�ܣ���������ȷ��Ž��в�ѯ��");
							}
					}	
					for(i=0;i<m;i++)
					{
						if(strcmp(film[i].norms,norms)==0)
						{
							f[i]=film[i];
							k++;
						}
					}
				}
				break;
			case 9:											//�������ֲ�ѯ 
				{
					printf("������ӰƬ����:\n");
					scanf("%f",&film_score);
					for(i=0;i<m;i++)
					{
						if(film[i].score==film_score)
						{
							f[i]=film[i];
							k++;
						}
					}
				}
				break;
			case 0: break;
			default: printf("��ѯ������������ȷ�Ĳ�ѯ��ʽ"); 
		}
		if(k==0)
		{
			printf("====================================================================================================================\n");
			printf("\n û������Ҫ���ҵ����ݣ�\n");
			printf("====================================================================================================================\n");
		}
		else
		{
			printf("====================================================================================================================\n");
			printf("ӰƬ��ţ�\t ӰƬ���ƣ�\t ӰƬ���ݣ�\t ӰƬƬ���ݣ�\t ӰƬ������\t ��ӳʱ�䣺\t ӰƬ���ͣ�\t ӰƬ���\t ӰƬ���֣�\n ");
			for(i=0;i<k;i++)
			{
				printf("%8d %16s %16s %16s %16s %16s %16s %16s %8f\n",f[i].num,f[i].name,f[i].actor,f[i].direct,f[i].area,f[i].date,f[i].type,f[i].norms,f[i].score);
			}
			printf("====================================================================================================================\n");
			printf("\n����Ϊ��ѯ���ݣ�\n");
		}
		printf("���Ƿ�Ҫ�������ң�������yes ��no �Իس�������\n");
		scanf("%s",c);
	}while(strcmp(c,"yes")==0);//�жϽ��� 
}
void printFilm(struct Film *film)//����ѯ�����ӡ���� 
{
	if(!film) printf("\tδ��ѯ����ӰƬ��Ϣ������������.");
	else 
	{
		printf("----------------------------------------------------------------------------"); 
		printf("|   ���    ����    ����    ����    ����   ��ӳʱ��   ����    ���    ����  |");
		printf("%d\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %d\t",film->num,film->name,film->actor,film->direct,film->area,film->date,film->type,film->norms,film->score);
	} 
}

//�޸�ӰƬ��Ϣ

void Change(struct Film *film) 
{
	 
	struct Film *p;
	struct Film *head=NULL;
	p=(struct Film *)malloc(sizeof(struct Film));							//��Ų��ң�������p��
	int num;
	printf("�������ţ�");
	scanf("%d",&num);								 
	if(p)
	{
		printf("\t		********�޸�ӰƬ��Ϣ********		\n");
		printf("\t ��ӰƬ����Ϣ���£�\n");
		printFilm(p);
		printf("\t%s","�������µ�ӰƬ����:\t");
		scanf("%s",p->name);
		printf("\t%s","�������µ�ӰƬ����:\t");
		scanf("%s",p->actor);
		printf("\t%s","�������µ�ӰƬ����:\t");
		scanf("%s",p->direct);
		printf("\t%s","�������µ�ӰƬ����:\t");
		scanf("%s",p->area);
		printf("\t%s","�������µ���ӳʱ��:\t");
		scanf("%s",p->date);
		printf("\t%s","�������µ�ӰƬ����:\t");
		scanf("%s",p->type);
		printf("\t%s","�������µ�ӰƬ���:\t");
		scanf("%s",p->norms);
		printf("\t%f","�������µ�ӰƬ����:\t");
		scanf("%f",&p->score);
	}
	else printf("\tδ��ѯ����ӰƬ��Ϣ������������.\n");
}

//ɾ��ӰƬ��Ϣ

void Del(struct Film *film)
{
	int num;
	struct Film *p,*q;
	struct Film *head=NULL;
	p=head;						
	if((head)->num==num)							//ɾ��ͷ������� 
	{
		head=(head)->next;
		free(p);
	}
	else 										//����ͷ������� 
	{
		while(p)								//��������Ѱ��Ҫɾ���Ľ�� 
		{
			if(p->num==num)
			{
				q->next=p->next;
				free(p);
				break;
			} 
			q=p;								//*qΪp��ǰ����� 
			p=p->next;
		}
	}
} 

//ͳ��ӰƬ����

int length(struct Film *head)
{
	Film *p=head;
	int count=0;
	while(p)
	{
		p=p->next;
		++count;
	}
	return count;
 } 
 
//�鿴����ӰƬ��Ϣ

void  printall(struct Film *head)
{
	Film *p=head;
	if(p)
	{
		printf("----------------------------------------------------------------------------");
		printf("|   ���    ����    ����    ����    ����   ��ӳʱ��   ����    ���    ����  |");
		while(p)
		{
			printf("%d\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %d\t",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
			p=p->next;	
		}
	}
}

//�����溯�� 

void menu()
{
	int x;
	printf("\t*************���ã���ӭʹ��ӰƬ����ϵͳ!*************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t|           1.¼��ӰƬ��Ϣ                           |\n");
	printf("\t|	    2.����ӰƬ��Ϣ	                     |\n");
	printf("\t|           3.�޸�ӰƬ��Ϣ		             |\n");
	printf("\t|           4.ɾ��ӰƬ��Ϣ		             |\n");
	printf("\t|           5.�鿴ӰƬ����	                     |\n");
	printf("\t|           6.�鿴ӰƬ��Ϣ		             |\n");
	printf("\t|           7.�˳�ϵͳ                               |\n"); 
	printf("\t-------------------------------------------------------\n");
	printf("\t����1-7֮�����ѡ������Ҫ�Ĺ��ܣ���Ҫ����ʹ���밴�س���\n");
}
 
//��½���溯��
 
/*-------------------------------------------------------------------------------������--------------------------------------------------------------------------------------------*/ 
int main()
{
	struct Film *film=(struct Film *)malloc(sizeof(struct Film));
	film->next=NULL;
	int choice;
	while(1)
	{
		system("cls");
		menu();
		scanf("%d",&choice);
		if(choice==7) break;
		switch(choice)
		{
			case 1:
					Add(film);
					break;
			case 2:
					Search(film);
					break;
			case 3:
					Change(film);
					break;
			case 4:
					Del(film);
					break;
			case 5:
					length(film);
					break;
			case 6:
					printall(film);				
					break;	
		}
	}
}

 
