/*程序功能：键入01回车，switch选区对应英文打印。
switch()语句应搭配break使用，否则易错*/
#include<stdio.h>

int main()
{
	char k;
	int i;
	
	for(i=1;i<3;i++)
	{
		scanf("%c",&k);     //每次scanf()只读取一个字符，即 '0' '1' '\n'
		switch(k)
		{
			/*未使用 break 则打印匹配 case 和后续所有case 后的内容*/
			case '0': printf("Zero\n");
			case '1': printf("One\n");
			case '2': printf("Three\n");
			case '3': printf("Four\n");
		}
	}
	
	getchar();  //消除scanf()读取的回车
	getchar();  //暂停待读取
	return 0;
}
