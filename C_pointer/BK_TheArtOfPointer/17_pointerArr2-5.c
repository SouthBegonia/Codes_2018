#include<stdio.h>
#include<conio.h>

int main()
{
	int j[3][2] = {10,20,30,40,50,60};
	int k,m;
	
	for(k=0;k<3;k++)
	{
		for(m=0;m<2;m++)
			printf("j[%d][%d] = %d        ",k,m,j[k][m]);
		printf("\n");
	}
	
	for(k=0;k<3;k++)
	{
		for(m=0;m<2;m++)
			printf("j[%d][%d] = %p  ",k,m,&j[k][m]);
		printf("\n");
	}
	printf("\n");
	
	for(k=0;k<3;k++)
		printf("j[%d] = %d  j[%d] = %p\n",k,j[k],k,j[k]);   //j[k] 为元素 j[k][0] 的地址，而不是j[k][0],故无实值
	printf("\n");
	
	for(k=0;k<3;k++)
		printf("j+%d = %p\n",k,j+k);
	printf("\n");
	
	for(k=0;k<3;k++)
		printf("*(j+%d) = %p\n",k,*(j+k));  //此处同理，j+k 为j[k][0] 的地址
	printf("\n");
	
	for(k=0;k<3;k++)
		printf("**(j+%d) = %d\n",k,**(j+k));    //解引用 j+k 即表示数值j[k][0]


	getch();
	return 0;
}
