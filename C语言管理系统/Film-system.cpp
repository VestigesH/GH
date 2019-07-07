#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define Savepath "./Savedata.txt"   //数据存储路径

/* 
影片信息管理系统功能 :
			(1).录入影片信息 
			(2).查询影片信息 
			(3).打印影片信息
			(4).修改影片信息 
			(5).删除影片信息 
			(6).统计影片总数
			(7).影片信息排序 
			(8).查看所有影片信息
*/ 

//函数调用 

//1.功能函数 
void Add(); 				// 录入 
void Change();				//修改 
void Del();					//删除 
void Search();				//查找 
void landing();				//登陆 
void registered();			//注册 
void Length();				//影片数量  
void printall();			//打印影片信息 
void savedata();            //保存影片信息
void Sort();                //排序 
void Usortnum();            //影片编号升序
void Dsortnum();            //影片编号降序
void Usortname();           //影片名称升序
void Dsortname();           //影片名称降序
void Usortdate();           //上映时间升序
void Dsortdate();           //上映时间降序
void Usortscore();          //影片评分升序
void Dsortscore();          //影片评分降序 
 
//2.界面函数 
void menu(); 				//登陆注册界面 
void Menu();				//影片信息管理系统功能界面


struct Film 				//影片信息结构体 :电影编号、电影名称 、主演、 导演 、地区、 上映时间 、电影类型 、电影规格 、电影评分
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
struct Film *const film=(struct Film *)malloc(sizeof(struct Film));//全局链表，带头结点，头指针film被const限定，不可修改；


struct User					   //用户结构体
{
    char user[20];
    char code[20];
}save; 						


/*---------------------------------------------------------------------函数部分-------------------------------------------------------------------------------------------*/

/*=========================================读写文件信息函数==========================================*/

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
			printf("分配内存失败");
			exit(1);
		}
		fscanf(fp,"%d %s %s %s %s %d %s %s %f\n",&p->num,p->name,p->actor,p->direct,p->area,&p->date,p->type,p->norms,&p->score);
		if(feof(fp)) 
			break;
		p->next = film->next;//头插法
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
	printf("\n\t\t\t\t\t\t\t成功写入文件！"); 
}


/*=========================================影片信息函数==========================================*/

//1.录入影片信息
void Add()
{
	system("cls");
	int n=0;					       //录入新影片数 
	char A[3];
	printf("\n");
	printf("\n\t\t\t\t\t\t\t**************录入新影片**************\n");
	printf("\n");
	printf("\n");
	FILE *fp = fopen(Savepath,"a+");//以追加模式写入文件
	if(fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Sorry! 文件打开失败!\n");
        exit(1);
    }
    do
	{
		struct Film *p = (struct Film*)malloc(sizeof(struct Film));
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片编号:");
   		scanf("%d",&p->num);
   		printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片名称:");
    	scanf("%s",p->name);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片主演:");
    	scanf("%s",p->actor);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片导演:");
    	scanf("%s",p->direct);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片地区:");
    	scanf("%s",p->area);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的上映时间:");
    	scanf("%d",&p->date);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片类型:");
    	scanf("%s",p->type);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片规格:");
    	scanf("%s",p->norms);
    	printf("\n");
    	printf("\t\t\t\t\t\t\t 请输入要录入的影片评分:");
    	scanf("%f",&p->score);
    	p->next = film->next;
    	film->next = p;
    	fprintf(fp,"%d %s %s %s %s %d %s %s %f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		printf("\n");
		n++; 
		printf("\n\t\t\t\t\t\t\t Congractulations! 成功录入第%d个新影片!",n);
		printf("\n");
		printf("\n\t\t\t\t\t\t\t是否继续录入影片信息？请输入yes or no ?\t");
		scanf("\n\t\t\t\t\t\t\t%s",&A);
		system("cls");
	}while(strcmp(A,"yes") == 0);
	
	fclose(fp);
}


// 2.查询影片信息 
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
		printf("\n\n\n\t\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃             *****查找影片途径****                  ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┠────────────────────────────────────────────────────┨\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃           请输入下列方式前的序号进行选择           ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   1.影片编号                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   2.影片名称                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   3.影片主演                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   4.影片导演                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   5.影片地区                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   6.上映时间                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   7.影片类型                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   8.影片规格                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   9.影片评分                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                   0.退出查询                       ┃\n");
		printf("\t\t\t\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\t\t\t\t\t\t\t您的选择是:");
		scanf("%d",&choice);
		system("cls");
		if(choice == 0)
			break;
		switch (choice)
		{
			case 1:											//按照编号查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片编号:");  
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
			case 2:											//按照名称查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片名称:");
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
			case 3:											//按照主演查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片主演:");
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
			case 4:											//按照导演查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片导演:");
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
			case 5:											//按照地区查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片地区:");
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
			case 6:											//按照时间查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片上映时间:");
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
			case 7:											//按照类型查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片类型:");
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
			case 8:											//按照规格查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片规格:");
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
			case 9:											//按照评分查询
				{
					printf("\t\t\t\t\t\t\t请输入要查询的影片评分:");
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
			printf("\t\t\t\t\t\t  	   Sorry! 没有您所要查找的内容！\n");
			printf("\t\t======================================================================================================================\n");
		}
		else
		{
			system("cls");
			for(i=0;i<k;i++)
			{
				printf("\n");
				printf("\t\t\t\t\t\t\t 影片编号:%d \n",f[i].num);
				printf("\t\t\t\t\t\t\t 影片名称:%s \n",f[i].name);
				printf("\t\t\t\t\t\t\t 影片主演:%s \n",f[i].actor);
				printf("\t\t\t\t\t\t\t 影片导演:%s \n",f[i].direct);
				printf("\t\t\t\t\t\t\t 影片地区:%s \n",f[i].area);
				printf("\t\t\t\t\t\t\t 上映时间:%d \n",f[i].date);
				printf("\t\t\t\t\t\t\t 影片类型:%s \n",f[i].type);
				printf("\t\t\t\t\t\t\t 影片规格:%s \n",f[i].norms);
				printf("\t\t\t\t\t\t\t 影片评分:%4.1f \n",f[i].score);
			}
			printf("\n");
			printf("\t\t\t\t\t\t\t以上为您所查询的内容！\n");
		}
		printf("\n");
		printf("\t\t\t\t\t\t\t您是否要继续查找？请输入yes或no! \t");
		scanf("\t\t\t\t\t\t\t%s",c);
	}while(strcmp(c,"yes")==0);
}


