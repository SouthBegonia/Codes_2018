/*
程序功能：atoi(),atol(),atof()函数的应用。

atoi()将你输入的字符串形式的整数转为int型。
atol()将你输入的字符串形式的整数转换为long型。
atof()将你输入的字符串形式的整数转换为double型。
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char s[100];
	printf("atoi()将你输入的字符串形式的整数转为int型\natol()将你输入的字符串形式的整数转换为long型\natof()将你输入的字符串形式的整数转换为double型\n\n");
	printf("请输入字符串：");
	while (scanf("%s", s) == 1)
	{
		printf("atoi()将你输入的字符串转为int型： %d\n", atoi(s));
		printf("atol()将你输入的字符串转换为long型: %ld\n", atol(s));
		printf("atof()将你输入的字符串转换为double型: %f\n", atof(s));
		printf("\n请输入字符串：");
	}
	getchar();
	getchar();
	return 0;
}