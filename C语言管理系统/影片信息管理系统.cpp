#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define Savepath "./Savedata.txt"   //数据存储路径

/* 
影片信息管理系统功能 :
			(1).录入影片信息 
			(2).查询影片信息 
			(3).打印影片信息
			(4).修改影片信息 
			(5).删除影片信息 
			(6).统计影片总数
			(7).查看所有影片信息
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
void write();               //写入用户的信息  
 

//2.界面函数 
void menu(); 				//登陆注册界面 
void menu1();				//影片信息管理系统功能界面



struct Film 		//影片信息结构体 :电影编号、电影名称 、主演、 导演 、地区、 上映时间 、电影类型 、电影规格 、电影评分
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
struct Film * const film=(struct Film*)malloc(sizeof(struct Film));//全局链表，带头结点，头指针film被const限定，不可修改；


struct User					//用户结构体
{
    char user[20];
    char code[20];
}save; 							//save结构体用来保存用户名和密码


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
			printf("分配内存失败");
			exit(1);
		}
		fread(node,sizeof(struct Film),1,fp);
		if(feof(fp))
			break;
		node->next=film->next;//头插法
		film->next=node;
		film->num++;          //第一个节点不存储数据，就把其中的num用来放数据的个数
	}
	fclose(fp);
}


/*---------------------------------------------------------------------函数调用部分-------------------------------------------------------------------------------------------*/


/*=========================================影片信息函数==========================================*/

//录入影片信息

void Add()
{
	int n;					//录入新影片数 
	char A[3];
	printf("\n\t\t\t**************录入新影片**************\n");
	printf("\n");
	struct Film *p =(struct Film*)malloc(sizeof(struct Film));
	if(p)
	{
		FILE *fp=fopen(Savepath,"a");//以追加模式写入文件
    	if(fp==NULL)
        {
            printf("\n\t\t\t Sorry! 文件打开失败!\n");
            exit(0);
        }
        do
		{
			p->next=film->next;
        	film->next=p;
        	printf("\t\t\t 请输入要录入的影片编号:");
       		scanf("%d",&p->num);
       		getchar();
        	printf("\t\t\t 请输入要录入的影片名称:");
        	scanf("%s",p->name);
        	getchar();
        	printf("\t\t\t 请输入要录入的影片主演:");
        	scanf("%s",p->actor);
        	getchar();
        	printf("\t\t\t 请输入要录入的影片导演:");
        	scanf("%s",p->direct);
        	getchar();
        	printf("\t\t\t 请输入要录入的影片地区:");
        	scanf("%s",p->area);
        	getchar();
        	printf("\t\t\t 请输入要录入的上映时间:");
        	scanf("%s",p->date);
        	getchar();
        	printf("\t\t\t 请输入要录入的影片类型:");
        	scanf("%s",p->type);
        	getchar();
        	printf("\t\t\t 请输入要录入的影片规格:");
        	scanf("%s",p->norms);
        	getchar();
        	printf("\t\t\t 请输入要录入的影片评分:");
        	scanf("%f",&p->score);
        	getchar();
        	fwrite(p,sizeof(struct Film),1,fp);
        	
        	n++; 
			printf("\n\t\t\t Congractulations! 成功录入第%d个新影片!",n++);
			printf("\n");
 			printf("\n\t\t\t是否继续录入影片信息？请输入yes or no ?\t");
 			scanf("\n\t\t\t%s",&A);
		}while(strcmp(A,"yes")==0);
		
		fclose(fp);
	}
	else
        printf("\t\t\t Sorry! 录入失败!\n");
}


