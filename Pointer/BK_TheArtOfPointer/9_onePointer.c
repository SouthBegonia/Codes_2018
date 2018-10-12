#include<stdio.h>
#include<conio.h>

int main()
{
	int x=100, y=200;
	int *ptr = &x;
	
	printf("&x = %p , x = %d\n",&x,x);
	printf("&y = %p , y = %d\n",&y,y);
	printf("&ptr = %p\n\n",&ptr);    //存放指针变量的地址 &ptr
	
	printf("ptr = %p\n",ptr);   //指针变量的内容(&x)
	printf("x = %d, *ptr = %d\n",x,*ptr);
	
	ptr = &y;
	printf("ptr = %p\n",ptr);
	printf("y = %d, *ptr = %d\n",y,*ptr);
	
	getch();
	return 0;
}
