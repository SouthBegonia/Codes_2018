#include<stdio.h>
#define N 10
int main()
{
    //关键：N个元素，在N-1次循环内：每次进行N-1次相邻排序
	/* 第一趟排序(外循环)

第一次两两比较6 > 2交换(内循环)

交换前状态| 6 | 2 | 4 | 

交换后状态| 2 | 6 | 4 | 
*/
	int a[N],i,j,t;
	printf("Input 10 numbers: \n");
	for(i=0;i<N;i++)
	     scanf("%d",&a[i]);        //输入N个整数到数组 
	for(j=0;j<N-1;j++)                  //读取数组内所有元素:a[0]
		for(i=0;i<N-1;i++)                //让数组内元素进行N-1次相邻排序 
			if(a[i]>a[i+1])                 //若前元素大于后元素则交换 
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
			printf("The sorted numbes: \n");
			for(i=0;i<N;i++)
				printf("%d ",a[i]);
			printf("\n");
}
