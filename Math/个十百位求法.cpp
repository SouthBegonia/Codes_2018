//在3位自然数中，统计百位数和个位数相等，
//但3个数不全相等的偶数个数，并求出所有满足条件的数 
#include<stdio.h>
int main()
{
	int i,a,b,c,n=0;
	for(i=100;i<=999;i=i+2)
	{
		a=i%10;      //个位 
		b=i/10%10;   //十位 
		c=i/100;     //百位 
		if (a==c&&a!=b)
		{
			printf("%6d",i);
			n++;
			if(n%10==0)
			   printf("\n");
		}
	}
	printf("\nn=%d\n",n);
	
 } 
