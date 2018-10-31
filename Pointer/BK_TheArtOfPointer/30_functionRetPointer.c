/*指针函数： int *p(int,...)*/
#include<stdio.h>
#define MAX 5
int k[MAX];

/* p 是一个函数(参数int *, int) 返回一个 int型 的指针*/
int *p(int x[],int n)
{
	int m;
	int j[] ={100,200,300,400,500};
	for(m=0;m<n;m++)
	{
		k[m] = j[m] + x[m];
		printf("k[%d] = %d\n",m,k[m]);
	}
	printf("k = %#x\n",k);
	
	/*返回一个地址*/
	return k;
}

int main()
{
	int total = 0,n;
	int i[MAX] = {10,20,30,40,50};
	int *ptr;
	ptr = p(i,MAX);     //执行后: ptr = k
	
	printf("ptr = %#x\n\n",ptr);
	printf("Sum of (\n");
	for(n=0;n<MAX;n++)
	{
		printf("k[%d] = %d\n",n,*(ptr+n));
		total += *(ptr+n);
	}
	printf(") is %d\n",total);
	
	getchar();
	return 0;
}
