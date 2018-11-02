/*定义的数组型字符串空间不足时，末尾无法存放空字符 '\0'*/
#include<stdio.h>

int main()
{
	char *str1 = "Are you ok";
	char str2[4]  = "I AM FINE";
	/*waring：initializi-string for array of chars is too long*/
	
	printf("字符串(指针变量) str1 = %s\n",str1);
	printf("字符串(指针常量，空间不足) str2 = %s\n",str2);
	
	getchar();
	return 0;
}
