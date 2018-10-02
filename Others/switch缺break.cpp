/*switch()语句应搭配break使用，否则易错*/
#include<stdio.h>

int main()
{
	char k;
	int i;
	for(i=1;i<3;i++)
	{
		scanf("%c",&k);     //键入 01回车，每次scanf()只读取一个字符
		switch(k)
		{
			case '0': printf("Zero\n");
			case '1': printf("One\n");
			case '2': printf("case \'2\' \n");
			case '3': printf("case \'3\' \n");
		}
	}
	
	getchar();  //消除scanf()读取的回车
	getchar();  //暂停待读取
	return 0;
}
