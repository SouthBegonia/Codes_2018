/* 指针数组 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Len 5

int main()
{
    char *p1[Len] = {"ONE","TWO","THREE","FOUR","FIVE"};
    char var[Len][6] = {"one","two","three","four","five"};
    char *p2[Len];

    for(int i=0;i<Len;i++)
        printf("var[%d]=%5s\n",i,var[i]);
    printf("\n\n");


    /* 打印初始化过的指针数组 p1 */
    printf("p1 : ");
    for(int i=0;i<Len;i++)
        printf("%s ",p1[i]);
    printf("\n");


    /* 使指针数组 p2 内各元素(指针型) 指向 var 各元素 */
    for(int i=0;i<Len;i++)
        p2[i] = &var[i][0];
    printf("p2 : ");
    for(int i=0;i<Len;i++)
        printf("%s ",p2[i]);
    printf("\n\n");


    /* 指针数组和二维数组分配字符串空间区别
    通过结果的地址信息可以看出二维数组由最大值(three\0共6字节)决定其他元素的空间也为 6 字节：6,6,6,6,6
    而指针数组分配的空间因个元素不同而不同：4,4,6,5,5 */
    printf("______________________________________________\n");
    for(int i=0;i<Len;i++)
        printf("var[%d]: sizeof = %d, strlen = %d, ADS = %p\n",i,sizeof(var[i]),strlen(var[i]),var[i]);
        /*sizeof()为创建二维数组时的 6*/

    printf("______________________________________________\n");
    for(int i=0;i<Len;i++)
        printf("p1[%d] : sizeof = %d, strlen = %d, ADS = %p\n",i,sizeof(p1[i]),strlen(p1[i]),p1[i]);
        /*sizeof()大小为 指针数组内各元素的类型 (int *)*/
    printf("sizeof(var) = %d \nsizeof(int *) = %d   sizeof(p1) = %d\n\n",sizeof(var),sizeof(int *),sizeof(p1));


    /* 字符串末尾填充转义字符 '\0'  ASCII为十进制的 0 */
    printf("ASCII: e = %d  \\0 = %d\n",var[0][2],var[0][3]);


    return 0;
}
