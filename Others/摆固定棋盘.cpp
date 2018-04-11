/*编写程序摆成 N * N的围棋盘，
其中1、0分别表示黑子和白子，统计黑子和白子的数目 
       1 1 1 1 1 1 1
       1 0 0 0 0 0 1
       1 0 1 1 1 0 1
       1 0 1 0 1 0 1
       1 0 1 1 1 0 1
       1 0 0 0 0 0 1
       1 1 1 1 1 1 1       */ 

#include<stdio.h>
#define N 7
int main()
{
	int i,j,n=0;
	int a[N][N] = {0};        //定义N*N的数组并全部赋值为 0 
	
	//第一个for循环将对应元素的值改赋为1 
	for(i=0;i<=N/2;i++)
	{
		if(i%2==0)
		{
			for(j=i;j<N-i;j++)
			{
				a[i][j]=1;           //行赋值 
				a[N-i-1][j]=1;
			}
			for(j=i+1;j<N-i-1;j++)
			{
				a[j][i]=1;           //列赋值 
				a[j][N-i-1]=1;
			}
		}
	}
	
	//第二个for循环统计值为1的元素的个数 
	for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(a[i][j] != 0)
                n++;
    
    //第三个for循环打印出赋值后的棋盘 
	for(i=0;i<N;i++)
    {
    	for(j=0;j<N;j++)
    	    printf("%3d",a[i][j]);
    	printf("\n");
	}
	
	printf("%d %d\n",n,N*N-n);
	
	return 0;
 } 
