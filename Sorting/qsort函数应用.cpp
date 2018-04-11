//qsort函数
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)      // 排序规则（按降序排）
{
   return  *(int*)a-*(int*)b;         //a-b升序，b-a降序 
}

int main()
{
   int  a[6]={1,2,3,4,5,6},i;
   
   qsort(a,6,sizeof(int),cmp);      
   //a是被排序的数组   
   //6是排序元素的个数        
   //sizeof（int）是每个元素所占的字节数       
   //cmp是排序规则
   
   for(i=0;i<6;i++)                 //输出
	  printf("%d ",a[i]);
    return 0;
}
 
