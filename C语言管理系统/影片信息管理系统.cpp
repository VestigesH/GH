#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define m 30 //ӰƬ����������ɶ� 

struct Film 					//ӰƬ��Ϣ�ṹ�� 
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

struct User					//�û��ṹ�� 
{
    char user[20];
    char code[20];
}save; 							//save�ṹ�����������û��������� 
	FILE *fp;
 

/*---------------------------------------------------------------------�������ò���-------------------------------------------------------------------------------------------*/

/*=========================================ӰƬ��Ϣ����==========================================*/ 
 
//¼��ӰƬ��Ϣ

void Add(struct Film *film)
{
	printf("\n\t\t\t**************¼����ӰƬ**************\n"); 
	struct Film *p =(struct Film*)malloc(sizeof(struct Film));
	if(p)
	{
		p->next=film->next;
		film->next=p;
		printf("\t\t\t ������Ҫ¼���ӰƬ���:");
		scanf("%d",&p->num);
		printf("\t\t\t ������Ҫ¼���ӰƬ����:");
		scanf("%s",p->name);
		printf("\t\t\t ������Ҫ¼���ӰƬ����:");
		scanf("%s",p->actor);
		printf("\t\t\t ������Ҫ¼���ӰƬ����:");
		scanf("%s",p->direct);
		printf("\t\t\t ������Ҫ¼���ӰƬ����:");
		scanf("%s",p->area);
		printf("\t\t\t ������Ҫ¼�����ӳʱ��:");
		scanf("%s",p->date);
		printf("\t\t\t ������Ҫ¼���ӰƬ����:");
		scanf("%s",p->type);
		printf("\t\t\t ������Ҫ¼���ӰƬ���:");
		scanf("%s",p->norms);
		printf("\t\t\t ������Ҫ¼���ӰƬ����:");
		scanf("%f",&p->score); 
		printf("\t\t\t Congractulations! �ɹ�¼����ӰƬ!");
	}
	else
	{
		printf("\t\t\t Sorry! ¼��ʧ��!\n"); 
	}
	getchar(); 
	getchar(); 
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
		printf("\n\t\t\t**************����ӰƬ;��**************\n");
		printf("\t\t\t|  ���������з�ʽǰ����Ž���ѡ��      |\n");
		printf("\t\t\t|      1.ӰƬ���                      |\n");
		printf("\t\t\t|      2.ӰƬ����                      |\n");
		printf("\t\t\t|      3.ӰƬ����                      |\n");
		printf("\t\t\t|      4.ӰƬ����                      |\n");
		printf("\t\t\t|      5.ӰƬ����                      |\n");
		printf("\t\t\t|      6.��ӳʱ��                      |\n");
		printf("\t\t\t|      7.ӰƬ����                      |\n");
		printf("\t\t\t|      8.ӰƬ���                      |\n");
		printf("\t\t\t|      9.ӰƬ����		       |\n");
		printf("\t\t\t|      0.�˳���ѯ		       |\n");
		printf("\t\t\t----------------------------------------\n");
		printf("\n\t\t\t����ѡ����:");
		scanf("%d",&choice);
		if(choice==0)
			break;
		switch (choice)
		{
			case 1:											//���ձ�Ų�ѯ 
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ���:");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����(1.���� 2.��� 3.���� 4.ŷ�� 5.���� 6.�ձ� 7.ӡ�� 8.����):");
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
								printf("\t\t\t��ѯʧ�ܣ���������ȷ��Ž��в�ѯ��");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ��ӳʱ��:");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����(1.ϲ�� 2.���� 3.���� 4.ǹս 5.���� 6. ��� 7.���� 8.��ͥ 9.�ഺ 10.����):");
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
								printf("\t\t\t��ѯʧ�ܣ���������ȷ��Ž��в�ѯ��");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ���(1.���� 2.Ժ�� 3.�ű���Ч 4.���� 5.���� ):");
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
								printf("\t\t\t��ѯʧ�ܣ���������ȷ��Ž��в�ѯ��");
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
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
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
			default: printf("\t\t\t��ѯ������������ȷ�Ĳ�ѯ��ʽ"); 
		}
		if(k==0)
		{
			printf("======================================================================================================================\n");
			printf("\t\t\t\t  	   Sorry! û������Ҫ���ҵ����ݣ�\n");
			printf("======================================================================================================================\n");
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
			printf("\t\t\t����Ϊ��ѯ���ݣ�\n");
		}
		printf("\t\t\t���Ƿ�Ҫ�������ң�������yes��no! \t");
		scanf("\t\t\t%s",c);
	}while(strcmp(c,"yes")==0);//�жϽ��� 
}

//��ӡӰƬ��Ϣ 
void printFilm(struct Film *film)
{
	if(!film) 
	{
		printf("\t\t\tδ��ѯ����ӰƬ��Ϣ������������.");
	}
	else 
	{
		printf("\t----------------------------------------------------------------------------\n"); 
		printf("\t|   ���    ����    ����    ����    ����   ��ӳʱ��   ����    ���    ����  |\n");
		printf("%d\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %d\t",film->num,film->name,film->actor,film->direct,film->area,film->date,film->type,film->norms,film->score);
	} 
}

