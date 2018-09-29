/*kbhit()函数的引用*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	char ch;
	
	while(ch!=27)   //ESC键
	{
		printf("HelloWorld\n");

		if(kbhit()) //如果有键盘输入
			ch=getch(); //读取但不回显
	}
	printf("End!\n");
	getchar();
	return 0;
}
