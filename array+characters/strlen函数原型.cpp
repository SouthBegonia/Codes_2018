#include<stdio.h>
int strlength(char s[100]);    //函数原型 
int main()
{
	int i=0,length;
	char s[100];
	printf("请输入字符串: ");
	gets(s);
	length=strlength(s);
	while(s[i]!='\0')
		i++;
	printf("字符串: ");
	puts(s);
	printf("字符串长度 length= %d   \n",length);
}
int strlength(char s[100])
{
	int i=0;
	while(s[i]!='\0')       //while循环体的应用 
		i++;
	return i;
}
