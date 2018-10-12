#include<stdio.h>
#include<conio.h>

int main()
{
	int i[] = {10,20,30,40,50};
	int *p = i;
	
	printf("*p = %d  p = %p\n\n",*p,p);
	
	/* * 与 ++ 的优先级相同，故从右到左 */
	printf("*p++...%d\n",*p++);     //*(p++)
	printf("*p = %d  p = %p\n\n",*p,p);
	
	p = i;
	printf("*++p...%d\n",*++p);     //*(++p)
	printf("*p = %d  p = %p\n\n",*p,p);

	p = i;
	printf("++*p...%d\n",++*p);     //++(*p)
	printf("*p = %d  p = %p\n\n",*p,p);     //对*p的递增运算，不影响 p
	
	getch();
	return 0;
}
