/*回文数
注意scanf()读取和 gets():读取字符串，回车读取且回显
*/
#include<stdio.h>
#include<string.h>

int main()
{
	int n;   //字符串个数
	
	printf("输入字符串数量：");
	scanf("%d",&n);
	getchar();
	
	for( ; n>0; n--)
	{
		int l,i,t;
		char str[10000];
		
		gets(str);
		l = strlen(str);    	//字符个数

		//printf("%d",l);
		
		if(l == 1)  	//一个字符的情况
			t = 1;
		else if(l % 2 == 0)  	//偶数
		{
			for(i=0;i<l;i++)
				if(str[i] != str[l-i-1])
					t = 0;
				else t = 1;
		}
		else {
			for(i=0;i<(l/2);i++)    //奇数
				if(str[i] != str[l-i-1])
					t = 0;
				else t = 1;
		}
		
		/*判断*/
		if(t==1)
			printf("Yes!\n");
		else printf("No!\n");
	}
	
	printf("\nDone！\n");
	
	getchar();
	return 0;
}
