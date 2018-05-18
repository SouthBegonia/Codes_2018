/*
程序功能：加一的记忆训练。记忆多个数值，输入这些数值加一后的值。总共10个关卡，自选等级，每次完成一个关卡打印答题对错，最终统计总答题情况及全部关卡答题情况。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STAGE 10			//关卡数
#define LEVEL_MIN 2				//最低等级（数值个数）
#define LEVEL_MAX 6				//最高等级（数值个数）

int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;
	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0*(c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main()
{
	int i, stage;
	int level;			//等级
	int right;			//答对总数
	int score[MAX_STAGE];		//对应关卡答对数量
	clock_t start, end;			//用时计算

	srand(time(NULL));

	printf("一加训练开始！\n");
	printf("来记忆2位数的数值！\n");
	printf("请输入原数值加1后的数值。\n");

	do {
		printf("要挑战的等级(%d~%d): ", LEVEL_MIN, LEVEL_MAX);		//读取等级
		scanf("%d", &level);
	} while (level<LEVEL_MIN || level>LEVEL_MAX);

	right = 0;
	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		int no[LEVEL_MAX];			//要记忆的数值(电脑生成)
		int x[LEVEL_MAX];			//输入的数值
		int right_each = 0;			//本关卡答对的数量

		printf("\n第%d关开始!\n", stage + 1);

		for (i = 0; i < level; i++)
		{
			no[i] = rand() % 90 + 10;
			printf("%d ", no[i]);		//生成要记忆的数值
		}
		fflush(stdout);
		sleep(500 * level);			//等待
		printf("\r%*c\r", 3 * level, ' ');	//清屏
		fflush(stdout);

		for (i = 0; i < level; i++)
		{
			printf("第%d个数： ", i + 1);
			scanf("%d", &x[i]);		//读取答案
		}
		for (i = 0; i < level; i++)		//判断对错
		{
			if (x[i] != no[i] + 1)
				printf("N ");
			else {
				printf("Y ");
				right_each++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++)		//显示正确答案
			printf("%2d ", no[i]);
		printf("......答对了%d个。(回车继续)\n", right_each);
		score[stage] = right_each;		//记录本关卡答对数
		right += right_each;		//更新总答对数
		getchar(); getchar();
	}
	end = clock();

	printf("%d个中答对了%d个。\n", level*MAX_STAGE, right);
	for (stage = 0; stage < MAX_STAGE; stage++)
		printf("第%2d关卡：%d\n", stage + 1, score[stage]);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	getchar(); getchar();
	return 0;
}