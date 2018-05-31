/*
程序功能：采用asctime()函数实现特定格式时间的显示，
asctime:把结构体的分解时间转换成类似格式的字符串： sun sep 16 01:03:49 1990\n\0
asctime2： sun sep 16 01:03:49 1990\0
注意：利用asctime函数显示时间，其末尾是换行符和空字符，一共26个字符
备注：VS下出现C4996，告知asctime()函数不安全，在预处理器定义内添加 _CRT_SECURE_NO_DEPRECATE 即可。
*/
#include<stdio.h>
#include<time.h>

/*---根据asctime函数把分解时间转换成字符串（不添加换行符）---*/
char *asctime2(const struct tm *timeptr)
{
	const char wday_name[7][4] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };		//注意每个元素4字节
	const char mon_name[12][4] = { "Jan","Feb","Mar","Apr","May","Jun",
								"Jul","Aug","Sep","Oct","Nov","Dec" };
	static char result[25];		//用于储存字符串的空间还是静态空间

	sprintf(result, "%0.3s %.3s %02d %02d:%02d:%02d %4d",
		wday_name[timeptr->tm_wday],
		mon_name[timeptr->tm_mon],
		timeptr->tm_mday,
		timeptr->tm_hour,
		timeptr->tm_min,
		timeptr->tm_sec,
		timeptr->tm_year + 1900
	);
	return result;
}

int main()
{
	time_t current = time(NULL);		//获取当前时间
	printf("当前日期和时间：%s", asctime(localtime(&current)));		//此处可自行调用asctime2()函数实现其特定功能
	
	getchar(); getchar();
	return 0;
}
