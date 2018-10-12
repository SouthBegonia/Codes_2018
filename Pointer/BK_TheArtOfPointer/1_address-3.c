#include<stdio.h>
#include<conio.h>

int main()
{
	int x=100, y=200, z=300;
	
	printf("x 的变量地址是 %p\n",&x);
	printf("y 的变量地址是 %p\n",&y);
	printf("z 的变量地址是 %p\n",&z);
	
	printf("x 变量的内容是 %d\n",x);
	printf("y 变量的内容是 %d\n",y);
	printf("z 变量的内容是 %d\n",z);
	
	getch();
	return 0;
}
