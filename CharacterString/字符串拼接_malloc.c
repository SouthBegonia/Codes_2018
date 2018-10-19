/*演示字符串拼接的操作
方法：另创建动态内存并分配合适大小进行拼接，不可在字符串字面量池进行拼接*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    /*正确拼接*/
    char *error = "ERROR:";     //前缀
    char *errorMessage = "Not enough memory";   //后缀
    char *buffer = (char *)malloc(strlen(error)+strlen(errorMessage)+1);    //申请动态内存 buffer
    strcpy(buffer,error);   //复制 error 到 buffer
    strcat(buffer,errorMessage);    //连接errorMessage 到 buffer末尾

    printf("%s\n",buffer);
    printf("%s\n",error);
    printf("%s\n",errorMessage);
    free(buffer);
    /*正确打印：
    ERROR: Not enough memory
    Not enough memory
    */


    /*错误事例：不另创建动态内存而是在字符串字面量池上进行拼接，会导致覆写错误
    char *error_mistake = "ERROR:";
    char *errorMessage_mistake = "Not enough memory";
    strcat(error_mistake,errorMessage_mistake);

    printf("%s\n",error_mistake);
    printf("%s\n",errorMessage_mistake);

    错误打印：
    ERROR: Not enough memory
    ot enough memory
    */
    return 0;
}
