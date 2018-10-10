#include<stdio.h>
#include<conio.h>

int main()
{
	int i[] = {10,20,30,40,50};
	int *ptr = i+2;     //ptr指向第3个元素
	int k;
	
	for(k=0;k<5;k++)
		printf("i[%d] = %d  &i[%d] = %p\n",k,i[k],k,&i[k]);
	printf("\n");
	
	for(k=-2;k<3;k++)
		printf("ptr[%2d] = %d  &ptr[%2d] = %p\n",k,ptr[k],k,ptr+k);
	printf("\n");
	
	ptr++;
	printf("After executing ptr++...\n");
	printf("ptr[0] = %d  ptr = %p  ",ptr[0],ptr);
	printf("*(ptr+0) = %d\n",*(ptr+0));
	printf("ptr[1] = %d  ptr+1 = %p  ",ptr[1],ptr+1);
	printf("*(ptr+1) = %d\n",*(ptr+1));
	
	/*  ptr[i] == *(ptr+i)*/
	getch();
	return 0;
}
