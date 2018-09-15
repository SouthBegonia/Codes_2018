#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read_slogan(FILE *fp, char **slogan)
{
	char buf[1024];
	int i;
	
	for(i=0;i<7;i++)
	{
        /*从标准流读取7次标语*/
		fgets(buf,1024,fp);     
		
		/*删除末尾换行字符*/
		buf[strlen(buf)-1] = '\0';
		
		/*分配保存一个标语的内存空间*/
		slogan[i] = malloc(sizeof(char) * (strlen(buf)+1));
		
		/*复制标语的内容*/
		strcpy(slogan[i],buf);
	}
}

int main()
{
	char *solgan[7];    //等价于slogan[i][n]
	int i;
	
	read_slogan(stdin,solgan);

	for(i=0;i<7;i++)
		printf("%s\n",solgan[i]);
		
	getchar();
	return 0;
}
