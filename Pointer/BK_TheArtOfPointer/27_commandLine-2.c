#include<stdio.h>

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		switch(*(argv[1]+1))
		{
			case 'd':
				system("dir/w c:\\");
				break;
			case 't':
				system("type c:\\commandLine.c");
				break;
			default :
				printf("Using commandLine -d or -t");
		}
	}
	else printf("Using commandLine -d or -t");

	getchar();
	return 0;
}
/* 在生成 27_commandLine-1.exe 的目录下使用命令提示符 27_commandLine-1 -d (c盘根目录)*/
