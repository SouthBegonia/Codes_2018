/*
程序功能：显示当前时刻的时间（年月日分秒周几）。

说明：程序内部详细显示 分解时间结构体tm 的各成员情况。

备注：本程序在DevC++及VC++6.0上运行正常，但在VS2017下显示错误E0144和C2440
时间结构示意图： \Code_2018\BK_明解C语言\C6_日历\显示当前时间(显示结构体信息).jpg
*/
#include<stdio.h>
#include<time.h>

void put_data(const struct tm *timer)
{
	char *wday_name[] = { "日","一","二","三","四","五","六" };

	printf("%4d年%02d月%02d日(%s)%02d时%02d分%02d秒",
		timer->tm_year + 1900,		//年
		timer->tm_mon + 1,			//月
		timer->tm_mday,				//日
		wday_name[timer->tm_wday],	//星期
		timer->tm_hour,				//时
		timer->tm_min,				//分
		timer->tm_sec				//秒
		);
}

int main()
{
	time_t current;		//日历时间（单独的数据类型，VS2017下为 typedef long time_t）
	struct tm *timer;	//分解时间(结构体)
	/*
	tm:分解时间的结构体类型，示例如下：
	struct tm {
		int tm_sec;		//秒（0~61）
		int tm_min;		//分（0~59）
		int tm_hour;	//时（0~23）
		int tm_mday;	//日（0~31）
		int tm_mon;		//从1月开始的月份（0~11）
		int tm_year;	//从1900开始的年份
		int tm_wday;	//星期：星期日~星期六（0~6）
		int tm_yday;	//从1月1日开始的天数（0~365）
		int tm_isdst;	//夏令时标志
	};
	*/
	time(&current);		//获取当前时间
	timer = (localtime(&current));	//转换成分解时间（本地时间）

	printf("当前的时间是");
	put_data(timer);
	printf("。\n");

	getchar(); getchar();
	return 0;
}
