/*
程序功能：有多组乱序的不重复数字(1~9)，但其间缺失了某一数字。
每个数字逐一显示一定时间后消失，所有数字显示完后要求输入缺失的数，要求即时输入，回答正确则打印正确答案及数组完整信息。

思路：每次显示一个数字，调用等待函数等待，后用空白符覆盖该数字。回答正确后则退到当行最前面开始打印完整数组及答案。即时输入采用getch函数。

注意：getch函数读取的是数字字符，即我们输入键盘上的1，但读取值为'1'即整数值的49，故需要对读取的值转换，可以减去 48 或者减去 '0'
整数值x(0~9) ---  x +'0' -->数字字符no('0'~'9')
整数值x(0~9) <-- no -'0' ---数字字符no('0'~'9')
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

#define MAX_STAGE 10	//游戏次数
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)	//函数宏

int sleep(unsigned long x)				//等待 x 毫秒
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
	int i, j, stage;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };	//被复制数组
	int a[8];	//复制数组
	double times;
	clock_t start, end;

	srand(time(NULL));

	printf("程序会间隔一段时间显示 1~9 内随机的数字(不重复)，但其中有一个数字缺失，请输入缺失的数字。\n");
	printf("按空格键开始。\n");
	while (getch() != ' ')
		;

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

		for (i = 7; i > 0; i--)	//数组乱序排列
		{
			j = rand() % (i + 1);
			if (i != j)
			{
				swap(int, a[i], a[j]);
			}
		}

		for (i = 0; i < 8; i++)
		{
			printf("%d ", a[i]);
			sleep(1000);		//每次暂停显示1000ms
			printf("\b\b%*c", 2, ' ');	//后隐藏(空格符覆盖)
		}
		printf(" : ");

		do {
			no = getch();
		} while (no - '0' != dgt[x]);		//getch读取的no为字符型数字('1'为49，'a'为97)，将其减去字符型'0'(为48)即表示整数值

		printf("\b\b%c\r",' ');		//覆盖前面的冒号
		for (i = 0; i < 8; i++)
			printf("%d ", a[i]);	//回答正确下重头打印完整数组

		printf(" : %c", no);	//并打印正确答案
		printf(" 正确!\n");
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