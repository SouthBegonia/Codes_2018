#include<stdio.h>
#include<conio.h>

int main()
{
	int arr[3][4] = {0,2,4,6,8,10,12,14,16,18,20,22};
	int *parr[3] = {arr[0], arr[1], arr[2]};
	int i,j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("arr[%d][%d]=%2d %p |",i,j,arr[i][j],&arr[i][j]);
		printf("\n");
	}
	printf("\n");

    /*存储parr指针变量的地址 3x4=12*/
	printf("parr  = %p   *parr = %p    **parr  = %2d\n",parr,*parr,**parr);

	printf("arr   = %p   *arr  = %p    **arr   = %2d\n\n",arr,*arr,**arr);

	printf("parr+1    = %p  *(parr+1)    = %d   **(parr+1)  = %2d\n",*(parr+1),**(parr+1));
	printf("arr+1     = %p  *(arr+1)     = %p   **(arr+1)   = %2d\n\n",arr+1,*(arr+1),**(arr+1));

	printf("parr[0]+1 = %p  *(parr[0]+1) = %2d  *(*parr+1) = %2d\n",(parr[0]+1),*(parr[0]+1),*(*parr+1));

	printf("arr[0]+1  = %p  *(arr[0]+1)  = %2d  *(*arr+1)  = %2d\n",arr[0]+1,*(arr[0]+1),*(*arr+1));


	getch();
	return 0;
}
