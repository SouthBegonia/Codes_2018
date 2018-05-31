/*
程序功能：读取年月日，计算该天是星期几。应用mktime()函数。

mktime():
原型：time_t mktime(struct tm *timeptr)
把表示timeptr指向的结构体中的本地时间的分解时间转换成与time函数返回值具有相同表现形式的日历时间值。
其功能可以简单理解为：把自行设定的本地时间的分解时间的结构体(t)转换成标准格式的分解时间(见 \Code_2018\BK_明解C语言\C6_日历\显示当前时间(显示结构体信息))

思路：在自行设定并修改分解时间结构体 tm 的参数后，调用mktime()函数，其内部自动把 tm 内的其他参数设定好(所求的 t.tm_wday)

备注：1. C语言提供的关于日期和时间的库不一定能正确处理1970年1月1日以前的日期。
2. VS2017下创建指针并初始化任报错，请在其他IDE运行。
*/

#include<stdio.h>
#include<time.h>

/*---求year年month月day日是星期几---*/
int dayofweek(int year, int month, int day)
{
	struct tm t;		//生成分解时间(结构体)

	t.tm_year = year - 1900;	//调整年份
	t.tm_mon = month - 1;		//调整月份
	t.tm_mday = day;	//调整日
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1;
	
	if (mktime(&t) == (time_t)-1)
		return -1;
	return t.tm_wday;		
	/*返回mktime()自动修改设定的星期,把分解时间转换成time_t型的值得表现形式
	假若不调用mktime()函数，则t.tm_wday为null，即不会自动设定*/
}

int main()
{
	int y, m, d, w;
	char *ws[] = { "日","一","二","三","四","五","六" };

	printf("求星期。\n");
	printf("年： ");	scanf("%d", &y);
	printf("月： ");	scanf("%d", &m);
	printf("日： ");	scanf("%d", &d);

	w = dayofweek(y, m, d);		//注意并未使用time()读取当前时间传入，而是在dayofweek()内设定一个分解时间结构体。

	if (w != -1)
		printf("这一天星期%s。\n", ws[w]);
	else
		printf("无法求出星期。\n");

	getchar();
	return 0;
}