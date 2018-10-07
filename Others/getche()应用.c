/*
getche：及时读取切回显
ESC 27
*/
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	int situation;
	char letter_1,letter_2;
	
	srand(time(NULL));
	
	while(1)
	{
		printf("产生一个随机的字母：");
		situation = rand()%2;

		if(situation == 0)
		{
			letter_1 = rand()%26 + 'A'; 	//大写字母
			printf("%c\n",letter_1);
		}
		else {
			    letter_1 = rand()%26 + 'a';     //小写字母
			    printf("%c\n",letter_1);
		}
		
		do
		{
			printf("请输入：");
			letter_2 = getche(); //残留回车符
			fflush(stdin);
			/* 或是
			scanf("%c",&letter_2);
			getchar();
			*/

			if(letter_2 == letter_1)
			{
				printf("正确！\n\n");
				break;
			}
			else if(letter_2 != letter_1 && letter_2 != 27){
				printf("错误！\n");
			}
		}while(letter_2 != letter_1 && letter_2 != 27);
		
		if(letter_2 == 27)
			break;
	}
	printf("结束！\n");;
	return 0;
}
