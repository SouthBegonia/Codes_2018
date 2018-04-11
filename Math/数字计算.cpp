//O,[],&分别代表一个数字，求:   
//   1Ox3[]=&&&
#include<stdio.h>
int main()
{
	int a,b,c,x,y;
	for(a=0;a<=9;a++)
	   for(b=0;b<=9;b++)
	      for(c=1;c<=9;c++)
	      {
	      	x=(1*10+a)*(3*10+b);
	      	y=c*100+c*10+c;    //attention 
	      	if(x==y)
	      	   printf("%d*%d=%d\n",1*10+a,3*10+b,y);
	      	   
		  }
 } 
