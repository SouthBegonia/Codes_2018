#include<stdio.h>
#include<stdlib.h>

void allocateArray(int **arr, int size, int value)  //传递指针的指针
{
    *arr=(int *)malloc(size * sizeof(int));

    if(*arr != NULL)    //检验是否为空指针
    {
        for(int i=0;i<size;i++)
            *(*arr+i) = value;

        for(int i=0;i<size;i++)
            printf("*arr+%d =%p   *(*arr+%d) =%d\n",i,*arr+i,i,*(*arr+i));
            // arr[0]+i  arr[0][i]
    }
}

int main()
{
    int *vector=NULL;
    allocateArray(&vector,5,45);
    free(vector);
    return 0;
}
