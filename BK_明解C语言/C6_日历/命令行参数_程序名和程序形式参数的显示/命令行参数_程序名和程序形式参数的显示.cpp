/*
程序功能：显示程序名和陈旭形式参数。

解析：
argc: argument count 参数数量,接收程序名和形式参数的总个数。
argv: argument vecotor 参数向量，类型为"指向char型的指针数组"。argv[0]指向程序名，之后元素指向程序形式参数。
		char *argv[] 等价于 char **argv
*/
#include<stdio.h>

int main(int argc , char *argv[])	// main()函数接收2个参数 argc 和 argv (其他名称亦可)
{
	int i;

	for (i = 0; i < argc; i++)
		printf("argv[%d] = \"%s\"\n", i, argv[i]);

	getchar();
	return 0;
}
/* 以字符串为单位遍历命令行参数
int main(int argc , char **argv)
{
int i;
while(argc-->0)
printf("argv[%d] = \"%s\"\n", i++, *argv);

getchar();
return 0;
}
*/

/* 以字符串为单位遍历命令行参数
int main(int argc,int **argv)
{
	int i = 0;
	char c;

	while (argc-- > 0)
	{
		printf("argv[%d] = \"", i++);
		while (c = *(*argv)++)
			putchar(c);
		argv++;
		printf("\"\n");
	}
	getchar();
	return 0;
}
*/