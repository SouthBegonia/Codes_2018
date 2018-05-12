/*
程序功能：打印倒计时，每隔一秒打印一个（覆盖上个数）。
clock():求处理器调用某个进程所花费的时间，暂理解为执行到该命令时进程已花费的时间。
*/
#include<stdio.h>
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
int main()
{
	int i;
	clock_t c;

	for (i = 11; i > 0; i--)					// 从10倒数
	{
		printf("\r%2d", i);						// '\r'回车符回到本行开头
		fflush(stdout);							// 强制清空缓存区内容，使得立即打印
		sleep(1000);
	}
	printf("\rFIRE!\n");

	c = clock();								// 记录程序至此运行时间
	printf("程序开始运行后经过了%.1f秒。\n", (double)c / CLOCKS_PER_SEC);
	getchar();
	return 0;
}