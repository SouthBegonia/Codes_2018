/*
程序功能：猜测数字。在两端范围为随机数(min,max)之间猜数。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define RAND_MAX 32767

int main()
{
	int min, max, t = 0;
	int no;
	int ans, num;
	int n = 1, stage = 0;						//n起始值为1，表示即便范围内只有1个数，也至少需要猜1次 
	srand(time(NULL));
	min = rand() % RAND_MAX;
	max = rand() % RAND_MAX;
	if (min>max)								//修正范围 
	{
		t = min;
		min = max;
		max = t;
	}

	ans = min + rand() % (max - min + 1);				//计算目标值 

	num = max - min;
	while (num != 1)							//计算合适的猜数次数 n 
	{
		num = num / 2;
		n++;
	}
	printf("猜一个在%d~%d之间的数：\n", min, max);
	do
	{
		printf("还剩余%d次机会，请猜数：", n - stage);
		scanf_s("%d", &no);					//读入猜测数 
		stage++;							//当结果不为3的倍数时，不计数 
		if (no>ans)
			printf("数字偏大\n");
		else if (no<ans)
			printf("数字偏小\n");
	} while (no != ans && stage<n);
	if (no != ans)
		printf("很遗憾，答案是：%d", ans);
	else {
		printf("正确！\n");
		printf("你用了%d次猜中\n", stage);
	}
	return 0;
}
