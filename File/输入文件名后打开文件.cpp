//
#include<stdio.h>
int main()
{
	FILE *fp;
	char ch,filename[50];
	printf("please input file's name;\n");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}
