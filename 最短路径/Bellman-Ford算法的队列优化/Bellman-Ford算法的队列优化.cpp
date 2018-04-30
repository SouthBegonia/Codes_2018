/*
	程序原理：每次从队首(head)取出一个顶点，并对与其相邻的所有顶点进行松弛尝试，如果某个邻点松弛成功，且不在队列que[]中(head与tail之间)则将其加入到队列；
				当前顶点处理完后，顶点出队(head++)，并对队列中的下一个新队首重复同样的操作。
	队列优化：只有在前一遍松弛中改变了最短路程估计值的顶点，才可能引起它的邻接点最短路程的估计值发生改变，因此用que[]来记录被成功松弛的顶点，再对其中的点进行处理，降低了算法的时间复杂度。
	存有疑问：键入点和边信息时，first[]和next[]和k值得关系。
*/
#include<stdio.h>
int main()
{
	int n, m, i, k;
	int u[8], v[8], w[8];
	/* 
	int u[8] = { 0,1,1,2,2,3,4,5 }, v[8] = { 0,2,5,3,5,4,5,3 }, w[8] = { 0,2,10,3,7,4,5,6 };
	*/
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
		/*	疑惑点	*/
		next[i] = first[u[i]];								// 建立邻接表
		first[u[i]] = i;
	}
	/*
	for (i = 1; i <= n; i++)
		printf("%d ", first[i]);
	putchar('\n');
	for (i = 1; i <= m; i++)
		printf("%d ", next[i]);
	*/
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
	/*
	for (i = 1; i <= 10; i++)
		printf("%d ", que[i]);
	*/
	getchar();
	getchar();
	return 0;
}

/*
检测到的：
first[]={0, 2, 4, 5, 6, 7 } 
next[]={ 0,-1, 1,-1, 3,-1,-1,-1} 
que[]={0,1,5,2,3,5,4,}
dis[1] = 0 dis[2] = 2 dis[3] = 5 dis[4] = 9 dis[5] = 9
*/