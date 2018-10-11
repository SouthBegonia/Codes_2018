/*指针数组*/
#include<stdio.h>
#include<conio.h>

int main()
{
	char *parr[] = {"The", "Art", "Of", "Poniter"};
	
	printf("*parr[3] = %c\n",*parr[3]);     // [] 优先级高于 *
	printf("**(parr+3) = %c\n",**(parr+3));
	printf("parr[3][0] = %c\n",parr[3][0]);
	printf("parr[2] = %s\n",parr[2]);
	printf("*(parr+2) = %s\n",*(parr+2));
	
	getch();getch();
	return 0;
}
