/*
程序功能：获取玩家从键盘输入的字符，不回车显示。

getch:直接从键盘读取字符而不回显，返回读取到字符的值
putch:在界面上显示字符c

备注：在提供了Visual C++的MS-Windows/MS-DOS环境下运行

*/
#include<stdio.h>
#include<conio.h>	//提供getch和putch的
#include<ctype.h>	//提供isprint

int main()
{
	int ch;
	int retry;

	do {
		printf("请按键。");
		ch = getch();

		printf("\n按下的键是%c，值是%d。\n", isprint(ch) ? ch : ' ', ch);

		printf("再来一次？(y/n): ");
		retry = getch();
		if (isprint(retry))	//只有当retry是显示字符时才显示
			putch(retry);
		putchar('\n');
	} while (retry == 'y' || retry == 'Y');

	getchar();
	return 0;
}