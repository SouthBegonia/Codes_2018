/*argv[0]中保存了命令名自身。
argc中保存了参数的个数*/
#include<stdio.h>
#include<stdlib.h>

void type_one_file(FILE *fp)
{
	int ch;
	while((ch = getc(fp)) != EOF)
		putchar(ch);
}

int main(int argc, char **argv)
{
	if(argc == 1)   //如果不指定参数，则使用标准输入
		type_one_file(stdin);
	else{
		int i;
		FILE *fp;
		
		for(i=1;i<argc;i++) //顺序处理参数指定的文件名
		{
			fp = fopen(argv[i],"rb");
			if(fp == NULL)
			{
				fprintf(stderr,"%s:%s can not open.\n",argv[0],argv[i]);
				exit(1);
			}
			type_one_file(fp);
			fclose(fp);
		}
	}
	
	getchar();
	return 0;
}
