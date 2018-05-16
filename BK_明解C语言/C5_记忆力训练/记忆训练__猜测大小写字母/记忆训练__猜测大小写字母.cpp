/*
程序功能：实现记忆训练，自选难度，记忆的为大小写英文字母。
思路：无序再把读取的数字转为字符串，只需单纯读取字符串再比较。
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;
	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0*(c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main()
{
	int i, stage;			//作答次数
	int level;				//等级
	int right = 0;			//答对数
	clock_t start, end;
	const char ltr[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz" };				//是一个" "中的内容

	srand(time(NULL));

	printf("英文字母记忆训练：\n");
	do {
		printf("要挑战的等级(%d~%d): ", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level<LEVEL_MIN || level>LEVEL_MAX);

	printf("来记忆%d个英文字母吧。(回车开始)", level);
	getchar();getchar();

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++)
	{
		char mstr[LEVEL_MAX + 1];			//字符串末尾有'\0'故加1
		char x[LEVEL_MAX + 2];				//字符串末尾+1，,同时考虑到玩家可能从键盘输入超过20位的值+1

		for (i = 0; i < level; i++)
			mstr[i] = ltr[rand() % strlen(ltr)];
		mstr[level] = '\0';

		printf("%s", mstr);
		fflush(stdout);
		sleep(125 * level);

		printf("\r%*c\r请输入：", level, ' ');
		fflush(stdout);
		scanf("%s", x);

		if (strcmp(x, mstr) != 0)			//比较字符串
			printf("回答错误。\n");
		else {
			printf("回答正确。\n");
			right++;
		}
	}
	end = clock();

	printf("%d中答对了%d次。\n", MAX_STAGE, right);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
	getchar(); getchar();
	
	return 0;
}