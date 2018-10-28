/*数组指针*/
#include<stdio.h>
#include<conio.h>
int main()
{
    int (*p)[3];   //数组指针
    int array[2][3]={
	{1,2,3},
	{4,5,6}};
    int i,j;

    /*打印二维数组 array */
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
            printf("array[%d][%d]=%2d  ADS = %p\n",i,j,array[i][j],&array[i][j]);
    }
    printf("\n");


	/* 未给数组指针p赋值
	p 指向的默认数组大小为 4x3 =12
	因为未初始化，所以 p[i] 内暂时没有实际值*/
	printf("未初始化的数组指针 p：\n");
	for(i=0;i<3;i++)
		printf("*p+%d = %p   *(p+%d) = %d\n",i,*p+i,i,*(*p+i));
	printf("\n\n");


	/* p 指向 array ，打印array[0]行内容 */
    p = array;
	printf("*p = array 后:\n");
	for(i=0;i<3;i++)
		printf("*p+%d = %p    *(*p+%d) = %d    (*p)[%d] = %d\n",i,*p+i,i,*(*p+i),i,(*p)[i]);
	printf("\n\n");


    /* 通过 *(p+i) 读取 array[i]行内容 */
	p = array;
	printf("打印array[i]行内容：\n");
	for(int j=0;j<2;j++)
	for(i=0;i<3;i++)
		printf("(*p+%d)+%d = %p   *(*(p+%d)+%d) = %2d\n",j,i,*(p+j)+i,j,i,*(*(p+j)+i));
    printf("\n\n");


	/*其他*/
    p= array;
    printf("  p=%p    array=%p\n",p,array);
	printf(" *p=%p   *array=%p\n",*p,*array);
	printf("**p=%p  **array=%p\n",**p,**array);

    getchar();
	return 0;
}
