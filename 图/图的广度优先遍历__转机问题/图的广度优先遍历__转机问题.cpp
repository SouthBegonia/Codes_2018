/*
	程序功能：构建 n 个城市，m 条线路的无向图，之间路程设为1即1次转机，要求输入起始、终点城市，计算出最少需转机次数。
	广度优先遍历：找出起点到终点最少的遍历次数，即为最少需转机次数。
					广度优先搜索更适用于所有边权值相同的情况（寻找最值只需看遍历次数）
*/
#include<stdio.h>
struct note
{
	int x;												// 城市编号
	int s;												// 转机次数
};
int main()
{
	struct note que[2501];
	int e[51][51] = { 0 }, book[51] = { 0 };
	int head, tail;
	int i, j, a, b, cur, flag=0;
	int n, m;											// n个 城市，m 条路线
	int start, end;										// 起点城市和终点城市

	/*
	构建的城市航线地图见：Codes_2018/图/转机问题.jpg
	*/
	printf("依次输入城市数、线路总数、起点城市、终点城市：");
	scanf_s("%d %d %d %d", &n, &m, &start, &end);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 999999;

	for (i = 1; i <= m; i++)							// 赋予特定城市路线的转机次数 1
	{
		scanf_s("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;									// 无向图，且所有边权重相同
	}

	head = 1, tail = 1;
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[1] = start;

	while (head < tail)
	{
		cur = que[head].x;								// 当前队列中首城市的编号
		for (j = 1; j <= n; j++)
		{
			if (e[cur][j] != 999999 && book[j] == 0)
			{
				que[tail].x = j;						// 符合条件，j号城市入队
				que[tail].s = que[head].s + 1;			// 转机次数+1
				tail++;
				book[j] = 1;							// 标记 j 城市已在队列中
				/*
					广度优先遍历，需要依次遍历所有点，不能取消标记，即不能返回某一点。
				*/
			}
			if (que[tail - 1].x == end)					// 到达目的地城市，退出循环
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;											// 继续下一扩展点
	}

	printf("从城市 %d 到 %d 最少需转机 %d 次", start, end, que[tail - 1].s);
	getchar();
	getchar();
	return 0;
}
/*
	输入： 5 7 1 5
		   1 2
		   1 3
		   2 3
		   2 4
		   3 4
		   3 5
		   4 5
	输出：从城市 1 到 5 最少需转机 2 次
*/