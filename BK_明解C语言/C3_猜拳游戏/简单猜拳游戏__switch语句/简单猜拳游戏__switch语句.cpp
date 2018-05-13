/*
程序功能：实现简单的猜拳游戏。要求显示人的手势(human)和电脑的手势(comp)的手势。
思路：设定三种手势为0、1、2,根据判断公式(human-comp + 3)%3，得出三种值（0,、1、2）表示为胜负情况。多switch语句辨别。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int human;			//玩家手势
	int comp;			//电脑手势
	int judge;			//胜负判定
	int retry;			//是否再次游戏

	srand(time(NULL));
	printf("猜拳游戏开始!\n");

	do
	{
		comp = rand() % 3;			//随机生成电脑手势
		do
		{
			printf("\n石头剪刀布...(0)石头 (1)剪刀 (3)布： ");
			scanf_s("%d", &human);	//读取玩家手势
		} while (human < 0 || human>2);
		printf("我出");
		switch (comp)			//显示计算机手势
		{
		case 0: printf("石头");	break;
		case 1: printf("剪刀");	break;
		case 2: printf("布");		break;
		}
		printf(",你出");
		switch (human)			//显示玩家手势
		{
		case 0: printf("石头");	break;
		case 1: printf("剪刀");	break;
		case 2: printf("布");		break;
		}
		printf("。\n");

		judge = (human - comp + 3) % 3;		//判定胜负公式，结果有：胜利(2) 输(1) 平局(0)
		switch (judge)
		{
		case 0: printf("平局。");	break;
		case 1: printf("你输了。");	break;
		case 2:	printf("你赢了。");	break;
		}
		printf("\n再来一次吗...(0)否 (1)是:");
		scanf_s("%d", &retry);
	} while (retry == 1);
	printf("游戏结束！");
	getchar();
	getchar();
	return 0;
}