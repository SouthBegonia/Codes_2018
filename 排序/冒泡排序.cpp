//冒泡排序 
#include<stdio.h>
int main()
{
	int  a[100], i, j, t, n;
	scanf_s("%d", &n);              //输入一个数n，表示接下来有n个数
	for (i = 1; i <= n; i++)            //循环读入n个数到数组a中 
		scanf_s("%d", &a[i]);

	//冒泡排序的核心 
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)  //从第1位开始比较直到最后一个尚未归位的数
		{
			if (a[j] < a[j + 1])   //比较大小并交换
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
		for (i = 1; i <= n; i++)     //输出
			printf("%d", a[i]);

		getchar();
		getchar();
		return 0;
}

