/*
	程序功能：解决带有负权边的图（边的权值为负）。
	 Ballman-Ford算法：对所有的边进行n-1次“松弛”操作。
	概念图： C code\Code_2018\最短路径\Bellman-Ford算法\Ballman-Ford算法.jpg
*/
#include<stdio.h>
int main()
{
	int dis[10] = { 0,0,999999,999999,999999,999999 };
	int bak[10], i, k;
	int n = 5, m = 5;
	int u[10] = { 0,2,1,1,4,3 }, v[10] = { 0,3,2,5,5,4 }, w[10] = { 0,2,-3,5,2,3 };
	/*	u[]、v[]、w[]组成的给出边的信息的顺序可随意，因为不影响松弛的结果，但各边信息必须对应，如 2 3 2、1 2 -3 等	*/
	int check, flag;
	int inf = 999999;

	/*	初始化过程，u[],v[],w[],dis[]已经设定，如需更改可参考以下代码
	for (i = 1; i <= m; i++)
		scanf_s("%d %d %d", &u[i], &v[i], &w[i]);
	for (i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;
	*/
	for (k = 1; k <= n - 1; k++)							// 进行 n-1 轮松弛
	{
		for (i = 1; i <= n; i++)							// 将dis数组备份至bak数组中
			bak[i] = dis[i];
		for (i = 1; i <= m; i++)							// 进行 1 轮松弛
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
		/*
			根据键入的各边信息，则30行的比较为：
				dis[3]	dis[2]+2
				dis[2]	dis[1]-3
				dis[5]	dis[1]+5
				dis[5]	dis[4]+2
				dis[4]	dis[3]+3
			需要说明的是：每次松弛，dis[]值会改变，例如：在进行第2轮（k=2）松弛时，33行能松弛dis[3]，当进行到37行时，dis[3]也相应改变。
		*/
		check = 0;
		for(i=1;i<=n;i++)									// 如果dis数组没有更新（松弛），则提前退出
			if (bak[i] != dis[i])
			{
				check = 1;
				break;
			}
	}
	flag = 0;
	for (i = 1; i <= m; i++)								// 检测负权回路
		if (dis[v[i]] > dis[u[i]] + w[i])
			flag = 1;
	if (flag == 1)
		printf("此图含有负权回路。\n");
	else
	{
		for (i = 1; i <= n; i++)
			printf("%d ", dis[i]);
	}
	getchar();
	getchar();
	return 0;
}