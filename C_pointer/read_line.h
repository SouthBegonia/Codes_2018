#ifndef READ_LINE_H_INCLUDE
#define READ_LINE_H_INCLUDE

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define ALLOC_SIZE (256)

/*读取行的缓冲，必要时进行扩展，但是取悦不会被减小
调用free_buffer()释放*/
static char *st_line_buffer = NULL;

/*在st_line_buffer 前方被分配的内存区域的大小*/
static int st_current_buffer_size = 0;

/*st_line_buffer 中现在保存的字符的大小*/
static int st_current_used_size = 0;

/*如有必要，扩展st_line_buffer 前方的内存区域
在st_line_buffer 末尾追加一个字符*/
static void add_character(int ch)
{
	/*此函数每次被调用，st_current_used_size 都必定会加1
	在正常情况下，下面的判断不会错*/
	assert(st_current_buffer_size >= st_current_used_size);

	/*扩展缓冲的内存区域*/
	if(st_current_buffer_size == st_current_used_size)
	{
		st_line_buffer = realloc(st_line_buffer,(st_current_buffer_size + ALLOC_SIZE)*sizeof(char));
		st_current_buffer_size += ALLOC_SIZE;
	}
	/*在缓冲区末尾追加一个字符*/
	st_line_buffer[st_current_used_size] = ch;
	st_current_used_size++;
}

/*从fp读取一个行字符，一旦读取到文件的末尾，就返回 NULL*/
char *read_line(FILE *fp)
{
	int ch;
	char *ret;

	st_current_used_size = 0;
	while((ch=getc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			add_character('\0');
			break;
		}
		add_character(ch);
	}
	if(ch == EOF)
	{
		if(st_current_used_size > 0)
			add_character('\0');
		else return NULL;
	}

	ret = malloc(sizeof(char)*st_current_used_size);
	strcpy(ret,st_line_buffer);

	return ret;
}

/*释放缓冲区内存*/
void free_buffer(void)
{
	free(st_line_buffer);
	st_line_buffer = NULL;
	st_current_buffer_size = 0;
	st_current_used_size = 0;
}

#endif /*READ_LINE_H_INCLUDE*/
