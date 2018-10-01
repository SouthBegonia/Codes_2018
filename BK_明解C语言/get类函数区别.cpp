/*
程序功能：区别getch/getchar/getche 

说明：可能存在异议，待完善。 
*/ 
#include<stdio.h>
#include<conio.h>
#include<string.h>


/*getch(): 读取单字符，即时读取但不回显 */
void __getch(void)
{
 	char ch;
 	printf("类型：getch()\n") ;
 	printf("输入一个字符：");
 	ch=getch();
 	printf("\n你输入的字符是：'%c'\n",ch);
	printf("sizeof = %d\n",sizeof(ch));
	//printf("strlen = %d\n",strlen(ch));    不可用原因：strlen(const char*)
}

/*需getchar():读取单字符，要回车才可读取并回显*/
void __getchar(void)
{
 	char ch;
 	printf("类型：getchar()\n") ;
	printf("输入一个字符：");
 	ch=getchar();		
	printf("\n你输入的字符是：'%c'\n",ch); 
	printf("sizeof = %d\n",sizeof(ch));
}

/*getche(): 读取单字符，即时读取且回显 */
void __getche(void)
{
 	char ch;
 	printf("类型：getche()\n") ;
	printf("输入一个字符：");
 	ch=getche();
 	printf("\n你输入的字符是：'%c'\n",ch); 
 	printf("sizeof = %d\n",sizeof(ch));
}

/*gets(): 读取字符串，回车读取且回显*/
void __gets(void)
{
	char ch[20];		//必须事先规定范围 ，即为常量
	printf("类型：gets()\n");
	printf("输入字符串：");
	gets(ch);
	printf("你输入的字符串是：'%s'\n",ch);
	printf("strlen = %d\n",strlen(ch));
	printf("sizeof = %d\n",sizeof(ch));
}
int main()
{
	int type=0;
	int retry=1;
	do{
	puts("############################################");
	printf("选择你想查看的函数类型\n1.getch  2.getche  3.getchar  4.gets  0.退出\n");
	type=getch();
	type=type-'0';
	
	switch(type)
	{
		case 1: __getch();
			break;
		case 2: __getche();
			break;
		case 3: __getchar();
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
