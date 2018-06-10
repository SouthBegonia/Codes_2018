/*
程序功能：找出乱序数组重复的数字，重复10次，采取实时键盘输入，在新答案基础上覆盖错误答案。

思路：采用 getch 实现即时读取，getch 隶属于 conin.h 内。

说明：本代码尝试调用同目录下自建的头文件 getputch.h ，其内包含头文件 conin.h ，即调用 getputch.h 即可实现 getch 功能。
并且在 getputch.h 内写了2空函数 init_getputch 及 term_getputch 在源文件内调用。

*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include"getputch.h"	//调用同目录下所写的头文件

#define MAX_STAGE 10	//游戏次数
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)	//函数宏
int main()
{
	int i, j, stage;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };	//被复制数组
	int a[10];	//复制数组
	double times;
	clock_t start, end;

	init_getputch();	//调用的 getputch.h 内的函数
	srand(time(NULL));

	printf("输入重复的数字。\n");
	printf("按下空格开始。\n");
	fflush(stdout);

	while (getch() != ' ')	//按下空格开始
		;

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		int x = rand() % 9;
		int no;

		i = j = 0;
		while (i < 9)
		{
			a[j++] = dgt[i];
			if (i == x)		//复制时重复dgt[x]
				a[j++] = dgt[i];
			i++;
		}
		for (i = 9; i > 0; i--)	//重新排列数组
		{
			j = rand() % (i + 1);
			if (i != j)
			{
				swap(int, a[i], a[j]);
			}
		}
		for (i = 0; i < 10; i++)
			printf("%d ", a[i]);	//显示所有元素
		printf(" : ");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no))	//如果读取的是显示字符
			{
				putch(no);	//显示按下的键(字符)，注：putch 返回
				if (no != dgt[x] + '0')
					putch('\b');	//如果回答错误，光标退一格
				else
					printf("\n");
				fflush(stdout);
			}
		} while (no != dgt[x]+'0');	//no为字符和对应数值，此处需转换
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

	term_getputch();

	getchar(); getchar();
	return 0;
}