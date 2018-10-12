#include<stdio.h>
#include<conio.h>

int main()
{
	int num[]={10,20,30,40,50};
	int *p = num;
	int i;

	for(i=0;i<5;i++)
		printf("&num[%d] = %p, num[%d] = %d\n",i,&num[i],i,num[i]);
	printf("p = %p, *p = %d\n\n",p,*p);
	
	p+1;
	printf("After p+1:\n");
	printf("p = %p, *p = %d\n",p+1,*p);     //p+1表示p指向下一个元素地址，但并没有覆盖 p
	printf("p = %p, *p = %d\n\n",p,*p);     //即不影响原本的p
	
	p++;
	printf("After p++:\n");
	printf("p = %p, *p = %d\n\n",p,*p);
	
	
    /*简单事例区别 p+1，p++*/
	p = num;    //重置p
	for(i=0;i<5;i++)
	{
		p+i;    //进行 p+i 不影响原本 p 的指向
		printf("p+%d = %p, *(p+%d) = %d\n",i,p,i,*p);
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("p+%d = %p, *(p+%d) = %d\n",i,p,i,*p);
		p++;    //进行 p++ 改变原本 p 的指向
	}
    
	getch();
	return 0;
}
