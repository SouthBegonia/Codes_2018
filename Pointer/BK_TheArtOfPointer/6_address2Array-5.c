#include<stdio.h>
#include<conio.h>

int main()
{
	int x[3][2] = {10,20,30,40,50,60};
	int i,j;
	printf("x is %p\n\n",x);
	
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			printf("&x[%d][%d] = %p\n",i,j,&x[i][j]);
	printf("\n");
	
	for(i=0;i<3;i++)
		printf("x[%d] = %p\n",i,x[i]);
	printf("\n");
	
	for(i=0;i<3;i++)
		printf("x[%d] = %p\n",i,x+i);
	printf("\n");
	
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			printf("x[%d][%d] = %d\n",i,j,x[i][j]);
			
	getch();
	return 0;
}
