#include<stdio.h>

int main()
{
	int array[5] ={10,20,30,40,50};
	int *p[] ={array,array+1,array+2,array+3,array+4};  //指针数组，每个元素储存一个地址
	int **p2 = p;

	/*打印数组地址信息*/
	for(int k=0;k<5;k++)
		printf("&array[%d] = %p\n",k,&array[k]);
	printf("\n");

    /*打印指针数组内各元素内容及其指向的内容*/
	for(int k=0;k<5;k++)
		printf("p[%d] = %p   *p[%d] = %d\n",k,p[k],k,*p[k]);
	printf("\n");
	
	/*通过双重指针 p2 打印内容*/
	for(int k=0;k<5;k++)
		printf("**(p2+%d) = %d\n",k,**(p2+k));

	getchar();
	return 0;
}
