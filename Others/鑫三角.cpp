#include<stdio.h>
#define N 4                            //4行 
int main()
{
	/*      *                 i=1
	       ***                i=2
	      *****               i=3
	     *******              i=4
	      *****               i=3
	       ***                i=2
	        *                 i=1
	*/
	int i,j;
	
	//上半部分 
	for(i=1;i<=N;i++)      
	{
	   for(j=1;j<=N-i;j++)
		  printf(" ");
	   for(j=1;j<=2*i-1;j++)           //关键 
	      printf("*");
	    printf("\n");
	}                                                     
	
	
	//下半部分 
	for(i=N-1;i>=1;i--)               //关键                  
	{                       
		for(j=1;j<=N-i;j++)           //这部分不变 
		   printf(" ");
		for(j=1;j<=2*i-1;j++)
		   printf("*");
		printf("\n");
	}
 } 
