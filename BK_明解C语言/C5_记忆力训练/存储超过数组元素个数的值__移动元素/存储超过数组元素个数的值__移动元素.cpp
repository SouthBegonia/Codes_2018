/*
程序功能：创建10个元素的数组，将超过10个数字读入数组，超过10个元素后，数组内已有元素前移一位，末尾供新元素，依次类推。
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
		if (cnt >= MAX)
		{
			for (i = 0; i < MAX - 1; i++)
				a[i]=a[i + 1];
		}
		printf("第%d个整数： ", cnt + 1);
		scanf("%d", &a[cnt < MAX ? cnt : MAX - 1]);
		cnt++;

		printf("是否继续？(YES...1/NO...0): ");
		scanf("%d", &retry);
	} while (retry == 1);
	putchar('\n');
	if (cnt <= MAX)
		for (i = 0; i < cnt; i++)
			printf("第%2d个：%d\n", i + 1, a[i]);
	else
		for (i = 0; i < MAX; i++)
			printf("第%2d个：%d\n", cnt - MAX + i, a[i]);
	getchar(); getchar();
	return 0;
}