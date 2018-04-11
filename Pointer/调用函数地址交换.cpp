#include<stdio.h>
int pointer(int *m,int *n);
int main()
{
	int a=2,b=3;
	int *m,*n;
	m=&a;
	n=&b;
	printf("已知：          *m=&a=%d,*n=&b=%d\n",*m,*n);
	pointer(m,n);
	printf("main函数体末:   *m=&a=%d,*n=&b=%d\n",*m,*n);
	
 } 
int pointer(int *m,int *n)
 {
 	int *t;
 	t=m;
 	m=n;
 	n=t;
 	printf("Pointer函数体内:*m=&a=%d,*n=&b=%d\n",*m,*n);
 }
