#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *str;

   /* 最初的内存分配 */
   str = (char *) malloc(15);
   strcpy(str, "Hello");
   printf("String = %s  Address = %p\n", str, str);

   /* 重新分配内存 */
   str = (char *) realloc(str, 25);
   strcat(str, " World");
   printf("String = %s  Address = %p\n", str, str);

   free(str);

	getchar();
   return(0);
}
