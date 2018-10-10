#include<stdio.h>
#include<conio.h>

int main()
{
	int a=100, b=200;
	
	const int *p = &a;      // *p 不可改
	int * const q = &b;     // q 不可改
	
	printf(" a = %d &a = %p  ,  b = %d  &b = %p\n",a,&a,b,&b);
	printf("*p = %d  p = %p  , *q = %d   q = %p\n\n",*p,p,*q,q);

	/*不可以*p间接修改a的值
    *p = b;q */
	/*但可以将指针p指向另一个变量的地址*/
	p = &b;
	printf("a = %d, *p = %d, p = %p\n\n",a,*p,p);
	
	/*不可以更改指针q指向另一个变量的地址
	q = &a */
	/*但可以使用q指针间接修改变量 b 的值*/
	*q = 300;
	printf("b = %d, *q = %d, q = %p\n",b,*q,q);
	
	getch();
	return 0;
}
