/*
程序功能：创建10个元素的数组，将超过10个数字读入数组，超过10个元素后，新元素取代首位元素，再下一元素取代第2位元素，依次类推，组成循环结构。
说明：效率低，假若有1000个元素需要移动999位。
*/
#include<stdio.h>
#define MAX 10

int main()
{
	int i;
	int a[MAX];
	int cnt = 0;
	int retry;

	printf("请输入整数。\n");

	do {
		printf("第%d个整数： ", cnt + 1);
		scanf("%d", &a[cnt++%MAX]);				//核心代码
		
		printf("是否继续？(YES...1/NO...0): ");
		scanf("%d", &retry);
	} while (retry == 1);

	i = cnt - MAX;
	if (i < 0)
		i = 0;
	for (; i < cnt; i++)
		printf("第%2d个： %d\n", i + 1, a[i%MAX]);

	getchar(); getchar();
	return 0;
}