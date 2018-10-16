/*分配可能不连续的内存 malloc*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows=2;
    int columns=5;
    int i=0;

    int **matrix=(int **)malloc(rows * sizeof(int *));

    for(i=0;i<rows;i++)
    {
        matrix[i]=(int *)malloc(columns * sizeof(int));
    }

    /*分别给两数组赋值*/
    for(i=0;i<columns;i++)
        *(*matrix+i)=i;

    for(i=0;i<columns;i++)
            *(*(matrix+1)+i)=i+1;

    printf("matrix   =%p    matrix+1=%p    &matrix=%p\n\n",matrix,matrix+1,&matrix);
    printf("*matrix  =%p   *(matrix+1)=%p\n",*matrix,*(matrix+1));
    printf("*(matrix+1)=%p  **(matrix+1)=%p\n\n",*(matrix+1),**(matrix+1));

    for(i=0;i<columns;i++)
        printf("matrix[0][%d]=%d  %p  ",i,matrix[0][i],&matrix[0][i]);
    printf("\n");

    /*malloc 分配的内存不连续，两数组起始位置差为48*/
    for(i=0;i<columns;i++)
        printf("matrix[1][%d]=%d  %p  ",i,matrix[1][i],&matrix[1][i]);
    printf("\n");
    return 0;
}
