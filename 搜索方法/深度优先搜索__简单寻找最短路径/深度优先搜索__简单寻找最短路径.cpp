/*
	程序功能：建立地图、起点、中点、障碍物，要求算出有几种路径，切最短路径的步数是多少。
	深度优先搜索应用：当目前点可以走时，则再次调用函数继续行走。
	深度优先搜索基本模型：参照于 深度优先搜索__盒子填充 内说明

*/
#include<stdio.h>
int n, m, p, q, way=0, min = 999999;
int a[51][51] = {                        //设定的地图，起始为a[1][1],第0行和0列为0（不算入边界）。
	{0,0,0,0,0},                         //空地为0，障碍物为1
	{0,0,0,1,0},
	{0,0,0,0,0},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,0,0,0,1},
};
int book[51][51];                        //点的标记，起始全为 0 表示未走过，1 表示为走过

void dfs(int x, int y, int step)         //起始点 (x,y)，步数 step
{
	int next[4][2] = {
		{0,1},                           //向右走
		{1,0},							 //向下走
		{0,-1},							 //向左走
		{-1,0},							 //向上走
	};
	int tx, ty, k;

	if (x == p && y == q)                 //如果到达目的地坐标
	{
		if (step < min)
			min = step;
		way++;                            //计算可行路径的总数
		return;
	}

	for (k = 0; k <= 3; k++)              //对4个方向进行枚举
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		/*
			k从0循环到3过程，自行计算看出向4个方向走的优先顺序为：右下左上
			每次走一步（一个方向）
		*/

		if (tx<1 || tx>5 || ty<1 || ty>4)               //（地图5行4列）判断是否越界
			continue;                                   //结束当前 k 次的循环（不跳出for），执行k++循环

		if (a[tx][ty] == 0 && book[tx][ty] == 0)        //如果该点可以走（无界无障碍）
		{
			book[tx][ty] = 1;                           //标记该点已经走过
			dfs(tx, ty, step + 1);                      
			/*
				已走过该点后，以该点(tx,ty)为新起始点，已走过步数(step+1)为参数调用dfs()
			*/
			book[tx][ty] = 0;                            //取消该点的标记（否则后续新的循环该点不可用）
		}
	}
	return;
}

int main()
{
	int i, j, startx, starty;

	printf("输入起点坐标： ");
	scanf_s("%d %d", &startx, &starty);
	printf("输入终点坐标： ");
	scanf_s("%d %d", &p, &q);

	book[startx][starty] = 1;                            //标记起点已经走过
	dfs(startx, starty, 0);                              //从起点开始调用 dfs()

	printf("有 %d 种走法\n", way);
	printf("最短步数： %d",min);
	getchar();
	getchar();
	return 0;
}
/*
	输入： 1 1
		   4 3
	输出：共7中办法，最短7步
	解释：优先右下左上的方向走，dfs()自身调用次数较多。
		  可以看出深度优先搜索基本原理是找出所有办法，从中比较选出最有解。
*/
