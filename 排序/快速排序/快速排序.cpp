/*
    快速排序：待排序数组a[n]，选取首位为基准数(temp)，设定左右标记(i,j)；
先右后左个移动一次(i++,j--）检索，当遇到不符合排序的数值则将其数值交换(标记不换)，使得基准数两侧数字大于或者小于基准数。
当左右标记相遇(i=j)，则交换a[i]（a[j])和基准数(temp)的值；
再递归排序左右个分组，再细分多次排序，最后跳出函数，打印。
    类似于二分法。
    算法复杂度：最差为 O(N^2)，平均为 O(NlogN)
*/
#include<stdio.h>
int a[101], n;                         //定义全局变量
 
void quicksort(int left, int right)    //快速排序函数(升序) 
{
	int i, j, t, temp;
	if (left > right)             
		return;                        //用于递归跳出快速排序函数

	temp = a[left];                    //temp中存的就是基准数（假定为数组首位a[1]）
	i = left;
	j = right;
	while (i != j)                     //前提：左右标记不等时循环
	{
		//从右往左对比，若右边的数大于基准数（符合升序），标记左移
		while (a[j] >= temp && i < j)
			j--;
		//在从左往右对比，若左边的数小于基准数（符合升序），则右移
		while (a[i] <= temp && i < j)
			i++;

		//当找到 a[j]<temp && a[i]>temp 且标记不相遇(i<j)时，交换两个数
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//当标记相遇(i=j)时，对应的数值与基准数(a[left])交换，即基准数归位
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);            //处理左侧的分组，这里是一个递归的过程
	quicksort(i + 1, right);           //继续处理右边的分组，right依旧为 n 

}

int main()
{
	int i,j;
	//读入数据
	scanf("%d",&n);                    //需要对 n 个数排序
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	quicksort(1, n);                   //调用快速排序函数

	//排序后的结果
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);

	getchar();
	getchar();
	return 0;

}