//输入一个字符串存放在数组中，改变其中所有大小写字母后逆序输出
#include<stdio.h>
#include<ctype.h>
void exc(char e[]);
int main()
{
	int i = 0;
	int j = 0;
	char a[80];
	
	gets(a);
	
	// ctype.h函数库做法 
	while(a[i] != '\0')
	{
		if(isupper(a[i]))
		    a[i] = tolower(a[i]);
		else if(islower(a[i]))
		    a[i] = toupper(a[i]);
		i++;
	}
	printf("There is the first result: ");
	for(i--;i >= 0;i--)
	    putchar(a[i]);
	printf("\n");
	
	
	
	//普通方法:  *本题a[80]中大小写字母已经被上面函数所改变，
	//             即下列函数改变的是上函数运行后的值 
	
	while(a[j] != '\0')
	{
		if(a[j] >= 'A'&& a[j] <= 'Z')
		    a[j] = a[j] + 32;    
		else if(a[j] >= 'a'&& a[j] <= 'z')
		    a[j] = a[j] - 32;
		j++;
	}
	printf("Exchanging the last result in another way: ");
	for(j--;j >= 0;j--)
	    putchar(a[j]);
	printf("\n");
	
	return 0;
	
}
