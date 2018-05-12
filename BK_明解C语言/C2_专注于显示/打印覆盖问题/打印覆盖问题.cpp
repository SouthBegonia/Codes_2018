/*
程序功能：间歇性覆盖打印pritnf()语句。
原理：'\r'回车符使光标回到本行最前面，新得字符覆盖老的字符，但假如长短不一会造成不完全覆盖。
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
	printf("My name is South.");
	fflush(stdout);
	sleep(2000);
	printf("\rHow do you do?");
	fflush(stdout);
	sleep(2000);
	printf("\rThanks!");
	/*
	使用回车符'\r'光标移到首位，但结果后两句打印只覆盖了第一句的靠前部分，
	原因在于以上三句printf()内容长度不一，加入将后两句末尾添加空白符补齐，可实现完全覆盖。
	*/
	getchar();
	return 0;
}