#include<stdio.h>
#include<string.h>
int main()
{
	//strlne与sizeof的区别： 
	char k[]="ABCD";
	printf("k=\"%s\"\n",k);
	printf("strlen(k)=%-3d\n",strlen(k)); //算所有有效字符。'\0'未计入 
	printf("sizeof(k)=%d\n",sizeof(k));   //算所有字符 
	
 } 
