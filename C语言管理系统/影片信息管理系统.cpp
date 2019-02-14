#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define m 30 //影片数量最大容纳度 

struct Film 					//影片信息结构体 
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

struct User					//用户结构体 
{
    char user[20];
    char code[20];
}save; 							//save结构体用来保存用户名和密码 
	FILE *fp;
 

/*---------------------------------------------------------------------函数调用部分-------------------------------------------------------------------------------------------*/

/*=========================================影片信息函数==========================================*/ 
 
//录入影片信息

void Add(struct Film *film)
{
	printf("\n\t\t\t**************录入新影片**************\n"); 
	struct Film *p =(struct Film*)malloc(sizeof(struct Film));
	if(p)
	{
		p->next=film->next;
		film->next=p;
		printf("\t\t\t 请输入要录入的影片编号:");
		scanf("%d",&p->num);
		printf("\t\t\t 请输入要录入的影片名称:");
		scanf("%s",p->name);
		printf("\t\t\t 请输入要录入的影片主演:");
		scanf("%s",p->actor);
		printf("\t\t\t 请输入要录入的影片导演:");
		scanf("%s",p->direct);
		printf("\t\t\t 请输入要录入的影片地区:");
		scanf("%s",p->area);
		printf("\t\t\t 请输入要录入的上映时间:");
		scanf("%s",p->date);
		printf("\t\t\t 请输入要录入的影片类型:");
		scanf("%s",p->type);
		printf("\t\t\t 请输入要录入的影片规格:");
		scanf("%s",p->norms);
		printf("\t\t\t 请输入要录入的影片评分:");
		scanf("%f",&p->score); 
		printf("\t\t\t Congractulations! 成功录入新影片!");
	}
	else
	{
		printf("\t\t\t Sorry! 录入失败!\n"); 
	}
	getchar(); 
	getchar(); 
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
		printf("\n\t\t\t**************查找影片途径**************\n");
		printf("\t\t\t|  请输入下列方式前的序号进行选择      |\n");
		printf("\t\t\t|      1.影片编号                      |\n");
		printf("\t\t\t|      2.影片名称                      |\n");
		printf("\t\t\t|      3.影片主演                      |\n");
		printf("\t\t\t|      4.影片导演                      |\n");
		printf("\t\t\t|      5.影片地区                      |\n");
		printf("\t\t\t|      6.上映时间                      |\n");
		printf("\t\t\t|      7.影片类型                      |\n");
		printf("\t\t\t|      8.影片规格                      |\n");
		printf("\t\t\t|      9.影片评分		       |\n");
		printf("\t\t\t|      0.退出查询		       |\n");
		printf("\t\t\t----------------------------------------\n");
		printf("\n\t\t\t您的选择是:");
		scanf("%d",&choice);
		if(choice==0)
			break;
		switch (choice)
		{
			case 1:											//按照编号查询 
				{
					printf("\t\t\t请输入要查询的影片编号:");
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
					printf("\t\t\t请输入要查询的影片名称:");
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
					printf("\t\t\t请输入要查询的影片主演:");
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
					printf("\t\t\t请输入要查询的影片导演:");
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
					printf("\t\t\t请输入要查询的影片地区(1.华语 2.香港 3.美国 4.欧洲 5.韩国 6.日本 7.印度 8.其他):");
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
								printf("\t\t\t查询失败！请输入正确序号进行查询！");
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
					printf("\t\t\t请输入要查询的影片上映时间:");
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
					printf("\t\t\t请输入要查询的影片类型(1.喜剧 2.爱情 3.动作 4.枪战 5.犯罪 6. 惊悚 7.悬疑 8.家庭 9.青春 10.其他):");
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
								printf("\t\t\t查询失败！请输入正确序号进行查询！");
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
					printf("\t\t\t请输入要查询的影片规格(1.巨制 2.院线 3.杜比音效 4.经典 5.独播 ):");
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
								printf("\t\t\t查询失败！请输入正确序号进行查询！");
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
					printf("\t\t\t请输入要查询的影片评分:");
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
			default: printf("\t\t\t查询错误！请输入正确的查询方式"); 
		}
		if(k==0)
		{
			printf("======================================================================================================================\n");
			printf("\t\t\t\t  	   Sorry! 没有您所要查找的内容！\n");
			printf("======================================================================================================================\n");
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
			printf("\t\t\t以上为查询内容！\n");
		}
		printf("\t\t\t您是否要继续查找？请输入yes或no! \t");
		scanf("\t\t\t%s",c);
	}while(strcmp(c,"yes")==0);//判断结束 
}

