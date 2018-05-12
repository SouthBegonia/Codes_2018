/*
程序功能：猜测指定范围内的随机数，并打印出猜测情况。
rand():头文件<stdlib.h>
格式：int rand(void);
功能：生成伪随机数，基于种子值(seed,默认为1)，按照特定规律生成的随机数。

srand():文件<stdlib.h>
格式：void srand(unsigned seed);
功能：给后续调用的rand()设置种子(seed)，用于生成新的伪随机数序列。

srand(time(NULL))：把运行程序时间的时间当种子(seed)。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_STAGE 10						//定义最多可输入次数 

int main()
{
	int i;
	int stage;								//已输入的次数 
	int no;									//猜的数 
	int ans;								//随机数答案 
	int num[MAX_STAGE];						//存储猜的数的历史记录 
	srand(time(NULL));						//设定随机数的种子 
	ans = rand() % 1000;						//生成0~999的随机数 

	printf("请猜一个0~999的整数。\n");
	stage = 0;
	do
	{
		printf("还剩余 %d 次机会。请猜数： ", MAX_STAGE - stage);
		scanf_s("%d", &no);
		num[stage++] = no;					//猜的数字逐一存入数组 
		if (no>ans)
			printf("再小一点。\n");
		else if (no<ans)
			printf("再大一点。\n");
	} while (no != ans && stage < MAX_STAGE);
	if (no != ans)
		printf("很遗憾，正确答案是 %d。\n", ans);
	else {
		printf("回答正确。\n");
		printf("你用了 %d 次猜中了。\n", stage);
	}
	puts("\n--- 输入记录 ---");
	for (i = 0; i<stage; i++)
		printf(" %2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);

	return 0;
}