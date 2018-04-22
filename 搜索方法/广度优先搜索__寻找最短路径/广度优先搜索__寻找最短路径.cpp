/*
	广度优先搜索(Breath First Search，BFS)。
	原理概述(待补全)：进行head次的按方向顺序的遍历，走过 tail-1 个数，走过点的信息存于 que[tail]内；
					一直遍历，直到找到终点，所需步数可理解为遍历的次数。
	区别于深度优先搜索：广度依靠遍历数，深度依靠可能数。
*/
#include<stdio.h>
struct note
{
	int x;                                         //横坐标
	int y;										   //纵坐标
	int f;										   //父亲在队列中的编号
	int s;										   //步数
};

int main()
{
	struct note que[2501];						   //地图大小不超过50*50，故队列的扩张不超过2500个
	int book[51][51] = { 0 };                      //标记某坐标是否走过
	int a[51][51] = {                              //地图，从[1][1]到[5][4]，1为障碍
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,1,0,0},
		{0,0,0,0,1},
	};
	int next[4][2] = {                            //表示行走方向的数组
		{ 0,  1},			//向右走
		{ 1,  0},			//向下走
		{ 0, -1},			//向左走
		{-1,  0},			//向上走
	};
	int head, tail;
	int i, j, k;
	int n = 5, m = 4;                           //5行4列的地图
	int startx, starty;					        //起点坐标
	int p, q;								    //终点坐标
	int tx, ty;								    //下一个点的坐标
	int flag;                                   //标记是否达到目的地，0表示未到达，1表示到达

	printf("输入起点坐标和终点坐标： ");
	scanf_s("%d %d %d %d", &startx, &starty, &p, &q);         //目的地坐标

	head = 1, tail = 1;
	que[tail].x = startx;                       //插入起点坐标
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;					//起点已经走过，标记

	flag = 0;
	while (head < tail)
	{
		//枚举四个方向
		for (k = 0; k <= 3; k++)
		{
			//计算下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx<1 || tx>n || ty<1 || ty>m)                 //判断是否越界
				continue;                                     
			/*
				continue: 结束当前 k 的循环，进行下一个方向，即执行 k++循环
			*/

			if (a[tx][ty] == 0 && book[tx][ty] == 0)         //判断下一个点是否是障碍物或者已经未走过
			{
				book[tx][ty] = 1;                            //标记该路径已经走过
				que[tail].x = tx;							 //插入新的点到队列中
				que[tail].y = ty;
				que[tail].f = head;							 //这个点从head中扩展出来，所以他的父亲是head
				que[tail].s = que[head].s + 1;               //步数未父亲的步数+1
				tail++;
				/*
					区别于深度优先搜索，广度优先搜索末尾不需要book[tx][ty]==0，即取消标记。
					因为每个点只入队一次。
				*/
			}

			if (tx == p && ty == q)                         //判断是否到达终点
			{
				flag = 1;
				break;
				/*
					break:结束当前所在的 for 循环（54行），执行到 90行。
				*/
			}
		}

		if (flag == 1)
			break;
		/*
			再次break:结束当前 while 循环（51行），执行 99行。
		*/

		head++;                                            
		/*
			当一个点扩展(遍历)完后，head++ 对后面的点在进行扩展，即进行下一次遍历
		*/
	}
	

	// printf("que[tail-1].f=%d\n", que[tail - 1].f);
	printf("head=%d, tail=%d\n",head, tail);
	printf("最短步数为：%d \n", que[tail - 1].s);            //tail指向队尾（最后一位的下一个位置，空），故-1
	/*
	for (i = 1; i <= head; i++)
		printf("que[%d].s=%d\n", i, que[i].s);
	*/
	getchar();
	getchar();
	return 0;
}
/*
	输入：1 1 2 2
	输出：head=2,tail=5

	解析： tail 作为末尾的指向，表示数组que[tail-1]内均存有数据（que[tail]一直留出来，为空)。
				que[]数组内存的数据为每次循环走过的点的信息，如que[1]存储起点(1,1)，que[2]存储(1,2)点。
				当储存que[2](存储前tail=2,存储后到48行,tail=3)，再进行下个方向，则que[3]用于储存(2,1)点。
				可以理解tail:按方向依次全部走，走过点的个数为 tail-1
					事例中的 tail=5 表示 2 次遍历过程，共搜寻（走过） 5-1=4个点

		   head 可以理解为执行个方向遍历得次数。
				如当初始化后 head=1 ，执行 k=0 循环时，即进行第一次各方向的遍历；
				当四个方向执行完毕后（遍历出可行点(1,2)(2,1))，执行 while 内97行的 head++ ，表示开始第二次遍历。
					事例中的 head=2 即表示进行2次遍历可达到终点。

		   head与tail的关系：没有严格的逻辑关系，head 次的遍历走过 tail-1 个点
				73行：que[tail].s = que[head].s + 1; 表示到达该点的步数，等于到达该点需要遍历得次数。
					进行 108~109 行的输出即可看到走到各点所需步数，即que[i].s的值，体现出 head 与 tail 的关系
*/