/*
    程序功能：读取字符串，奇数判回文，偶数判对称。
	栈特点：遵循后进先出，只能在一端进行插入和删除操作。
	实现栈：一维数组，指向栈顶的变量top，通过top实现插入和删除。
	说明：栈的首位元素s[0]是否可以填入，奇偶数的判断。
*/
#include<stdio.h>
#include<string.h>
int  main()
{
	char a[101], s[101];
	int i, len, mid, next = 0, top;

	gets_s(a);                             
	len = strlen(a);                       //字符串长度
	printf("len = %d\n", len);
	mid = len/2;                           
	/*
		奇数下，中点在数组中索引为 len/2
		偶数下，中点索引采用数学中偶数中点的情况（字符数/2+1，但代码和奇数的相同）
	*/
	printf("中点索引 mid = %d，中点对应的元素是a[%d] = %c\n\n", mid,mid,a[mid]);

	top = 0;                               //初始化栈顶
	for (i = 0; i<= mid-1;i++)             //将中点前所有元素入栈
	{
		s[++top] = a[i];                   
		/* 
		    23行代码等价于： ++top; s[top] = a[i];
			对应入栈：s[1]=a[0],s[2] = a[1]
			注意：本段的s[0]认为是栈底，不予入栈，关系到后续出栈的判定，暂从s[1]开始入栈
		
		*/
		printf("入栈：a[%d] = %c, s[%d] = %c\n", i, a[i], top, s[top]);
	}           

	if (len % 2 != 0)
		next = mid + 1;                    
	else
		next = mid;                        
	/*
		奇偶性唯一代码区别：决定回文或对称
			奇数，待比较元素的索引为中点后一元素的索引；
			偶数，无需移动。
	*/

	for (i = next; i < len ; i++)          //对比中点后元素到末尾元素与栈中元素
	{
		if (a[i] == s[top])                //中点后元素一一与栈顶比较，不同则跳出
		{
			printf("出栈：a[%d] = %c,s[%d] = %c\n", i, a[i], top, s[top]);
			--top;                         //栈顶元素和中点后元素相等，则出栈，栈顶下移
		}
		/*
			执行完上列if后，top减为0，即抵达s[0]栈底，s[0]不等于a[len-1]，因为s[0]并未给具体数值，为随机数
			printf("s[0] = %c\n",s[0]);
		*/
		else
			break;        
	}
	printf("\n栈顶索引：top = %d\n", top);

	if (top == 0)                          //抵达栈底s[0]，所有元素比较后都符合
	{
		if (len % 2 != 0)                  //回文数或对称数    
			printf("%s是回文数\n", a);
		else
			printf("%s是对称数\n", a);
	}
	else                              
		printf("%s既不是回文数，又不是对称数\n",a);

	getchar();
	getchar();
	return 0;

}