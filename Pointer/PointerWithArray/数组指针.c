/*数组指针: int (*p)[n]
当数组指针指向另一个数组时，要求数据类型匹配，否则出现警告甚至错误*/
#include<stdio.h>

int main()
{
	int array[3][4]={
		{11,12,13,14},
		{21,22,23,24},
		{31,32,33,34}
	};
	int (*p)[5];    //不匹配的数据类型，正确格式：(*p)[4]
	p = array;
	
	
	/*打印数组 array 各值及地址*/
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
			printf("array[%d][%d]=%d  ADS=%p |",i,j,array[i][j],&array[i][j]);
		printf("\n");
	}
	printf("\n");
	
	
	/* ++p 与 p+i
	p指向一个匿名数组 (*p)
	p+1 或者 ++p 的差值 = 数组类型大小(sizeof(int [5]) = 4x5 =20) x i */
	printf("###### ++p 与 p+i  ######\n");
	printf("p   = %p\n",p);
	printf("++p = %p\n",++p);   //差值=20x1
	printf("p   = %p\n",p);   //注意，一旦进行指针自加自减运算即改变了其指向
	
	p = array;
	for(int i=0;i<4;i++)
		printf("p+%d  = %p     *(p+%d) = %p  p[%d]= %p \n",i,p+i,i,*(p+i),i,p[i]);
	printf("\n\n");
	
	
	/* p指向的数组
	读取 array[0] 的内容*/
	printf("###### p 指向的数组 ######\n");
	for(int i=0;i<4;i++)
		printf("*p+%d =%p    *(*p+%d) =%d   (*p)[%d] =%d   ==   &array[0][%d] =%p  array[0][%d] =%d\n",i,(*p+i),i,*(*p+i),i,(*p)[i],i,&array[0][i],i,array[0][i]);
	printf("\n\n");

	
    /* p+1 指向的另一个数组
    读取 array[1] 的内容
	但发现不是预想的 p+1 对称指向array[1][0]，这就是因为 p 指向为 int [5]类型，而数组为 array[][4] 类型，p内末位 *p+4 占据了 array[1][0]
	同理，p+2 时的首位元素也被 p+1 内的末位元素占据*/
	printf("###### p+1 指向的数组 ######\n");
	for(int i=0;i<4;i++)
        printf("*(p+1)+%d =%p  *(*(p+1)+%d) =%d\n",i,*(p+1)+i,i,*(*(p+1)+i));
	printf("被占据的array[1][0] : *p+4 = %p   *(*p+4) = %d",*p+4,*(*p+4));
	printf("\n\n");
	
	
	/* *p[] 与 (*p)[] 尽量修改数据类型匹配防止发生错误 */
	printf("###### *p[] 与 (*p)[] ######\n");
	for(int i=0;i<3;i++)
		printf("*p[%d] = %d   (*p)[%d] = %d\n",i,*(p[i]),i,(*p)[i]);
	printf("\n");
	
	getchar();
	return 0;
}

