#include<stdio.h>
#include<stdlib.h>  //malloc

int *allocateArray(int size, int value)
{
    int *arr=(int *)malloc(size * sizeof(int));
    for(int i=0;i<size;i++)
        arr[i]=value;
    return arr;     //返回指针
}

int main()
{
    int *vector = allocateArray(5,45);

    for(int i=0;i<5;i++)
        printf("vector[%d]: Address=%p  Value=%d\n",i,&vector[i],vector[i]);

    free(vector);
    return 0;
}

