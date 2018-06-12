/*
程序功能：随机设定3个连续的数字或字母，随机隐藏其中一个，玩家判断隐藏的字符

思路：设定3组字符(大小写英文，数字)，设定3个随机数(字符种类、字符起始位置、隐藏位置)
*/
#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"getputch.h"		//内包含conio.h，为了调用getch。也可直接调用conio.h

#define MAX_STAGE 10	//游戏次数

int main()
{
	char *qstr[] = { "0123456789",	//数字
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ",	//大写英文字母
	"abcdefghijklmnopqrstuvwxyz",	//小写英文字母
	};

	int chmax[] = { 10,26,26 };
	int i, stage;
	int key;	//读取的值
	double times;	//耗时
	clock_t start, end;

	init_getputch();	//getputch.h内无功能的空函数

	srand(time(NULL));	//设定随机数的种子

	printf("_______________________________________________\n");
	printf("| 请输入连续的3个数字或英文字母中被隐去的字符。\n");
	printf("| 例如显示A*C:就请输入B\n");
	printf("|\n");
	printf("| 按下空格开始。\n");
	printf("______________________________________________\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		int qtype = rand() % 3;		//0:数字 /1:大写字母 /2:小写字母
		int nhead = rand() % (chmax[qtype] - 2);	//开头字符的下标
		int x = rand() % 3;		//隐藏字符的序号

		putchar('\r');
		for (i = 0; i < 3; i++)		//显示题目
		{
			if (i != x)
				printf("  %c", qstr[qtype][nhead + i]);
			else
				printf("  *");
		}
		printf(" : ");
		fflush(stdout);

		do {
			key = getch();
			if (isprint(key))	//若能显示字符则显示
			{
				putch(key);
				if (key != qstr[qtype][nhead + x])
					putch('\b');	//若回答错误则退格覆盖
			}
		} while (key != qstr[qtype][nhead + x]);
		putch('\n');
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

	term_getputch();		//getputch.h内的空函数

	getchar(); 
	return 0;
}