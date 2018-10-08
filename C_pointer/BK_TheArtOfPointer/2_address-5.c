#include<stdio.h>
#include<stdlib.h>

int main()
{
	double x, y, average;
	
	printf("输入浮点数x和y：");
	scanf("%lf%lf",&x,&y);     //%lf间是否有空格不影响
	
	average = (x+y)/2;
	
	printf("x与y的平均数为：%.2f\n",average);
	system("PAUSE");

	return 0;
}
