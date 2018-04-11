#include<stdio.h>
#include<stdlib.h> //必要头文件 
#include<time.h>   //暂不需要 
int main()
{
	int num,i,ran;
	printf("How many random numbers do you want?\n");
	scanf("%d",&num);
	printf("What's the rang?\n");
	scanf("%d",&ran);
	for(i=0;i<num;i++)
	   printf("%d ",rand()%ran+1); //产生随机数在0~ran之间 
	return 0;
 } 