//�޸�ӰƬ��Ϣ

void Change(struct Film *film) 
{
	char name1[20];
	int choice;
	struct Film *pc=film->next;
	printf("\t\t\t ���������޸ĵ�ӰƬ����:");
	scanf("%s",&name1); 
	printf("\t\t\t		********�޸�ӰƬ��Ϣ********		\n");
	while(1)
	{
		if(pc==NULL)
		{
			printf("\t\t\t Sorry! δ��ѯ����ӰƬ��Ϣ!\n");
			break;
		}
		if(strcmp(name1,pc->name)!=0)
			pc=pc->next;
		else if(strcmp(name1,pc->name)==0)
		{
			printf("\n");
			printf("\t\t\t\t\t 1.ӰƬ���");
			printf("\t\t\t\t\t 2.ӰƬ����"); 
			printf("\t\t\t\t\t 3.ӰƬ����"); 
			printf("\t\t\t\t\t 4.ӰƬ����"); 
			printf("\t\t\t\t\t 5.ӰƬ����"); 
			printf("\t\t\t\t\t 6.��ӳʱ��"); 
			printf("\t\t\t\t\t 7.ӰƬ����"); 
			printf("\t\t\t\t\t 8.ӰƬ���"); 
			printf("\t\t\t\t\t 9.ӰƬ����"); 
			printf("\t\t\t ����������Ҫ�޸ĵ�ѡ��:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("\t\t\t �������µ�ӰƬ���:");
					scanf("%s",pc->num);
					break;
				case 2:
					printf("\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->name);
					break;					
				case 3:
					printf("\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->actor);
					break;
				case 4:
					printf("\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->direct);
					break;
				case 5:
					printf("\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->area);
					break;
				case 6:
					printf("\t\t\t �������µ���ӳʱ��:");
					scanf("%s",pc->date);
					break;
				case 7:
					printf("\t\t\t �������µ�ӰƬ����:");
					scanf("%s",pc->type);
					break;
				case 8:
					printf("\t\t\t �������µ�ӰƬ���:");
					scanf("%s",pc->norms);
					break;
				case 9:
					printf("\t\t\t �������µ�ӰƬ����:");
					scanf("%f",&pc->score);
					break;				
			}
			printf("\t\t\t  ӰƬ��Ϣ�޸ĳɹ���");
			break;
		}
	}
	getchar();
	getchar(); 
}	

//ɾ��ӰƬ��Ϣ

void Del(struct Film *film)
{
	char name1[20];
	printf("\n\n\t\t\t		********ɾ��ӰƬ��Ϣ********		\n");
	struct Film *p=film->next;
	struct Film *q=film;				
	printf("\t\t\t ������Ҫɾ����ӰƬ����:");
	scanf("%s",&name1); 	
	while(1)
	{
		if(p==NULL)							
		{
			printf("\n\n\t\t\t  û�д�ӰƬ����Ϣ��\n"); 
			break;
		}
		if(strcmp(name1,p->name)!=0)
		{
			q=p;
			p=p->next;
		}
		else if(strcmp(name1,p->name)==0)
		{
			q->next=p->next;
			free(p);
			printf("\n\n\t\t\t ɾ���ɹ�!\n");
			break; 
		}
    }
    getchar();
    getchar();
} 

//ͳ��ӰƬ����

void Length(struct Film *film)
{
	int count=0;
	struct Film *p;
	struct Film *head=NULL;
	p=head;
	while(p)
	{
		p=p->next;
		++count;
	}
	printf("\n\n\t\t\t  ӰƬ����Ϊ��%d",count);
} 
 
//�鿴����ӰƬ��Ϣ

void  Printall(struct Film *film)
{
	printf("\n\n\t\t\t ********�鿴����ӰƬ��Ϣ********		\n");
	struct Film *p=film->next;
	if(p)
	{
		while(p)
		{
			printf("\n");
			printf("\t\t\t\t\t ӰƬ���:%d \n",p->num);
			printf("\t\t\t\t\t ӰƬ����:%s \n",p->name); 
			printf("\t\t\t\t\t ӰƬ����:%s \n",p->actor); 
			printf("\t\t\t\t\t ӰƬ����:%s \n",p->direct); 
			printf("\t\t\t\t\t ӰƬ����:%s \n",p->area); 
			printf("\t\t\t\t\t ��ӳʱ��:%s \n",p->date); 
			printf("\t\t\t\t\t ӰƬ����:%s \n",p->type); 
			printf("\t\t\t\t\t ӰƬ���:%s \n",p->norms); 
			printf("\t\t\t\t\t ӰƬ����:%f \n",p->score); 
			p=p->next;	
		}
	}
	else
		printf("\n\t\t\t  Ŀǰ����ӰƬ��Ϣ��");
	getchar();
	getchar();
}

/*===================================================�����溯��=========================================*/ 

void menu()
{
	int choice();
	printf("\n\n\n\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|      		*****  WELCOME  *****  		     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|               1.ע�����û�                         |\n");
	printf("\t\t\t|	        2.��½�˻�	                     |\n");
	printf("\t\t\t|               3.�˳�		                     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\n\n\t\t\t����1-3֮�����ѡ������Ҫ�Ĺ���:");
} 
void menu1()
{
	int choice1;
	printf("\n\n\n\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|     ***** ����,��ӭʹ��ӰƬ��Ϣ����ϵͳ! *****     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|           1.¼��ӰƬ��Ϣ                           |\n");
	printf("\t\t\t|	    2.����ӰƬ��Ϣ	                     |\n");
	printf("\t\t\t|           3.�޸�ӰƬ��Ϣ		             |\n");
	printf("\t\t\t|           4.ɾ��ӰƬ��Ϣ		             |\n");
	printf("\t\t\t|           5.�鿴ӰƬ����	                     |\n");
	printf("\t\t\t|           6.�鿴ӰƬ��Ϣ		             |\n");
	printf("\t\t\t|           7.�˳�ϵͳ                               |\n"); 
	printf("\t\t\t------------------------------------------------------\n");
	printf("\n\n\t\t\t����1-7֮�����ѡ������Ҫ�Ĺ���:");
	scanf("%d",&choice1);
	if(choice1==7)	exit(0);
	switch(choice1)
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
			Length(film);
			break;
		case 6:
			Printall(film);
			break;		
	}
}
 
/*===================================================�û����ֺ���=========================================*/
 
//ע�ắ��

void registered()
{
    char temp[20];        
    do
    {
        printf("\n\t\t\t �û�ע��\n");
        printf("\t\t\t �����������û���:");
        scanf("%s",save.user);
        fp=fopen(save.user,"r");					//�ж��û����Ƿ��ظ�
        if(fp!=NULL) 
        {
           printf("\n\t\t\t Sorry! ���û����Ѵ���!");
           fclose(fp);
           printf("\n\t\t\t �Ƿ����ע��?(Y/N)");
           if(getchar()=='Y') return registered();
           else break; 
        }
        printf("\n\t\t\t ��������������:");				//ȷ���������������Ƿ�һ��
        scanf("%s",save.code);
        printf("\n\t\t\t ���ٴ�����ȷ������:");
        scanf("%s",temp);
        if(strcmp(save.code,temp)!=0)
        printf("\n\t\t\t Sorry! �������벻һ��,����������");
    }while(strcmp(save.code,temp)!=0);
    //�û�����������д���ĵ������û���Ϣ
    fp=fopen(save.user,"w");
    if(fp==NULL)
       {
          printf("\n\t\t\t Sorry! ע��ʧ��!\n");
          exit(0);
       }
    else 
    {
        system("cls");
        printf("\n\t\t\t ע��ɹ�!");
        getchar();              
		fclose(fp);            						
    }
}
//д���û���Ϣ
void write()
{
    if(fwrite(&save,sizeof(User),1,fp)!=1)
    {
        printf("\n\t\t\t Sorry!д���ļ�����!");
        exit(0);                     
    }
}

//��½����

void landing()
{
    char u[20],c[20],temp[20];      		//�����������飬��ż���������û���������
    printf("\n\t\t\t\t �û���¼");
    printf("\n\t\t\t �������û���:");
    scanf("%s",u);
    //�ж��û����Ƿ����
    fp=fopen(u,"r+");
    temp[0]='0';
    if(fp==NULL)
    {
        printf("\n\t\t\t Sorry! �û�������,��ע��!");
        printf("\n\t\t\t	1.ע��\n2.���µ�½");
        temp[0]=getchar();
        if(temp[0]=='1')
        {
            system("cls");
            registered();
        }
        else return landing();
    }
    //��֤�����Ƿ���ȷ
    do
    {
        if(1) fread(&save,sizeof(User),1,fp); //��ȡ�û���Ϣ�����û���������
        printf("\t\t\t ��������������:");
        scanf("%s",c);
        if(strcmp(save.code,c)!=0)                      //�Ա����������Ͷ�ȡ������
        {
            printf("\n\t\t\t Sorry! �������(1.�˳� 2.��������)!");
            temp[0]=getchar();
            printf("\n");
            if(temp[0]=='1')
            {
                fclose(fp);                           //�ر��ļ���ֹ�������
            	break;
            }
        }
        if(strcmp(save.code,c)==0) return menu1(); 
    }while(temp[0]=='2');
    getchar();
    printf("\n");
    
} 



 
 
/*-------------------------------------------------------------------------------������--------------------------------------------------------------------------------------------*/ 
int main()
{
	struct Film *film=(struct Film *)malloc(sizeof(struct Film));
	film->next=NULL;
	int choice;
	while(1)
	{
		menu();
		scanf("%d",&choice);
		if(choice==3) break;
		switch(choice)
		{
			case 1:
				registered();
				break;
			case 2:
				landing();
				break;
		}	
	}
}

 
