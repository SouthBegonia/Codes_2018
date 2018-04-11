#include<stdio.h>
int main()
{
	int a=5,b,i=57;
	b=(i>10&&i%2||i%3?a++:a--);
	//b=(((i>10)&&(i%2)||(i%3)?a++:a--)
	//b=((1&&1||0)?a++:a--)
	//b=a++ 
	printf("b= %d\n",b);
	return 0;
}
