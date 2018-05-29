/*
程序功能：显示当前时刻的协调世界时（UTC）。
协调世界时(UTC)：是一种利用原子钟，在一定程度上尽量接近基于地球自转的世界时(UT)的时间。北京时间比协调世界时快了8小时。
gmtime:把current指向的日历时间转换成协调世界时表示的分解时间。
备注：本程序在DevC++及VC++6.0上运行正常，但在VS2017下显示错误E0144和C2440
*/
#include<stdio.h>
#include<time.h>

void put_data(const struct tm *timer)
{
	char *wday_name[] = { "日","一","二","三","四","五","六" };

	printf("%4d 年%02d月%02d日(%s)%02d时%02d分%02d秒",
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

	time(&current);		//获取当前时间
	timer = (gmtime(&current));	//转换成分解时间（协调世界时）

	printf("当前时间和日期用UTC表示是");
	put_data(timer);
	printf("。\n");

	getchar(); getchar();
	return 0;
}