/*
程序功能：实现字符串的滚动打印，滚动速度可设定。
核心：向左和向右滚动代码区别，滚动速度的设定。
*/
#include<stdio.h>
#include<string.h>
#include<time.h>

int sleep(unsigned long x)					//等待 x 毫秒
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
	int cnt = 0;							//第几个字符在最前面
	char name[] = "Hello World ";			//要显示的字符串
	int name_len = strlen(name);
	
	while (1)
	{
		putchar('\r');						//光标移到本行开头
		for (i = 0; i < name_len; i++)
		{
			if (cnt + i < name_len)
				putchar(name[cnt + i]);
			else
				putchar(name[cnt + i - name_len]);
		}
		fflush(stdout);
		sleep(500);							//0.5秒滚动更新一次

		/*从左往右滚动
		if (cnt > 0)
			cnt--;
		else
			cnt = name_len - 1;
		*/

		/*从右往左滚动*/
		if (cnt < name_len - 1)
			cnt++;							
		else
			cnt = 0;						//字符串完整滚动完一次，下一次从最前面的字符开始
	}
	getchar();
	getchar();
	return 0;
}