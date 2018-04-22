/*
	程序原理：以广度优先搜索方法替代枚举法解决炸弹人游戏。
*/
#include<stdio.h>
struct note
{
	int x;
	int y;
};
char a[20][21] = {
	//0	  1   2   3   4   5   6   7   8   9   10  11  12
	{ '#','#','#','#','#','#','#','#','#','#','#','#','#' },        //0
	{ '#','G','G','.','G','G','G','#','G','G','G','.','#' },        //1
	{ '#','#','#','.','#','G','#','G','#','G','#','G','#' },		//2
	{ '#','.','.','.','.','.','.','.','#','.','.','G','#' },		//3
	{ '#','G','#','.','#','#','#','.','#','G','#','G','#' },		//4
	{ '#','G','G','.','G','G','G','.','#','.','G','G','#' },		//5
	{ '#','G','#','.','#','G','#','.','#','.','#','.','#' },		//6
	{ '#','#','G','.','.','.','G','.','.','.','.','.','#' },		//7
	{ '#','G','#','.','#','G','#','#','#','.','#','G','#' },		//8
	{ '#','.','.','.','G','#','G','G','G','.','G','G','#' },		//9
	{ '#','G','#','.','#','G','#','G','#','.','#','G','#' },		//10
	{ '#','G','G','.','G','G','G','#','G','.','G','G','#' },		//11
	{ '#','#','#','#','#','#','#','#','#','#','#','#','#' }			//12
};
int getnum(int i, int j)									   //统计当前点可消灭敌人个数的函数
{
	int sum, x, y;
	sum = 0;

	x = i, y = j;
	while (a[x][y] != '#')                                    //如果不是墙
	{
		if (a[x][y] == 'G')									  //如果是敌人
			sum++;
		x--;                                                  //向上统计
	}
	x = i, y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		x++;												 //向下统计
	}
	x = i, y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		y--;												 //向左统计
	}
	x = i, y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		y++;												 //向右统计
	}

	return sum;
}

int main()
{
	struct note que[401];
	int head, tail;
	int book[20][20] = { 0 };           //标记数组
	int i, j, k, sum, max = 0;			//消灭敌人数 sum
	int mx, my;							//最佳放置点(消灭敌人最多)坐标
	int n=13, m=13;						//n行m列的地图
	int startx, starty;					//起点坐标
	int tx, ty;							//下一个点的坐标

	int next[4][2] = {
		{ 0,  1 },			//向右走
		{ 1,  0 },			//向下走
		{ 0, -1 },			//向左走
		{ -1,  0 },			//向上走
	};

	printf("输入起点： ");
	scanf_s("%d %d", &startx, &starty);

	head = 1, tail = 1;

	que[tail].x = startx;                       //插入起点坐标
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;					//起点已经走过，标记
	max = getnum(startx, starty);
	mx = startx;
	my = starty;

	while (head < tail)
	{
		//枚举四个方向
		for (k = 0; k <= 3; k++)
		{
			//尝试下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)			//判断是否越界
				continue;
			if (a[tx][ty] == '.'&&book[tx][ty] == 0)			//如果是平地且从未走过
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

				sum = getnum(tx, ty);							//统计当前点可以消灭敌人个数

				if (sum > max)
				{
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
		head++;													
		/*
			head++ 进行下一次遍历;
			区别于寻找最短路径，我们需要的是遍历所有点计算对应点可消灭敌人个数。
		*/
	}
	//所有遍历完成，得出 max
	printf("遍历次数为:head=%d, 遍历点个数为:tail-1=%d\n", head, tail - 1);
	printf("将炸弹放置在（%d,%d）处，可以消灭 %d 个敌人\n", mx, my, max);

	getchar();
	getchar();
	return 0;
}
