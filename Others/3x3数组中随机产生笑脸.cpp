#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h> 
int main()
{
	char ch,a[3][3];
	int i,j,n;
	do
	{
		printf("\n");
		for(i=0;i<3;i++)
		   for(j=0;j<3;j++)
		      a[i][j]='*';
		n=0;
		do
		{
			i=rand()%3;
			j=rand()%3;
			if(a[i][j]=='*')
			{
				a[i][j]='\1';
				n++;	
			}
		}while(n!=3);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			   printf("%3c",a[i][j]);
			printf("\n");
		}
		scanf("%c",&ch);
	}while(ch!='#');
 } 
