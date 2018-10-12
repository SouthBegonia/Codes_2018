#include<stdio.h>

void func(int *array, int size)
{
	/*作为被调方是不知道数组元素个数的，故通常也要传递数组元素个数等参数*/
	int i;
	for(i=0;i<size;i++)
		printf("array[%d]...%d\n",i,array[i]);
}

int main()
{
	int array[]={1,2,3,4,5};
	
	func(array,sizeof(array)/sizeof(int));
	
	getchar();
	return 0;
}
