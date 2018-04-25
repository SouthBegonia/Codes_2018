/*
		程序原理：构建5个点的有向城市地图，之间有具体数值代表距离，要求计算从1城市走到5城市最短距离。
		深度优先遍历：找出所有可以从1走到5的可能路线，对比得出最短距离 min 
		疑问：是否能实现打印出最短距离的路线（因为深度优遍历是尝试所有可能，若打印的话只能打印所有路线）
*/
#include<stdio.h>
int n = 5, min = 999999, book[101] = { 0 };
int e[101][101] = {
	{ 0,0,0,0,0,0 },
	{ 0,0,2,999999,999999,10},
	{ 0,999999,0,3,999999,7},
	{ 0,4,999999,0,4,999999},
	{ 0,999999,999999,999999,0,5},
	{ 0,999999,999999,3,999999,0},
	/*
	二维数组图：Codes_2018/图/城市地图__1.jpg
	城市地图模型：Codes_2018/图/城市地图__2.jpg
	*/
};
void dfs(int cur, int dis)
{
	int j;
	if (dis > min)										// 如果当前走的路程大于之前找到的最小值，则没必要再往下尝试，返回
	{
		printf("%d ", cur);
		return;
	}
		
	if (cur == n)										// 如果到达了目的地城市
	{
		printf("%d ", cur);
		if (dis < min)
			min = dis;									// 更新最小值
		return;
	}
	for (j = 1; j <= n; j++)
	{
		if (e[cur][j] != 999999 && book[j] == 0)
		{
			printf("%d ", cur);
			/*
				尝试是否能打印出最短的路程：
					27行和36行的 printf 运行后，结果为 1 2 3 4 5 2 5 1 5我们分开看
						1 2 3 4 5 ：1、2、3、4为40行打印结果，表示一次遍历直到终点走过的点，5为抵达终点31行打印结果。
						2 5 ：因为此时遍历从2号城市开始，接下来检索5号城市，故前面无法打印起点城市1，该路线为1、2、5。5为抵达终点27行打印结果。
						1 5：此路线为1、5，路程比1、2、5，故无法执行到31行，而是执行25行的printf，打印出5，而后26行就return。
			*/
			book[j] = 1;
			dfs(j, dis + e[cur][j]);
			book[j] = 0;								// 涉及最小值，需要取消标记
		}
	}
	return;
}
int main()
{
	int i, j, m=5, a, b, c;
	/*	
		城市（元素）信息已经在e[101][101]内预设好，如需自行设置可调用如下代码
		n行m列，点自身为0，无边连接为999999，有边连接为正数（距离）
	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 999999;
		此处为有向图，表示城市（元素）之间单向，不可逆。
		e[a][b]表示城市 a 可以到城市 b ，其值 c 表示之间距离
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d %d", &a, &b, &c);
		e[a][b] = c;								// 有向图标志
	}
	*/
	book[1] = 1;									// 标记起点，1 号城市
	dfs(1, 0);										// 参数 城市 路程
	printf("城市 1 到城市 5 的最短路程为 %d", min);
	/*
		解析：可能额路线有： 1、2、3、4、5  距离14
							1、2、5		   距离9
							1、5			   距离10
							(1、2、3、1 这样的路线被book[]标记数组所排除）
	*/
	getchar();
	getchar();
	return 0;
}