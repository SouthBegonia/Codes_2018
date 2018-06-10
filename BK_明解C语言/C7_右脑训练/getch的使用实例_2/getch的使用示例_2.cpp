/*
程序功能：获取玩家从键盘输入的字符，不回车显示。

备注：仅在提供了Curses库的 UNIX/LINUS/OS 环境下运行

*/
#include<stdio.h>
#include<curses.h>	//提供getch
#include<ctype.h>	//提供isprint

int main()
{
	int ch;
	int retry;

	initscr();	//生成屏幕并初始化库。使用curses库时必须最先调用的函数
	cbreak();	//禁止行缓冲
	noecho();	//禁止输的字符显示在画面上
	refresh();	//刷新画面

	do {
		printf("请按键。");
		ddlush(stdout);

		ch = getch();

		printf("\n\r按下的键是%c，值是%d。\n\r", isprint(ch) ? ch : ' ', ch);

		printf("再来一次？(y/n): ");
		fflush(stdout);
		retry = getch();
		if (isprint(retry))	//只有当retry是显示字符时才显示
			putch(retry);
		putchar('\n');
		fflush(stdout);
	} while (retry == 'y' || retry == 'Y');

	endwin();	//使用库时用于收尾的函数。使用curses库必须最后调用的函数

	return 0;
}