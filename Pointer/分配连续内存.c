/*分配连续内存
数组指向上个数组末尾不合法元素实现连续内存*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows=2;
    int columns=5;
    int i=0;
    int **matrix=(int **)malloc(rows * sizeof(int *));

    matrix[0]=(int *)malloc(rows * columns * sizeof(int));

    /*matrix[1]指向matrix[0][5]元素，即接入matrix[0]数组末尾*/
    for(i=1;i<rows;i++)
        matrix[i]=matrix[0]+ i*columns;

    for(i=0;i<columns;i++)
        matrix[0][i]=i;
    for(i=0;i<columns;i++)
        matrix[1][i]=i+1;

    for(i=0;i<columns;i++)
        printf("matrix[0][%d]=%d  %p  |",i,matrix[0][i],&matrix[0][i]);
    printf("\n");
    for(i=0;i<columns;i++)
        printf("matrix[1][%d]=%d  %p  |",i,matrix[1][i],&matrix[1][i]);

    return 0;
}
