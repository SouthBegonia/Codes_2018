/*
程序功能：打印某几个月的日历。横向显示最多3个月的日历。

思路：创建三维数组存储日历，日历信息包括：首行标题(日期)，其次星期几，其次分割线，其次每一号。
因为要实现横向显示3个日历，故单行需要打印3个日历数组的对应行的信息，且彼此间分隔开。
要仔细检查日历内容的大小是否合规数组范围，且对齐。

易错点：调整对齐，数组不溢出。

日历对齐示意图：\Code_2018\BK_明解C语言\C6_日历\显示某几个月的日历.jpg
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*---各月的天数---*/
int mday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

/*---求year年month月day日是星期几---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		year--;
		month += 12;
	}
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

/*---year年是闰年么(0···平年/1···闰年)---*/
int is_leap(int year)
{
	return year % 4 == 0 && year != 0 || year % 400 == 0;
}

/*---year年month月的天数(28~31)---*/
int monthday(int year, int month)
{
	if (month-- != 2)		//当month非2月时
		return mday[month];
	return mday[month] + is_leap(year);	//当month为2月时
}

/*---把y年m月的日历存入二维数组s中---*/
void make_calendar(int y, int m, char s[7][22])
{
	int i, k;
	int wd = dayofweek(y, m, 1);		//y年m月1日对应的星期
	int mdays = monthday(y, m);			//y年m月的天数
	char tmp[4];

	sprintf(s[0], "%10d / %02d      ", y, m);	//标题(年/月)，VS下显示为18
	/*查看s[0]情况(sizeof(s[0])=22,strlen(s[0])=21)
	printf("s[0]=%s\nsizeof()=%d\nstrlen()=%d\n\n", s[0], sizeof(s[0]), strlen(s[0]));
	*/
	for (k = 1; k < 7; k++)		//清除标题以外的缓冲区
		s[k][0] = '\0';			//注：在VS下 '\0' 为 char('\000')
	/*
	原解析(错误)：
	上述sprintf和for循环需要特别注意：
	打印的字符串大小必须为22字节(存储日历的三维数组为sbuf[3][7][22],日历信息的某行大小为22)
	即sprintf和for循环所打印的字符必须小于或者等于22，若超出，则打印错误代码。
	本代码for()为3字节('\000')，故sprintf()最多为18字节。

	合理解析：
	sprintf()语句在s[0]输入了标题信息，虽然VS显示大小为18，调用strlen()查看后为21，加上末尾'\0'刚好合规，
	在print()函数内，打印标题时，%s后为3空格符，加上其内容共24(不算末尾'\0')，是因为打印"星期日~星期六"及"---"字符时，其大小(strlen)也为24，刚好一致，对齐。
	故在打印"标题"、"星期几"和"---"时，做到字符大小一致即可实现对齐，但为了对齐日历信息，则需要稍稍调整。
	
	*/
	k = 1;
	sprintf(s[k], "%*s", 3 * wd, "");	//在1号左侧填上空白字符

	for (i = 1; i <= mdays; i++)
	{
		sprintf(tmp, "%3d", i);	//tmp是字符串，末尾为'\0'
		strcat(s[k], tmp);		//字符串后追加第i日的日期(格式为 "  1\0" 或 " 12\0" 共4字节)，但追加的字符串首位替代前一位的'\0'
		if (++wd % 7 == 0)		//存入星期六后
			k++;				//移动到下一行
	}
	if (wd % 7 == 0)
		k--;
	else {
		for (wd %= 7; wd < 7; wd++)		//在最后一日的右侧添加空白字符
			strcat(s[k], "   ");	//3个空格符(但作为字符串末尾有'\0')
	}
	while (++k < 7)
		sprintf(s[k], "%21s", "");		//用空白字符填满未使用的行()，s[6][0]已经被设为'\0'，故此处为%21s。可在设定为"E"查看末位
}

/*---把存在三维数组sbuf中的日历横向排列n个并显示---*/
void print(char sbuf[3][7][22],int n)
{
	int i, j;

	for (i = 0; i < n; i++)
		printf("%s   ", sbuf[i][0]);		//打印标题(年/月)
	putchar('\n');

	for (i = 0; i < n; i++)
		printf(" 日 一 二 三 四 五 六   ");//此处strlen()为24
	putchar('\n');

	for (i = 0; i < n; i++)
		printf("----------------------  ");//此处strlen()为24
	putchar('\n');

	for (i = 1; i < 7; i++)		//循环日历的7行
	{
		for (j = 0; j < n; j++)
			printf("%s   ", sbuf[j][i]);	//循环 j 个日历的 i 行(j为3即表示需要同一行接连打印3个月的日历信息)
		putchar('\n');
	}
	putchar('\n');
}

/*---显示自y1年m1月起至y2年m2月的日历---*/
void put_calendar(int y1, int m1, int y2, int m2)
{
	int y = y1;
	int m = m1;
	int n = 0;				//存在缓冲区的月数(待打印的月份数)
	char sbuf[3][7][22];	//日历字符串的缓冲区

	while (y <= y2)			//循环期间的年份
	{
		if (y == y2 && m > m2)		//仅有1个月情况
			break;
		make_calendar(y, m, sbuf[n++]);		//把该月的日历存入二维数组,此处进行了 n++
		if (n == 3)			//累计3个月显示
		{
			print(sbuf, n);
			n = 0;
		}
		m++;		//转到下一个月
		if (m == 13 && y < y2)		//转到下一年
		{
			y++;
			m = 1;
		}
	}
	if (n)	//当n不到3时候，例如1月到2月或者1月到11月(n=2)，其最后的月份数不为3，则无法进行上面的if(n==3)判断，因此需要单独打印
		print(sbuf, n);
}

int main()
{
	int y1, m1, y2, m2;

	printf("显示日历。\n");
	printf("输入开始年月。\n");
	printf("年：");	scanf("%d", &y1);
	printf("月：");	scanf("%d", &m1);

	printf("输入结束年月。\n");
	printf("年：");	scanf("%d", &y2);
	printf("月：");	scanf("%d", &m2);
	putchar('\n');

	put_calendar(y1, m1,y2,m2);		//显示y年m月的日历

	getchar(); getchar();
	return 0;
}