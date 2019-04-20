#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Coins[100];
int weight(int Start,int End)
{
	int weight = 0, i;
	for(i = Start;i <= End;i++)
		weight += Coins[i];
	return weight;
}
int compare(int lStart, int lEnd, int rStart, int rEnd)
{
	int falseCoin ;
	printf("\nlStart = %d \t lEnd = %d \t rStart = %d \t rEnd = %d \n",lStart, lEnd, rStart, rEnd);
	printf("\nlweight = %d \t rweight = %d\n",weight(lStart, lEnd), weight(rStart,rEnd));
	if (lStart == lEnd && rStart == rEnd) {//硬币总数为两枚的情况 
        if (weight(lStart, lEnd) < weight(rStart, rEnd)) {//伪币在左 
            falseCoin = lStart;
        } else {//伪币在右 
            falseCoin = rStart;
        }
    	printf("\n伪币在%d处！",falseCoin);
    } else if (lStart == lEnd) {//左边只有一枚硬币 （硬币总数为3枚） 
        if (weight(lStart, lEnd) == 0) {//这一枚为伪币 
            falseCoin = lStart;
            printf("\n伪币在%d处！",falseCoin);
        } else {//伪币在右，对右边剩余的硬币进行比较 
            compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 + 1, rEnd);
        }
    } else if (rStart == rEnd) {//右边只有一枚硬币 （硬币总数为3枚）
        if (weight(rStart, rEnd) == 0) {//这一枚为伪币 
            falseCoin = rStart;
            printf("\n伪币在%d处！",falseCoin);
        } else {//伪币在左，对左边的硬币进行比较 
            compare(lStart, (lStart + lEnd) / 2, (lStart + lEnd) / 2 + 1, lEnd);
        }
    } else {//硬币数大于3的情况 
        if (weight(lStart, lEnd) < weight(rStart, rEnd)) {
            compare(lStart, (lStart + lEnd) / 2, (lStart + lEnd) / 2 + 1, lEnd);
        } else if (weight(lStart, lEnd) > weight(rStart, rEnd)) {
            compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 + 1, rEnd);
        } else {//左右硬币重量相等，利用硬币个数找出伪币 
            if ((lEnd - lStart) > (rEnd - rStart)) {
                compare(lStart, (lStart + lEnd) / 2, (lStart + lEnd) / 2 + 1, lEnd);
            } else {
                compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 + 1, rEnd);
            }
        }
    }
}
int main()
{
	int n , i , falseCoin;
	printf("请输入硬币数量：");
	scanf("%d", &n);
	srand(( unsigned ) time ( NULL ));
	falseCoin = rand() % n;
	for(i = 0;i < n; i++)
		Coins[i] = 1; 
	Coins[falseCoin] = 0;
	for( i = 0;i < n;i++)
		printf("%d",Coins[i]);
	printf("\n%d",falseCoin);
	compare(0, n / 2 - 1, n / 2 + 1, n - 1);
} 
