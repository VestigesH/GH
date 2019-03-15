#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define Savepath "./Savedata.txt"   //���ݴ洢·��

/* 
ӰƬ��Ϣ����ϵͳ���� :
			(1).¼��ӰƬ��Ϣ 
			(2).��ѯӰƬ��Ϣ 
			(3).��ӡӰƬ��Ϣ
			(4).�޸�ӰƬ��Ϣ 
			(5).ɾ��ӰƬ��Ϣ 
			(6).ͳ��ӰƬ����
			(7).�鿴����ӰƬ��Ϣ
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
void write();               //д���û�����Ϣ  
void savedata();            //����ӰƬ��Ϣ 
 

//2.���溯�� 
void menu(); 				//��½ע����� 
void menu1();				//ӰƬ��Ϣ����ϵͳ���ܽ���



struct Film 		//ӰƬ��Ϣ�ṹ�� :��Ӱ��š���Ӱ���� �����ݡ� ���� �������� ��ӳʱ�� ����Ӱ���� ����Ӱ��� ����Ӱ����
{
	int num;
	char name[20];
	char actor[30];
	char direct[10];
	char area[10];
	char date[10];
	char type[10];
	char norms[10];
	float score;
	struct Film *next;
};
struct Film * const film=(struct Film*)malloc(sizeof(struct Film));//ȫ��������ͷ��㣬ͷָ��film��const�޶��������޸ģ�


struct User					//�û��ṹ��
{
    char user[20];
    char code[20];
}save; 							//save�ṹ�����������û���������


void readdata(void)
{
	FILE *fp;
	Film *node;
	if((fp=fopen(Savepath,"rab"))==NULL)
		return;
	while(!feof(fp))
	{
		node=(struct Film *)malloc(sizeof(struct Film));
		if(node==NULL)
		{
			printf("�����ڴ�ʧ��");
			exit(1);
		}
		fread(node,sizeof(struct Film),1,fp);
		node->next=film->next;//ͷ�巨
		film->next=node;
		film->num++;          //��һ���ڵ㲻�洢���ݣ��Ͱ����е�num���������ݵĸ���
	}
	fclose(fp);
}

/*void savedata()
{
	FILE *fp;
	Film *film;
	if((fp=fopen("Savedata.txt","ab+"))==NULL)
	{
		printf("���ļ�����!\n");
		return;
	}
	while(film)
	{
		fwrite(film,sizeof(Film),1,fp);
		film=film->next;
	}
	fclose(fp); 
}*/


/*---------------------------------------------------------------------�������ò���-------------------------------------------------------------------------------------------*/


/*=========================================ӰƬ��Ϣ����==========================================*/

//¼��ӰƬ��Ϣ

void Add()
{
	int n;					//¼����ӰƬ�� 
	char A[3];
	printf("\n\t\t\t**************¼����ӰƬ**************\n");
	printf("\n");
	struct Film *p =(struct Film*)malloc(sizeof(struct Film));
	if(p)
	{
		FILE *fp=fopen(Savepath,"a");//��׷��ģʽд���ļ�
    	if(fp==NULL)
        {
            printf("\n\t\t\t Sorry! �ļ���ʧ��!\n");
            exit(0);
        }
        do
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
        	fwrite(p,sizeof(struct Film),1,fp);
        	n++; 
			printf("\n\t\t\t Congractulations! �ɹ�¼���%d����ӰƬ!",n);
			printf("\n");
 			printf("\n\t\t\t�Ƿ����¼��ӰƬ��Ϣ��������yes or no ?\t");
 			scanf("\n\t\t\t%s",&A);
		}while(strcmp(A,"yes")==0);
		
		fclose(fp);
	}
	else
        printf("\t\t\t Sorry! ¼��ʧ��!\n");
}


// ��ѯӰƬ��Ϣ 

