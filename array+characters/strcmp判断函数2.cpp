#include<stdio.h>
#include<string.h>
int main()
{
	//strcmp函数：比较两字符串长度
	//strcat函数: 将后一个字符串接到前一个字符串后面 
	char a[20],b[20];
	gets(a);
	gets(b);
	printf("\n");
	puts(a);
	puts(b);
	printf("\n");
	if(strcmp(a,b)>0)   //若a比b长 
	   strcat(a,b);     //则将b接到a后面 
	else strcat(b,a);  
	puts(a);
	puts(b);
	
 } 
