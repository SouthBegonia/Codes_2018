//输入两个正数分别作为分子和分母，编写程序，化为最间带分数后输出
//如输入12和8后输出1又1/2 
#include<stdio.h>
int main()
{
	long x,y,x1,y1,t;
	printf("Input x,y(x>0,y>0):");
	scanf("%ld%ld",&x,&y);
	printf("%ld/%ld=",x,y);
	if(x==y)
	   printf("1\n");
	else 
	{
		x1=x;  y1=y;
		//计算x和y的最大公倍数
		while(x1!=y1)
		{
			if (x1>y1)
			   x1=x1-y1;
			else 
			   y1=y1-x1;
		 }        //退出循环后x1=y1的值是x和y的最大公约数
		 x=x/x1;  y=y/x1;    //约分化简
		 
		 if (x>y)   //化带分数
		 {
		 	t=x/y;
		 	x=x%y;
		 	printf("%ld又%ld/%ld\n",t,x,y);
		  } 
		  else printf("%ld/%ld\n",x,y);
	 } 
}
