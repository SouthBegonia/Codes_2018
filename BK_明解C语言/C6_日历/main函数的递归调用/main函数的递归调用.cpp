/*
程序功能：main函数的递归调用。
*/
#include<stdio.h>

int main(void)
{
	static int x = 5;	//静态变量
	static int v = 0;	//静态变量

	if (--x > 0)
	{
		printf("x     = %d\n", x);
		printf("main()= %d\n", main());
		v++;
		return v;
	}
	else
		return 0;

}
