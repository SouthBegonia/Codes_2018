/*
程序功能：完成n次简单的三元一次方程的加减法运算，3个数都为随机数，运算的加减号也随机。
思路：仅有2个符号（加或者减）可以if()嵌套罗列出所有可能(4种)，符号通过随机数在0~1之间取。
疑惑：本例穷举所有可能较为笨拙，假如可能情况众多则无法解决，switch()也不便。需要更加简练的代码。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int a, b, c, i;									
	int n = 5;										//重复运算次数
	int x;											//输入值
	int sg_1, sg_2;									//左右侧符号（0为减号，1为加号）
	clock_t start, end;								//记录用时
	srand(time(NULL));				
	start = clock();

	for (i = 1; i <= n; i++)						
	{
		a = rand() % 11;							//取3个0~10的随机数	
		b = rand() % 11;
		c = rand() % 11;
		sg_1 = rand() % 2;							//在0和1之间随机选取
		sg_2 = rand() % 2;
		if (sg_1 == 0)								//左负
		{
			if (sg_2 == 0)							//左负+又负
			{
				printf("%2d - %2d - %2d = ", a, b, c);
				do
				{
					scanf_s("%d", &x);
					if (x == a - b - c)
						break;
					printf("回答错误，请重新输入：");
				} while (1);
			}
			else
			{
				printf("%2d - %2d + %2d = ", a, b, c);
				do                                  //左负+右正
				{
					scanf_s("%d", &x);
					if (x == a - b + c)
						break;
					printf("回答错误，请重新输入：");
				} while (1);
			}
		}
		else										//左正
		{
			if (sg_2 == 0)							//左正+右负
			{
				printf("%2d + %2d - %2d = ", a, b, c);
				do
				{
					scanf_s("%d", &x);
					if (x == a + b - c)
						break;
					printf("回答错误，请重新输入：");
				} while (1);
			}
			else
			{
				printf("%2d + %2d + %2d = ", a, b, c);
				do                                  //左正+右正
				{
					scanf_s("%d", &x);
					if (x == a + b + c)
						break;
					printf("回答错误，请重新输入：");
				} while (1);
			}
		}

	}
	end = clock();
	printf("Over!\n");
	printf("用时为：%.1f秒\n", double(end - start) / CLOCKS_PER_SEC);
	getchar();
	getchar();
	return 0;
}