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
	if (lStart == lEnd && rStart == rEnd) {//Ӳ������Ϊ��ö����� 
        if (weight(lStart, lEnd) < weight(rStart, rEnd)) {//α������ 
            falseCoin = lStart;
        } else {//α������ 
            falseCoin = rStart;
        }
    	printf("\nα����%d����",falseCoin);
    } else if (lStart == lEnd) {//���ֻ��һöӲ�� ��Ӳ������Ϊ3ö�� 
        if (weight(lStart, lEnd) == 0) {//��һöΪα�� 
            falseCoin = lStart;
            printf("\nα����%d����",falseCoin);
        } else {//α�����ң����ұ�ʣ���Ӳ�ҽ��бȽ� 
            compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 + 1, rEnd);
        }
    } else if (rStart == rEnd) {//�ұ�ֻ��һöӲ�� ��Ӳ������Ϊ3ö��
        if (weight(rStart, rEnd) == 0) {//��һöΪα�� 
            falseCoin = rStart;
            printf("\nα����%d����",falseCoin);
        } else {//α�����󣬶���ߵ�Ӳ�ҽ��бȽ� 
            compare(lStart, (lStart + lEnd) / 2, (lStart + lEnd) / 2 + 1, lEnd);
        }
    } else {//Ӳ��������3����� 
        if (weight(lStart, lEnd) < weight(rStart, rEnd)) {
            compare(lStart, (lStart + lEnd) / 2, (lStart + lEnd) / 2 + 1, lEnd);
        } else if (weight(lStart, lEnd) > weight(rStart, rEnd)) {
            compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 + 1, rEnd);
        } else {//����Ӳ��������ȣ�����Ӳ�Ҹ����ҳ�α�� 
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
	printf("������Ӳ��������");
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
