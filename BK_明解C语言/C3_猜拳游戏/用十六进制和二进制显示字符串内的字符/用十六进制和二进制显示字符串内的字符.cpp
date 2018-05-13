/*
程序功能：用十六进制和二进制显示部分数字、字母及汉字。
isprintf(c):判断c是否为含有空白字符(' ')的显示字符。
备注：目前汉字采用GB18030编码方案，有单字节、双字节、四字节分段编码。
*/
#include<stdio.h>
#include<limits.h>
#include<ctype.h>

void strdump(const char *s)
{
	while (*s)
	{
		int i;
		unsigned char x = (unsigned char)*s;

		printf("%c  ", isprint(x) ? x : ' ');			//字符
		printf("%0*X  ", (CHAR_BIT + 3) / 4, x);		//十六进制数
		for (i = CHAR_BIT - 1; i >= 0; i--)				//二进制数
			putchar(((x >> i) & 1U) ? '1' : '0');		/*用法存疑，待解决*/
		putchar('\n');
		s++;
	}
}
void ASC(void)
{
	printf("ASCII码表\n");
	printf("数值   ");
	printf("符号   \n");
	int i;
	for (i = 0; i <= 50; i++)
	{
		printf("%3d   %3c", i, i);
		putchar('\n');
	}
}

int main()
{
	puts("汉字");
	strdump("汉字");
	putchar('\n');
	puts("12中国话AB");
	strdump("12中国话AB");
	putchar('\n');

	ASC();

	getchar();
	getchar();
	return 0;
}