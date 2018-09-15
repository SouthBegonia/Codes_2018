/*将3x4的二位数组传递给函数func()，然后在func()中将其内容输出*/
#include<stdio.h>

void func(int (*hoge)[3])   //传递的二维数组
{
	int i,j;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
			printf("%d, ",hoge[i][j]);
		putchar('\n');
	}
}

int main()
{
	int hoge[][3]={
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{10,11,12},
	};
	
	func(hoge);
	
	getchar();
	return 0;
}
