#include<stdio.h>

int main()
{
	int array[] = {10,20,30,40,50};
	int *p[] = {array,array+1,array+2,array+3,array+4};
	int **p2 = p;
	/*图解见同文件夹下同名图片:25_starstarPointer-5.jpg*/
	
	for(int i=0;i<5;i++)
		printf("array[%d] = %d,  &array[%d] = %p\n",i,array[i],i,&array[i]);
	printf("\n");
	
	printf("Initial       **p2 = %d\n",**p2);

	p2++;
	printf("After p2++,   **p2 = %d\n",**p2);
	
	++*p2;
	printf("After ++*p2,  **p2 = %d\n",**p2);
	
	**p2++;
	printf("After **p2++, **p2 = %d\n",**p2);
	
	++**p2;
	printf("After ++**p2, **p2 = %d\n",**p2);
	
	getchar();
	return 0;
	
}
