/*
程序功能:简单表示c语言指针

int *p;
声明的变量是 p ,p 的类型是"指向int的指针"
*/ 
#include<stdio.h>
int main()
{
	int hoge=5;
	int piyo=10;
	int *p;     //声明 "指向int的指针"类型的变量 p
	
	/*输出每个变量的地址*/
	printf("&hoge...%p\n",&hoge);
	printf("&piyo...%p\n",&piyo);
	printf("&p......%p\n",&p);
	
	/*将hoge的地址赋予p*/
	p=&hoge;    //指针变量p保存了另一个变量hoge的地址,即表示 "p指向hoge"
	printf("p.......%p\n",p);
	
	/*通过p输出hoge的内容*/
	printf("*p......%d\n",*p);
	
	/*通过p修改hoge的内容*/
	*p=10;     //因为 p 指向 hoge,所以 *p 和 hoge 表示同一事物(相关联,等价于 hoge = 10;)
	printf("hoge....%d\n",hoge);
	
	getchar();
	return 0; 
 } 
