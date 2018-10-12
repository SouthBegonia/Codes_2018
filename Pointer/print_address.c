/*
C中有三种内存区的寿命: 静态变量  自动变量  通过malloc()分配的领域
- 静态变量: 全局变量,文件内的static变量,指定static的局部变量都持有静态储存周期,统称静态变量.
        变量的寿命从程序运行时开始,到程序关闭时结束,也就是说一直存在于内存的同一地址上.
- 自动变量: 没有指定static的局部变量持有自动储存期,称为自动变量.
        变量在程序进入他所在的语句块时被分配内存区域,该语句在执行结束后这片内存区域被释放.
- malloc(): 变量通过malloc()分配的领域的寿命到调用free()为止.
*/
#include<stdio.h>
#include<stdlib.h>

int global_var;     //全局变量
static int file_static_var;     //文件内的static变量

void func1(void)
{
	int func1_var;      //自动变量,与func2()内自动变量地址相同
	static int func1_static_var;    //指定static的局部变量
	
	printf("&func1_var............%p\n",&func1_var);
	printf("&func1_static_var.....%p\n",&func1_static_var);
}

void func2(void)
{
	int func2_var;		//自动变量,与func1()内自动变量地址相同

	printf("&func2_var............%p\n",&func2_var);
}

int main()
{
	int *p;
	
	/*输出指向函数的指针*/
	printf("&func1...%p\n",func1);
	printf("&func2...%p\n",func2);
	
	/*输出字符串常量的地址*/
	printf("string literal........%p\n","abc");
	
	/*输出全局变量*/
	printf("&global_var...........%p\n",&global_var);
	
	/*输出文件内的static变量的地址*/
	printf("&file_static_var......%p\n",&file_static_var);
	
	/*输出局部变量*/
	func1();
	func2();
	
	/*通过malloc申请内存区域的地址*/
	p = malloc(sizeof(int));
	printf("malloc address........%p\n",p);
	
	free(p);
	getchar();
	return 0;
}
