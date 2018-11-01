/*
程序功能：简单实现飞机大战
运行环境：VS2017
更新记录：2018.10.30  --创建程序

存疑：是否可用sleep()实现飞机的子弹的调速，或者其他方法
*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


int high, width;				//边界 
int plane_x, plane_y;			//飞机坐标 
int bullet_x, bullet_y;			//子弹坐标 
int enemy_x, enemy_y;			//敌机坐标
int score;		//分数
int flag;						//飞机状态 


/* 光标移动到(x,y)位置 */
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

/* 隐藏光标 */
void HideCursor() 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };  // 第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
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

/* 初始化各项信息 */
void initialize()
{
	/*边界范围*/
	high = 28;
	width = 40;

	/*飞机初始位置*/
	plane_x = high - 3;
	plane_y = width / 2;

	/*子弹初始位置*/
	bullet_x = 0;
	bullet_y = plane_y;

	/*敌人初始位置*/
	enemy_x = 0;
	enemy_y = plane_y;

	/*初始分数*/
	score = 0;

	/*飞机完好*/
	flag = 0;							 

	HideCursor();
}

/*显示界面*/ 
void show()							
{
	int i, j;
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (flag)
				break;
			else if ((i == plane_x) && (j == plane_y))		//飞机坐标 
				printf("A");
			else if ((i == enemy_x) && (j == enemy_y))		//敌机坐标 
				printf("o");
			else if ((i == bullet_x) && (j == bullet_y))	//子弹坐标 
				printf("|");
			else if ((j == width - 1) || (i == high - 1) || (j == 0) || (i == 0))				//打印边界 
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}

	if ((plane_x == enemy_x) && (plane_y == enemy_y))	//撞到敌机
	{
		flag = 1;
		printf("%*c游戏结束! 最终得分: %d\n",10,' ',score);
	}
	else
		printf("%*c当前得分: %d\n", 15,' ',score);
}

/*自动过程：子弹和敌机的自动持续移动，判定是否生成新敌机*/
void AutomaticProcess()
{
	/*敌机的子弹的速度参数及预设值*/
	static int speed_enemy;
	static int speed_bullet;
	static int NORMAL_SPEED_ENEMY = 20;
	static int NORMAL_SPEED_BULLET = 1;

	/* 子弹的发射效果，可进行子弹调调速(但没什么实际意义，首先速度已经很慢，其次每次发射都会刷新前一颗子弹)；
	运动原理：由于while()循环子弹一直持续运动(bullet_x--)， speed_bullet 参数的引入增加循环次数实现调速，
	持续运动不会出现乱跳么？不会，原因在于 initialize() 初始化后子弹坐标 bullet_x=-1，在地图外，即它的运动在地图内不可打印，当我们空格发射后即赋值 bullet_x 子弹可见地持续运动*/ 
	if (speed_bullet < NORMAL_SPEED_BULLET)
		speed_bullet++;
	if (speed_bullet == NORMAL_SPEED_BULLET)
	{
		if (bullet_x > 0)
		{
			bullet_x--;
		}
		speed_bullet = 0;
	}

	/* 子弹命中敌机后，分数增加，初始化子弹坐标，生成新的敌机 */
	if ((bullet_x == enemy_x) && (bullet_y == enemy_y))		 
	{
		score++;
		bullet_x = -1;	

		/*新的敌机从顶端横排随机出现*/
		enemy_x = 1;
		enemy_y = 1 + rand() %(width - 2);	// 1~(width-2)
	}

	/* 敌机速度，同理也可调速 */
	if (speed_enemy < NORMAL_SPEED_ENEMY)					
		speed_enemy++;
	if (speed_enemy == NORMAL_SPEED_ENEMY)
	{
		if (enemy_x < high)
			enemy_x++;
		else
		{
			enemy_x = 0;
			enemy_y = 1 + rand() % (width - 2);
		}
		speed_enemy = 0;
	}
}

/* 即时读取输入使飞机移动及发射子弹 */
void InputEnableMobile()						
{
	char input;

	if (_kbhit())	//检测键盘输入(有输入则返回非0，该过程的输入不读入流中)
	{
		input = _getch();	//即时读取且不回显
		if ((input == 72) && plane_x > 1)		//↑
			plane_x--;
		if ((input == 80) && plane_x < high - 2)	//↓
			plane_x++;
		if ((input == 75) && plane_y > 1)		//←
			plane_y--;
		if ((input == 77) && plane_y < width - 2)	//→
			plane_y++;
		if (input == ' ')	//空格发射子弹，子弹从飞机前一坐标发射
		{
			bullet_x = plane_x - 1;
			bullet_y = plane_y;
		}
	}
}

int main()
{
	
	int replay = 1;		//是否继续游戏标志
	char ch;		//读取判定是否继续游戏

	system("color 0");	//控制台背景颜色：0 黑

	while (replay == 1)
	{
		initialize();	//初始地图及各项信息
		system("cls");	//清屏

		/*飞机没有破坏则持续过程*/
		while (flag == 0)	
		{
			gotoxy(0, 0);
			show();			// 显示画面
			AutomaticProcess();		// 自动过程(子弹敌机移动，判定是否生成新敌机)
			InputEnableMobile();	// 读取输入使飞机移动及发射子弹
		}

		printf("%*c再次游戏(y/n)？",10,' ');
		scanf_s("%c", &ch);
		if (ch == 'y' || ch == 'Y')
			replay = 1;
		else 
			replay = 0;
	}

	printf("%*c游戏结束\n",10,' ');
	system("PAUSE");

	return 0;
}