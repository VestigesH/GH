void Sort()
{
	struct Film *p = film->next;
	struct Film *p1,*p2 ;
	struct f;
	p2 = film;
	int choice; 
	printf("\n\t\t\t\t\t\t\t**************ӰƬ�������**************\n");
	printf("\t\t\t\t\t\t\t|  ���������з�ʽǰ����Ž���ѡ��      |\n");
	printf("\t\t\t\t\t\t\t|          1.ӰƬ�������              |\n");
	printf("\t\t\t\t\t\t\t|          2.ӰƬ��Ž���              |\n");
	printf("\t\t\t\t\t\t\t|          3.ӰƬ��������              |\n");
	printf("\t\t\t\t\t\t\t|          4.ӰƬ���ƽ���              |\n");
	printf("\t\t\t\t\t\t\t|          5.��ӳʱ������              |\n");
	printf("\t\t\t\t\t\t\t|          6.��ӳʱ�併��              |\n");
	printf("\t\t\t\t\t\t\t|          7.ӰƬ��������              |\n");
	printf("\t\t\t\t\t\t\t|          8.ӰƬ���ֽ���              |\n"); 
	printf("\t\t\t\t\t\t\t|          0.�˳��鿴����              |\n");
	printf("\t\t\t\t\t\t\t----------------------------------------\n");
	printf("\n\t\t\t\t\t\t\t����ѡ����:");
	scanf("%d",&choice);
	if(p2 == NULL)
	{
		printf("\n\t\t\t\t\t\t\tSorry! ��ʱ��ӰƬ��Ϣ���޷�����!"); 
		return;
	}
	if(choice==1)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else if(choice==2)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else if(choice==3)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else if(choice==4)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else if(choice ==5)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else if(choice == 6)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else if(choice == 7)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else if(choice == 8)
	{
		for(p2 = p2->next;p2->next != NULL;p2 = p2->next)
		{
			for(p1 = p2->next;p1 != NULL;p1 = p1->next)
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
	else
		break;		
}



