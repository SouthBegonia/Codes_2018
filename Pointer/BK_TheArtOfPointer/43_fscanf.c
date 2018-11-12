/*fscanf 从流 stream 读取格式化输入*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr;
	char id[10];
	int score;
	
	/*文件必须事先存在才可读取，否则失败*/
	if((fptr=fopen("score.txt","r")) == NULL)
	{
		printf("无法打开 score.txt");
		getchar();
	}
	printf("%-10s %-10s\n","id","score");
	printf("==================\n");
	
	while(fscanf(fptr,"%s %d",id,&score) != EOF)
		printf("%-10s %3d\n",id,score);
		
	fclose(fptr);
	
	getchar();

	return 0;
}
