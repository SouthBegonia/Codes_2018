/*使用静态变量进行字符串操作会造成缓冲区覆写*/
#include<stdio.h>

char *staticFormat(const char* name, size_t quantity, size_t weight)
{
	static char buffer[64]; //静态缓冲区 buffer
	sprintf(buffer,"Item: %s Quantity: %u Weight: %u",name,quantity,weight);
	return buffer;
}

int main()
{
	char *part1 = staticFormat("Axle",25,45);
	char *part2 = staticFormat("Piston",55,5);
	printf("%s\n",part1);
	printf("%s\n",part2);
	/*staticFormat 两次都调用都使用同一个静态缓存区，导致二次调用时覆写前一次调用的结果
	错误打印：Item: Piston Quantity: 55 Weight: 5*/
	
	getchar();
    return 0;
}

