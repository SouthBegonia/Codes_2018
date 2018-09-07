/*
标准流:stdout, stdin, stderr 中文名字分别是 标准输出，标准输入 和 标准错误
*/
#include<stdio.h>

int main()
{
	/*int printf(const char *format, ...) 发送格式化输出到标准输出 stdout*/
	printf("printf(*s)\n");
	
	/*int fprintf(FILE *stream, const char *format, ...) 发送格式化输出到流 stream 中
	此处设置 fprintf() 输出到 stdout 等价于上面的 printf()*/
	fprintf(stdout,"fprintf(stdout,\*s)\n");
	
	/*此处设置 fprintf() 输出到 stderr 等价于上面的 printf()*/
	fprintf(stderr,"fprintf(stderr,\*s)\n");

	putchar('\n');

	/* stderr 与 stdout 均表示默认显示器(终端), 但存在区别
	stderr: 没有缓冲，立即输出
	stdout: 默认是行缓冲，输出会先放于一个buffer里面,当遇到 '\n'，才向外输出内容*/
	fprintf(stdout,"Hello ");
	fprintf(stderr,"World!");
	/*打印内容应为 "World!Hello "
	但在在我的环境下(GCC 6.3.0)并未体现有无缓冲区别,待解决*/
	
	putchar('\n');

	/*void perror (const char *);
	把一个描述性错误消息输出到标准错误 stderr。首先输出字符串 str，后跟一个冒号，然后是一个空格
	类似于 fprintf（stderr，char *） 但是 perror() 还会输出错误信息 */
	perror("Stderr Hello World!!\n");   //末尾有 : No error
	
	/*清空输入缓冲区*/
	fflush(stdin);
	
	getchar();
	return 0;
}