void Search()
{
	int i,k,choice;
	int film_num;
	char *film_name;
	char *film_actor;
	char *film_direct;
	char *film_area;
	char *film_date;
	char *film_type;
	char *film_norms;
	float film_score;
	char c[3];
	struct Film * hp=film;
	struct Film f[100];  
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
                    hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->num==film_num)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 2:											//�������Ʋ�ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_name);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->name==film_name)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 3:											//�������ݲ�ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_actor);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->actor==film_actor)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 4:											//���յ��ݲ�ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_direct);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->direct==film_direct)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 5:											//���յ�����ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_area);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->area==film_area)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 6:											//����ʱ���ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ��ӳʱ��:");
					scanf("%s",film_date);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->date==film_date)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 7:											//�������Ͳ�ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%s",film_type);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->type==film_type)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 8:											//���չ���ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ���:");
					scanf("%s",film_norms);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->norms==film_norms)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 9:											//�������ֲ�ѯ
				{
					printf("\t\t\t������Ҫ��ѯ��ӰƬ����:");
					scanf("%f",&film_score);
					hp=film->next;
                    while(hp!=NULL)
                    {
                        if(hp->score==film_score)
                        {
                            f[k]=*hp;   
                            k++;
                        }
                        hp=hp->next;
                    }
				}
				break;
			case 0: break;
			default:
				printf("\t\t\t��ѯ������������ȷ�Ĳ�ѯ��ʽ");
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
			for(i=0;i<k;i++)
			{
				printf("\n");
				printf("\t\t\t\t\t ӰƬ���:%d \n",f[i].num);
				printf("\t\t\t\t\t ӰƬ����:%s \n",f[i].name);
				printf("\t\t\t\t\t ӰƬ����:%s \n",f[i].actor);
				printf("\t\t\t\t\t ӰƬ����:%s \n",f[i].direct);
				printf("\t\t\t\t\t ӰƬ����:%s \n",f[i].area);
				printf("\t\t\t\t\t ��ӳʱ��:%s \n",f[i].date);
				printf("\t\t\t\t\t ӰƬ����:%s \n",f[i].type);
				printf("\t\t\t\t\t ӰƬ���:%s \n",f[i].norms);
				printf("\t\t\t\t\t ӰƬ����:%f \n",f[i].score);
			}
			printf("\t\t\t����Ϊ������ѯ�����ݣ�\n");
		}
		printf("\t\t\t���Ƿ�Ҫ�������ң�������yes��no! \t");
		scanf("\t\t\t%s",c);
	}while(strcmp(c,"yes")==0);//�жϽ���
}


//�޸�ӰƬ��Ϣ

void Change()
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
			printf("\t\t\t\t\t 1.ӰƬ���\n");
			printf("\t\t\t\t\t 2.ӰƬ����\n");
			printf("\t\t\t\t\t 3.ӰƬ����\n");
			printf("\t\t\t\t\t 4.ӰƬ����\n");
			printf("\t\t\t\t\t 5.ӰƬ����\n");
			printf("\t\t\t\t\t 6.��ӳʱ��\n");
			printf("\t\t\t\t\t 7.ӰƬ����\n");
			printf("\t\t\t\t\t 8.ӰƬ���\n");
			printf("\t\t\t\t\t 9.ӰƬ����\n");
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
			//savedata();
			printf("\t\t\t  ӰƬ��Ϣ�޸ĳɹ���");
			break;
		}
	}
}


//ɾ��ӰƬ��Ϣ

void Del()
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
		//savedata();
    }
}


//ͳ��ӰƬ����

void Length()
{
	int count=0;
	struct Film *p=film->next;
	while(p)
	{
		p=p->next;
		++count;
	}
	printf("\n\n\t\t\t  ӰƬ����Ϊ��%d",count);
}


//�鿴����ӰƬ��Ϣ

