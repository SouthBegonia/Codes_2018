/*关于数组指针*/
#include<stdio.h>
#include<conio.h>
int main()
{
    int *(pa)[3];   //数组指针
    int arr1[2][3]={1,2,3,4,5,6};
    int i,j;

    /*打印arr1信息*/
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
            printf("arr1[%d][%d]=%2d %p  |",i,j,arr1[i][j],&arr1[i][j]);
        printf("\n");
    }
    printf("\n");


	/*数组指针原地址*/
	printf("未赋址：\n");
	for(i=0;i<3;i++)
		printf("pa[%d]  =%p  ",i,(*pa)++);
	printf("\n\n");

	/*赋址*/
    *pa=(int *)arr1;   //*pa=arr1 或 pa[]=arr1 且需要显示转换
	printf("进行*pa=(int *)arr1后：\n");
	for(i=0;i<3;i++)
		printf("pa[%d]  =%p  ",i,(*pa)++);
	printf("\n\n");

	/*赋址*/
    *pa=(int *)arr1;
    printf("再行*pa=(int *)arr1后：\n");
    for(i=0;i<3;i++)
		printf("*pa[%d]=%d  ",i,*((*pa)++));
    printf("\n\n");

	/*赋址*/
    *pa=(int*)arr1;
    printf("再行*pa=(int *)arr1后：\n");
    printf("  pa=%p    arr1=%p\n",pa,arr1);
	printf(" *pa=%p   *arr1=%p\n",*pa,*arr1);
	printf("**pa=%p  **arr1=%p\n",**pa,**arr1);

    getchar();
	return 0;
}
