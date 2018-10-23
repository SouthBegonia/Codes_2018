#include<stdio.h>

int main()
{
	int array[3][4]={
		{11,12,13,14},
		{21,22,23,24},
		{31,32,33,34}
	};
	int (*p)[4];
	p = array;
	
	/*打印数组 array 各值及地址*/
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
			printf("array[%d][%d]=%d  Address=%p |",i,j,array[i][j],&array[i][j]);
		printf("\n");
	}
	printf("\n");
	
	/* ++p */
	printf("++p = %p\n",++p);
	printf("p   = %p\n\n",p);   //注意，一旦进行指针自加自减运算即改变了其指向
	
	/* p+i */
	p = array;
	for(int i=0;i<3;i++)
		printf("p+%d = %p\n",i,p+i);    
	for(int i=0;i<3;i++)        //等价于 array+i
		printf("array[%d] = %p\n",i,array+i);
	printf("\n");
	
	/* p[i] */
	p = array;
	for(int i=0;i<4;i++)
		printf("p[%d] = %p\n",i,p[i]);
	printf("\n");
	
	
	getchar();
	return 0;
}

