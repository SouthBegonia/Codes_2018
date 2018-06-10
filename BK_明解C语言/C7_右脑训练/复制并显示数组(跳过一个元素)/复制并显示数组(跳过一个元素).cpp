/*
程序功能：复制并显示数组(跳过某一个元素)
*/
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int i, j, x;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8] = { 0 };

	srand(time(NULL));

	x = rand() % 9;		//随机设定跳过的元素

	i = j = 0;
	while (i < 9)
	{
		if (i != x)
			a[j++] = dgt[i];	//复制时跳过dgt[x]
		i++;
	}
	for (i = 0; i < 8; i++)
		printf("%d  ", a[i]);

	putchar('\n');
	getchar();
	return 0;

}