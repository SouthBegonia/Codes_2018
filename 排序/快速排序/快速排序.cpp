/*输入n个数字，后进行排序并打印*/
#include<stdio.h>
int a[101], n;                   //定义全局变量
 
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;

	temp = a[left];              //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j)
	{
		//从右往左走
		while (a[j] >= temp && i < j)
			j--;
		//在从左往右找
		while (a[i] <= temp && i < j)
			i++;

		//交换两个数在数组中的位置
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//最终将基准数归位
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);            //继续处理左边的，这里是一个递归的过程
	quicksort(i + 1, right);           //继续处理右边的，同样是递归

}

int main()
{
	int i,j;
	//读入数据
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	quicksort(1, n);                   //快速排序调用

	//排序后的结果
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);

	getchar();
	getchar();
	return 0;

}