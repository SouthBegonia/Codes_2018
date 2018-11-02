#include<stdio.h>

int main()
{
	char *str1 = "THIS IS";
	char str2[] = "HONOR MAGIC";
	
	printf("字符串(指针变量) str1 = %s\n",str1);
	printf("字符串(指针常量) str2 = %s\n",str2);
	
	getchar();
	return 0;
}
