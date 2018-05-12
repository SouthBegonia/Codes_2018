/*
程序功能：编写bput(const char*s,int d,int e,int n)函数实现字符串s显示d毫秒后，消失e毫秒，重复n次后返回调用方。
核心：注意字符串传入函数的格式，显示即停留打印的时间，消失即空白内容覆盖的时间。
注意：puts()和printf()打印字符串区别：puts()会在末尾添加'\n'
*/
#include<stdio.h>
#include<string.h>
#include<time.h>

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

void bput(const char *s, int d, int e, int n)
{
	int i, s_len;
	s_len = strlen(s);
	do
	{
		putchar('\r');							//光标回到本行起点
		printf("%s", s);
		/*注意：此处打印s[]不可用puts()，因为puts()会在末尾添加'\n'*/
		fflush(stdout);
		sleep(d);								//续显示d毫秒
		putchar('\r');
		for (i = 0; i < s_len; i++)				//空白符覆盖
			putchar(' ');
		fflush(stdout);
		sleep(e);								//消失e毫秒
		n--;
	} while (n != 0);
	return;
}

int main()
{
	int a, b, c;
	char k[] = "Hello";
	printf("依次输入显示时间(ms)、消失时间(ms)、重复次数：");
	scanf_s("%d %d %d", &a, &b, &c);
	bput(k, a, b, c);
	printf("\rDone!\n");
	getchar();
	getchar();
	return 0;
}

