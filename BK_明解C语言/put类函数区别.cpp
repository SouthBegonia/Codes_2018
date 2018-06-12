/*
程序功能：区别puts/putch/putchar 

说明：可能存在异议，待完善。 
*/
#include<stdio.h>
#include<conio.h>

int main()
{
	char c='A';
	char s[]={"12345"};
	
	printf("##########\n");
	puts(s);				//末尾自带'\n' 
	puts("puts字符串") ;	//末尾自带'\n' 
	printf("##########\n\n");
	
	printf("##########\n");
	putch(c);			// 字母 'A' 
	putch('m');			// 字母 'm' 
	putch(97);			// 字母 'a' 
	printf("##########\n\n");
	
	printf("##########\n");
	putchar(c);			// 字母'A' 
	putchar('n');		// 字母'n' 
	putchar(98);		//字母 'b' 
	printf("##########\n\n");
	
	return 0;
} 
