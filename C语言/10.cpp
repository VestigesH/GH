//��Ŀ����ͣһ�����������ʽ����ǰʱ�䡣
#include <stdio.h>
#include <time.h>
#include <windows.h>
int main ()
{
   time_t curtime;
   time(&curtime);
   Sleep(1000);
   printf("��ǰʱ��Ϊ:%s", ctime(&curtime));

}

