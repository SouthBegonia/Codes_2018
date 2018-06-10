/*	保护头文件，防止被包含多次而产生故障	*/
#ifndef __GETPUTCH	
#define __GETPUTCH

/* MS_Windows/MS-Dos(Visual C++, Borland C++, LIS-C 86 etc...) */
#include<conio.h>

/*	无功能的函数	*/
static void init_getputch(void)	{/*空*/}
static void term_getputch(void)	{/*空*/}

/* #ifndef 结尾 */
#endif  