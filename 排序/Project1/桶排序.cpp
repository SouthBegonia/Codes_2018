/* 
    桶排序原理：设定 m 个空位（book[1001])，n 个待输入数字（n<<m）；
键入数字，数值对应的空位数据+1（键入数字2，则book[2]++)；
依次判断 m 个空位(book[1001])，空位的数据出现几次则打印几次。
    算法时间复杂度：O( M+N ) 
*/
#include<stdio.h>
int main()
{
	int book[1001], i, j, t, n;
	for (i = 0; i <= 1000; i++)
		book[i] = 0;         //数组初始化 
	scanf_s("%d", &n);          //输入一个数n，表示截下来有n个数
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &t);      //把每一个数读到变量 t 中
		book[t]++;           //进行计数，对编号为t的桶放一个小旗子 
	}
	for (i = 1000; i >= 0; i--)     //依次判断编号1000~0的桶 
		for (j = 1; j <= book[i]; j++) //出现了几次就将桶的编号打印几次
			printf("%d ", i);

	printf("桶排序");
	getchar();
	getchar();
	return 0;
}