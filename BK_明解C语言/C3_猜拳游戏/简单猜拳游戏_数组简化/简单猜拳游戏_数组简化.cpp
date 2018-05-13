/*
程序功能：用数组简化多switch语句的猜拳游戏。
思路：创建三种手势的数组，每次打印某种手势时，即可调用数组（数值对应手势和数组序号，数组值对应手势的中文）。
备注：定义数组时，代码在 Microsoft Visual Studio Community 2017 下会出错，显示：E0144	"const char *" 类型的值不能用于初始化 "char *" 类型的实体。
但代码在Dev C++ 及Visual C++ 6.0 下运行正常。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int i;
	int human;			//玩家手势
	int comp;			//电脑手势
	int judge;			//胜负判定
	int retry;			//是否再次游戏
	char *hd[10]= { "石头","剪刀","布" };			//指针数组存储手势（也可用二维数组），出错点

	srand(time(NULL));

	printf("猜拳游戏开始！\n");
	do
	{
		comp = rand() % 3;
		do
		{
			printf("\n石头剪刀布...");
			for (i = 0; i < 3; i++)
				printf("(%d)%s", i, hd[i]);			//初次采用指针数值
			printf(": ");
			scanf_s("%d", &human);
		} while (human < 0 || human>2);
		printf("我出%s，你出%s。\n", hd[comp], hd[human]);	//再次使用指针数组

		judge = (human - comp + 3) % 3;		//判断胜负

		switch (judge)
		{
		case 0:puts("平局");		break;
		case 1:puts("你输了");	break;
		case 2:puts("你赢了");	break;
		}
		printf("再来一次吗...(0)否 (1)是：");
		scanf_s("%d", &retry);
	} while (retry == 1);

	getchar();
	getchar();
	return 0;
}