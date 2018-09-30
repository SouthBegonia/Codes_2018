/*

*/
#include<stdio.h>


struct  Tag    //结构体的标签
{
	int a;      //三个结构体成员
	char b;
	double c;
} s1;       //声明了结构体变量 s1

typedef struct
{
	int k;
	char l;
	double m;
} Simple;

int main()
{
	struct Tag s2;  //另一种声明方式
	Simple x;
	
	printf("struct 创建:\n");
	printf("输入s1.a整数：");
	scanf("%d",&s1.a);
	fflush(stdin);  //清除缓存区的回车键
	printf("s1.a = %d\n",s1.a);
	
	printf("输入s2.b字符：");
	scanf("%c",&s1.b);
	fflush(stdin);
	printf("s2.b = %c\n",s1.b);
	printf("-----------------\n");
	
	printf("typedef 创建：\n");
	printf("输入x.k整数：");
	scanf("%d",&x.k);
	fflush(stdin);
	printf("x.k = %d\n",x.k);
	
	
	getchar();
	
	return 0;
}
