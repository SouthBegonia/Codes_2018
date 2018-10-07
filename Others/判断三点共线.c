//判断3个点是否在同一直线上
#include<stdio.h>

int main()
{
	int N;
	double a1,a2,a3,b1,b2,b3;
	double A,B,C;
	
	scanf("%d",&N);

	while(N--)  //循环N次
	{
		scanf("%lf%lf",&a1,&b1);    //读取每个点坐标
		scanf("%lf%lf",&a2,&b2);
		scanf("%lf%lf",&a3,&b3);
		
		A = (b1-b2)/(a1-a2);
		B = (b1-b3)/(a1-a3);
		C = (b2-b3)/(a2-a3);

		if(A==B && B==C && A==C)    //判断斜率是否相等
			printf("Yes\n");
		else printf("No\n");
	}
	getchar();
	return 0;
}
