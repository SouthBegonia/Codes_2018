#include<stdio.h>

int main()
{
	int hoge=0x12345678;
	unsigned char *hoge_p=(unsigned char*)&hoge;
	
	printf("%x\n",hoge_p[0]);
	printf("%x\n",hoge_p[1]);
	printf("%x\n",hoge_p[2]);
	printf("%x\n",hoge_p[3]);
	/*结果为:
		78
		56
		34
		12
    也就是说,CPU将 "0x12345678" 这样的值以 "78,56,34,12" 这样的形式颠倒过来存放, 称为小端字节序.
    但对于工作站等CPU采用顺序存放,称为大端字节序.
    无论是整数还是浮点数,内存上的表现形式都随环境的不同而不同.
	*/
	getchar();
	return 0;
}
