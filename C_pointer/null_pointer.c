#include<stdio.h>
int main()
{
	void *p;
	int a[2]={1,2};
	p=&a;
	
	printf("a[0]....%d    &a.....%p\n",a[0],&a);
	
    /*未强制转换, 不存在 *p*/
    printf("*p......      p.....%p\n\n",p);
	
	
	/*强制转换成指向int的指针类型 */
	printf("*p......%d    p......%p\n",*(int *)p,(int *)p);
	
	/*强制转换是单次的,故下列代码错误, p 仍为空指针
	printf("*p....%d    p....%p\n",*(p+1),(p+1));*/
	
	/*指针强制转换后加一操作,
	易错: *(int *)(p+1) 表示空指针加一再强制转换*/
	printf("*(p+1)..%d   (p+1)...%p\n",*(((int *)p)+1),(int *)p+1);
	
	getchar();
	return 0;
}
