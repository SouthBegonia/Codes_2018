/*fwrite 把所指向的数组中的数据写入到给定流 stream 中*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	struct node
	{
		char name[10];
		int score;
	};
	struct node student;
	
	FILE *fptr;
	char scorebuf[81];
	
	/*每次写入清除以前数据*/
	if((fptr = fopen("student.txt","wb")) == NULL)
	{
		printf("无法打开 syudent.txt");
		exit(1);
	}
	
	do
	{
		printf("\n\nEnter name:");
		gets(student.name);
		printf("Enter score:");
		/*atoi 将字符串转换成整数*/
		student.score = atoi(gets(scorebuf));
		
		fwrite(&student,sizeof(student),1,fptr);
		printf("One more(y/n)?");
	}while(getche() == 'y');
	
	fclose(fptr);
	getchar();
	return 0;
}