//3.修改影片信息
void Change()
{
	system("cls");
	int flag=1,choice;
	char name1[20];
	char A[3];
	struct Film *pc = film->next;
	printf("\t\t\t\t\t\t\t 请输入需修改的影片名称:");
	scanf("%s",&name1);
	printf("\t\t\t\t\t\t\t		********修改影片信息********		\n");
	do
	{
		if(pc == NULL)
		{
			printf("\t\t\t Sorry! 未查询到该影片信息!\n");
			break;
		}
		if(strcmp(name1,pc->name) != 0)
			pc = pc->next;
		else if(strcmp(name1,pc->name) == 0)
		{
			printf("\n");
			printf("\t\t\t\t\t\t\t 1.影片编号\n");
			printf("\t\t\t\t\t\t\t 2.影片名称\n");
			printf("\t\t\t\t\t\t\t 3.影片主演\n");
			printf("\t\t\t\t\t\t\t 4.影片导演\n");
			printf("\t\t\t\t\t\t\t 5.影片地区\n");
			printf("\t\t\t\t\t\t\t 6.上映时间\n");
			printf("\t\t\t\t\t\t\t 7.影片类型\n");
			printf("\t\t\t\t\t\t\t 8.影片规格\n");
			printf("\t\t\t\t\t\t\t 9.影片评分\n");
			printf("\t\t\t\t\t\t\t 请输入您所要修改的选项:");
			scanf("%d",&choice);
			pc = pc->next;
			switch(choice)
			{
				case 1:
					printf("\t\t\t\t\t\t\t 请输入新的影片编号:");
					scanf("%d",&pc->num);
					break;
				case 2:
					printf("\t\t\t\t\t\t\t 请输入新的影片名称:");
					scanf("%s",pc->name);
					break;
				case 3:
					printf("\t\t\t\t\t\t\t 请输入新的影片主演:");
					scanf("%s",pc->actor);
					break;
				case 4:
					printf("\t\t\t\t\t\t\t 请输入新的影片导演:");
					scanf("%s",pc->direct);
					break;
				case 5:
					printf("\t\t\t\t\t\t\t 请输入新的影片地区:");
					scanf("%s",pc->area);
					break;
				case 6:
					printf("\t\t\t\t\t\t\t 请输入新的上映时间:");
					scanf("%d",&pc->date);
					break;
				case 7:
					printf("\t\t\t\t\t\t\t 请输入新的影片类型:");
					scanf("%s",pc->type);
					break;
				case 8:
					printf("\t\t\t\t\t\t\t 请输入新的影片规格:");
					scanf("%s",pc->norms);
					break;
				case 9:
					printf("\t\t\t\t\t\t\t 请输入新的影片评分:");
					scanf("%f",&pc->score);
					break;
			}
		}
		printf("\n\t\t\t\t\t\t\t是否继续修改影片信息？请输入yes or no ?\t");
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
	printf("\t\t\t\t\t\t\t  影片信息修改成功！");
}

 
// 4.删除影片信息
void Del()
{
	system("cls");
	char name1[20];
	printf("\n\n\t\t\t\t\t\t\t		********删除影片信息********		\n");
	struct Film *p = film->next;
	struct Film *q = film;
	printf("\t\t\t\t\t\t\t 请输入要删除的影片名称:");
	scanf("%s",&name1);
	while(1)
	{
		if(p == NULL)
		{
			printf("\n\n\t\t\t\t\t\t\t  没有此影片的信息！\n");
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
			printf("\n\n\t\t\t\t\t\t\t 删除成功!\n");
			break;
		}
		savedata(film);
	}
}


// 5.统计影片总数
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
	printf("\n\n\t\t\t\t\t\t\t  影片总数为；%d",count);
}


