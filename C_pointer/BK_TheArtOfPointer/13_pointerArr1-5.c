#include<stdio.h>
#include<conio.h>

int main()
{
	int arr[] = {100,200,300};
	int *ptr = arr;
	int i,size = 0;
	size = (sizeof(arr) / sizeof(arr[0]));  //size = 3
	
	/* 使用 arr */
	printf("使用 arr 指针常量来表示：\n");
	for(i=0;i<size;i++)
		printf("&arr[%d] = %p\n",i,&arr[i]);
	printf("\n");
	
	for(i=0;i<size;i++)
		printf("arr+%d = %p\n",i,arr+i);    //&arr[i]
	printf("\n");
	
	for(i=0;i<size;i++)
		printf("arr[%d] = %d\n",i,arr[i]);
	printf("\n");
	
	for(i=0;i<size;i++)
		printf("*(arr+%d) = %d\n",i,*(arr+i));  //arr[i]
	printf("\n");
	
	/* 使用 ptr */
	printf("使用 ptr 指针变量来表示：\n");
	for(i=0;i<size;i++)
		printf("ptr+%d = %p\n",i,ptr+i);    //&arr[i]
	printf("\n");
	
	for(i=0;i<size;i++)
		printf("ptr[%d] = %d\n",i,ptr[i]);  //arr[i]
	printf("\n");
	
	for(i=0;i<size;i++)
		printf("*(ptr+%d) = %d\n",i,*(ptr+i));  //arr[i]

	getch();
	return 0;
}
