/*
程序功能：逐一打印字符串中的字符，打印完后再逐一往后消去。
核心：往后逐一消去的代码 printf("\b \b")
*/
#include<stdio.h>
#include<time.h>
#include<string.h>

int sleep(unsigned long x)								//等待 x 毫秒
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
	int i;
	char name[] = "Hello World!";
	int name_len = strlen(name);

	while (1)
	{
		for (i = 0; i < name_len; i++)				//从头开始逐一打印
		{
			putchar(name[i]);					
			fflush(stdout);
			sleep(500);
		}
		for (i = 0; i < name_len; i++)				//从末尾开始逐一消去
		{
			printf("\b \b");						//注意：先移动光标到上一位置，再打印空白符，再移动
			fflush(stdout);
			sleep(500);
		}
		printf("Done!\n");
		getchar();
		getchar();
		return 0;
	}
}