//打印影片信息 
void printFilm(struct Film *film)
{
	if(!film) 
	{
		printf("\t\t\t未查询到该影片信息，请重新输入.");
	}
	else 
	{
		printf("\t----------------------------------------------------------------------------\n"); 
		printf("\t|   编号    名称    主演    导演    地区   上映时间   类型    规格    评分  |\n");
		printf("%d\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %d\t",film->num,film->name,film->actor,film->direct,film->area,film->date,film->type,film->norms,film->score);
	} 
}

//修改影片信息

void Change(struct Film *film) 
{
	char name1[20];
	int choice;
	struct Film *pc=film->next;
	printf("\t\t\t 请输入需修改的影片名称:");
	scanf("%s",&name1); 
	printf("\t\t\t		********修改影片信息********		\n");
	while(1)
	{
		if(pc==NULL)
		{
			printf("\t\t\t Sorry! 未查询到该影片信息!\n");
			break;
		}
		if(strcmp(name1,pc->name)!=0)
			pc=pc->next;
		else if(strcmp(name1,pc->name)==0)
		{
			printf("\n");
			printf("\t\t\t\t\t 1.影片编号");
			printf("\t\t\t\t\t 2.影片名称"); 
			printf("\t\t\t\t\t 3.影片主演"); 
			printf("\t\t\t\t\t 4.影片导演"); 
			printf("\t\t\t\t\t 5.影片地区"); 
			printf("\t\t\t\t\t 6.上映时间"); 
			printf("\t\t\t\t\t 7.影片类型"); 
			printf("\t\t\t\t\t 8.影片规格"); 
			printf("\t\t\t\t\t 9.影片评分"); 
			printf("\t\t\t 请输入您所要修改的选项:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("\t\t\t 请输入新的影片编号:");
					scanf("%s",pc->num);
					break;
				case 2:
					printf("\t\t\t 请输入新的影片名称:");
					scanf("%s",pc->name);
					break;					
				case 3:
					printf("\t\t\t 请输入新的影片主演:");
					scanf("%s",pc->actor);
					break;
				case 4:
					printf("\t\t\t 请输入新的影片导演:");
					scanf("%s",pc->direct);
					break;
				case 5:
					printf("\t\t\t 请输入新的影片地区:");
					scanf("%s",pc->area);
					break;
				case 6:
					printf("\t\t\t 请输入新的上映时间:");
					scanf("%s",pc->date);
					break;
				case 7:
					printf("\t\t\t 请输入新的影片类型:");
					scanf("%s",pc->type);
					break;
				case 8:
					printf("\t\t\t 请输入新的影片规格:");
					scanf("%s",pc->norms);
					break;
				case 9:
					printf("\t\t\t 请输入新的影片评分:");
					scanf("%f",&pc->score);
					break;				
			}
			printf("\t\t\t  影片信息修改成功！");
			break;
		}
	}
	getchar();
	getchar(); 
}	

//删除影片信息

void Del(struct Film *film)
{
	char name1[20];
	printf("\n\n\t\t\t		********删除影片信息********		\n");
	struct Film *p=film->next;
	struct Film *q=film;				
	printf("\t\t\t 请输入要删除的影片名称:");
	scanf("%s",&name1); 	
	while(1)
	{
		if(p==NULL)							
		{
			printf("\n\n\t\t\t  没有此影片的信息！\n"); 
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
			printf("\n\n\t\t\t 删除成功!\n");
			break; 
		}
    }
    getchar();
    getchar();
} 

//统计影片总数

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
	printf("\n\n\t\t\t  影片总数为；%d",count);
} 
 
//查看所有影片信息

void  Printall(struct Film *film)
{
	printf("\n\n\t\t\t ********查看所有影片信息********		\n");
	struct Film *p=film->next;
	if(p)
	{
		while(p)
		{
			printf("\n");
			printf("\t\t\t\t\t 影片编号:%d \n",p->num);
			printf("\t\t\t\t\t 影片名称:%s \n",p->name); 
			printf("\t\t\t\t\t 影片主演:%s \n",p->actor); 
			printf("\t\t\t\t\t 影片导演:%s \n",p->direct); 
			printf("\t\t\t\t\t 影片地区:%s \n",p->area); 
			printf("\t\t\t\t\t 上映时间:%s \n",p->date); 
			printf("\t\t\t\t\t 影片类型:%s \n",p->type); 
			printf("\t\t\t\t\t 影片规格:%s \n",p->norms); 
			printf("\t\t\t\t\t 影片评分:%f \n",p->score); 
			p=p->next;	
		}
	}
	else
		printf("\n\t\t\t  目前暂无影片信息！");
	getchar();
	getchar();
}