// 6.查看所有影片信息
void  Printall()
{
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t ********查看所有影片信息********		\n");
	struct Film *p = film->next;
	if(p)
	{
		printf("\t=================================================================================================================================================\n");
		printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");
		while(p)
		{
			printf("\n");
			printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
			p = p->next;
		}
		printf("\t=================================================================================================================================================\n");
	}
	else
		printf("\n\t\t\t\t\t\t\t  目前暂无影片信息！");
}


// 7.影片信息排序  
void Sort()
{
	system("cls");
	struct Film *p = film->next;
	struct Film *p1,*p2 ;
	struct Film f;
	p2 = film;
	int choice; 
		printf("\n\n\n\t\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");	
	printf("\t\t\t\t\t\t\t┃                 *****影片排序输出*****             ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┠────────────────────────────────────────────────────┨\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃            请输入下列方式前的序号进行选择          ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   1.影片编号升序                   ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   2.影片编号降序                   ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   3.影片名称升序                   ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   4.影片名称降序                   ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   5.上映时间升序                   ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   6.上映时间降序                   ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   7.影片评分升序                   ┃\n");
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   8.影片评分降序                   ┃\n"); 
	printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
	printf("\t\t\t\t\t\t\t┃                   0.退出查看排序                   ┃\n");
	printf("\t\t\t\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n\t\t\t\t\t\t\t您的选择是:");
	scanf("%d",&choice);
	if(p2 == NULL)
	{
		printf("\n\t\t\t\t\t\t\tSorry! 暂时无影片信息，无法排序!"); 
		return;
	}
	switch(choice)
	{
		case 1: 
			Usortnum();//影片编号升序 
			break;
		case 2: 
			Dsortnum();//影片编号降序
			break;
		case 3:
			Usortname();//影片名称升序 
			break;
		case 4:
			Dsortname();//影片名称降序 
			break;
		case 5:
			Usortdate();//上映时间升序 
			break;
		case 6:
			Dsortdate();//上映时间降序 
			break;
		case 7: 
			Usortscore();//影片评分升序
			break;
		case 8:
			Dsortscore();//影片评分降序 
			break;
		default:
			exit(1); 
	}														
}

void Usortnum()            //影片编号升序
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************影片编号升序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Dsortnum()            //影片编号降序
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************影片编号降序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Usortname()           //影片名称升序
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************影片名称升序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Dsortname()           //影片名称降序
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************影片名称降序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Usortdate()           //上映时间升序
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************上映时间升序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");

}
void Dsortdate()           //上映时间降序
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************上映时间降序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Usortscore()          //影片评分升序
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************影片评分升序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}
void Dsortscore()          //影片评分降序 
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
	printf("\n\t\t\t\t\t\t\t 成功排序!");	
	printf("\n\\t\t\t\t\t\t\t**************影片评分降序输出**************\n");
	printf("\t=================================================================================================================================================\n");
	printf("\t影片编号  \t 影片名称  \t 影片主演  \t 影片导演  \t 影片地区  \t 上映时间 \t影片类型  \t影片规格  \t影片评分 \n ");	
	while(p)
	{
		printf("\n");
		printf("\t %6d %16s %16s %16s %12s %12d %16s %12s \t\t%8.1f\n",p->num,p->name,p->actor,p->direct,p->area,p->date,p->type,p->norms,p->score);
		p = p->next;
	}
	printf("\t=================================================================================================================================================\n");
}




/*===================================================主界面函数=========================================*/ 


