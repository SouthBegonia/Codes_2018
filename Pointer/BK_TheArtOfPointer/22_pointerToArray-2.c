#include<stdio.h>
#include<conio.h>

int main()
{
    int i[3][2]={1,2,3,4,5,6};
    int j,k;
    int (*pi)[2];  //不可在此处直接初始化
    pi=i;

    for(j=0;j<3;j++)
    {
        for(k=0;k<2;k++)
            printf("i[%d][%d] = %2d %p  |",j,k,i[j][k],&i[j][k]);
        printf("\n");
    }
    printf("\n");

    for(k=0;k<3;k++)
        printf("pi+%d = %p\n",k,pi+k);
    printf("\n");


    printf("*pi=%p  *pi+1=%p  *(pi+1)=%p  *pi[0]*+1 =%p   (pi[0]+1) =%p\n",*pi,*pi+1,*(pi+1),*pi[0]+1,*(pi[0]+1));
    printf("i  =%p  *i+1 =%p  *(i+1) =%p  *i[0]+1   =%p   *(i[0]+1) =%p\n\n",i,*i+1,*(i+1),*i[0]+1,*(i[0]+1));

    printf("pi[0][0]=%d  pi[1][0]=%d\n",pi[0][0],pi[1][0]);

    printf("(*(*(pi+1)+1) = %p\n",(*(*(pi+1)+1)));
    printf("  *(*pi+1)    = %d\n",*(*pi+1));
}
