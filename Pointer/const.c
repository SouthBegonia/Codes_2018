#include <stdio.h>
#include <string.h>

struct Books{
	char *title;
	int price;
	char isbn[32];
};

void regist_book(struct Books const *book_data)     //使用const提示警告，但仍可修改isbn内容
{
	strcpy(book_data->isbn, "Hello ");
	printf( "isbn : %s\n", book_data->isbn);
	
	strcat(book_data->isbn,"world");
	printf( "isbn : %s\n", book_data->isbn);
}
int main()
{
	struct Books book1;
	
	regist_book(&book1);
	
	getchar();
	return 0;

}

