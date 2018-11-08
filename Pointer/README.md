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

- 代码示例 [pointer.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/pointer.c)



## 指针运算

> 对指针进行加 N 运算, **地址的值**会增加当前指针所指向数据类型的长度 ✖ N

- 代码示例 [pointer-calc.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/pointer_calc.c)

## 空指针 
确保没有指向任何一个**实际的对象**或者**函数**的指针.通常使用宏定义**NULL**来表示空指针常量值.
- 代码示例 [null_pointer.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/null_pointer.c)

## 指针与数组
> 表达式中,数组可以解读成 **"指向它的初始元素的指针"**.(有例外)
> **p[i]** 是 ***(p+i)** 的简便写法.

- 代码示例 [array.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/array.c)	[array2.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/array2.c)

**C的数组从0开始原因:**
- 解决生活中"差1错误"问题
- 在支持指针的语言中，标号被视作是偏移量，因此从0开始更符合逻辑

> 当今的操作系统都会给应用程序的**每一个进程分配独立的** "虚拟地址空间".
> 操作系统负责将物理内存分配给虚拟地址空间,同时还会对每一个内存区域设定"只读"或者"可读"属性.
- 代码示例 [vmtest.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/vmtest.c)


## 变量储存地址

| 储存期 |  含义 | 寿命  |
|---|---|---|
**静态变量**| 全局变量,文件内的static变量,指定static的局部变量都持有静态储存周期  | 从程序运行时开始,到程序关闭时结束
**自动变量**| 没有指定static的局部变量持有自动储存期  | 到声明该变量的语句块执行结束为止
**malloc()**| 变量通过malloc()分配的领域 | 到free()释放为止

- 代码示例 [print_address.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/print_address.c)

## 自动变量(栈)
> **自动变量**重复使用内存区域,因此自动变量的**地址不是一定的**.

- 代码示例 [auto.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/auto.c)

> 大部分CPU中已经嵌入**栈**的功能,C语言通常直接使用.
> C语言中,通常将自动变量1保存在**栈**中.

`assert(条件表达式)`:若表达式为真,assert()不执行任何动作,否则在标准错误 stderr 上显示错误消息，并中止程序执行.

## 动态内存分配
**malloc()**:
- 声明: `void *malloc(size_t size)`
- **功能**:分配所需的内存空间，并返回一个指向它的指针.
- 在标准C库中，提供了`malloc/free`函数分配释放内存，这两个函数底层是由brk，mmap，munmap这些系统调用实现的,但他们不是系统调用,是标准库函数.

 可能调用 `free()` 后,**对应的内存区域不会立即返还给操作系统**,因为可能有2个指针(A与B)在引用当前区域的情况出现,使用指针A引用的区域后仓促调用 `free()` ,指针B引用的内存区域也不会立即破坏,暂时保留以前的值,**直到某个地方执行 `malloc()`** ,随着当前内存区域被重新分配,内容才开始被破坏.
- 代码示例 [free.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/free.c)

> 碎片化 : 内存被零零散散分割,出现较多无法利用的细碎空块.
> 使用 `malloc()` 的内存管理过程,可能引发碎片化

**realloc()**
- 声明: `void *realloc(void *ptr, size_t size)`
- 功能: 尝试重新调整之前调用 `malloc` 或 `calloc` 所分配的 `ptr` 所指向的内存块的大小,即**扩展内存区域**. 如果通过`ptr`传递的区域后面有足够大小的空闲空间,则直接实施内存区域扩展. 若没有足够多的区域,则**分配其他新空间**,然后将内容**复制**过去.
- `realloc`同样可能引发**碎片化**,但相比`malloc`较为缓和,但要是用在**扩展较大的内存区域**,除了复制耗时,也会造成堆中大量的空间过分活跃,此时应该积极使用**链表**.
- 代码示例 [realloc.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/realloc.c)

## 布局内存对齐

根据硬件(**CPU**)的特征,对于不同数据类型的可配置地址受到一定的限制.

为了**提高CPU的效率**,**编译器**会适当地进行 **边界调整(布局对齐)** ,在结构体中插入合适的**填充物**(也就是再添加适当大小的储存空间). 但即便使用手工进行布局对其,也不能提高可移植性.
- 代码示例 [alignment.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/alignment.c)

