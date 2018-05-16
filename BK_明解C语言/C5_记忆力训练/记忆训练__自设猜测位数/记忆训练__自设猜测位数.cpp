/*
程序功能：在实现游戏记忆训练的基础上，添加选择等级(位数)功能。要求作答位数可在3~20位。
思路：整数型，最大就只能为 unsigned long int(最大4294967295)仅为10位，故本文采用字符串记录数字。
随机生成的数字转换为字符串存储于字符型数组，读取的数字以字符串形式读取，最终用比较字符串函数strcmp()对比。
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STAGE 10			//关卡数(最大答题数)
#define LEVEL_MIN 3				//最低等级(位数)
#define LEVEL_MAX 20			//最高等级(位数)

/*---等待x毫秒---*/
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

int main()
{
	int i, stage;
	int level;
	int right = 0;
	clock_t start, end;

	srand(time(NULL));

	printf("数值记忆训练：\n");
	do {
		printf("要挑战的等级(%d~%d): ", LEVEL_MIN, LEVEL_MAX);	//玩家选择挑战等级
		scanf("%d", &level);
	} while (level<LEVEL_MIN || level>LEVEL_MAX);

	printf("来记忆一个%d位的数值把。(回车开始)", level);
	getchar();
	getchar();

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		char no[LEVEL_MAX + 1];			//需要记忆的数字串，字符串末尾+1
		char x[LEVEL_MAX + 2];			//已读取的数字串，字符串末尾+1，同时考虑到玩家可能从键盘输入超过20位的值+1

		no[0] = '1' + rand() % 9;		//开头字符是 '1'~'9'
		for (i = 1; i < level; i++)
			no[i] = '0' + rand() % 10;
		no[level] = '\0';				//字符串末尾是空 '\0'

		printf("%s", no);
		fflush(stdout);
		sleep(125 * level);

		printf("\r%*c\r请输入： ", level, ' ');		//对应位数的空格符清屏
		scanf("%s", x);

		if (strcmp(no, x) != 0)			//比较 no 和 x 字符串是否相等
			printf("回答错误。\n");
		else {
			printf("回答正确。\n");
			right++;
		}
	}
	end = clock();
	
	printf("%d次中你答对了%d次。\n", MAX_STAGE, right);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	getchar();
	getchar();
	return 0;
}