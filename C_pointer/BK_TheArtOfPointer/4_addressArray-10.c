#include<stdio.h>
#include<conio.h>

int main()
{
	int x[5]={10,20,30,40,50};
	int i;
	
	for(i=0;i<5;i++)
		printf("&x[%d] = %p\n",i,&x[i]);
	printf("\n");
	
	for(i=0;i<5;i++)
		printf("x+%d = %p\n",i,x+i);
	printf("\n");
	
	for(i=0;i<5;i++)
		printf("x[%d] = %d\n",i,x[i]);
		
	getch();
	return 0;
}
