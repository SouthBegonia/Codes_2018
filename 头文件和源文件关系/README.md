# 简单演示头文件和源文件关系
----------------------

深受启发：
- [C语言中，头文件和源文件的关系](https://blog.csdn.net/xhbxhbsq/article/details/78955216)
- [使用dev-c++建立工程（多个文件一同编译连接）并运行](https://blog.csdn.net/test1280/article/details/52102583/)
- [C语言头文件避免重复包含、#pragma once和#ifndef的区别](https://blog.csdn.net/liulina603/article/details/12083723)

----------------------
## 源代码：
- *main.c*
- *abc.c*
- *abc.h*

```
主函数
/****** main.c ******/
#include<stdio.h>
#include "abc.h"

int main()
{
	printf("This is main()!\n");
	aaa();
	getchar();
	return 0;
}
```

```
实现打印函数aaa()
/****** abc.c *******/
#include<stdio.h>
void aaa(void)
{
	printf("This is aaa()!\n");
}
```

```
同名头文件，声明了函数aaa()
/****** abc.h *******/
#ifndef _H_ABC_H_INCLUDE
#define _H_ABC_H_INCLUDE

void aaa(void);

#endif /*_H_ABC_H_INCLUDE*/
```
一般情况，在*abc.h*内声明功能函数，在*abc.c*内编写函数功能，在*main.c*内调用*abc.h*，从而实现调用*abc.c*内的功能函数`aaa()`。
## 命令行gcc编译流程

1. 执行**编译**指令: `gcc -c abc.c -o abc.o` 和 `gcc -c main.c -o main.o`生成目标文件*abc.o*和*main.o*
2. **连接**目标文件:`gcc abc.o main.o -o main.exe` 生成可执行程序*main.exe*


## 预处理命令放置不同位置编译情况

按照 `#include<stdio.h>` 所放位置：
1. 三处都有
2. 在mian.c内
3. 在abc.h 内
4. 在abc.c 内
5. 在main.c 和 abc.h 内
6. 在main.c 和 abc.c 内
7. 在abc.h  和 abc.c 内


情况见文件夹下对应序号的截图，对比结果
- 1,6,7:正常编译
- 2,3,5：警告*abc.c*内`printf()`缺`#include<stdio.h>`
- 4:警告*main.c*内`printf()`缺`#include<stdio.h>`

但上述7种情况都能生成 *main.exe* 并正常运行。


## 头文件重复包含保护

```
#ifndef _H_ABC_H_INCLUDE
#define _H_ABC_H_INCLUDE

/*内容*/

#endif	/*_H_ABC_H_INCLUDE*/
```
暂且不细说，可参考：[C语言头文件避免重复包含、#pragma once和#ifndef的区别](https://blog.csdn.net/liulina603/article/details/12083723)
## 可能错误情景
1. 在三者内重复定义或者申明函数，如
   - 在*abc.c*内再次申明`aaa()`函数(反之同理)
   - 在*abc.c*或者*abc.h*内写`main()`函数
   - 在*main.c*内写`aaa()`函数
2. 缺漏或者重复预处理指令，如
   - 缺漏:上述事例2,3,4,5 
   - 重复(本事例代码写了**头文件重复包含保护**)