#include<stdio.h>
#define N 3
int main()
{
	int i=1;
	long s1=0,s2=0;
	do
	{
		if(i%2==0) s1=s1+i;
		if(i%2!=0) s2=s2+i;
		i++; 
	}while(i<=N);   //包含N 
	printf("在从1到%d(包含%d)在内的数字中：\n",N,N);
	printf("这%d个数字为：",N);
	for(i=1;i<=N;i++)
	    printf("%d ",i);
	putchar('\n');
	printf("偶数和s1=%ld, 奇数和s2=%ld\n",s1,s2);
	return 0;
}
