#include<stdio.h>
int main()
{
	int x = 5, y = 10;
	x = y+2;
	y = x+3;
	printf("x= %d,y = %d\n", x, y);
	printf("D x= %x,D y = %x\n", &x, &y);
	x = x * 2;
	y = y * 2;
	printf("x= %d,y = %d\n", x, y);
	printf("D x= %x,D y = %x\n", &x, &y);

	getchar();
	return 0;

}