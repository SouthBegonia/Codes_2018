/*
程序功能：用于访问可变参数的函数

备注：待详解

<stdarg.h>
va_list型：用于访问可变参数的类型
va_start宏：负责访问可变参数前的装备工作
va_arg宏：负责访问后一个可变参数
va_end宏：复制结束访问可变参数

*/
#include<stdio.h>
#include<stdarg.h>

/*---根据第1参数，求后面的参数的和---*/
double vsum(int sw, ...)
{
	double sum = 0.0;
	
	va_list ap;		
	/*用于访问调用函数时堆积的参数*/

	va_start(ap, sw);	//开始访问可变部分的参数

	switch (sw)
	{
	case 0: sum += va_arg(ap, int);		//vsum(0,int,int)
		sum += va_arg(ap, int);
		break;
	case 1:sum += va_arg(ap, int);		//vsum(1,int,long)
		sum += va_arg(ap, long);
		break;
	case 2:sum += va_arg(ap, int);		//vsum(2,int,long,double)
		sum += va_arg(ap, long);
		sum += va_arg(ap, double);
		break;
		/*
		0：把int型的第2参数和int型的第3参数相加
		1：把int型的第2参数和long型的第3参数相加
		2：把int型的第2参数和long型的第3参数以及double型的第4参数相加
		*/
	}
	va_end(ap);		//结束访问可变部分的参数

	return sum;
}

int main()
{
	printf("10 + 2         = %.2f\n", vsum(0, 10, 2));
	printf("57 + 300000L   = %.2f\n", vsum(1, 57, 300000L));
	printf("98 + 2L + 3.14 = %.2f\n", vsum(2, 98, 2L, 3.14));

	getchar();
	return 0;
}