#include<stdio.h>
int main()
{
	int a = 1;
	a = a + 1;     // 2   
	a = a + 1;     // 3
 	a = a * 2;     // 6
	a = a * 2;     // 12
	a = a * 3;     // 24
	a = a * a;     // 1296

	printf("a=%d", a);
	getchar();
	return 0;
 } 
