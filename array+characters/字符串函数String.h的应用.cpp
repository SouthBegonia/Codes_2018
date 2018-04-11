//字符串函数的应用
#include<stdio.h>
#include<string.h>
int main()
{
	char a1[]="a1";
	char a2[]="a2";
	char b[]="abcdefgc";
	char c1[]="123";
	char c2[]="1234";
	char d[]="adc";
	char e1[]="abcKKdef";
	char e2[]="KK";
	char f1[]="AAAA";
	char f2[]="BBBB";
	
	
	//strcat函数:s2所指的字符串接到s1后面。返还：s1字符首地址 
	printf("***%s***%s***\n",strcat(a2,a1));
	 
	 
	//strchr函数：在s中找出第一次出现字符c所在的位置。返还：地址/NULL 
	printf("\n在abcdefgc中，c第一次出现的地址为%ox(16进制)\n",strchr(b,'c'));
	
	
	//strcmp函数：比较s1和s2的大小。返还：s1<s2负数；s1>s2正数;s1=s2 0。
	printf("\n字符串 [%s]与 [%s]大小比较：",c1,c2);
	if(strcmp(c1,c2)==0)
	   printf("%s与%s大小相等\n",c1,c2);
	else if(strcmp(c1,c2)>0)
	   printf("%s大于%s\n",c1,c2);
	else printf("%s小于%s\n",c1,c2);
	
	 
	//strlen函数：求s所指字符长度。返还：有效字符个数。
	printf("\n字符串%s的有效字符个数为%d\n",d,strlen(d)); 
	//  '\n'等转义字符算一个字符 
	//  '\0'并未计入 
	
	
	//strstr函数:找出s1所在字符串中s2所指字符串第一次出现的位置。返还：找到返还首字母地址/NULL
	printf("\n%s所在字符串中%s所指字符串第一次出现的位置为%ox(16进制)\n",e1,e2,strstr(e1,e2));
	
    //strcpy函数：将s2所指字符串复制到s1所指向的内存空间。返还：s1所指内存的空间。
	printf("\n此时s1为[%s],s2为[%s].\n",f1,f2);
	printf("s2所指字符串复制到s1所指向的内存空间:%s",f1,f2,strcpy(f1,f2)); 
	printf("\n此时s1为[%s],s2为[%s].\n",f1,f2);
}
