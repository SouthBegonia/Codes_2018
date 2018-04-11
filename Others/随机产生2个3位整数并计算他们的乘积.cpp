#include<stdio.h>
#include<stdlib.h> //调用randomize（）时要加此行 
#include<time.h>  //调用randomize （）或random（）时必须加此行 
int main()
{
	int a,b,i;
	long int x;
	a=rand()%11;
	b=rand()%11;    //产生0~（11-1）中的随机数字 
	x=(long)a*b;
	printf("%d * %d= %ld\n",a,b,x);
	getchar();     //等待输入回车后开始下一行代码 
	printf("Generate 10 random Numbers\n");
	for(i=0;i<10;i++)
	    printf("%-3d ",rand()%11);
	return 0; 
}
