#include<stdio.h>
#include<string.h>
int main()
{
	int n=0;
	char m[]="ZZW";
	char k[10];
	do
	{
		gets(k);
		if(strcmp(k,m)==0)    //将字符串k与m进行比较： k=m->0; k>m->+ ;k<m->-;
		{
			printf("Right!\n");
			break;
		}
		else printf("Error!Input again!\n");
		n++;
	}while(n!=3);
	if(n==3)
	   printf("Please use authorized software!\n");
	else printf("Welcome to use this software!\n");
}
