/*
程序功能：猜想目标数字，目标数字是一个在3~999之间的3的倍数的数；
当猜想的数不是3的倍数时不计入猜测次数，且要求重新输入。需要合理计算允许猜测数n。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int no;
	int ans, num;
	int n = 1, stage = 0;						//n起始值为1，表示即便范围内只有1个数，也至少需要猜1次，stage 已经猜测的次数 
	srand(time(NULL));						//设定随机数种子 
	ans = ((1 + rand() % 333) * 3);					//依照要求设定的随机数 
	num = 999 / 3;
	while (num != 1)							//计算合适的猜数次数 n 
	{
		num = num / 2;
		n++;
	}
	printf("猜一个在3~999之间且为3的倍数的数：\n");
	do
	{
		printf("还剩余%d次机会，请猜数：", n - stage);
		scanf_s("%d", &no);					//读入猜测数 
		if (no % 3 != 0)
		{
			printf("输出错误！\n");
		}
		else {
			stage++;						//当结果不为3的倍数时，不计数 
			if (no>ans)
				printf("数字偏大\n");
			else if (no<ans)
				printf("数字偏小\n");
		}
	} while (no != ans && stage<n);

	if (no != ans)
		printf("很遗憾，答案是：%d", ans);
	else {
		printf("正确！\n");
		printf("你用了%d次猜中\n", stage);
	}
	return 0;
}