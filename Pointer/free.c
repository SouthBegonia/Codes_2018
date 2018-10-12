/*在我的环境下(DEv c++/GCC 6.3.0)调用free()后对应的内存区域被立即破坏*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
int *int_p;
int_p = malloc(sizeof(int));

*int_p=12345;

printf("int_p...%p   *int_p...%d\n",int_p,*int_p);

free(int_p);

printf("int_p...%p   *int_p...%d\n",int_p,*int_p);

getchar();
return 0;
}

