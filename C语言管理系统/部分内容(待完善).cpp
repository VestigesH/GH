#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Film 					//影片结构体 
{
	int num;					//电影编号 
	char name[20];				//电影名称 
	char actor[30]; 			//主演 
	char direct[10];			//导演 
	char area[10];				//地区 
	char date[10];				//上映时间 
	char type[10];				//电影类型 
	char norms[10];				//电影规格 
	float score;				//电影评分 	
	struct Film *next;
}film[1000],f[1000];

	int m=0;					//全局变量，记录影片数目 

/*---------------------------------------------------------------------函数定义-------------------------------------------------------------------------------------------*/

//录入影片信息

void Add(struct Film *film)
{
	int num;
	struct Film *p,*q;
	struct Film *head=NULL;
	q=head;
	p=(struct Film *)malloc(sizeof(struct Film));
	p->num=num;
	printf("\t%d","请输入影片编号:\t");
	scanf("%d",&p->num);
	printf("\t%s","请输入影片名称:\t");
	scanf("%s",&p->name);
	printf("\t%s","请输入影片主演:\t");
	scanf("%s",&p->actor);
	printf("\t%s","请输入影片导演:\t");
	scanf("%s",&p->direct);
	printf("\t%s","请输入影片地区:\t");
	scanf("%s",&p->area);
	printf("\t%s","请输入上映时间:\t");
	scanf("%s",&p->date);
	printf("\t%s","请输入影片类型:\t");
	scanf("%s",&p->type);
	printf("\t%s","请输入影片规格:\t");
	scanf("%s",&p->norms);
	printf("\t%f","请输入影片评分:\t");
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

//读取影片信息

int read(struct Film *p)
{
	FILE *fa,*fb;
	int i;
	if((fa=fopen("Film.dat","rb"))==NULL);			//打开文件，判断是否出错
	{
		printf("没有影片信息！请先录入影片信息");	//出错提醒 
		getchar();
		return -1;	
	}
	if((fb=fopen("film.dat","rb"))==NULL);			//打开文件，判断是否出错
	{
		printf("创建文件失败！\n\n");				//出错提醒 
		getchar();
		return -1;	
	} 
	fscanf(fb,"%d",&m);								//获取文件中影片信息的记录数 
	fclose(fb);
		if(m==0)
		{
			printf("没有影片信息！请先输入影片信息\n");
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

// 查询影片信息

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
		printf("\t**************查找影片途径**************\n");
		printf("\t|  请输入下列方式前的序号进行选择      |\n");
		printf("\t|      1.影片编号                      |\n");
		printf("\t|      2.影片名称                      |\n");
		printf("\t|      3.影片主演                      |\n");
		printf("\t|      4.影片导演                      |\n");
		printf("\t|      5.影片地区                      |\n");
		printf("\t|      6.上映时间                      |\n");
		printf("\t|      7.影片类型                      |\n");
		printf("\t|      8.影片规格                      |\n");
		printf("\t|      9.影片评分		       |\n");
		printf("\t|      0.退出查询		       |\n");
		printf("\t---------------------------------------\n");
		printf("您的选择是:");
		scanf("%d",&choice);
		if(choice==0)
			break;
		switch (choice)
		{
			case 1:											//按照编号查询 
				{
					printf("请输入影片编号:\n");
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
			case 2:											//按照名称查询 
				{
					printf("请输入影片名称:\n");
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
			case 3:											//按照主演查询 
				{
					printf("请输入影片主演:\n");
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
			case 4:											//按照导演查询 
				{
					printf("请输入影片导演:\n");
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
			case 5:											//按照地区查询 
				{
					printf("请输入影片地区(1.华语 2.香港 3.美国 4.欧洲 5.韩国 6.日本 7.印度 8.其他):\n");
					scanf("%d",&film_area);
					switch(film_area)
					{
						case 1:
							{
								strcpy(area,"华语"); 
							}
							break;
						case 2:
							{
								strcpy(area,"香港"); 
							}
							break;
						case 3:
							{
								strcpy(area,"美国"); 
							}
							break;
						case 4:
							{
								strcpy(area,"欧洲"); 
							}
							break;
						case 5:
							{
								strcpy(area,"韩国"); 
							}
							break;
						case 6:
							{
								strcpy(area,"日本"); 
							}
							break;
						case 7:
							{
								strcpy(area,"印度"); 
							}
							break;
						case 8:
							{
								strcpy(area,"其他"); 
							}
							break; 
						default:
							{
								printf("查询失败！请输入正确序号进行查询！");
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
			case 6:											//按照时间查询 
				{
					printf("请输入上映时间:\n");
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
			case 7:											//按照类型查询 
				{
					printf("请输入影片类型(1.喜剧 2.爱情 3.动作 4.枪战 5.犯罪 6. 惊悚 7.悬疑 8.家庭 9.青春 10.其他):\n");
					scanf("%d",&film_type);
					switch(film_type)
					{
						case 1:
							{
								strcpy(type,"喜剧");
							}
							break;
						case 2:
							{
								strcpy(type,"爱情");
							}
							break;
						case 3:
							{
								strcpy(type,"动作");
							}
							break;
						case 4:
							{
								strcpy(type,"枪战");
							}
							break;
						case 5:
							{
								strcpy(type,"犯罪");
							}
							break;
						case 6:
							{
								strcpy(type,"惊悚");
							}
						case 7:
							{
								strcpy(type,"悬疑");
							}
							break;
						case 8:
							{
								strcpy(type,"家庭");
							}
							break;
						case 9:
							{
								strcpy(type,"青春");
							}
							break;
						case 10:
							{
								strcpy(type,"其他");
							}
							break;
						default:
							{
								printf("查询失败！请输入正确序号进行查询！");
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
			case 8:											//按照规格查询  
				{
					printf("请输入影片规格(1.巨制 2.院线 3.杜比音效 4.经典 5.独播 ):\n");
					scanf("%d",&film_norms);
					switch(film_norms)
					{
						case 1:
							{
								strcpy(norms,"巨制");
							}
							break;
						case 2:
							{
								strcpy(norms,"院线");
							}
							break;
						case 3:
							{
								strcpy(norms,"杜比音效");
							}
							break;
						case 4:
							{
								strcpy(norms,"经典");
							}
							break;
						case 5:
							{
								strcpy(norms,"独播");
							}
							break;
						default:
							{
								printf("查询失败！请输入正确序号进行查询！");
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
			case 9:											//按照评分查询 
				{
					printf("请输入影片评分:\n");
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
			default: printf("查询错误！请输入正确的查询方式"); 
		}
		if(k==0)
		{
			printf("====================================================================================================================\n");
			printf("\n 没有您所要查找的内容！\n");
			printf("====================================================================================================================\n");
		}
		else
		{
			printf("====================================================================================================================\n");
			printf("影片编号：\t 影片名称：\t 影片主演：\t 影片片导演：\t 影片地区：\t 上映时间：\t 影片类型：\t 影片规格：\t 影片评分：\n ");
			for(i=0;i<k;i++)
			{
				printf("%8d %16s %16s %16s %16s %16s %16s %16s %8f\n",f[i].num,f[i].name,f[i].actor,f[i].direct,f[i].area,f[i].date,f[i].type,f[i].norms,f[i].score);
			}
			printf("====================================================================================================================\n");
			printf("\n以上为查询内容！\n");
		}
		printf("您是否要继续查找？请输入yes 或no 以回车键结束\n");
		scanf("%s",c);
	}while(strcmp(c,"yes")==0);//判断结束 
}
void printFilm(struct Film *film)//将查询结果打印出来 
{
	if(!film) printf("\t未查询到该影片信息，请重新输入.");
	else 
	{
		printf("----------------------------------------------------------------------------"); 
		printf("|   编号    名称    主演    导演    地区   上映时间   类型    规格    评分  |");
		printf("%d\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %d\t",film->num,film->name,film->actor,film->direct,film->area,film->date,film->type,film->norms,film->score);
	} 
}

//修改影片信息

void Change(struct Film *film) 
{
	 
	struct Film *p;
	struct Film *head=NULL;
	p=(struct Film *)malloc(sizeof(struct Film));							//编号查找，保存在p中
	int num;
	printf("请输入编号：");
	scanf("%d",&num);								 
	if(p)
	{
		printf("\t		********修改影片信息********		\n");
		printf("\t 该影片的信息如下：\n");
		printFilm(p);
		printf("\t%s","请输入新的影片名称:\t");
		scanf("%s",p->name);
		printf("\t%s","请输入新的影片主演:\t");
		scanf("%s",p->actor);
		printf("\t%s","请输入新的影片导演:\t");
		scanf("%s",p->direct);
		printf("\t%s","请输入新的影片地区:\t");
		scanf("%s",p->area);
		printf("\t%s","请输入新的上映时间:\t");
		scanf("%s",p->date);
		printf("\t%s","请输入新的影片类型:\t");
		scanf("%s",p->type);
		printf("\t%s","请输入新的影片规格:\t");
		scanf("%s",p->norms);
		printf("\t%f","请输入新的影片评分:\t");
		scanf("%f",&p->score);
	}
	else printf("\t未查询到该影片信息，请重新输入.\n");
}

//删除影片信息

void Del(struct Film *film)
{
	int num;
	struct Film *p,*q;
	struct Film *head=NULL;
	p=head;						
	if((head)->num==num)							//删除头结点的情况 
	{
		head=(head)->next;
		free(p);
	}
	else 										//不是头结点的情况 
	{
		while(p)								//遍历链表寻找要删除的结点 
		{
			if(p->num==num)
			{
				q->next=p->next;
				free(p);
				break;
			} 
			q=p;								//*q为p的前驱结点 
			p=p->next;
		}
	}
} 

//统计影片总数

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
 
//查看所有影片信息

void  printall(struct Film *head)
{
	Film *p=head;
	if(p)
	{
		printf("----------------------------------------------------------------------------");
		printf("|   编号    名称    主演    导演    地区   上映时间   类型    规格    评分  |");
		while(p)
		{
			printf("%d\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %d\t",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
			p=p->next;	
		}
	}
}

//主界面函数 

void menu()
{
	int x;
	printf("\t*************您好，欢迎使用影片管理系统!*************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t|           1.录入影片信息                           |\n");
	printf("\t|	    2.查找影片信息	                     |\n");
	printf("\t|           3.修改影片信息		             |\n");
	printf("\t|           4.删除影片信息		             |\n");
	printf("\t|           5.查看影片总数	                     |\n");
	printf("\t|           6.查看影片信息		             |\n");
	printf("\t|           7.退出系统                               |\n"); 
	printf("\t-------------------------------------------------------\n");
	printf("\t请在1-7之间进行选择您需要的功能，若要结束使用请按回车键\n");
}
 
//登陆界面函数
 
/*-------------------------------------------------------------------------------主函数--------------------------------------------------------------------------------------------*/ 
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

 
