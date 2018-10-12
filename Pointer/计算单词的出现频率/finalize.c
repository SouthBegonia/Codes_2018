#include<stdlib.h>
#include "word_manage_P.h"

/*
管理单词部分的结束处理
*/

void word_finalize(void)
{
	Word *temp;
	
	/*将所有登陆的单词free()*/
	while(word_header != NULL)
	{
		temp = word_header;
		word_header = word_header->next;
		
		free(temp->name);
		free(temp);
	}
}
