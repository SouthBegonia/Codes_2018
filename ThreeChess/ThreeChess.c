#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

struct Chess
{
	int x;
	int y;
	int tag;	//判断是否打印，0否 1是
};

void gotoxy(int, int);		//跳转光标
void HideCursor();		//隐藏光标
void initialize(struct Chess *, struct Chess *);	//初始化棋子
void move1(struct Chess *, struct Chess *);		//一号棋移动
void move2(struct Chess *, struct Chess *);		//二号棋移动
int judge(int [][2], int [][2]);	//判断胜负
void print(struct Chess *, struct Chess *);		//打印棋盘


int main()
{
	struct Chess ces1, ces2;
	int arr1[5][2] = { 0 };
	int arr2[5][2] = { 0 };
	int i = 0, j = 0;
	int sign = 0;

	initialize(&ces1, &ces2);
	print(&ces1, &ces2);

	//move(&ces1);
	for (i = 0; i < 6; i++)
	{
		move1(&ces1, &ces2);
		arr1[i][0] = ces1.x;
		arr1[i][1] = ces1.y;
		sign = judge(arr1, arr2);
		if (sign != 0)
			break;

		move2(&ces2, &ces1);
		arr2[i][0] = ces2.x;
		arr2[i][1] = ces2.y;

		sign = judge(arr1, arr2);
		if (sign != 0)
			break;
	}

	gotoxy(0, 7);
	switch (sign)
	{
	case 0:
		printf("没有赢家!\n");
		break;
	case 1:
		printf("1号棋 '*' 赢了!\n");
		break;
	case 2:
		printf("2号棋 '#' 赢了!\n");
		break;
	default: printf("Done!\n");
	}
	printf("游戏结束！");

	getchar();
	return 0;
}

/* 隐藏光标 */
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };  // 第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

/*初始化两棋子位置*/
void initialize(struct Chess *p1, struct Chess *p2)
{
	/*初始化两棋子*/
	p1->x = 2;
	p1->y = 1;
	p1->tag = 0;
	p2->x = 2;
	p2->y = 1;
	p2->tag = 0;
}

/* 打印棋盘 */
void print(struct Chess *p1, struct Chess *p2)
{
	printf(" --- --- --- \n");
	printf("|   |   |   |\n");
	printf(" --- --- --- \n");
	printf("|   |   |   |\n");
	printf(" --- --- --- \n");
	printf("|   |   |   |\n");
	printf(" --- --- --- \n");
	gotoxy(2, 1);	//光标首先置于棋盘中
}

/* 光标移动到(x,y)位置 */
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

/* 等待 x 毫秒 */
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;
	do
	{
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0*(c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

/* 一号棋子的移动 */
void move1(struct Chess *p1, struct Chess *p2)
{
	char ch;

	/* 移动到上一颗棋子的位置 */
	p1->x = p2->x;
	p1->y = p2->y;
	gotoxy(p1->x, p1->y);


	while (1)
	{
		ch = _getch();
		if ((ch == 72) && (p1->y > 1))	//上
			(p1->y) -= 2;
		else if ((ch == 80) && (p1->y) < 5)	//下
			(p1->y) += 2;
		else if ((ch == 75) && (p1->x) > 3)	//左
			(p1->x) -= 4;
		else if ((ch == 77) && (p1->x) < 8)
			(p1->x) += 4;
		else if (ch == ' ')		//空格即打印
		{
			p1->tag = 1;
			break;
		}
		gotoxy(p1->x, p1->y);
	}

	gotoxy(p1->x, p1->y);
	printf("*\b");
	p1->tag = 0;
}

/* 二号棋子的移动 */
void move2(struct Chess *p1, struct Chess *p2)
{
	char ch;

	p1->x = p2->x;
	p1->y = p2->y;
	gotoxy(p2->x, p2->y);

	while (1)
	{
		ch = _getch();
		if ((ch == 72) && (p1->y > 1))	//上
			(p1->y) -= 2;
		else if ((ch == 80) && (p1->y) < 5)	//下
			(p1->y) += 2;
		else if ((ch == 75) && (p1->x) > 3)	//左
			(p1->x) -= 4;
		else if ((ch == 77) && (p1->x) < 8)
			(p1->x) += 4;
		else if (ch == ' ')
		{
			p1->tag = 1;
			break;
		}
		gotoxy(p1->x, p1->y);
	}

	gotoxy(p1->x, p1->y);
	printf("#\b");
	p1->tag = 0;
}


/* 判断胜负：0 不分胜负 ; 1 一号棋子赢 ; 2 二号棋子赢 */
int judge(int p1[5][2], int p2[5][2])
{
	int i = 0, j = 0;

	/* 棋子1 */
	if ((p1[0][0] == p1[1][0]) && (p1[1][0] == p1[2][0]) && p1[0][0] !=0)
		return 1;
	else if ((p1[0][1] == p1[1][1]) && (p1[1][1] == p1[2][1]) && p1[0][1] != 0)
		return 1;
	//else if (  (double)( (p1[0][1] - p1[1][1])/(p1[0][0] - p1[1][0]) ) == (double)((p1[0][1] - p1[1][1]) / (p1[0][0] - p1[1][0])) )
	//	return 1;

	/* 棋子2 */
	 else if ((p2[0][0] == p2[1][0]) && (p2[1][0] == p2[2][0]) && p2[0][0] != 0)
		return 2;
	else if ((p2[0][1] == p2[1][1]) && (p2[1][1] == p2[2][1]) && p2[0][1] != 0)
		return 2;
	//else if (  (double)( (p1[0][1] - p1[1][1])/(p1[0][0] - p1[1][0]) ) == (double)((p1[0][1] - p1[1][1]) / (p1[0][0] - p1[1][0])) )
	//	return 1;

	 else return 0;
}