/*在dev C内无法实现,会闪退.VC++6.0正常
例:123abc↙
   xyz↙
   
a = 123, c = x*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a;
    char c;

    scanf("%d", &a);
    fflush(stdin);
    
    c = getchar();
    printf("a = %d, c = %c \n", a, c);
    
    getchar();
    return 0;
}
