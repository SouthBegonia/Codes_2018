//
#include<stdio.h>
int main()
{
	FILE *fp;
	char ch;
	fp=fopen("C:\\Users\\zzw\\Desktop\\C code\\Other Codes\\File\\text.txt","r");
	
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}
