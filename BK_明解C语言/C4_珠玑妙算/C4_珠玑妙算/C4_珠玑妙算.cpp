/*
程序功能：实现珠玑妙算游戏功能，即电脑随机生成4个不重复的数字组合，玩家猜测，就打印告诉玩家有几个相同的数字，有几个相同的位置，玩家持续猜测直至正确答案。

思路：需要有校验玩家输入的数字是否有效（位数，重复情况），判断读取的数字时，数字一致位置一致的数目设为hit,数字一致位置不一致设定为blow。
假如 blow=4 即位置全部一致，即为正确答案，否则打印目前一致数字的个数及一致的位置数。

备注：Visual Studio 2017 Community 下运行代码可能产生无限循环打印"请确保输入4个字符。"代码段，
原因在于VS下原C语言scanf()函数的形式为scanf_s()，即每次读取一个字符到buff数组(剩下3个数字在缓存区)，导致check()函数内一直判断buff数组仅有一个字符，
我尝试在scanf_s()后加入getchar()暂停查看，发现程序会打印4次前面的话，也就是说，循环判断了输入的4个数字。或许能用清除缓存的办法解决。
目前解决方案：在VS项目-属性-配置属性-C/C++-预处理器-预处理器定义内添加 _CRT_SECURE_NO_WARNINGS ，即为解决 error C4996 的办法。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

/*---生成4个不同数字的组合放入数组x---*/
void makedigits(int x[])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		do
		{
			x[i] = rand() % 10;
			for (j = 0; j < i; j++)
				if (x[i] == x[j])		//是否已获得此数值
					break;
		} while (j < i);				//循环直到获得全部不同的数值
	}
}

/*---检查好已输入的字符串s的有效性---*/
int check(const char s[])
{
	int i, j;
	if (strlen(s) != 4)					//字符串长度不为4
		return 1;
	for (i = 0; i < 4; i++)
	{
		if (!isdigit(s[i]))				//包含数字以外的字符
			return 2;
		for (j = 0; j < i; j++)			//含有相同的数字
			if (s[i] == s[j])
				return 3;
	}
	return 0;							//字符串有效
}

/*---hit和blow的判断---*/
void judge(const char s[], const int no[], int *hit, int *blow)
{
	int i, j;
	*hit = *blow = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (s[i] == '0' + no[j])	//数字一致
				if (i == j)				
					(*hit)++;			//位置也一致
				else
					(*blow)++;			//位置不一致
	/*
	上述判断数字一致时，代码为 s[i]== '0' + no[j]
	首先，no[]为电脑预设的数字数组(int:0~9)。而s[]为我们输入的字符数组（char:'0'~'9')，这样做解决了采用数组记录输入情况下忽略首位为0的情况，如0957）。当然应该可以创建数组依次读取每个数字。
	上述代码段， '0'+no[j] 将整数值no[j]转换为数字字符，同理， s[i]-'0' 表示将数字字符s[i]转换为整数值。

	数字字符和数值间的转换：
	整数值x(0~9) --- x+'0'-->数字字符c('0'~'9')
	整数值x(0~9) <-- c-'0'---数字字符c('0'~'9')
	*/
}

/*---显示判断结果---*/
void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("回答正确！");
	else if (snum == 0)
		printf("    这些数字里没有正确答案。\n");
	else
	{
		printf("    这些数字里包括%d个答案数字。\n", snum);

		if (spos == 0)
			printf("    但是数字的位置不一致。\n");
		else
			printf("    其中有%d个数字的位置是一致的。\n", spos);
	}
	putchar('\n');
}

int main()
{
	int try_no = 0;			//输入的次数
	int chk;				//已输入的字符串的检查结果
	int hit;				//位置和数字都正确的数字个数
	int blow;				//数字正确但位置不对的数字个数
	int no[4];				//要猜的字符串
	char buff[10];			//用于存放读取的数字串的字符串
	clock_t start, end;		//开始时间/结束时间

	srand(time(NULL));		//设定随机数种子

	puts("# 来玩珠玑妙算把。");
	puts("# 请猜4个数字。");
	puts("# 其中不包含相同的数字。");
	puts("# 请像9527这样连续的输入数字。");
	puts("# 不能输入空格符号。\n");

	makedigits(no);			//生成要猜测的4个数字各不相同的字符串

	start = clock();		//开始计算

	do {
		do
		{
			printf("请输入： ");
			scanf("%s", buff);		//读取字符串

			chk = check(buff);		//检测当读到的字符串是否有效

			switch (chk)
			{
			case 1:puts("请确保输入4个字符。");	break;
			case 2:puts("请不要输入数字以外的字符。");	break;
			case 3:puts("请不要输入相同的数字。");	break;
			}
		} while (chk != 0);
		try_no++;
		judge(buff, no, &hit, &blow);		//判断匹配情况
		print_result(hit + blow, hit);		//显示判断结果，hit+blow 即为一致数字的个数（不考虑位置），hit即为数字位置都一直的个数
	} while (hit < 4);

	end = clock();							//计算结束

	printf("用了%d次。\n用时%.1f秒。\n", try_no, (double)(end - start) / CLOCKS_PER_SEC);
	getchar();
	return 0;
}