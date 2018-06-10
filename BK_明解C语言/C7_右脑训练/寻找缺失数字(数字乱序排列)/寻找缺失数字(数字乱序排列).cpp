/*
程序功能：找出乱序数组缺失的数字，重复10次。
思路：打乱数组采用的洗牌(Fisher-Yates)算法，函数宏。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_STAGE 10	//游戏次数
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)	//函数宏
int main()
{
	int i, j, stage;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };	//被复制数组
	int a[8];	//复制数组
	double times;
	clock_t start, end;

	srand(time(NULL));

	printf("输入缺失的数字。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		int x = rand() % 9;
		int no;

		i = j = 0;
		while (i < 9)
		{
			if (i != x)
				a[j++] = dgt[i];	//复制数组
			i++;
		}
		for (i = 7; i > 0; i--)	//从a[0]到a[i]中随机选取一个元素，把1该元素与a[i]进行交换，该算法为洗牌(Fisher-Yates)算法
		{
			j = rand() % (i + 1);
			if (i != j)
			{
				swap(int, a[i], a[j]);
				/*	上行函数宏作交换处理后等价于
				do {
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				} while (0);
				函数宏swap只起到替换的作用，宏定义不分配内存。
				*/
			}
		}
		for (i = 0; i < 8; i++)
			printf("%d ", a[i]);
		printf(":");

		do {
			scanf_s("%d", &no);
		} while (no != dgt[x]);
	}
	end = clock();
	times = (double)difftime(end, start) / CLOCKS_PER_SEC;

	printf("用时%.1f秒。\n", times);
	if (times > 25.0)
		printf("太慢了。\n");
	else if (times > 20.0)
		printf("反应有点慢啊。\n");
	else if (times > 17.0)
		printf("反应还行吧。\n");
	else printf("反应很快。\n");

	getchar();
	return 0;
}