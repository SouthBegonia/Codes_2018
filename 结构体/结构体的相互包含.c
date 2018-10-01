#include<stdio.h>
#include<string.h>

/*结构体*/
typedef struct
{
	char a;
}COMPLEX_1;

/* COMPLEX_2 包含 COMPLEX_1 */
typedef struct
{
	int a;
	COMPLEX_1 com1;
}COMPLEX_2;

/*包含了指向自己类型的指针*/
/*此处可否用 typedef */
struct NODE
{
	char string[1000];
	struct NODE *next_node;
};

int main()
{
	COMPLEX_2 f;
	struct NODE n1,n2;
	char talk[1000];
	
	f.a = 12;
	f.com1.a = 'Z';
	
	printf("f.a = %d\n",f.a);
	printf("f.com1.a = %c\n",f.com1.a);
	printf("--------------\n");
	
	/*将字符串赋予 string 内，可以scanf(),strcpy()*/
	strcpy(n1.string, "Hello");
	printf("%s\n",n1.string);
	fflush(stdin);
	
	scanf("%s",talk);
	strcpy(n2.string, talk);
	printf("%s\n",n2.string);
	fflush(stdin);
	
	getchar();
	return 0;
}
