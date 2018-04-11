#include<stdio.h>
#include<string.h>
int main()
{
	char a[10]="carry";
	char b[10]="cook"; 
	char t[10];
	printf("Before exchanging: a=%s, b=%s\n",a,b);
	if(strlen(a)>strlen(b))
	{
		strcpy(t,a);
		strcpy(a,b);
		strcpy(b,t);
		printf("After exchanging:  a=%s, b=%s, t=%s\n",a,b,t);
	}
}
