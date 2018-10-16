/*复合字面量可以用于创建不规则数组*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j;

    /*复合字面量创建二维数组，操作看起来像类型操作转换: (..){..}*/
    /*此处创建规则数组 arr*/
    int (*arr[])={
    (int[]){0,1,2},
    (int[]){3,4,5},
    (int[]){6,7,8}
    };

    /*创建不规则数组 arr2*/
    int (*arr2[])={
    (int[]){0,1,2,3},
    (int[]){4,5},
    (int[]){6,7,8}
    };

    /*打印 arr*/
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("arr[%d][%d] Address=%p  Value=%d\n",i,j,&arr[i][j],arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /*打印 arr2*/
    for(i=0;i<4;i++)
        printf("arr2[%d][%d] Address=%p  Value=%d\n",0,i,&arr2[0][i]);
    printf("\n");
    for(i=0;i<2;i++)
        printf("arr2[%d][%d] Address=%p  Value=%d\n",1,i,&arr2[1][i],arr2[1][i]);
    printf("\n");
    for(i=0;i<3;i++)
        printf("arr2[%d][%d] Address=%p  Value=%d\n",2,i,&arr2[2][i],arr2[2][i]);


    return 0;
}
