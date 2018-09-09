/*区别于 scanf("%d",&hoge);
scanf():连续从流中读入字符,对和格式说明符(%d)相匹配的部分进行变换处理.
	如说明符为%d时输入123↙ 从流中读取了 123 但换行符依旧残留在流中被后续getchar()读取
    此外,当scanf()读取失败(说明符%d但输入了英文字符),scanf()会导致读取失败的部分遗留在流中
*/
#include<stdio.h>
#include<windows.h>

int main()
{
	int hoge;
	printf("开始\n");
	
	while(scanf("%d",&hoge)!=1)
	{
		/*当输入非法格式,非法的数据一直在流中不被读取和清除,故一旦错误就无限循环
		假若输入 123a↙ ,则scanf()读取有效部分 123, 即 hoge=123 其余部分残存在流中*/
		printf("输入错误!\n");  
		
		/*若是添加清除缓存语句,则实现效果:读取正确就结束,失败则提示并再次读取
		fflush(stdin);
        */
	}
	
	printf("读取正确:%d",hoge);
	
	/*因为scanf()读取后遗留回车键,被此处 getchar() 读取,故此处没有暂停效果*/
	getchar();
	
	/*此处亦无用,原因暂不明*/
	system("cls");
	return 0;
}
