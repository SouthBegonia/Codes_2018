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

