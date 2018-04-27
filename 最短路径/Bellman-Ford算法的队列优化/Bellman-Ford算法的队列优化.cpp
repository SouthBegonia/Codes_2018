/*

*/
#include<stdio.h>
int main()
{
	int n, m, i, k;
	int u[8], v[8], w[8];
	// int u[8] = { 0,1,1,2,2,3,4,5 }, v[8] = { 0,2,5,3,5,4,5,3 }, w[8] = { 0,2,10,3,7,4,5,6 };
	int first[6] = { 0 }, next[8];
	int dis[6] = { 0 }, book[6] = { 0 };
	int que[101] = { 0 }, head = 1, tail = 1;
	int inf = 999999;

	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= n; i++)								// 初始化 dis 数组，表示1号顶点到i号顶点的初始距离
		dis[i] = inf;
	dis[1] = 0;
	for (i = 1; i <= n; i++)								// 初始化 book 数组，表示开始时都不在队列中
		book[i] = 0;
	for (i = 1; i <= n; i++)								// 初始化 first 数组，表示1~n号顶点暂时都没有边
		first[i] = -1;

	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d %d", &u[i], &v[i], &w[i]);
		next[i] = first[u[i]];								// 建立邻接表
		first[u[i]] = i;
	}

	que[tail] = 1;											// 1号顶点入队
	tail++;
	book[1] = 1;											// 标记1号顶点已经入队

	while (head < tail)
	{
		k = first[que[head]];								// 当前需要处理的队首顶点
		while (k != -1)										// 扫描当前顶点所有的边
		{
			if (dis[v[k]] > dis[u[k]] + w[k])				// 判断是否松弛成功
			{
				dis[v[k]] = dis[u[k]] + w[k];				// 更新顶点1号顶点 v[k] 的距离
				if (book[v[k]] == 0)						// 判断顶点 v[k] 是否在队列中
				{
					que[tail] = v[k];						// v[k] 顶点入队
					tail++;
					book[v[k]] = 1;							// 标记 v[k] 顶点已经入队
				}
			}
			k = next[k];
		}
		book[que[head]] = 0;								// 出队
		head++;
	}
	for (i = 1; i <= n; i++)
		printf("dis[%d]=%d ", i, dis[i]);

	getchar();
	getchar();
	return 0;
}