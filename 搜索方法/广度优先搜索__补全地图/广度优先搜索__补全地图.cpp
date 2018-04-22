/*

*/
#include<stdio.h>
struct note
{
	int x;
	int y;
};
int main()
{
	struct note que[2501];
	int head, tail;
	int a[51][51] = {
		{0,0,0,0,0,0,0,0,0,0,0},
		{0,1,2,1,0,0,0,0,0,2,3},
		{0,3,0,2,0,1,2,1,0,1,2},
		{0,4,0,1,0,1,2,3,2,0,1},
		{0,3,2,0,0,0,1,2,4,0,0},
		{0,0,0,0,0,0,0,1,5,3,0},
		{0,0,1,2,1,0,1,5,4,3,0},
		{0,0,1,2,3,1,3,6,2,1,0},
		{0,0,0,3,4,8,9,7,5,0,0},
		{0,0,0,0,3,7,8,6,0,1,2},
		{0,0,0,0,0,0,0,0,0,1,0},
	};
	int book[51][51] = { 0 };
	int i, k,  sum, max = 0, mx, my, n=10, m=10, startx, starty, tx, ty;
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
	book[startx][starty] = 1;					//标记起点
	sum = 1;

	while (head < tail)
	{
		//枚举四个方向
		for (k = 0; k <= 3; k++)
		{
			//尝试下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx<1 || tx>n || ty<1 || ty>m)					//判断是否越界
				continue;
			if (a[tx][ty] > 0 &&book[tx][ty] == 0)				//如果是陆地且从未走过
			{
				sum++;
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;                                                 //向下一个点扩展（遍历）
	}
	printf("岛屿大小：sum = %d\n", sum);
	getchar();
	getchar();
	return 0;
}