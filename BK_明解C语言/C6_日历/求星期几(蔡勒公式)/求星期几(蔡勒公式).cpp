/*
程序功能：使用蔡勒公式实现星期几的求解。
备注：蔡勒公式能计算出1582年10月15日以后的日期所对应的星期。其数学求解过程不做阐述。
*/
#include<stdio.h>

int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		year--;
		month += 12;
	}
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

int main()
{
	int y, m, d, w;
	char *ws[] = { "日","一","二","三","四","五","六" };

	printf("求星期。\n");
	printf("年： ");	scanf("%d", &y);
	printf("月： ");	scanf("%d", &m);
	printf("日： ");	scanf("%d", &d);

	w = dayofweek(y, m, d);
	printf("这一天是星期%s。\n", ws[w]);

	getchar();
	return 0;
}