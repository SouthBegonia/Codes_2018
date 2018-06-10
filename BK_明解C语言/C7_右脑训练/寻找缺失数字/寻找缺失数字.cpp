/*
程序功能：找出数组缺失的数字，重复10次。
思路：设定一随机数，复制数组时跳过。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STAGE 10	//游戏次数

int main()
{
	int i, j, stage;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };	//被复制数组
	int a[8];	//复制数组
	double times;
	clock_t start, end;

	srand(time(NULL));

	printf("寻找缺失数字。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		int x = rand() % 9;		//生成随机数 0~8
		int no;		//玩家答案
		
		i = j = 0;
		while (i < 9)
		{
			if (i != x)
				a[j++] = dgt[i];	//复制数组时跳过dgt[x]
			i++;
		}
		for (i = 0; i < 8; i++)
			printf("%d ", a[i]);
		printf(": ");

		do
		{
			scanf("%d", &no);
		} while (no != dgt[x]);
	}
	end = clock();

	times = (double)difftime(end, start) / CLOCKS_PER_SEC;	
	/* start 和 end 单位为毫秒，为long型。代码等价于 times = (double)(start - end) / CLOCK_PER_SEC */

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