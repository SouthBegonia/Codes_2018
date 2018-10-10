#include<stdio.h>
#include<conio.h>

int main()
{
	int x[5];
	int i;
	
	for(i=0;i<5;i++)
	{
		printf("请输入x[%d]的整数值：",i);
		scanf("%d",&x[i]);      //等效
	}
	for(i=0;i<5;i++)
		printf("x[%d] = %d\n",i,x[i]);
	printf("\n");
	
	for(i=0;i<5;i++)
	{
		printf("请输入x[%d]的整数值：",i);
		scanf("%d",x+i);        //等效于 &x[0+i]
	}
	for(i=0;i<5;i++)
		printf("x[%d] = %d\n",i,x[i]);
	printf("\n");
	
	getch();
	return 0;
}
