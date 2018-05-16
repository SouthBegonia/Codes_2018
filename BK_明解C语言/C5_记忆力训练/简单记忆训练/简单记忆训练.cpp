/*
程序功能：电脑生成4位数的随机数让玩家记忆，数字仅显示一瞬间(0.5s)，玩家输入，重复10次，打印出答对的次数的所用的时间。
核心：等待函数sleep()和清屏的操作。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_STAGE 10			//关卡数(最大答题数)

/*---等待x毫秒---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;
	do
	{
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0*(c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main()
{
	int stage;				//作答次数
	int right = 0;			//答对数量
	clock_t start, end;		//开始时间/结束时间

	srand(time(NULL));

	printf("来猜测一个4位数的值吧(按回车开始)\n");
	getchar();

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		int x;				//读取的值
		int no = rand() % 9000 + 1000;		//4位数的随机数

		printf("%d", no);
		fflush(stdout);
		sleep(500);			//只显示0.5秒

		printf("\r请输入：");	//清屏
		fflush(stdout);
		scanf_s("%d", &x);

		if (x != no)
			printf("回答错误。\n");
		else
		{
			printf("回答正确。\n");
			right++;
		}
	}
	end = clock();
	printf("%d次中你猜对了%d次。\n", MAX_STAGE, right);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	getchar();
	getchar();
	return 0;
}