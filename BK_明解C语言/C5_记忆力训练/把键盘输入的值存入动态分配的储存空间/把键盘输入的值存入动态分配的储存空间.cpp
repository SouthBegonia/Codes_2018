/*
程序功能：简单实现把键入值存入申请的动态储存空间。
核心：scanf()读入信息所存储的位置。
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *x;

	x = (int *)malloc(sizeof(int));		//分配（强制转换类型）

	if (x == NULL)
		puts("储存空间分配失败。");
	else {
		printf("要存入 *x 的值：");
		scanf("%d", x);			
		/*
		注意，此处是把scanf()读取的整数值存入 calloc() 为 x 所分配的空间；
		若误写成 &x 则表示将整数值存入存放指针 x 的空间，此时 x 本身值被改写，无法指向calloc()分配的空间，且free()会把不正确的值(calloc分配的空间的地址以外的值)传递给scanf()
		*/
		printf("*x = %d\n", *x);
		free(x);
	}
	getchar(); getchar();
	return 0;
}