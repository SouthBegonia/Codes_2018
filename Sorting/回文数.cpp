#include<stdio.h>
#include<string.h>
#define N 40
int main()
{
	char str[N],ch='Y';
	int i;
	int len;
	printf("Input a string: ");
	while(scanf("%s",&str)==1)     
	{
	len=strlen(str);             //有效字符长度 
	for(i=0;i<len;i++)
		if(str[i]!=str[len-1-i])
		{
			ch='N';
			break;
		}     //内层循环
		if(ch=='Y')
		     printf("%s是一个回文数\n",str);
		else printf("%s不是一个回文数\n",str);
    printf("Please input a string again: ");
	}      //while循环
}  
