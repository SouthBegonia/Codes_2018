/*fprintf 输出数据到流中*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char id[10];
	int score;
	FILE *fptr;
	
	/*w+打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则创建新文件
	a+是可读写和追加，r+覆写*/
	if((fptr = fopen("score.txt","w+")) == NULL)
	{
		printf("无法打开 score.txt");
		exit(1);
	}
	
	do
	{
		printf("请输入 id 与 score (-1 与 -1 时表示结束)");
		scanf("%s %d",id,&score);
		
		if(strcmp(id,"-1") != 0 && score != -1)
			fprintf(fptr,"%s %d\n",id,score);
			/*与printf相比多了指向文件的指针fptr*/
	}while(strcmp(id,"-1") != 0 && score != -1);
	
	fclose(fptr);       //关闭文件才算写入完成
	printf("\n");
	
	/*只读模式打开文件score.txt并打印其内容*/
	if((fptr = fopen("score.txt","r+")) != NULL)
	{
		printf("%-10s %-10s\n","id","score");
		printf("==================\n");

		while(fscanf(fptr,"%s %d",id,&score) != EOF)
			printf("%-10s %3d\n",id,score);
	}
	fclose(fptr);
	
	getchar();
	return 0;
}
