/*
程序功能：设定3个随机数的运算，键入数值直到正确，计算该过程（人为计算的过程）耗时。
原理：在处理过程的起始点、终点设定参数记录时间（start=clock()、end=clock())所得时间差即为耗时。
clock_t：头文件<time.h>把返回值的类型clock_t型定义为等同于算数型。
		即 typedef unsigned clock_t;可以理解为把新类型明clock_t赋给原类型unsigned。
		而不同编程环境下不一定是unsigned。

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int a, b, c;							//进行加法运算的随机数
	int x;									//读取的值
	clock_t start, end;						//开始时间、结束时间
	double req_time;						//总用时

	srand(time(NULL));						//设定种子
	a = rand() % 11;						//生成0~10的随机数
	b = rand() % 11;
	c = rand() % 11;

	printf("%d + %d + %d = ",a,b,c);

	start = clock();						//开始计算
	while (1)
	{
		scanf_s("%d", &x);
		if (x == a + b + c)
			break;
		printf("错误，请重新输入：");
	}
	end = clock();							//计算结束
	req_time = (double)(end - start) / CLOCKS_PER_SEC;

	printf("共计用时 %.1f 秒。\n", req_time);
	printf("start=%.2fs,end=%.2fs", (double)start / CLOCKS_PER_SEC, (double)end / CLOCKS_PER_SEC);
	getchar();
	getchar();
	return 0;
}