//1.注册登陆界面
void menu()        
{
	system("cls");
	int choice = 0;
	while(choice != 3)
	{
		printf("\n\n\n\t\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃               *****    WELCOME    *****            ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┠────────────────────────────────────────────────────┨\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                 ①. 注册新用户                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                 ②. 登陆账户                       ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                 ③. 退出                           ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\t\t\t\t\t\t\t请在1-3之间进行选择您需要的功能:");
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
					printf("\n\t\t\t\t\t\t\t Sorry! 输入错误，请重新输入正确序号!");
					menu(); 
				}
				break;
		}
	}
} 


//2.影院管理系统功能界面 
void Menu()     
{
	system("cls");
	int choice1;
	do
	{
		printf("\n\n\n\t\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃     ***** 您好,欢迎使用影片信息管理系统! *****     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┠────────────────────────────────────────────────────┨\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ①.录入影片信息                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ②.查找影片信息                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ③.修改影片信息                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ④.删除影片信息                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ⑤.查看影片总数                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ⑥.查看影片信息                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ⑦.影片排序输出                     ┃\n");
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┃                ⑧.退出系统                         ┃\n"); 
		printf("\t\t\t\t\t\t\t┃                                                    ┃\n");
		printf("\t\t\t\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n\n\t\t\t\t\t\t\t请在1-7之间进行选择您需要的功能:");
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



/*===================================================用户部分函数=========================================*/


//1.注册函数 
void registered()													
{
    char temp[20];
    char user[20];
    FILE *User;
    do
    {
    	system("cls");
        printf("\n\t\t\t\t\t\t\t 用户注册\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t 请输入您的用户名:");
        scanf("%s",user);
        User=fopen("user.txt","r");
		fscanf(User,"%s %s",save.user,save.code);			       
        if(strcmp(user,save.user)==0)                       		  //判断用户名是否重复
        {
        	printf("\n");
        	printf("\n\t\t\t\t\t\t\t Sorry! 该用户名已存在!");
        	printf("\n\t\t\t\t\t\t\t 是否继续注册?(Y/N)");
        	if(getchar()=='Y')
				registered();
        	else	break;
        }
        else
        {
        	strcpy(save.user, user);
        	printf("\n\t\t\t\t\t\t\t 请输入您的密码:");				//确认两次密码输入是否一致
        	scanf("%s",save.code);
        	printf("\n\t\t\t\t\t\t\t 请再次输入确认密码:"); 
        	scanf("%s",temp);
        	if(strcmp(save.code,temp)!=0)
        	printf("\n\\t\t\t\t\t\t\t Sorry! 两次密码不一致,请重新输入");
        	else
        	{
        		fprintf(User,"%s",save.code);
        		printf("\n\t\t\t\t\t\t\t 注册成功!"); 
			}			
		} 
		fclose(User);
    }while(strcmp(save.code,temp)!=0);
    //用户名密码无误，写入文档储存用户信息
    User=fopen("user.txt","a+");
    if(User==NULL)
    {
	    printf("\n\t\t\t\t\t\t\t Sorry! 注册失败!\n");
	    exit(0);
    }
    else
    {
        fprintf(User,"%s %s\n",save.user,save.code); 
		fclose(User);
    }
}


//2.登陆函数
void landing()
{
	system("cls");
    char username[20];
	char code[20];
	char temp; 
	int flag=0;     		
    printf("\n\t\t\t\t\t\t\t 用户登录");
    printf("\n");
    printf("\n\t\t\t\t\t\t\t 请输入用户名:");
    scanf("%s",username);
    FILE *User=fopen("user.txt","r+");
    temp='0';
    fscanf(User,"%s %s",save.user,save.code);
    if(feof(User)) 
	{
    	printf("\n\t\t\t\t\t\t\t Sorry! 暂无用户信息!请注册!\n");
	    return registered();
	} 
	else 
	{
		do 
		{
			fscanf(User,"%s %s",save.user,save.code);
			if (strcmp(username, save.user) == 0) 
			{
				printf("\n\t\t\t\t\t\t\t 请输入密码：");
				scanf("%s",&code);
				if (strcmp(code, save.code) == 0) 
				{
					Sleep(1000);
					printf("\n\t\t\t\t\t\t\t 登陆成功！");  
					Menu();
				} else {
					printf("\n\t\t\t\t\t\t\t Sorry!密码错误!请重新登录!");
			    	landing();
				}
			}
		}while(!feof(User));
		printf("\t\t\t用户信息不存在！");
		printf("\t\t\t1.注册  \n\t\t\t2.重新登陆  \n\t\t\t3.退出");
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
		 		printf("\t\t\t输入错误,请正确选择您需要的功能！"); 
		 		break; 
			  
		}	 
	}
}


/*-------------------------------------------------------------------------------主函数--------------------------------------------------------------------------------------------*/ 


int main()
{
	film->next=NULL;
	film->num=0;
    readdata();
	menu();
}




