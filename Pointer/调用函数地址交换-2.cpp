#include<stdio.h>
int swap(int *p,int *q);
int main()
{  
   int  x=3,y=5,*p=&x,*q=&y;
   swap(p,q);             //地址，非*p 
   printf("%d\t%d\n",*p,*q); 
} 
int swap(int *p,int *q)
{  
   int t;                   //注意！不是*t； 
   t=*p;   
   *p=*q;  
   *q=t;
}
