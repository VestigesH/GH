#include <stdio.h>
#include <stdlib.h> 
int main() 
{ 
	int money = 0; 
	int total = 0; 
	int empty = 0; 
	scanf("%d", &money);
	/*total = money; 
	empty = money; 
	while(empty>=2) 
	{ 
	total = total + empty/2; 
	empty = empty/2+empty%2; 
	}*/ 
	total = money*2-1; 
	printf("total = %d\n", total); 
	system("pause"); 
	return 0; 
} 
 

