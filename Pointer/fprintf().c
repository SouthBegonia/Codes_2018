/*
函数原型: int fprintf(FILE *stream, const char *format, ...) 可变参数
	stream -- 指向 FILE 对象的指针
	format -- C 字符串，包含了要被写入到流 stream 中的文本
功能:发送格式化输出到流 stream 中,成功则返回写入的字符数,失败则返回负数
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE * fp;

   fp = fopen ("file.txt", "w+");   //创建可读写文件 file.txt
   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2018);

   fclose(fp);

   getchar();
   return(0);
}
