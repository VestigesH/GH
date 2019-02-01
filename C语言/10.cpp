//题目：暂停一秒输出，并格式化当前时间。
#include <stdio.h>
#include <time.h>
#include <windows.h>
int main ()
{
   time_t curtime;
   time(&curtime);
   Sleep(1000);
   printf("当前时间为:%s", ctime(&curtime));

}

