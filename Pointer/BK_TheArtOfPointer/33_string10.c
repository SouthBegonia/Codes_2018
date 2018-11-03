#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/*指针变量：char *str1
	创建时没有分配固定的内存空间(str1 和 str2 地址相同)，所以应该都存于字符串面量池中;
	str1 指向的地址可以改变(赋址其他字符串)；
	str1 只有在用 malloc 分配内存后才可使用 scanf 读取字符串*/
	char *str1 = "Learing pointer now!";
	char *str2 = "Learing pointer now!";
	

	/*指针常量： char const *str2
	创建数组时(指针常量)，就已配分好固定大小和固定地址；
	str2 本身值不可以改变，也就是数组 str2 的地址不可改变，也不可进行自加自减运算 */
	char str3[] = "Go ahead";
	char str4[20];
	

	/*不同变量指向字符串面量池内相同内容 */
    printf("字符串面量池内：str1 = %p  str2 = %p\n",str1,str2);

	/*指针变量可重新赋址*/
	printf("Before: str2 = %s\n",str2);
	str2 = "I just coding\n";
    printf("After:  str2 = %s\n",str2);
    
    
    /*为指针变量分配内存后即可赋值改变其内容，也可再赋址 */
	str2 = malloc(80);
	printf("输入字符串读入 str2: ");
	scanf("%s",str2);
	printf("Now: str2 = %s\n",str2);



	printf("\n--------------------------\n");
	/*数组创建时，系统自动为数组分配的大小*/
	printf("str3[] =\"%s\",  sizeof(str3) = %d\n",str3,sizeof(str3));
	
	/*不可赋址给数组
	str3 = "hello"; */
	
	/*数组可直接用scanf()读取赋值*/
	printf("输入字符串读入 str4: ");
	scanf("%s",str4);
	printf("str4 = %s",str4);

	free(str2);
	
	getchar();
	return 0;
}
