/*
	程序原理：输入n个数组，以符合最小堆的树的形式储存，并且对堆升序排序。
*/
#include<stdio.h>
int h[101];													// 存放堆的数组
int n;														// 堆的大小

/*	交换堆中两个元素的值，即结点间的值  */
void swap(int x,int y)										
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}
/*	
	softdwn():向下调整函数，检验当前结点和其子节点（左和右）数字是否遵循最小堆特征，如不符合则交换。
	一次softdown()表示检查了一个非叶结点。
*/
void siftdown(int i)										// 传入一个需要向下调整的结点i
{
	int t, flag = 0;										// flag标记是否需要继续向下调整
	while (i * 2 <= n && flag == 0)							// 当i结点有子节点且需要调整
	{
		if (h[i] > h[i * 2])								// 判断与左儿子的大小，t 记录较小结点编号
			t = i * 2;
		else
			t = i;
		if (i * 2 + 1 <= n)									// 判断与右儿子的大小，更新 t
		{
			if (h[t] > h[i * 2 + 1])
				t = i * 2 + 1;
		}
		if (t != i)											// 当判断完后，t有改变，说明子节点中（左或右）存在比父节点小的数
		{
			swap(t, i);
			i = t;											// 更新父节点（为刚才交换的子节点），用于while()内再次判断（同上述判断过程）
		}
		else
			flag = 1;										// 当判断完后，t不变，则说明父节点比其2个子节点小（符合最小堆），则无序再调整，flag标记退出循环
	}
}

/*	
	creat():建立堆的函数。从最后一个非叶结点到第1个结点依次向上调整。
	为何从最后一个非叶结点，而不是最后的叶结点：叶节点下再无其他节点，siftdown()传入结点（作为父结点），与其子节点对比，故称向下调整函数，而叶结点无法进行该过程。
*/
void creat()
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

/*	
	deletemax():删除最大的元素。
	过程解释：每次输出堆顶值 t （最小值），把堆末尾值(h[n])赋到堆顶(h[1])，堆元素减 n-- ，堆顶向下调整(siftdown())。连续删除n次后，即返回从小到大n个数。
*/
int deletemax()
{
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}
int main()
{
	int i, num;
	scanf_s("%d", &num);								// 读入要排序的数字个数
	
	for (i = 1; i <= num; i++)
		scanf_s("%d", &h[i]);
	n = num;

	creat();											// 建堆			

	for (i = 1; i <= num; i++)							// 删除顶部元素，连续删除n次就是从大到小输出
		printf("%d ", deletemax());

	getchar();
	getchar();
	return 0;
}