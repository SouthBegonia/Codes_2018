#include<stdio.h>
#include<conio.h>

int main()
{
	double x[5] ={10.1, 20.2, 30.3, 40.4, 50.5};
	int i;
	
	for(i=0;i<5;i++)
		printf("&x[%d] = %p\n",i,&x[i]);
	printf("\n");
	
	for(i=0;i<5;i++)
		printf("x[%d] = %.1f\n",i,x[i]);
		
	getch();
	return 0;
}
