/*进行字符串操作时尽量malloc另创建空间进行操作，而不是在字符串面量池里面进行操作*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  
    char *error = "ERROR:";    
    char *errorMessage = "Not enough memory";   
    char *buffer = (char *)malloc(strlen(error)+strlen(errorMessage)+1);   //另创建空间进行字符串操作
    strcpy(buffer,error);   
    strcat(buffer,errorMessage);    

    printf("%s\n",buffer);
    printf("%s\n",error);
    printf("%s\n",errorMessage);
    free(buffer);
    /*正确打印
    ERROR: Not enough memory
    Not enough memory
    */


    /* 在字符串面量池内覆写造成的错误代码事例
    char *error_mistake = "ERROR:";
    char *errorMessage_mistake = "Not enough memory";
    strcat(error_mistake,errorMessage_mistake);

    printf("%s\n",error_mistake);
    printf("%s\n",errorMessage_mistake);

    错误打印：
    ERROR: Not enough memory
    ot enough memory
    */
    getchar();
    return 0;
}
