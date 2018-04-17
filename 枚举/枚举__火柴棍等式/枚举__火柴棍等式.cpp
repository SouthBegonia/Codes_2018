/*
	程序原理：指定的火柴数，分别计算3位数乘法公式和加法公式所需要火柴数
*/
#include<stdio.h>
int fun(int x)                                 //计算一个数所需火柴数的函数
{
	int num = 0;                               //用来计需要火柴数数
	int f[10] = { 6,2,5,5,4,5,6,3,7,6 };       //用一个数组来表示数字0~9各需要多少跟火柴
	while (x / 10!= 0)                         //商不为0则表示这个数至少2位数
	{
		num += f[x % 10];                      //这个多位数的个位数需的火柴数
		x = x / 10;                            //去末尾后的数字
	}
	num += f[x];                                    //去末尾后的数字所需的火柴数
	return num;
}
int main()
{
	int a, b, c, m, sum_add = 0, sum_mul = 0;
	printf("共有几根火柴： ");
	scanf_s("%d", &m);
	
	for (a = 0; a <= 1111; a++)				        //开始枚举 a 和 b
	{ 
		for (b = 0; b <= 1111; b++)
		{
			c = a + b;                              //满足加法公式

			if (fun(a) + fun(b) + fun(c) == (m - 4))
			{
				/* 
					减4表示除去'+'和'='所必须的2根，可以随意更改满足不同式子。
					例： c = a * b
						 fun(a)+fun(b)+fun(c) = m - 4  (乘号需要2根火柴)
				*/
				printf("%d + %d = %d\n", a, b, c);
				sum_add++;                         //计算满足条件的组合数
			}
		}

		for (b = 0; b <= 1111; b++)                //变形：乘法公式
		{
			c = a * b;							   //满足乘法公式

			if (fun(a) + fun(b) + fun(c) == (m - 4))
			{
				printf("%d * %d = %d\n", a, b, c);
				sum_mul++;                         //计算满足条件的组合数
			}
		}
	}

	printf("%d根火柴一共可以拼出%d个 a+b=c 的公式。\n",m,sum_add);
	printf("%d根火柴一共可以拼出%d个 a*b=c 的公式。\n",m,sum_mul);
	getchar();
	getchar();
	return 0;
}