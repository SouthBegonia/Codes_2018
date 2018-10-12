/*
对指针进行加1运算,,地址的值会增加当前指针所指向数据类型的长度.(本例中的int 4字节)
*/
#include<stdio.h>
int main()
{
	int hoge;
	int *p;

    /*将指向 hoge 的指针赋予p*/
	p=&hoge;
	
	/*输出 hoge 的值*/
	printf("p...%p\n",p);
	
	/*给 p 加 1*/
	p++;
	
	/*输出 hoge的值*/
	printf("p...%p\n",p);
	
	/*输出 hoge 再加 3 后的值*/
	printf("p...%p\n",p+3);
	
	getchar();
	return 0;
}
