/*
	程序原理：构建二维数组来存储图，这种方法称为图的邻接矩阵储存法。
	深度优先遍历原理：首先以一个未被访问的顶点作为起始点，沿当前顶点的边走到未被访问过的点；
					 当没有未访问的顶点时，则回到上一个顶点，继续访问其他顶点，直到所有点都被访问过。
*/
#include<stdio.h>
int book[101], sum, n=5;
int e[101][101] = {
	{0,0,0,0,0,0},
	{0,0,1,1,999999,1},
	{0,1,0,999999,1,999999},
	{0,1,999999,0,999999,1},
	{0,999999,1,999999,0,999999},
	{0,1,999999,1,999999,0},
	/*
		用e[101][101]二维数组储存图的方法称为图的邻接矩阵存储法；
		二维数组构成的图见 Codes_2018/图/图__邻接矩阵__1.jpg
		构成的图见 Codes_2018/图/图__邻接矩阵__2.jpg

		解释： 0表示自身点(i=j)，1 表示有边（如(1,2)为1，,表示1号元素和2号元素之间有边，同理可以看出1、3、5相互有边)；
				9999999 表示 ∞ ，即没有边。
	*/
};

void dfs(int cur)											// cur 当前所在顶点的编号（仅有1~5）
{
	int i, m=5;
	printf("%d ", cur);
	sum++;													// 访问顶点数

	if (sum == n)											// 当全部顶点（5个）全部访问完，则退出
		return;
	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1 && book[i] == 0)
		{
			/*
				首先判断当前顶点 cur 与 顶点 i 是否有边，
				其次还需判断该点是否已经走过。
					若把 1 、4设定为相连(即将(1,4)和(4,1)设为1)，结果依旧不变，因为1号元素一开始就被标记已经走过（67行）。
			*/
			book[i] = 1;
			dfs(i);
		}
	}
	return;
	/*
		dfs()过程解析：当main函数调用dfs(1)后，将1号点(1,1)与其他点对比；
							对比过程即对比概念图1的第一行，可以看到第一行1中，1列元素为0（即自身），2、4、5列为1,即1号元素与他们有边，4列为无限大，即1号元素与4号元素没边。
					   当dfs(1)内检索到(1,2)点即第2个元素，有边且没走过，则调用dfs(2)；
							继续下去可检索出与4号元素相连，就再也没其他点，则首先 return 到 dfs(2)；
							注意！ 39 行dfs(2)代码后面无book[]=0 即不取消标记，与我们之前看的深度搜索的其他方法区别在此，因为我们本例目的在于查看检索个元素的顺序，不在于查看路径和得最短路径。
							此时2号元素再无其他边，则回到1号元素，检索其他边（3、4号元素）。
	*/
}
int main()
{
	int i, m = 5;
	/*
	因为这里是无向图，故e[b][a]也赋值1，若为有向图只需要e[a][b]=1
	二维数组e[101][101]已提前输赋值，故不必该循环，如需要可自行设置。
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;
	}
	*/
	book[1] = 1;											// 标记1号点已经访问过	
	dfs(1);

	getchar();
	getchar();
	return 0;
	/* 输出结果：1 2 4 3 5  即为检索元素的顺序*/
}