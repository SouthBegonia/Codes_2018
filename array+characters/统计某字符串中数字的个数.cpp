//输入若干个字符存放在数组中，然后统计其中各数字字符出现的次数
//程序用a[n]统计数字n的出现次数 
#include<stdio.h>
int main()
{
	int i=0,n,a[10] = {0};
	char c[80];
	gets(c);
	
	while(c[i] != '\0')
	{
		if(c[i] >= '0' && c[i] <= '9')
		{
			n = c[i] -'0';            //'2' - '0'为整数 2 
			a[n]++;
		}
		i++;
	}
	
	
	/*   数字   0 1 2 3 4 5 6 7 8 9
	   出现次数                     */ 
	for(i=0;i<10;i++)
	    printf("%2c",'0'+i);
	printf("\n");
	for(i=0;i<10;i++)
	    printf("%2d",a[i]);
	printf("\n");
 } 
