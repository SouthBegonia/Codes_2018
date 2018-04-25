/*
	程序原理：设定n个顶点，m条线的城市地图，每条线设定距离，要求算出任意两个点之间的最短路径，更新并打印出地图。
	Floyd-Warshall算法：解决任意两点间的最短路径的一种算法。可以在任何图中使用，包括有向图、带赋权边的图。
	概念图： C code\Code_2018\最短路径\Floyd-Warshall算法\Floyd-Warshall.jpg
*/
#include<stdio.h>
int main()
{
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	int inf = 999999;										// 定义为正无穷

	printf("输入顶点个数和边数： ");
	scanf_s("%d %d", &n, &m);

	for (i = 1; i <= n; i++)								// 初始化，自身点设为0，其余暂设为无穷
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
	for (i = 1; i <= m; i++)								// 读入边，设定其距离
	{
		scanf_s("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
		/* 有向图。表示 t1 顶点到 t2 顶点的距离为 t3	  */
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
	/*
		Floyd-Warshall算法核心：
				如果从 i城 走到 k城，再从 k城 走到 j城 的距离小于直接从 i城 走到 j城 的距离，
				则将该较短的距离更新取代 i城 走到 j城 的距离。
			可以理解为，通过引入中转点k，计算是否存在两点间最短路程。
	*/

	for (i = 1; i <= n; i++)								// 打印出更新后的地图
	{
		for (j = 1; j <= n; j++)
			printf("%10d", e[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}
/*
	Floyd-Warshall算法和深度优先搜索、广度优先搜索都可用于搜索两点之间的最短距离，
		共同点：都用到了“图的邻接矩阵储存法”
		不同点：深度、广度优先搜索两个点间最短距离只需进行n*2遍搜索，即对每两个点都进行一次深度或者广度优先搜索。时间复杂度O(N*2)
				Floyd-Warshall算法的时间复杂度为O(N*3)，但代码核心部分简洁（28~32行）
*/