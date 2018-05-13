/*
程序功能：将游戏步骤分割为多个函数，且打印出分数，及比赛历史(双方手势及胜负情况)实现猜拳游戏。
思路：新建数组存储胜负情况，双方手势的历史。（注意游戏次数递增的位置）。
主函数内调用情况如下：
int main()
{
/*初始处理
do
{
/*运行猜拳游戏，并记录双方手势*/
/*显示计算机和玩家手势*/
/*判断胜负，并记录胜负情况*/
/*更新比赛分数(胜负平次数)*/
/*显示判断结果*/
/*确认是否再次挑战
/*比赛次数+1
} while (retry == 1);
备注：定义数组时，代码在 Microsoft Visual Studio Community 2017 下会出错，显示：E0144	"const char *" 类型的值不能用于初始化 "char *" 类型的实体。
但代码在Dev C++ 及Visual C++ 6.0 下运行正常。
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int human;
int comp;
int win_no;
int lose_no;
int draw_no;
char *hd[] = { "石头","剪刀","布" };

int n = 1;					//记录游戏次数
int his_hum[1000];			//玩家手势的历史
int his_com[1000];			//电脑手势的历史
int cout[1000];				//存储每次游戏胜负的值
char *end[] = { "平局","失败","胜利" };	//胜负情况

/*---初始处理---*/
void initialize(void)
{
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand(time(NULL));
	printf("猜拳游戏开始!\n");
}

/*---运行猜拳游戏(读取/生成手势)---*/
void gesture(void)
{
	int i;
	comp = rand() % 3;
	his_com[n] = comp;
	do
	{
		printf("\n石头剪刀布...");
		for (i = 0; i < 3; i++)
			printf("(%d)%s ", i, hd[i]);
		printf(":");
		scanf_s("%d", &human);
	} while (human < 0 || human>2);
	his_hum[n] = human;
	/*不可在此n++，需要进行一次完成的读取、更新、判断后才可n++*/
}

/*---更新胜利/失败/平局次数---*/
void count_no(int result)
{
	switch (result)
	{
	case 0:draw_no++;	break;
	case 1:lose_no++;	break;
	case 2:win_no++;	break;
	}
}

/*---显示判断结果---*/
void disp_result(int result)
{
	switch (result)
	{
	case 0:
	{
		printf("平局。");
		cout[n] = 0;
		break;
	}
	case 1:
	{
		printf("你输了。");
		cout[n] = 1;
		break;
	}
	case 2:
	{
		printf("你赢了。");
		cout[n] = 2;
		break;
	}
	}
}

/*---确认是否再次游戏---*/
int confirm_retry(void)
{
	int x;
	printf("再来一次吗...(0)否 (1)是: ");
	scanf_s("%d", &x);
	return x;
}

int main()
{
	int judge;
	int retry;
	int i;

	initialize();			//初始处理
	do
	{
		gesture();			//运行猜拳游戏
		printf("我出%s，你出%s。\n", hd[comp], hd[human]);
		judge = (human - comp + 3) % 3;		//判断胜负
		count_no(judge);					//更新胜利/失败/平局次数
		disp_result(judge);					//显示判断结果
		retry = confirm_retry();			//确认是否再次游戏
		n++;								//完成一次比赛流程，进行下一次
	} while (retry == 1);
	printf("\n比赛历史：\n");
	printf("人    电脑   结果\n");
	printf("-----------------\n");
	for (i = 1; i < n; i++)
	{
		printf("%-6s%-6s%-6s\n", hd[his_hum[i]], hd[his_com[i]], end[cout[i]]);
	}
	printf("-----------------\n");
	printf("\n得分结果：%d胜%d负%d平。\n", win_no, lose_no, draw_no);
	getchar();
	return 0;
}