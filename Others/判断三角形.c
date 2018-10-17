/*判断三角形*/
#include<stdio.h>
int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c))
	{

	if(a+b<=c || a+c<=b ||b+c<=a)   //非三角形
	{
		printf("不是三角形\n");
	}
	else if(a==b&&b==c&&a==c)
	{
		printf("等边三角形\n");
	}else if(a*a+b*b==c*c || a*a+c*c==b*b ||b*b+c*c==a*a)
	{
		printf("直角三角形\n");
	}else if((a==b&&b!=c) || (b==c&&c!=a) ||(a==c&&c!=b))
	{
		printf("等腰三角形\n");
	}else printf("一般三角形\n");

	}
	getchar();
	getchar();
	return 0;
}
