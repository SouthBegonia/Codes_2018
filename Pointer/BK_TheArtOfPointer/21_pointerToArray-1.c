#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i[][3]={10,20,
        30,40,
        50,60};
    int (*ptr)[3];
    int a,b,total=0;

    for(a=0;a<2;a++)
    {
        for(b=0;b<3;b++)
            printf("i[%d][%d]  = %d        ",a,b,i[a][b]);
        printf("\n");
    }

    for(a=0;a<2;a++)
    {
        for(b=0;b<3;b++)
            printf("&i[%d][%d] = %p  ",a,b,&i[a][b]);
        printf("\n");
    }

    ptr=i;
    printf("\n");

    printf("ptr  =%p  *ptr=%p\n",ptr,*ptr);
    printf("i[0] =%p    i =%p   *i=%p\n",i[0],i,*i);

    for(a=0;a<2;a++)
        for(b=0;b<3;b++)
            total +=*(*(ptr+a)+b);      // i[a][b]  *(i[a]+b)  ptr[a][b]

    printf("\nSum of array = %d\n",total);
    system("PAUSE");
    return 0;
}
