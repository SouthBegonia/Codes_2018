/*
	程序原理：输入n个数组，以符合最大堆的树的形式储存，并且对堆升序排序。
*/
#include<stdio.h>
int h[101];													// 存放堆的数组
int n;														// 堆的大小

															/*	交换堆中两个元素的值，即结点间的值  */
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}
/*
	softdwn():向下调整函数，检验当前结点和其子节点（左和右）数字是否遵循最大堆特征，如不符合则交换。
	最大堆：父节点比子节点大。
*/
void siftdown(int i)										// 传入一个需要向下调整的结点i
{
	int t, flag = 0;										// flag标记是否需要继续向下调整
	while (i * 2 <= n && flag == 0)							// 当i结点有子节点且需要调整
	{
		if (h[i] < h[i * 2])								// 判断与左儿子的大小，t 记录较大结点编号
			t = i * 2;
		else
			t = i;
		if (i * 2 + 1 <= n)									// 判断与右儿子的大小，更新 t
		{
			if (h[t] < h[i * 2 + 1])
				t = i * 2 + 1;
		}
		if (t != i)											// 当判断完后，t有改变，说明子节点中（左或右）存在比父节点大的数
		{
			swap(t, i);
			i = t;											// 更新父节点（为刚才交换的子节点），用于while()内再次判断（同上述判断过程）
		}
		else
			flag = 1;										// 当判断完后，t不变，则说明父节点比其2个子节点小（符合最小堆），则无序再调整，flag标记退出循环
	}
}

void creat()
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

/*	
	heapsort():堆排序函数。由于creat()建堆函数(内有siftdown()函数调整)后，堆是最大堆 ，程序要求升序输出，则需要heapsort()对堆进行升序排序。
*/
void heapsort()
{
	while (n > 1)
	{
		swap(1, n);
		n--;
		siftdown(1);
	}
}

int main()
{
	int i, num;
	scanf_s("%d", &num);								// 读入要排序的数字个数

	for (i = 1; i <= num; i++)
		scanf_s("%d", &h[i]);
	n = num;

	creat();											// 建堆			

	heapsort();											// 堆排序

	for (i = 1; i <= num; i++)
		printf("%d ", h[i]);
	/*
		区别于最小堆排序：
			最小堆：每次输出堆顶值（最小值），把堆末尾值赋到堆顶，堆元素减1(n--)，堆顶向下调整。连续删除n次后，即从小到大输出n个数。 
			最大堆：每次将堆顶（最大值）与堆低值(较小值）交换，同时n--，即每次把最大值移到数组末尾，然后对堆顶进行向下调整，重复进行直到n=1时抵达堆顶无序调整，此时h[]数组已为升序排列。
	*/
	getchar();
	getchar();
	return 0;
}