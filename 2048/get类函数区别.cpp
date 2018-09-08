/*
程序功能：区别getch/getchar/getche 

说明：可能存在异议，待完善。 
*/ 
#include<stdio.h>
#include<conio.h>

void __getch(void)
{
 	char ch;
 	printf("类型：getch()\n") ;
 	printf("输入一个字符：");
 	ch=getch();			//即时读取但不回显 
 	printf("\n你输入的字符是：'%c' '%d'\n",ch,ch); 
}

void __getchar(void)
{
 	char ch;
 	printf("类型：getchar()\n") ;
	printf("输入一个字符：");
 	ch=getchar();		//需要回车才可读取并回显 
	printf("\n你输入的字符是：'%c'\n",ch); 
}

void __getche(void)
{
 	char ch;
 	printf("类型：getche()\n") ;
	printf("输入一个字符：");
 	ch=getche();		//即时读取且回显 
 	printf("\n你输入的字符是：'%c'\n",ch); 
}

void __gets(void)
{
	char ch[20];		//必须事先规定范围 
	printf("类型：gets()\n");
	printf("输入字符串：");
	gets(ch);			//回车读取且回显 
	printf("你输入的字符串是：'%s'\n",ch);
}
int main()
{
	int type=0;
	int retry=1;
	do{
	puts("############################################");
	printf("选择你想查看的函数类型\n1.getch  2.getchar  3.getche  4.gets  0.退出\n");
	type=getch();
	type=type-'0';
	
	switch(type)
	{
		case 1: __getch();
			break;
		case 2: __getchar();
			break;
		case 3: __getche();
			break;
		case 4: __gets();
			break;
		case 0: retry=0;
			break;
	}
	
	puts("############################################\n");
	}while(retry!=0);
	
	printf("Done!\n");
	return 0;
}
