/*
程序功能：打印所需个数的自然数。
核心：动态分配储存空间。
malloc(size_t n,size_t size):为n个大小为size字节的对象分配储存空间，该空间内的所有位都会初始化为0
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *x;
	int n;

	printf("要分配储存空间的数组的元素个数：");
	scanf("%d", &n);

	x = (int *)calloc(n, sizeof(int));		// 分配

	if (x == NULL)
		puts("储存空间分配失败。");
	else {
		int i;

		printf("初始化后：\n");
		for (i = 0; i < n; i++)
			printf("x[%d] = %d\n", i, x[i]);
		
		printf("\n赋值后：\n");
		for (i = 0; i < n; i++)			//赋值
			x[i] = i;
		for (i = 0; i < n; i++)
			printf("x[%d] = %d\n", i, x[i]);
		free(x);			//释放
	}
	getchar(); getchar();
	return 0;
}