/*===================================================主界面函数=========================================*/ 

void menu()
{
	int choice();
	printf("\n\n\n\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|      		*****  WELCOME  *****  		     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|               1.注册新用户                         |\n");
	printf("\t\t\t|	        2.登陆账户	                     |\n");
	printf("\t\t\t|               3.退出		                     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\n\n\t\t\t请在1-3之间进行选择您需要的功能:");
} 
void menu1()
{
	int choice1;
	printf("\n\n\n\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|     ***** 您好,欢迎使用影片信息管理系统! *****     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|           1.录入影片信息                           |\n");
	printf("\t\t\t|	    2.查找影片信息	                     |\n");
	printf("\t\t\t|           3.修改影片信息		             |\n");
	printf("\t\t\t|           4.删除影片信息		             |\n");
	printf("\t\t\t|           5.查看影片总数	                     |\n");
	printf("\t\t\t|           6.查看影片信息		             |\n");
	printf("\t\t\t|           7.退出系统                               |\n"); 
	printf("\t\t\t------------------------------------------------------\n");
	printf("\n\n\t\t\t请在1-7之间进行选择您需要的功能:");
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
 
/*===================================================用户部分函数=========================================*/
 
//注册函数

void registered()
{
    char temp[20];        
    do
    {
        printf("\n\t\t\t 用户注册\n");
        printf("\t\t\t 请输入您的用户名:");
        scanf("%s",save.user);
        fp=fopen(save.user,"r");					//判断用户名是否重复
        if(fp!=NULL) 
        {
           printf("\n\t\t\t Sorry! 该用户名已存在!");
           fclose(fp);
           printf("\n\t\t\t 是否继续注册?(Y/N)");
           if(getchar()=='Y') return registered();
           else break; 
        }
        printf("\n\t\t\t 请输入您的密码:");				//确认两次密码输入是否一致
        scanf("%s",save.code);
        printf("\n\t\t\t 请再次输入确认密码:");
        scanf("%s",temp);
        if(strcmp(save.code,temp)!=0)
        printf("\n\t\t\t Sorry! 两次密码不一致,请重新输入");
    }while(strcmp(save.code,temp)!=0);
    //用户名密码无误，写入文档储存用户信息
    fp=fopen(save.user,"w");
    if(fp==NULL)
       {
          printf("\n\t\t\t Sorry! 注册失败!\n");
          exit(0);
       }
    else 
    {
        system("cls");
        printf("\n\t\t\t 注册成功!");
        getchar();              
		fclose(fp);            						
    }
}
//写入用户信息
void write()
{
    if(fwrite(&save,sizeof(User),1,fp)!=1)
    {
        printf("\n\t\t\t Sorry!写入文件错误!");
        exit(0);                     
    }
}

//登陆函数

void landing()
{
    char u[20],c[20],temp[20];      		//定义两个数组，存放键盘输入的用户名和密码
    printf("\n\t\t\t\t 用户登录");
    printf("\n\t\t\t 请输入用户名:");
    scanf("%s",u);
    //判断用户名是否存在
    fp=fopen(u,"r+");
    temp[0]='0';
    if(fp==NULL)
    {
        printf("\n\t\t\t Sorry! 用户不存在,请注册!");
        printf("\n\t\t\t	1.注册\n2.重新登陆");
        temp[0]=getchar();
        if(temp[0]=='1')
        {
            system("cls");
            registered();
        }
        else return landing();
    }
    //验证密码是否正确
    do
    {
        if(1) fread(&save,sizeof(User),1,fp); //读取用户信息，即用户名和密码
        printf("\t\t\t 请输入您的密码:");
        scanf("%s",c);
        if(strcmp(save.code,c)!=0)                      //对比输入的密码和读取的密码
        {
            printf("\n\t\t\t Sorry! 密码错误(1.退出 2.重新输入)!");
            temp[0]=getchar();
            printf("\n");
            if(temp[0]=='1')
            {
                fclose(fp);                           //关闭文件防止错误操作
            	break;
            }
        }
        if(strcmp(save.code,c)==0) return menu1(); 
    }while(temp[0]=='2');
    getchar();
    printf("\n");
    
} 



 
 
/*-------------------------------------------------------------------------------主函数--------------------------------------------------------------------------------------------*/ 
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

 
