//��Ŀ������ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
#include <stdio.h>
int main()
{
	int year,month,day,days,leap=0;
	printf("������������:");
	scanf("%d,%d,%d",&year,&month,&day);
	if (year%4==0&&year%100!=0||year%400==0) leap=1;
	if (1<=month<=12)
	switch (month)
	{
		case 1: days=day;										break;
		case 2: days=day+31+leap;								break;
		case 3: days=day+31+28+leap;							break;
		case 4: days=day+31+28+leap+31;							break;
		case 5: days=day+31+28+leap+31+30;						break;
		case 6: days=day+31+28+leap+31+30+31;					break;
		case 7: days=day+31+28+leap+31+30+31+30;				break;
		case 8: days=day+31+28+leap+31+30+31+30+31;				break;
		case 9: days=day+31+28+leap+31+30+31+30+31+31;			break;
		case 10:days=day+31+28+leap+31+30+31+30+31+31+30;		break; 
		case 11:days=day+31+28+leap+31+30+31+30+31+31+30+31;	break;
		case 12:days=day+31+28+leap+31+30+31+30+31+31+30+31+30; break; 
	}
	printf("��һ������һ��ĵ�%d��",days);
}
