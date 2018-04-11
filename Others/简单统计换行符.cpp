//统计换行符的个数
#include<stdio.h>
int main()
{
	int c,nl;
	nl = 0;
	while((c=getchar()) != EOF)
	    if(c == '\n')
	        nl++;
	printf("%d",nl);
	return 0;
 } 