## 字节序

[字节序](https://baike.baidu.com/item/%E5%AD%97%E8%8A%82%E5%BA%8F/1457160)，即**字节在电脑中存放时的序列**与输入（输出）时的序列是先到的在前还是后到的在前.

字节排序分为**大端字节序**和**小端字节序**. 说明见代码
- 代码示例 [byteorder.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/byteorder.c)
- 无论是整数还是浮点数,内存上的表现形式都随环境(CPU)的不同而不同.

![字节排序](https://i.imgur.com/N2eJ7hQ.png)

## C语言的声明

要用英语来解读 C 的声明.
1. 首先着眼于标识符(变量名或者函数名).
2. 从距离标识符最近的地方开始,依照优先顺序解释派生类型(指针.数组和函数).优先顺序说明:
  	1. 用于整理声明内容的括弧
  	2. 用于表示数组的 [],用于表示函数的 ()
  	3. 用于表示指针的 *
3. 解释完派生类型,使用"of","to","returning" 等将他们连接起来.
4. 最后,追加数据类型修饰符(在最左边,int double等).


| C语言 | 英语表达 | 中文表达 |
|:------|:--------|:--------|
|int hoge;|hoge is int|hoge 是 int |
|int hoge[10];|hoge is array(元素个数10)of int|hoge 是 int 的数组(元素个数10)|
|int hoge[10][3];|hoge is array(元素个数10) of array(元素个数3)of int|hoge 是 int 数组(元素个数3)的数组(元素个数10)|
|int *hoge[10];|hoge is array(元素个数10) of pointer to int|hoge 是指向 int 的指针的数组(元素个数10)| 
|int (*hoge)[3];|hoge is pointer to array(元素个数3) of int|hoge 是指向 int 的数组(元素个数3)的指针|
|int func(int a);|func  is function(参数为int a) returning int|func 是返回 int 的函数(参数为int a)|
|int (*func_p)(int a);|func_p is pointer to function(参数为int a) returning int|func_p是指向返回 int 的函数(参数为int a)的指针|


## C语言的表达式

**基本表达式**:
- 标识符(变量名,函数名)
- 常量(包括整数常量和浮点数常量)
- 字符串常量(使用 " " 括起来的字符串)
- 使用 () 括起来的表达式

**左值**
作为变量,它有作为 **"自身的值"** 和作为 **"自身内存区域"** 两种情况, 例如 `hoge = 10;` 和 `*hoge_p = &hoge; *hoge_p = 10;` .像这样表达式代表**某处的内存区域**的时候,称当前的表达式为**左值(lvalue)**; 相对的,当表达式代表**值**的时候,称当前表达式为**右值** .

**数组和指针相关的运算符**


| 运算符   |  作用    |
|:-------:|:-------:|
| `*`|单目运算符,称为**解引用**.将**指针**作为操作数,返回指针所指向的**对象或者函数**. 只要不是返回函数,运算符`*`的结果都是**左值**|
|`&`|单目运算符,称为**地址运算符**.将一个**左值**作为操作数,返回指向该**左值的指针**.对左值的类型加上一个指针,就是`&`运算符的返回类型|
|`->`|**箭头运算符**,通过指针访问**结构体**的成员的时候,用它引用某成员|

**const**
> `const`是在ANSI C中追加的修饰符,它将类型修饰为"只读"
> 可以定义`const`常量,但`const`不一定代表常量

假如有一个结构体:
```
struct Books{
	char *title;
	int price;
	char isbn[32];
};

void regist_book(struct Books const *book_data)
```
因为使用了`const`所以`book_data`所指向的对象是**禁止改写**的,但`book_data->title`所指向的内容是可以被改写的.
这种情况是因为由于`const`而成"只读"对象是 **"`book_data`所指向的对象自身"** ,而不包括 **"`book_data`所指向的对象再向前追溯到的对象"** 即结构体内的`title`所指向的对象.解决办法为`char const *title`


## 指针常量与指针变量

## 数组指针和指针数组
[数组指针与指针数组](https://github.com/SouthBegonia/Codes_2018/tree/master/Pointer/PointerWithArray)