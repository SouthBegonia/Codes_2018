# C_pointer
--------------

## 指针的声明
C语言声明格式:"类型 变量名;"
- 基本类型:`int hoge;`
- 指针类型:`int *pointer;`

区别在于:

|声明|含义|
|---|--|
int hoge;|声明**整数类型**的变量 hoge|
int *pointer;|声明 **"指向int的指针"**类型的变量 pointer| 

关于`int *pointer;` 其:

|   |   |
|---|---|
**指针类型**|指向int的指针  |
**指针类型的变量**|pointer  |
**指针类型的值**| 内存的地址 |

![C语言的数据类型](https://gss0.baidu.com/94o3dSag_xI4khGko9WTAnF6hhy/zhidao/wh%3D600%2C800/sign=c1793ba86c59252da342150204ab2f03/377adab44aed2e7393545f9e8b01a18b86d6fac7.jpg)

C语言的数据类型参考:[C 数据类型-菜鸟教程](http://http://www.runoob.com/cprogramming/c-data-types.html)  

- 代码示例 [pointer.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/pointer.c)



## 指针运算

> 对指针进行加 N 运算, **地址的值**会增加当前指针所指向数据类型的长度 ✖ N

- 代码示例 [pointer-calc.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/pointer_calc.c)

## 空指针 
确保没有指向任何一个**实际的对象**或者**函数**的指针.通常使用宏定义**NULL**来表示空指针常量值.
- 代码示例 [null_pointer.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/null_pointer.c)

## 指针与数组
> 表达式中,数组可以解读成 **"指向它的初始元素的指针"**.(有例外)
> **p[i]** 是 ***(p+i)** 的简便写法.

- 代码示例 [array.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/array.c)	[array2.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/array2.c)

**C的数组从0开始原因:**
- 解决生活中"差1错误"问题
- 在支持指针的语言中，标号被视作是偏移量，因此从0开始更符合逻辑

> 当今的操作系统都会给应用程序的**每一个进程分配独立的** "虚拟地址空间".
> 操作系统负责将物理内存分配给虚拟地址空间,同时还会对每一个内存区域设定"只读"或者"可读"属性.
- 代码示例 [vmtest.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/vmtest.c)

**scanf()说明**

`scanf()`:连续从**流**中读入字符,对和**格式说明符相匹配的部分**进行变换处理,但是当变换失败(与格式说明符不匹配等),则**读取失败的部分**会残存在**流**中(影响其他语句的读取).
- 代码示例 [scanf().c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/scanf().c)

## 变量储存地址

| 储存期 |  含义 | 寿命  |
|---|---|---|
**静态变量**| 全局变量,文件内的static变量,指定static的局部变量都持有静态储存周期  | 从程序运行时开始,到程序关闭时结束
**自动变量**| 没有指定static的局部变量持有自动储存期  | 到声明该变量的语句块执行结束为止
**malloc()**| 变量通过malloc()分配的领域 | 到free()释放为止

- 代码示例 [print_address.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/print_address.c)

## 自动变量(栈)
> **自动变量**重复使用内存区域,因此自动变量的**地址不是一定的**.

- 代码示例 [auto.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/auto.c)

> 大部分CPU中已经嵌入**栈**的功能,C语言通常直接使用.
> C语言中,通常将自动变量1保存在**栈**中.

`assert(条件表达式)`:若表达式为真,assert()不执行任何动作,否则在标准错误 stderr 上显示错误消息，并中止程序执行.

## 动态内存分配
**malloc()**:
- 声明: `void *malloc(size_t size)`
- **功能**:分配所需的内存空间，并返回一个指向它的指针.
- 在标准C库中，提供了`malloc/free`函数分配释放内存，这两个函数底层是由brk，mmap，munmap这些系统调用实现的,但他们不是系统调用,是标准库函数.

 可能调用 `free()` 后,**对应的内存区域不会立即返还给操作系统**,因为可能有2个指针(A与B)在引用当前区域的情况出现,使用指针A引用的区域后仓促调用 `free()` ,指针B引用的内存区域也不会立即破坏,暂时保留以前的值,**直到某个地方执行 `malloc()`** ,随着当前内存区域被重新分配,内容才开始被破坏.
- 代码示例 [free.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/free.c)

> 碎片化 : 内存被零零散散分割,出现较多无法利用的细碎空块.
> 使用 `malloc()` 的内存管理过程,可能引发碎片化

**realloc()**
- 声明: `void *realloc(void *ptr, size_t size)`
- 功能: 尝试重新调整之前调用 `malloc` 或 `calloc` 所分配的 `ptr` 所指向的内存块的大小,即**扩展内存区域**. 如果通过`ptr`传递的区域后面有足够大小的空闲空间,则直接实施内存区域扩展. 若没有足够多的区域,则**分配其他新空间**,然后将内容**复制**过去.
- `realloc`同样可能引发**碎片化**,但相比`malloc`较为缓和,但要是用在**扩展较大的内存区域**,除了复制耗时,也会造成堆中大量的空间过分活跃,此时应该积极使用**链表**.
- 代码示例 [realloc.c](https://github.com/SouthBegonia/Codes_2018/blob/master/C_pointer/realloc.c)