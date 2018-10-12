#include<stdio.h>

int main()
{
	int hoge;
	char buf[256];
	
	printf("&hoge...%p\n",&hoge);
	printf("Input initial value.\n");
	
	/*区别于 scanf("%d",&hoge);
	scanf():连续从流中读入字符,对和格式说明符(%d)相匹配的部分进行变换处理.
		如说明符为%d时输入123↙ 从流中读取了 123 但换行符依旧残留在流中被后续getchar()读取
        此外,当scanf()读取失败(说明符%d但输入了英文字符),scanf()会导致读取失败的部分遗留在流中
	*/
	fgets(buf,sizeof(buf),stdin);
	sscanf(buf,"%d",&hoge);     //仅读取有效部分
	
	for(;;)
	{
		printf("hoge..%d\n",hoge);

		getchar();
		hoge++;
	}
	
	getchar();
	return 0;
}
