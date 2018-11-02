#include<stdio.h>

int main()
{
	char *str1 = "Learing pointer now!";    //初始化
	char str2[] = "Go ahead";   //初始化
	char *str3;     //指针变量
	char str4[20];  //指针常量
	
	str3 = "I just coding\n";   //指针变量可在赋字符串地址
	
	/* str4 = "I just coding\n"   指针常量地址固定，不可以再把字符串地址赋值给它不可由输入的方式完成赋值操作 */
	/* scanf("%s",str3)  指针变量不可由输入的方式来完成赋值操作 */
	
	printf("C or C++:");
	scanf("%s",str4);
	
	printf("\nstr1 = %s\n",str1);
	printf("str2 = %s\n",str2);
	printf("str3 = %s\n",str3);
	printf("Learing %s now\n",str4);
	
	getchar();
	getchar();
	return 0;
}