void  Printall()
{
	printf("\n\n\t\t\t ********�鿴����ӰƬ��Ϣ********		\n");
	struct Film *p=film->next;
	if(p)
	{
		printf("\t=================================================================================================================================================\n");
		printf("\tӰƬ���  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ӰƬ����  \t ��ӳʱ��\tӰƬ����\tӰƬ���\tӰƬ���� \n ");
		while(p)
		{
			printf("\n");
			printf("\t %6d %16s %16s %16s %12s  %12s %16s  %12s       %8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
			p=p->next;
		}
		printf("\t=================================================================================================================================================\n");
	}
	else
		printf("\n\t\t\t  Ŀǰ����ӰƬ��Ϣ��");
}


/*===================================================�����溯��=========================================*/ 

//ע���½����

void menu()        
{
	int choice;
	printf("\n\n\n\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|             *****  WELCOME  *****                  |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|               1.ע�����û�                         |\n");
	printf("\t\t\t|               2.��½�˻�                           |\n");
	printf("\t\t\t|               3.�˳�                               |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\n\n\t\t\t����1-3֮�����ѡ������Ҫ�Ĺ���:");
	while((scanf("%d",&choice)) != EOF){
		switch(choice)
		{
			case 1:
				registered();
			case 2:
				landing();
			case 3:
				break;
			default:
				{
					printf("\n\t\t\t Sorry! �������������������ȷ���!");
					menu(); 
				}
				break;
		}
	}
	
} 


//ӰԺ����ϵͳ���ܽ��� 

void menu1()     
{
	int choice1;
	while(1)
	{
		printf("\n\n\n\t\t\t------------------------------------------------------\n");
		printf("\t\t\t|     ***** ����,��ӭʹ��ӰƬ��Ϣ����ϵͳ! *****     |\n");
		printf("\t\t\t------------------------------------------------------\n");
		printf("\t\t\t|           1.¼��ӰƬ��Ϣ                           |\n");
		printf("\t\t\t|           2.����ӰƬ��Ϣ                           |\n");
		printf("\t\t\t|           3.�޸�ӰƬ��Ϣ                           |\n");
		printf("\t\t\t|           4.ɾ��ӰƬ��Ϣ                           |\n");
		printf("\t\t\t|           5.�鿴ӰƬ����                           |\n");
		printf("\t\t\t|           6.�鿴ӰƬ��Ϣ                           |\n");
		printf("\t\t\t|           7.�˳�ϵͳ                               |\n"); 
		printf("\t\t\t------------------------------------------------------\n");
		printf("\n\n\t\t\t����1-7֮�����ѡ������Ҫ�Ĺ���:");
		scanf("%d",&choice1);
		if(choice1==7)	exit(0);
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
		}
	}	
}


/*===================================================�û����ֺ���=========================================*/


void registered()
{
    char temp[20];
    char user[20];
    FILE *fp;
    do
    {
        printf("\n\t\t\t �û�ע��\n");
        printf("\t\t\t �����������û���:");
        scanf("%s",user);
        fp=fopen("user.txt","r+");				//�ж��û����Ƿ��ظ�
        if(strcmp(user,save.user)==0)
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
    fp=fopen("user.txt","w");
    if(fp==NULL)
       {
          printf("\n\t\t\t Sorry! ע��ʧ��!\n");
          exit(0);
       }
    else
    {
        system("cls");
        printf("\n\t\t\t ע��ɹ�!");
        fprintf(fp,"%s %s\n",save.user,save.code); 
		fclose(fp);
    }
}


//д���û���Ϣ
void write()
{
	FILE *fp;
	fp=fopen("user.txt","a");
    if(fwrite(&save,sizeof(User),1,fp)!=1)
    {
        printf("\n\t\t\t Sorry!д���ļ�����!");
        exit(0);
    }
    else	fprintf(fp,"%s %s\n",save.user,save.code);
    fclose(fp);
}

//��½����

void landing()
{
    char u[20],c[20],temp;      		//�����������飬��ż���������û���������
    printf("\n\t\t\t\t �û���¼");
    printf("\n\t\t\t �������û���:");
    scanf("%s",u);
    //�ж��û����Ƿ����
    FILE * fp=fopen("user.txt","r");
    temp='0';
    if(fp==NULL)
    {
        printf("\n\t\t\t Sorry! �û�������,��ע��!");
        printf("\n\t\t\t	1.ע��\n2.���µ�½");
        temp=getchar();
        if(temp=='1')
        {
            system("cls");
            registered();
        }
        else return landing();
    }
    //��֤�����Ƿ���ȷ
    do
    {
        if(1) fread(&save,sizeof(User),1,fp);

 		//��ȡ�û���Ϣ�����û���������
        printf("\t\t\t ��������������:");
        scanf("%s",c);
        if(strcmp(save.code,c)!=0)                      //�Ա����������Ͷ�ȡ������
        {
            printf("\n\t\t\t Sorry! �������(1.�˳� 2.��������)!");
            temp=getchar();
            printf("\n");
            if(temp=='1')
            {
                fclose(fp);                           //�ر��ļ���ֹ�������
            	break;
            }
        }
        if(strcmp(save.code,c)==0)
            return menu1();
    }while(temp=='2');
    printf("\n");

}




/*-------------------------------------------------------------------------------������--------------------------------------------------------------------------------------------*/ 


int main()
{
	film->next=NULL;
	film->num=0;
    readdata();
	menu1();		
}




