#include<stdio.h>

/*接收二维数组的求和函数*/
int sum(int p2[][2], int n, int m)
{
	int i,j,t=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			t += p2[i][j];
			
	return t;
}

int main()
{
	int i,j,row,column,total=0;
	int arr2[][2] = {10,20,30,40,50,60,70,80,90,100};
	int elements = sizeof(arr2)/sizeof(arr2[0][0]);
	row = elements / 2;
	column = 2;
	
	/*传递二维数组及其行列信息*/
	total = sum(arr2,row,column);
	
	printf("There are %d elements in the array\n",elements);
	printf("Sum(\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
			printf("%3d ",arr2[i][j]);
		printf("\n");
	}
	
	printf(") is %d\n",total);
	getchar();
	return 0;
}