// 查询影片信息(链表查询和数组查询结合) 

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
	struct Film f[100];  //数组查询 
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
			case 2:											//按照名称查询
				{
					printf("\t\t\t请输入要查询的影片名称:");
					scanf("%s",&film_name);
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
			case 3:											//按照主演查询
				{
					printf("\t\t\t请输入要查询的影片主演:");
					scanf("%s",&film_actor);
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
			case 4:											//按照导演查询
				{
					printf("\t\t\t请输入要查询的影片导演:");
					scanf("%s",&film_direct);
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
			case 5:											//按照地区查询
				{
					printf("\t\t\t请输入要查询的影片地区:");
					scanf("%s",&film_area);
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
			case 6:											//按照时间查询
				{
					printf("\t\t\t请输入要查询的影片上映时间:");
					scanf("%s",&film_date);
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
			case 7:											//按照类型查询
				{
					printf("\t\t\t请输入要查询的影片类型:");
					scanf("%s",&film_type);
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
			case 8:											//按照规格查询
				{
					printf("\t\t\t请输入要查询的影片规格:");
					scanf("%s",&film_norms);
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
			case 9:											//按照评分查询
				{
					printf("\t\t\t请输入要查询的影片评分:");
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
				printf("\t\t\t查询错误！请输入正确的查询方式");
		}
		
		if(k==0)
		{
			printf("======================================================================================================================\n");
			printf("\t\t\t\t  	   Sorry! 没有您所要查找的内容！\n");
			printf("======================================================================================================================\n");
		}
		else//以表格形式打印出所查询到的影片信息 
		{
			printf("\t=================================================================================================================================================\n");
			printf("\t影片编号：\t 影片名称：\t 影片主演：\t 影片片导演：\t 影片地区：\t 上映时间：\t 影片类型：\t 影片规格：\t 影片评分：\n ");
			
			for(i=0;i<k;i++)
			{
				printf("\t%8d %16s %16s %16s %16s %16s %16s %16s %8f\n",f[i].num,f[i].name,f[i].actor,f[i].direct,f[i].area,f[i].date,f[i].type,f[i].norms,f[i].score);
			}
			printf("\t=================================================================================================================================================\n");
			printf("\t\t\t以上为查询内容！\n");
		}
		printf("\t\t\t您是否要继续查找？请输入yes或no! \t");
		scanf("\t\t\t%s",c);
	}while(strcmp(c,"yes")==0);//判断结束
}


//修改影片信息

void Change()
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
			printf("\t\t\t\t\t 1.影片编号\n");
			printf("\t\t\t\t\t 2.影片名称\n");
			printf("\t\t\t\t\t 3.影片主演\n");
			printf("\t\t\t\t\t 4.影片导演\n");
			printf("\t\t\t\t\t 5.影片地区\n");
			printf("\t\t\t\t\t 6.上映时间\n");
			printf("\t\t\t\t\t 7.影片类型\n");
			printf("\t\t\t\t\t 8.影片规格\n");
			printf("\t\t\t\t\t 9.影片评分\n");
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

void Del()
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

void Length()
{
	int count=0;
	struct Film *p=film->next;
	while(p)
	{
		p=p->next;
		++count;
	}
	printf("\n\n\t\t\t  影片总数为；%d",count);
}


//查看所有影片信息

void  Printall()
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

//注册登陆界面

void menu()        
{
	int choice;
	printf("\n\n\n\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|      		*****  WELCOME  *****  		     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\t\t\t|               1.注册新用户                         |\n");
	printf("\t\t\t|	        2.登陆账户	                     |\n");
	printf("\t\t\t|               3.退出		                     |\n");
	printf("\t\t\t------------------------------------------------------\n");
	printf("\n\n\t\t\t请在1-3之间进行选择您需要的功能:");
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
				printf("\n\t\t\t Sorry! 输入错误，请重新输入正确序号!");
				menu(); 
			}
	}
} 


//影院管理系统功能界面 

void menu1()     
{
	int choice1;
	while(1)
	{
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


/*===================================================用户部分函数=========================================*/


//注册函数

void registered()
{
    char temp[20];
    char user[20];
    FILE *fp;
    do
    {
        printf("\n\t\t\t 用户注册\n");
        printf("\t\t\t 请输入您的用户名:");
        scanf("%s",user);
        fp=fopen("user.txt","r+");				//判断用户名是否重复
        if(strcmp(user,save.user)==0)
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
    fp=fopen("user.txt","w");
    if(fp==NULL)
       {
          printf("\n\t\t\t Sorry! 注册失败!\n");
          exit(0);
       }
    else
    {
        system("cls");
        printf("\n\t\t\t 注册成功!");
        fprintf(fp,"%s %s\n",save.user,save.code); 
		fclose(fp);
    }
}

//写入用户信息
void write()
{
	FILE *fp;
	fp=fopen("user.txt","w+");
    if(fwrite(&save,sizeof(User),1,fp)!=1)
    {
        printf("\n\t\t\t Sorry!写入文件错误!");
        exit(0);
    }
    else	fprintf(fp,"%s %s\n",save.user,save.code);
    fclose(fp);
}

//登陆函数

void landing()
{
    char u[20],c[20],temp[20];      		//定义两个数组，存放键盘输入的用户名和密码
    printf("\n\t\t\t\t 用户登录");
    printf("\n\t\t\t 请输入用户名:");
    scanf("%s",u);
    //判断用户名是否存在
    FILE * fp=fopen("user.txt","r");
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
        if(1) fread(&save,sizeof(User),1,fp);

 		//读取用户信息，即用户名和密码
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
        if(strcmp(save.code,c)==0)
            return menu1();
    }while(temp[0]=='2');
    getchar();
    printf("\n");

}



/*-------------------------------------------------------------------------------主函数--------------------------------------------------------------------------------------------*/ 


int main()
{
	film->next=NULL;
	film->num=0;
    readdata();
	while(1)
	{
		menu();	
	}
}




