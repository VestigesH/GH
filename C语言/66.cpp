//��Ŀ����дinput()��output()�������룬���5��ѧ�������ݼ�¼
#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct 
{
	char name[10];
	char sex[5];
	int number;
	int age;
}Stu;
void input(Stu*stu)
{
	int i;
	for(i=0;i<5;i++) scanf("%s%s%d%d",stu[i].name,stu[i].sex,&(stu[i].number),&(stu[i].age));
}
void output(Stu*stu)
{
	int i;
	for(i=0;i<5;i++) printf("%5s  %5s  %5d  %5d\n",stu[i].name,stu[i].sex,stu[i].number,stu[i].age);
}
void input(Stu*stu);
void output(Stu*stu); 
int main()
{
	Stu stu[5];
    printf("������5��ѧ������Ϣ������  �Ա�  ѧ��  ����\n");
    input(stu);
    printf("5��ѧ������Ϣ���£�\n ���� 	 �Ա� 	 ѧ�� 	����\n");
    output(stu);
    system("pause");
    return 0; 
}

